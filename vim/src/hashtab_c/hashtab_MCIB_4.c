

/*
 * hashtab.c: Handling of a hashtable with Vim-specific properties.
 *
 * Each item in a hashtable has a NUL terminated string key.  A key can appear
 * only once in the table.
 *
 * A hash number is computed from the key for quick lookup.  When the hashes
 * of two different keys point to the same entry an algorithm is used to
 * iterate over other entries in the table until the right one is found.
 * To make the iteration work removed keys are different from entries where a
 * key was never present.
 *
 * The mechanism has been partly based on how Python Dictionaries are
 * implemented.  The algorithm is from Knuth Vol. 3, Sec. 6.4.
 *
 * The hashtable grows to accommodate more entries when needed.  At least 1/3
 * of the entries is empty to keep the lookup efficient (at the cost of extra
 * memory).
 */

#include "vim.h"

#if 0
# define HT_DEBUG	

static long hash_count_lookup = 0;	/* count number of hashtab lookups */
static long hash_count_perturb = 0;	
#endif

/* Magic value for algorithm that walks through the array. */
#define PERTURB_SHIFT 5
int i = 1;

static int hash_may_resize(hashtab_T *ht, int minitems);

void
hash_init(hashtab_T *ht)
{
    /* This zeroes all "ht_" entries and all the "hi_key" in "ht_smallarray". */
    vim_memset(ht, 0, sizeof(hashtab_T));
    ht->ht_array = ht->ht_smallarray;
    ht->ht_mask = HT_INIT_SIZE - 1;
}
#if 0 
/*
 * Create an empty hash table.
 * Returns NULL when out of memory.
 */
    hashtab_T *
hash_create(void)
{
    hashtab_T *ht;

    ht = (hashtab_T *)alloc(sizeof(hashtab_T));
    if (ht != NULL)
	hash_init(ht);
    return ht;
}
#endif


    


    void
hash_clear(hashtab_T *ht)
{
    if (ht->ht_array != ht->ht_smallarray)
	vim_free(ht->ht_array);
}

/*
 * Free the array of a hash table and all the keys it contains.  The keys must
 * have been allocated.  "off" is the offset from the start of the allocate
 * memory to the location of the key (it's always positive).
 */
    void
hash_clear_all(hashtab_T *ht, int off)
{
    long	todo;
    hashitem_T	*hi;

    todo = (long)ht->ht_used;
    for (hi = ht->ht_array; todo > 0; ++hi)
    {
	if (!HASHITEM_EMPTY(hi))
	{
	    vim_free(hi->hi_key - off);
	    --todo;
	}
    }
    hash_clear(ht);
}


    hashitem_T *
hash_find(hashtab_T *ht, char_u *key)
{
    return hash_lookup(ht, key, hash_hash(key));
}

/*
 * Like hash_find(), but caller computes "hash".
 */
    hashitem_T *
hash_lookup(hashtab_T *ht, char_u *key, hash_T hash)
{
    hash_T	perturb;
    hashitem_T	*freeitem;
    hashitem_T	*hi;
    unsigned	idx;

#ifdef HT_DEBUG
    ++hash_count_lookup;
#endif

    
    idx = (unsigned)(hash & ht->ht_mask);
    hi = &ht->ht_array[idx];

    if (hi->hi_key == NULL)
	return hi;
    if (hi->hi_key == HI_KEY_REMOVED)
	freeitem = hi;
    else if (hi->hi_hash == hash && STRCMP(hi->hi_key, key) == 0)
	return hi;
    else
	freeitem = NULL;

    /*
     * Need to search through the table to find the key.  The algorithm
     * to step through the table starts with large steps, gradually becoming
     * smaller down to (1/4 table size + 1).  This means it goes through all
     * table entries in the end.
     * When we run into a NULL key it's clear that the key isn't there.
     * Return the first available slot found (can be a slot of a removed
     * item).
     */
    for (perturb = hash; ; perturb >>= PERTURB_SHIFT)
    {
#ifdef HT_DEBUG
	++hash_count_perturb;	    
#endif
	idx = (unsigned)((idx << 2U) + idx + perturb + 1U);
	hi = &ht->ht_array[idx & ht->ht_mask];
	if (hi->hi_key == NULL)
	    return freeitem == NULL ? hi : freeitem;
	if (hi->hi_hash == hash
		&& hi->hi_key != HI_KEY_REMOVED
		&& STRCMP(hi->hi_key, key) == 0)
	    return hi;
	if (hi->hi_key == HI_KEY_REMOVED && freeitem == NULL)
	    freeitem = hi;
    }
}

/*
 * Print the efficiency of hashtable lookups.
 * Useful when trying different hash algorithms.
 * Called when exiting.
 */
    void
hash_debug_results(void)
{
#ifdef HT_DEBUG
    fprintf(stderr, "\r\n\r\n\r\n\r\n");
    fprintf(stderr, "Number of hashtable lookups: %ld\r\n", hash_count_lookup);
    fprintf(stderr, "Number of perturb loops: %ld\r\n", hash_count_perturb);
    fprintf(stderr, "Percentage of perturb loops: %ld%%\r\n",
				hash_count_perturb * 100 / hash_count_lookup);
#endif
}


    int
hash_add(hashtab_T *ht, char_u *key)
{
    hash_T	hash = hash_hash(key);
    hashitem_T	*hi;

    hi = hash_lookup(ht, key, hash);
    if (!HASHITEM_EMPTY(hi))
    {
	internal_error("hash_add()");
	return FAIL;
    }
    return hash_add_item(ht, hi, key, hash);
}

/*
 * Add item "hi" with "key" to hashtable "ht".  "key" must not be NULL and
 * "hi" must have been obtained with hash_lookup() and point to an empty item.
 * "hi" is invalid after this!
 * Returns OK or FAIL (out of memory).
 */
    int
hash_add_item(
    hashtab_T	*ht,
    hashitem_T	*hi,
    char_u	*key,
    hash_T	hash)
{
    
    if (ht->ht_error && hash_may_resize(ht, 0) == FAIL)
	return FAIL;

    ++ht->ht_used;
    if (hi->hi_key == NULL)
	++ht->ht_filled;
    hi->hi_key = key;
    hi->hi_hash = hash;

    /* When the space gets low may resize the array. */
    return hash_may_resize(ht, 0);
}

#if 0  
/*
 * Overwrite hashtable item "hi" with "key".  "hi" must point to the item that
 * is to be overwritten.  Thus the number of items in the hashtable doesn't
 * change.
 * Although the key must be identical, the pointer may be different, thus it's
 * set anyway (the key is part of an item with that key).
 * The caller must take care of freeing the old item.
 * "hi" is invalid after this!
 */
    void
hash_set(hashitem_T *hi, char_u *key)
{
    hi->hi_key = key;
}
#endif


    void
hash_remove(hashtab_T *ht, hashitem_T *hi)
{
    --ht->ht_used;
    hi->hi_key = HI_KEY_REMOVED;
    hash_may_resize(ht, 0);
}

/*
 * Lock a hashtable: prevent that ht_array changes.
 * Don't use this when items are to be added!
 * Must call hash_unlock() later.
 */
    void
hash_lock(hashtab_T *ht)
{
    ++ht->ht_locked;
}

#if 0	    
/*
 * Lock a hashtable at the specified number of entries.
 * Caller must make sure no more than "size" entries will be added.
 * Must call hash_unlock() later.
 */
    void
hash_lock_size(hashtab_T *ht, int size)
{
    (void)hash_may_resize(ht, size);
    ++ht->ht_locked;
}
#endif


    void
hash_unlock(hashtab_T *ht)
{
    --ht->ht_locked;
    (void)hash_may_resize(ht, 0);
}

/*
 * Shrink a hashtable when there is too much empty space.
 * Grow a hashtable when there is not enough empty space.
 * Returns OK or FAIL (out of memory).
 */
    static int
hash_may_resize(
    hashtab_T	*ht,
    int		minitems)		
{
    hashitem_T	temparray[HT_INIT_SIZE];
    hashitem_T	*oldarray, *newarray;
    hashitem_T	*olditem, *newitem;
    unsigned	newi;
    int		todo;
    long_u	oldsize, newsize;
    long_u	minsize;
    long_u	newmask;
    hash_T	perturb;

    /* Don't resize a locked table. */
    if (ht->ht_locked > 0)
	return OK;

#ifdef HT_DEBUG
    if (ht->ht_used > ht->ht_filled)
	EMSG("hash_may_resize(): more used than filled");
    if (ht->ht_filled >= ht->ht_mask + 1)
	EMSG("hash_may_resize(): table completely filled");
#endif

    if (minitems == 0)
    {
	
	if (ht->ht_filled < HT_INIT_SIZE - 1
					 && ht->ht_array == ht->ht_smallarray)
	    return OK;

	/*
	 * Grow or refill the array when it's more than 2/3 full (including
	 * removed items, so that they get cleaned up).
	 * Shrink the array when it's less than 1/5 full.  When growing it is
	 * at least 1/4 full (avoids repeated grow-shrink operations)
	 */
	oldsize = ht->ht_mask + 1;
	if (ht->ht_filled * 3 < oldsize * 2 && ht->ht_used > oldsize / 5)
	    return OK;

	if (ht->ht_used > 1000)
	    minsize = ht->ht_used * 2;  
	else
	    minsize = ht->ht_used * 4;  /* make plenty of room */
    }
    else
    {
	
	if ((long_u)minitems < ht->ht_used)	/* just in case... */
	    minitems = (int)ht->ht_used;
	minsize = minitems * 3 / 2;	
    }

    newsize = HT_INIT_SIZE;
    while (newsize < minsize)
    {
	newsize <<= 1;		/* make sure it's always a power of 2 */
	if (newsize == 0)
	    return FAIL;	
    }

    if (newsize == HT_INIT_SIZE)
    {
	/* Use the small array inside the hashdict structure. */
	newarray = ht->ht_smallarray;
	if (ht->ht_array == newarray)
	{
	    
	    mch_memmove(temparray, newarray, sizeof(temparray));
	    oldarray = temparray;
	}
	else
	    oldarray = ht->ht_array;
    }
    else
    {
	/* Allocate an array. */
	newarray = (hashitem_T *)alloc((unsigned)
					      (sizeof(hashitem_T) * newsize));
	if (newarray == NULL)
	{
	    
	    if (ht->ht_filled < ht->ht_mask)
		return OK;
	    ht->ht_error = TRUE;
	    return FAIL;
	}
	oldarray = ht->ht_array;
    }
    vim_memset(newarray, 0, (size_t)(sizeof(hashitem_T) * newsize));

    /*
     * Move all the items from the old array to the new one, placing them in
     * the right spot.  The new array won't have any removed items, thus this
     * is also a cleanup action.
     */
    newmask = newsize - 1;
    todo = (int)ht->ht_used;
    for (olditem = oldarray; todo > 0; ++olditem)
	if (!HASHITEM_EMPTY(olditem))
	{
	    
	    newi = (unsigned)(olditem->hi_hash & newmask);
	    newitem = &newarray[newi];

	    if (newitem->hi_key != NULL)
		for (perturb = olditem->hi_hash; ; perturb >>= PERTURB_SHIFT)
		{
		    newi = (unsigned)((newi << 2U) + newi + perturb + 1U);
		    newitem = &newarray[newi & newmask];
		    if (newitem->hi_key == NULL)
			break;
		}
	    *newitem = *olditem;
	    --todo;
	}

    if (ht->ht_array != ht->ht_smallarray)
	vim_free(ht->ht_array);
    ht->ht_array = newarray;
    ht->ht_mask = newmask;
    ht->ht_filled = ht->ht_used;
    ht->ht_error = FALSE;

    return OK;
}

/*
 * Get the hash number for a key.
 * If you think you know a better hash function: Compile with HT_DEBUG set and
 * run a script that uses hashtables a lot.  Vim will then print statistics
 * when exiting.  Try that with the current hash algorithm and yours.  The
 * lower the percentage the better.
 */
    hash_T
hash_hash(char_u *key)
{
    hash_T	hash;
    char_u	*p;

    if ((hash = *key) == 0)
	return (hash_T)0;
    p = key + 1;

    
    while (*p != NUL)
	hash = hash * 101 + *p++;

    return hash;
}
