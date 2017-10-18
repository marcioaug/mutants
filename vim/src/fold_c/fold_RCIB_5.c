/* vi:set ts=8 sts=4 sw=4 noet:
 * vim600:fdm=marker fdl=1 fdc=3:
 *
 * VIM - Vi IMproved	by Bram Moolenaar
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 * See README.txt for an overview of the Vim source code.
 */

/*
 * fold.c: code for folding
 */

#include "vim.h"

#if defined(FEAT_FOLDING) || defined(PROTO)

/* local declarations. {{{1 */
/* typedef fold_T {{{2 */
/*
 * The toplevel folds for each window are stored in the w_folds growarray.
 * Each toplevel fold can contain an array of second level folds in the
 * fd_nested growarray.
 * The info stored in both growarrays is the same: An array of fold_T.
 */
typedef struct
{
    linenr_T	fd_top;		/* first line of fold; for nested fold
				 * relative to parent */
    linenr_T	fd_len;		/* number of lines in the fold */
    garray_T	fd_nested;	/* array of nested folds */
    char	fd_flags;	/* see below */
    char	fd_small;	/* TRUE, FALSE or MAYBE: fold smaller than
				   'foldminlines'; MAYBE applies to nested
				   folds too */
} fold_T;

#define FD_OPEN		0	/* fold is open (nested ones can be closed) */
#define FD_CLOSED	1	/* fold is closed */
#define FD_LEVEL	2	/* depends on 'foldlevel' (nested folds too) */

#define MAX_LEVEL	20	/* maximum fold depth */

/* static functions {{{2 */
static void newFoldLevelWin(win_T *wp);
static int checkCloseRec(garray_T *gap, linenr_T lnum, int level);
static int foldFind(garray_T *gap, linenr_T lnum, fold_T **fpp);
static int foldLevelWin(win_T *wp, linenr_T lnum);
static void checkupdate(win_T *wp);
static void setFoldRepeat(linenr_T lnum, long count, int do_open);
static linenr_T setManualFold(linenr_T lnum, int opening, int recurse, int *donep);
static linenr_T setManualFoldWin(win_T *wp, linenr_T lnum, int opening, int recurse, int *donep);
static void foldOpenNested(fold_T *fpr);
static void deleteFoldEntry(garray_T *gap, int idx, int recursive);
static void foldMarkAdjustRecurse(garray_T *gap, linenr_T line1, linenr_T line2, long amount, long amount_after);
static int getDeepestNestingRecurse(garray_T *gap);
static int check_closed(win_T *win, fold_T *fp, int *use_levelp, int level, int *maybe_smallp, linenr_T lnum_off);
static void checkSmall(win_T *wp, fold_T *fp, linenr_T lnum_off);
static void setSmallMaybe(garray_T *gap);
static void foldCreateMarkers(linenr_T start, linenr_T end);
static void foldAddMarker(linenr_T lnum, char_u *marker, int markerlen);
static void deleteFoldMarkers(fold_T *fp, int recursive, linenr_T lnum_off);
static void foldDelMarker(linenr_T lnum, char_u *marker, int markerlen);
static void foldUpdateIEMS(win_T *wp, linenr_T top, linenr_T bot);
static void parseMarker(win_T *wp);

static char *e_nofold = N_("E490: No fold found");

/*
 * While updating the folds lines between invalid_top and invalid_bot have an
 * undefined fold level.  Only used for the window currently being updated.
 */
static linenr_T invalid_top = (linenr_T)0;
static linenr_T invalid_bot = (linenr_T)0;

/*
 * When using 'foldexpr' we sometimes get the level of the next line, which
 * calls foldlevel() to get the level of the current line, which hasn't been
 * stored yet.  To get around this chicken-egg problem the level of the
 * previous line is stored here when available.  prev_lnum is zero when the
 * level is not available.
 */
static linenr_T prev_lnum = 0;
static int prev_lnum_lvl = -1;

/* Flags used for "done" argument of setManualFold. */
#define DONE_NOTHING	0
#define DONE_ACTION	1	/* did close or open a fold */
#define DONE_FOLD	2	/* did find a fold */

static int foldstartmarkerlen;
static char_u *foldendmarker;
static int foldendmarkerlen;

/* Exported folding functions. {{{1 */
/* copyFoldingState() {{{2 */

/*
 * Copy that folding state from window "wp_from" to window "wp_to".
 */
    void
copyFoldingState(win_T *wp_from, win_T *wp_to)
{
    wp_to->w_fold_manual = wp_from->w_fold_manual;
    wp_to->w_foldinvalid = wp_from->w_foldinvalid;
    cloneFoldGrowArray(&wp_from->w_folds, &wp_to->w_folds);
}

/* hasAnyFolding() {{{2 */
/*
 * Return TRUE if there may be folded lines in the current window.
 */
    int
hasAnyFolding(win_T *win)
{
    /* very simple now, but can become more complex later */
    return (win->w_p_fen
	    && (!foldmethodIsManual(win) || win->w_folds.ga_len > 0));
}

/* hasFolding() {{{2 */
/*
 * Return TRUE if line "lnum" in the current window is part of a closed
 * fold.
 * When returning TRUE, *firstp and *lastp are set to the first and last
 * lnum of the sequence of folded lines (skipped when NULL).
 */
    int
hasFolding(linenr_T lnum, linenr_T *firstp, linenr_T *lastp)
{
    return hasFoldingWin(curwin, lnum, firstp, lastp, TRUE, NULL);
}

/* hasFoldingWin() {{{2 */
    int
hasFoldingWin(
    win_T	*win,
    linenr_T	lnum,
    linenr_T	*firstp,
    linenr_T	*lastp,
    int		cache,		/* when TRUE: use cached values of window */
    foldinfo_T	*infop)		/* where to store fold info */
{
    int		had_folded = FALSE;
    linenr_T	first = 0;
    linenr_T	last = 0;
    linenr_T	lnum_rel = lnum;
    int		x;
    fold_T	*fp;
    int		level = 0;
    int		use_level = FALSE;
    int		maybe_small = FALSE;
    garray_T	*gap;
    int		low_level = 0;

    checkupdate(win);
    /*
     * Return quickly when there is no folding at all in this window.
     */
    if (!hasAnyFolding(win))
    {
	if (infop != NULL)
	    infop->fi_level = 0;
	return FALSE;
    }

    if (cache)
    {
	/*
	 * First look in cached info for displayed lines.  This is probably
	 * the fastest, but it can only be used if the entry is still valid.
	 */
	x = find_wl_entry(win, lnum);
	if (x >= 0)
	{
	    first = win->w_lines[x].wl_lnum;
	    last = win->w_lines[x].wl_lastlnum;
	    had_folded = win->w_lines[x].wl_folded;
	}
    }

    if (first == 0)
    {
	/*
	 * Recursively search for a fold that contains "lnum".
	 */
	gap = &win->w_folds;
	for (;;)
	{
	    if (!foldFind(gap, lnum_rel, &fp))
		break;

	    /* Remember lowest level of fold that starts in "lnum". */
	    if (lnum_rel == fp->fd_top && low_level == 0)
		low_level = level + 1;

	    first += fp->fd_top;
	    last += fp->fd_top;

	    /* is this fold closed? */
	    had_folded = check_closed(win, fp, &use_level, level,
					       &maybe_small, lnum - lnum_rel);
	    if (had_folded)
	    {
		/* Fold closed: Set last and quit loop. */
		last += fp->fd_len - 1;
		break;
	    }

	    /* Fold found, but it's open: Check nested folds.  Line number is
	     * relative to containing fold. */
	    gap = &fp->fd_nested;
	    lnum_rel -= fp->fd_top;
	    ++level;
	}
    }

    if (!had_folded)
    {
	if (infop != NULL)
	{
	    infop->fi_level = level;
	    infop->fi_lnum = lnum - lnum_rel;
	    infop->fi_low_level = low_level == 0 ? level : low_level;
	}
	return FALSE;
    }

    if (last > win->w_buffer->b_ml.ml_line_count)
	last = win->w_buffer->b_ml.ml_line_count;
    if (lastp != NULL)
	*lastp = last;
    if (firstp != NULL)
	*firstp = first;
    if (infop != NULL)
    {
	infop->fi_level = level + 1;
	infop->fi_lnum = first;
	infop->fi_low_level = low_level == 0 ? level + 1 : low_level;
    }
    return TRUE;
}

/* foldLevel() {{{2 */
/*
 * Return fold level at line number "lnum" in the current window.
 */
    int
foldLevel(linenr_T lnum)
{
    /* While updating the folds lines between invalid_top and invalid_bot have
     * an undefined fold level.  Otherwise update the folds first. */
    if (invalid_top == (linenr_T)0)
	checkupdate(curwin);
    else if (lnum == prev_lnum && prev_lnum_lvl >= 0)
	return prev_lnum_lvl;
    else if (lnum >= invalid_top && lnum <= invalid_bot)
	return -1;

    /* Return quickly when there is no folding at all in this window. */
    if (!hasAnyFolding(curwin))
	return 0;

    return foldLevelWin(curwin, lnum);
}

/* lineFolded()	{{{2 */
/*
 * Low level function to check if a line is folded.  Doesn't use any caching.
 * Return TRUE if line is folded.
 * Return FALSE if line is not folded.
 * Return MAYBE if the line is folded when next to a folded line.
 */
    int
lineFolded(win_T *win, linenr_T lnum)
{
    return foldedCount(win, lnum, NULL) != 0;
}

/* foldedCount() {{{2 */
/*
 * Count the number of lines that are folded at line number "lnum".
 * Normally "lnum" is the first line of a possible fold, and the returned
 * number is the number of lines in the fold.
 * Doesn't use caching from the displayed window.
 * Returns number of folded lines from "lnum", or 0 if line is not folded.
 * When "infop" is not NULL, fills *infop with the fold level info.
 */
    long
foldedCount(win_T *win, linenr_T lnum, foldinfo_T *infop)
{
    linenr_T	last;

    if (hasFoldingWin(win, lnum, NULL, &last, FALSE, infop))
	return (long)(last - lnum + 1);
    return 0;
}

/* foldmethodIsManual() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "manual"
 */
    int
foldmethodIsManual(win_T *wp)
{
    return (wp->w_p_fdm[3] == 'u');
}

/* foldmethodIsIndent() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "indent"
 */
    int
foldmethodIsIndent(win_T *wp)
{
    return (wp->w_p_fdm[0] == 'i');
}

/* foldmethodIsExpr() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "expr"
 */
    int
foldmethodIsExpr(win_T *wp)
{
    return (wp->w_p_fdm[1] == 'x');
}

/* foldmethodIsMarker() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "marker"
 */
    int
foldmethodIsMarker(win_T *wp)
{
    return (wp->w_p_fdm[2] == 'r');
}

/* foldmethodIsSyntax() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "syntax"
 */
    int
foldmethodIsSyntax(win_T *wp)
{
    return (wp->w_p_fdm[0] == 's');
}

/* foldmethodIsDiff() {{{2 */
/*
 * Return TRUE if 'foldmethod' is "diff"
 */
    int
foldmethodIsDiff(win_T *wp)
{
    return (wp->w_p_fdm[0] == 'd');
}

/* closeFold() {{{2 */
/*
 * Close fold for current window at line "lnum".
 * Repeat "count" times.
 */
    void
closeFold(linenr_T lnum, long count)
{
    setFoldRepeat(lnum, count, FALSE);
}

/* closeFoldRecurse() {{{2 */
/*
 * Close fold for current window at line "lnum" recursively.
 */
    void
closeFoldRecurse(linenr_T lnum)
{
    (void)setManualFold(lnum, FALSE, TRUE, NULL);
}

/* opFoldRange() {{{2 */
/*
 * Open or Close folds for current window in lines "first" to "last".
 * Used for "zo", "zO", "zc" and "zC" in Visual mode.
 */
    void
opFoldRange(
    linenr_T	first,
    linenr_T	last,
    int		opening,	/* TRUE to open, FALSE to close */
    int		recurse,	/* TRUE to do it recursively */
    int		had_visual)	/* TRUE when Visual selection used */
{
    int		done = DONE_NOTHING;	/* avoid error messages */
    linenr_T	lnum;
    linenr_T	lnum_next;

    for (lnum = first; lnum <= last; lnum = lnum_next + 1)
    {
	lnum_next = lnum;
	/* Opening one level only: next fold to open is after the one going to
	 * be opened. */
	if (opening && !recurse)
	    (void)hasFolding(lnum, NULL, &lnum_next);
	(void)setManualFold(lnum, opening, recurse, &done);
	/* Closing one level only: next line to close a fold is after just
	 * closed fold. */
	if (!opening && !recurse)
	    (void)hasFolding(lnum, NULL, &lnum_next);
    }
    if (done == DONE_NOTHING)
	EMSG(_(e_nofold));
    /* Force a redraw to remove the Visual highlighting. */
    if (had_visual)
	redraw_curbuf_later(INVERTED);
}

/* openFold() {{{2 */
/*
 * Open fold for current window at line "lnum".
 * Repeat "count" times.
 */
    void
openFold(linenr_T lnum, long count)
{
    setFoldRepeat(lnum, count, TRUE);
}

/* openFoldRecurse() {{{2 */
/*
 * Open fold for current window at line "lnum" recursively.
 */
    void
openFoldRecurse(linenr_T lnum)
{
    (void)setManualFold(lnum, TRUE, TRUE, NULL);
}

/* foldOpenCursor() {{{2 */
/*
 * Open folds until the cursor line is not in a closed fold.
 */
    void
foldOpenCursor(void)
{
    int		done;

    checkupdate(curwin);
    if (hasAnyFolding(curwin))
	for (;;)
	{
	    done = DONE_NOTHING;
	    (void)setManualFold(curwin->w_cursor.lnum, TRUE, FALSE, &done);
	    if (!(done & DONE_ACTION))
		break;
	}
}

/* newFoldLevel() {{{2 */
/*
 * Set new foldlevel for current window.
 */
    void
newFoldLevel(void)
{
    newFoldLevelWin(curwin);

#ifdef FEAT_DIFF
    if (foldmethodIsDiff(curwin) && curwin->w_p_scb)
    {
	win_T	    *wp;

	/*
	 * Set the same foldlevel in other windows in diff mode.
	 */
	FOR_ALL_WINDOWS(wp)
	{
	    if (wp != curwin && foldmethodIsDiff(wp) && wp->w_p_scb)
	    {
		wp->w_p_fdl = curwin->w_p_fdl;
		newFoldLevelWin(wp);
	    }
	}
    }
#endif
}

    static void
newFoldLevelWin(win_T *wp)
{
    fold_T	*fp;
    int		i;

    checkupdate(wp);
    if (wp->w_fold_manual)
    {
	/* Set all flags for the first level of folds to FD_LEVEL.  Following
	 * manual open/close will then change the flags to FD_OPEN or
	 * FD_CLOSED for those folds that don't use 'foldlevel'. */
	fp = (fold_T *)wp->w_folds.ga_data;
	for (i = 0; i < wp->w_folds.ga_len; ++i)
	    fp[i].fd_flags = FD_LEVEL;
	wp->w_fold_manual = FALSE;
    }
    changed_window_setting_win(wp);
}

/* foldCheckClose() {{{2 */
/*
 * Apply 'foldlevel' to all folds that don't contain the cursor.
 */
    void
foldCheckClose(void)
{
    if (*p_fcl != NUL)	/* can only be "all" right now */
    {
	checkupdate(curwin);
	if (checkCloseRec(&curwin->w_folds, curwin->w_cursor.lnum,
							(int)curwin->w_p_fdl))
	    changed_window_setting();
    }
}

/* checkCloseRec() {{{2 */
    static int
checkCloseRec(garray_T *gap, linenr_T lnum, int level)
{
    fold_T	*fp;
    int		retval = FALSE;
    int		i;

    fp = (fold_T *)gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i)
    {
	/* Only manually opened folds may need to be closed. */
	if (fp[i].fd_flags == FD_OPEN)
	{
	    if (level <= 0 && (lnum < fp[i].fd_top
				      || lnum >= fp[i].fd_top + fp[i].fd_len))
	    {
		fp[i].fd_flags = FD_LEVEL;
		retval = TRUE;
	    }
	    else
		retval |= checkCloseRec(&fp[i].fd_nested, lnum - fp[i].fd_top,
								   level - 1);
	}
    }
    return retval;
}

/* foldCreateAllowed() {{{2 */
/*
 * Return TRUE if it's allowed to manually create or delete a fold.
 * Give an error message and return FALSE if not.
 */
    int
foldManualAllowed(int create)
{
    if (foldmethodIsManual(curwin) || foldmethodIsMarker(curwin))
	return TRUE;
    if (create)
	EMSG(_("E350: Cannot create fold with current 'foldmethod'"));
    else
	EMSG(_("E351: Cannot delete fold with current 'foldmethod'"));
    return FALSE;
}

/* foldCreate() {{{2 */
/*
 * Create a fold from line "start" to line "end" (inclusive) in the current
 * window.
 */
    void
foldCreate(linenr_T start, linenr_T end)
{
    fold_T	*fp;
    garray_T	*gap;
    garray_T	fold_ga;
    int		i, j;
    int		cont;
    int		use_level = FALSE;
    int		closed = FALSE;
    int		level = 0;
    linenr_T	start_rel = start;
    linenr_T	end_rel = end;

    if (start > end)
    {
	/* reverse the range */
	end = start_rel;
	start = end_rel;
	start_rel = start;
	end_rel = end;
    }

    /* When 'foldmethod' is "marker" add markers, which creates the folds. */
    if (foldmethodIsMarker(curwin))
    {
	foldCreateMarkers(start, end);
	return;
    }

    checkupdate(curwin);

    /* Find the place to insert the new fold. */
    gap = &curwin->w_folds;
    for (;;)
    {
	if (!foldFind(gap, start_rel, &fp))
	    break;
	if (fp->fd_top + fp->fd_len > end_rel)
	{
	    /* New fold is completely inside this fold: Go one level deeper. */
	    gap = &fp->fd_nested;
	    start_rel -= fp->fd_top;
	    end_rel -= fp->fd_top;
	    if (use_level || fp->fd_flags == FD_LEVEL)
	    {
		use_level = TRUE;
		if (level >= curwin->w_p_fdl)
		    closed = TRUE;
	    }
	    else if (fp->fd_flags == FD_CLOSED)
		closed = TRUE;
	    ++level;
	}
	else
	{
	    /* This fold and new fold overlap: Insert here and move some folds
	     * inside the new fold. */
	    break;
	}
    }

    i = (int)(fp - (fold_T *)gap->ga_data);
    if (ga_grow(gap, 1) == OK)
    {
	fp = (fold_T *)gap->ga_data + i;
	ga_init2(&fold_ga, (int)sizeof(fold_T), 10);

	/* Count number of folds that will be contained in the new fold. */
	for (cont = 0; i + cont < gap->ga_len; ++cont)
	    if (fp[cont].fd_top > end_rel)
		break;
	if (cont > 0 && ga_grow(&fold_ga, cont) == OK)
	{
	    /* If the first fold starts before the new fold, let the new fold
	     * start there.  Otherwise the existing fold would change. */
	    if (start_rel > fp->fd_top)
		start_rel = fp->fd_top;

	    /* When last contained fold isn't completely contained, adjust end
	     * of new fold. */
	    if (end_rel < fp[cont - 1].fd_top + fp[cont - 1].fd_len - 1)
		end_rel = fp[cont - 1].fd_top + fp[cont - 1].fd_len - 1;
	    /* Move contained folds to inside new fold. */
	    mch_memmove(fold_ga.ga_data, fp, sizeof(fold_T) * cont);
	    fold_ga.ga_len += cont;
	    i += cont;

	    /* Adjust line numbers in contained folds to be relative to the
	     * new fold. */
	    for (j = 0; j < cont; ++j)
		((fold_T *)fold_ga.ga_data)[j].fd_top -= start_rel;
	}
	/* Move remaining entries to after the new fold. */
	if (i < gap->ga_len)
	    mch_memmove(fp + 1, (fold_T *)gap->ga_data + i,
				     sizeof(fold_T) * (gap->ga_len - i));
	gap->ga_len = gap->ga_len + 1 - cont;

	/* insert new fold */
	fp->fd_nested = fold_ga;
	fp->fd_top = start_rel;
	fp->fd_len = end_rel - start_rel + 1;

	/* We want the new fold to be closed.  If it would remain open because
	 * of using 'foldlevel', need to adjust fd_flags of containing folds.
	 */
	if (use_level && !closed && level < curwin->w_p_fdl)
	    closeFold(start, 1L);
	if (!use_level)
	    curwin->w_fold_manual = TRUE;
	fp->fd_flags = FD_CLOSED;
	fp->fd_small = MAYBE;

	/* redraw */
	changed_window_setting();
    }
}

/* deleteFold() {{{2 */
/*
 * Delete a fold at line "start" in the current window.
 * When "end" is not 0, delete all folds from "start" to "end".
 * When "recursive" is TRUE delete recursively.
 */
    void
deleteFold(
    linenr_T	start,
    linenr_T	end,
    int		recursive,
    int		had_visual)	/* TRUE when Visual selection used */
{
    garray_T	*gap;
    fold_T	*fp;
    garray_T	*found_ga;
    fold_T	*found_fp = NULL;
    linenr_T	found_off = 0;
    int		use_level;
    int		maybe_small = FALSE;
    int		level = 0;
    linenr_T	lnum = start;
    linenr_T	lnum_off;
    int		did_one = FALSE;
    linenr_T	first_lnum = MAXLNUM;
    linenr_T	last_lnum = 0;

    checkupdate(curwin);

    while (lnum <= end)
    {
	/* Find the deepest fold for "start". */
	gap = &curwin->w_folds;
	found_ga = NULL;
	lnum_off = 0;
	use_level = FALSE;
	for (;;)
	{
	    if (!foldFind(gap, lnum - lnum_off, &fp))
		break;
	    /* lnum is inside this fold, remember info */
	    found_ga = gap;
	    found_fp = fp;
	    found_off = lnum_off;

	    /* if "lnum" is folded, don't check nesting */
	    if (check_closed(curwin, fp, &use_level, level,
						      &maybe_small, lnum_off))
		break;

	    /* check nested folds */
	    gap = &fp->fd_nested;
	    lnum_off += fp->fd_top;
	    ++level;
	}
	if (found_ga == NULL)
	{
	    ++lnum;
	}
	else
	{
	    lnum = found_fp->fd_top + found_fp->fd_len + found_off;

	    if (foldmethodIsManual(curwin))
		deleteFoldEntry(found_ga,
		    (int)(found_fp - (fold_T *)found_ga->ga_data), recursive);
	    else
	    {
		if (first_lnum > found_fp->fd_top + found_off)
		    first_lnum = found_fp->fd_top + found_off;
		if (last_lnum < lnum)
		    last_lnum = lnum;
		if (!did_one)
		    parseMarker(curwin);
		deleteFoldMarkers(found_fp, recursive, found_off);
	    }
	    did_one = TRUE;

	    /* redraw window */
	    changed_window_setting();
	}
    }
    if (!did_one)
    {
	EMSG(_(e_nofold));
	/* Force a redraw to remove the Visual highlighting. */
	if (had_visual)
	    redraw_curbuf_later(INVERTED);
    }
    else
	/* Deleting markers may make cursor column invalid. */
	check_cursor_col();

    if (last_lnum > 0)
	changed_lines(first_lnum, (colnr_T)0, last_lnum, 0L);
}

/* clearFolding() {{{2 */
/*
 * Remove all folding for window "win".
 */
    void
clearFolding(win_T *win)
{
    deleteFoldRecurse(&win->w_folds);
    win->w_foldinvalid = FALSE;
}

/* foldUpdate() {{{2 */
/*
 * Update folds for changes in the buffer of a window.
 * Note that inserted/deleted lines must have already been taken care of by
 * calling foldMarkAdjust().
 * The changes in lines from top to bot (inclusive).
 */
    void
foldUpdate(win_T *wp, linenr_T top, linenr_T bot)
{
    fold_T	*fp;

    if (disable_fold_update > 0)
	return;

    /* Mark all folds from top to bot as maybe-small. */
    (void)foldFind(&wp->w_folds, top, &fp);
    while (fp < (fold_T *)wp->w_folds.ga_data + wp->w_folds.ga_len
	    && fp->fd_top < bot)
    {
	fp->fd_small = MAYBE;
	++fp;
    }

    if (foldmethodIsIndent(wp)
	    || foldmethodIsExpr(wp)
	    || foldmethodIsMarker(wp)
#ifdef FEAT_DIFF
	    || foldmethodIsDiff(wp)
#endif
	    || foldmethodIsSyntax(wp))
    {
	int save_got_int = got_int;

	/* reset got_int here, otherwise it won't work */
	got_int = FALSE;
	foldUpdateIEMS(wp, top, bot);
	got_int |= save_got_int;
    }
}

/* foldUpdateAll() {{{2 */
/*
 * Update all lines in a window for folding.
 * Used when a fold setting changes or after reloading the buffer.
 * The actual updating is postponed until fold info is used, to avoid doing
 * every time a setting is changed or a syntax item is added.
 */
    void
foldUpdateAll(win_T *win)
{
    win->w_foldinvalid = TRUE;
    redraw_win_later(win, NOT_VALID);
}

/* foldMoveTo() {{{2 */
/*
 * If "updown" is FALSE: Move to the start or end of the fold.
 * If "updown" is TRUE: move to fold at the same level.
 * If not moved return FAIL.
 */
    int
foldMoveTo(
    int		updown,
    int		dir,	    /* FORWARD or BACKWARD */
    long	count)
{
    long	n;
    int		retval = FAIL;
    linenr_T	lnum_off;
    linenr_T	lnum_found;
    linenr_T	lnum;
    int		use_level;
    int		maybe_small;
    garray_T	*gap;
    fold_T	*fp;
    int		level;
    int		last;

    checkupdate(curwin);

    /* Repeat "count" times. */
    for (n = 0; n < count; ++n)
    {
	/* Find nested folds.  Stop when a fold is closed.  The deepest fold
	 * that moves the cursor is used. */
	lnum_off = 0;
	gap = &curwin->w_folds;
	use_level = FALSE;
	maybe_small = FALSE;
	lnum_found = curwin->w_cursor.lnum;
	level = 0;
	last = FALSE;
	for (;;)
	{
	    if (!foldFind(gap, curwin->w_cursor.lnum - lnum_off, &fp))
	    {
		if (!updown)
		    break;

		/* When moving up, consider a fold above the cursor; when
		 * moving down consider a fold below the cursor. */
		if (dir == FORWARD)
		{
		    if (fp - (fold_T *)gap->ga_data >= gap->ga_len)
			break;
		    --fp;
		}
		else
		{
		    if (fp == (fold_T *)gap->ga_data)
			break;
		}
		/* don't look for contained folds, they will always move
		 * the cursor too far. */
		last = TRUE;
	    }

	    if (!last)
	    {
		/* Check if this fold is closed. */
		if (check_closed(curwin, fp, &use_level, level,
						      &maybe_small, lnum_off))
		    last = TRUE;

		/* "[z" and "]z" stop at closed fold */
		if (last && !updown)
		    break;
	    }

	    if (updown)
	    {
		if (dir == FORWARD)
		{
		    /* to start of next fold if there is one */
		    if (fp + 1 - (fold_T *)gap->ga_data < gap->ga_len)
		    {
			lnum = fp[1].fd_top + lnum_off;
			if (lnum > curwin->w_cursor.lnum)
			    lnum_found = lnum;
		    }
		}
		else
		{
		    /* to end of previous fold if there is one */
		    if (fp > (fold_T *)gap->ga_data)
		    {
			lnum = fp[-1].fd_top + lnum_off + fp[-1].fd_len - 1;
			if (lnum < curwin->w_cursor.lnum)
			    lnum_found = lnum;
		    }
		}
	    }
	    else
	    {
		/* Open fold found, set cursor to its start/end and then check
		 * nested folds. */
		if (dir == FORWARD)
		{
		    lnum = fp->fd_top + lnum_off + fp->fd_len - 1;
		    if (lnum > curwin->w_cursor.lnum)
			lnum_found = lnum;
		}
		else
		{
		    lnum = fp->fd_top + lnum_off;
		    if (lnum < curwin->w_cursor.lnum)
			lnum_found = lnum;
		}
	    }

	    if (last)
		break;

	    /* Check nested folds (if any). */
	    gap = &fp->fd_nested;
	    lnum_off += fp->fd_top;
	    ++level;
	}
	if (lnum_found != curwin->w_cursor.lnum)
	{
	    if (retval == FAIL)
		setpcmark();
	    curwin->w_cursor.lnum = lnum_found;
	    curwin->w_cursor.col = 0;
	    retval = OK;
	}
	else
	    break;
    }

    return retval;
}

/* foldInitWin() {{{2 */
/*
 * Init the fold info in a new window.
 */
    void
foldInitWin(win_T *new_win)
{
    ga_init2(&new_win->w_folds, (int)sizeof(fold_T), 10);
}

/* find_wl_entry() {{{2 */
/*
 * Find an entry in the win->w_lines[] array for buffer line "lnum".
 * Only valid entries are considered (for entries where wl_valid is FALSE the
 * line number can be wrong).
 * Returns index of entry or -1 if not found.
 */
    int
find_wl_entry(win_T *win, linenr_T lnum)
{
    int		i;

    for (i = 0; i < win->w_lines_valid; ++i)
	if (win->w_lines[i].wl_valid)
	{
	    if (lnum < win->w_lines[i].wl_lnum)
		return -1;
	    if (lnum <= win->w_lines[i].wl_lastlnum)
		return i;
	}
    return -1;
}

/* foldAdjustVisual() {{{2 */
/*
 * Adjust the Visual area to include any fold at the start or end completely.
 */
    void
foldAdjustVisual(void)
{
    pos_T	*start, *end;
    char_u	*ptr;

    if (!VIsual_active || !hasAnyFolding(curwin))
	return;

    if (LTOREQ_POS(VIsual, curwin->w_cursor))
    {
	start = &VIsual;
	end = &curwin->w_cursor;
    }
    else
    {
	start = &curwin->w_cursor;
	end = &VIsual;
    }
    if (hasFolding(start->lnum, &start->lnum, NULL))
	start->col = 0;
    if (hasFolding(end->lnum, NULL, &end->lnum))
    {
	ptr = ml_get(end->lnum);
	end->col = (colnr_T)STRLEN(ptr);
	if (end->col > 0 && *p_sel == 'o')
	    --end->col;
#ifdef FEAT_MBYTE
	/* prevent cursor from moving on the trail byte */
	if (has_mbyte)
	    mb_adjust_cursor();
#endif
    }
}

/* cursor_foldstart() {{{2 */
/*
 * Move the cursor to the first line of a closed fold.
 */
    void
foldAdjustCursor(void)
{
    (void)hasFolding(curwin->w_cursor.lnum, &curwin->w_cursor.lnum, NULL);
}

/* Internal functions for "fold_T" {{{1 */
/* cloneFoldGrowArray() {{{2 */
/*
 * Will "clone" (i.e deep copy) a garray_T of folds.
 *
 * Return FAIL if the operation cannot be completed, otherwise OK.
 */
    void
cloneFoldGrowArray(garray_T *from, garray_T *to)
{
    int		i;
    fold_T	*from_p;
    fold_T	*to_p;

    ga_init2(to, from->ga_itemsize, from->ga_growsize);
    if (from->ga_len == 0 || ga_grow(to, from->ga_len) == FAIL)
	return;

    from_p = (fold_T *)from->ga_data;
    to_p = (fold_T *)to->ga_data;

    for (i = 0; i < from->ga_len; i++)
    {
	to_p->fd_top = from_p->fd_top;
	to_p->fd_len = from_p->fd_len;
	to_p->fd_flags = from_p->fd_flags;
	to_p->fd_small = from_p->fd_small;
	cloneFoldGrowArray(&from_p->fd_nested, &to_p->fd_nested);
	++to->ga_len;
	++from_p;
	++to_p;
    }
}

/* foldFind() {{{2 */
/*
 * Search for line "lnum" in folds of growarray "gap".
 * Set *fpp to the fold struct for the fold that contains "lnum" or
 * the first fold below it (careful: it can be beyond the end of the array!).
 * Returns FALSE when there is no fold that contains "lnum".
 */
    static int
foldFind(garray_T *gap, linenr_T lnum, fold_T **fpp)
{
    linenr_T	low, high;
    fold_T	*fp;
    int		i;

    /*
     * Perform a binary search.
     * "low" is lowest index of possible match.
     * "high" is highest index of possible match.
     */
    fp = (fold_T *)gap->ga_data;
    low = 0;
    high = gap->ga_len - 1;
    while (low <= high)
    {
	i = (low + high) / 2;
	if (fp[i].fd_top > lnum)
	    /* fold below lnum, adjust high */
	    high = i - 1;
	else if (fp[i].fd_top + fp[i].fd_len <= lnum)
	    /* fold above lnum, adjust low */
	    low = i + 1;
	else
	{
	    /* lnum is inside this fold */
	    *fpp = fp + i;
	    return TRUE;
	}
    }
    *fpp = fp + low;
    return FALSE;
}

/* foldLevelWin() {{{2 */
/*
 * Return fold level at line number "lnum" in window "wp".
 */
    static int
foldLevelWin(win_T *wp, linenr_T lnum)
{
    fold_T	*fp;
    linenr_T	lnum_rel = lnum;
    int		level =  0;
    garray_T	*gap;

    /* Recursively search for a fold that contains "lnum". */
    gap = &wp->w_folds;
    for (;;)
    {
	if (!foldFind(gap, lnum_rel, &fp))
	    break;
	/* Check nested folds.  Line number is relative to containing fold. */
	gap = &fp->fd_nested;
	lnum_rel -= fp->fd_top;
	++level;
    }

    return level;
}

/* checkupdate() {{{2 */
/*
 * Check if the folds in window "wp" are invalid and update them if needed.
 */
    static void
checkupdate(win_T *wp)
{
    if (wp->w_foldinvalid)
    {
	foldUpdate(wp, (linenr_T)1, (linenr_T)MAXLNUM); /* will update all */
	wp->w_foldinvalid = FALSE;
    }
}

/* setFoldRepeat() {{{2 */
/*
 * Open or close fold for current window at line "lnum".
 * Repeat "count" times.
 */
    static void
setFoldRepeat(linenr_T lnum, long count, int do_open)
{
    int		done;
    long	n;

    for (n = 0; n < count; ++n)
    {
	done = DONE_NOTHING;
	(void)setManualFold(lnum, do_open, FALSE, &done);
	if (!(done & DONE_ACTION))
	{
	    /* Only give an error message when no fold could be opened. */
	    if (n == 0 && !(done & DONE_FOLD))
		EMSG(_(e_nofold));
	    break;
	}
    }
}

/* setManualFold() {{{2 */
/*
 * Open or close the fold in the current window which contains "lnum".
 * Also does this for other windows in diff mode when needed.
 */
    static linenr_T
setManualFold(
    linenr_T	lnum,
    int		opening,    /* TRUE when opening, FALSE when closing */
    int		recurse,    /* TRUE when closing/opening recursive */
    int		*donep)
{
#ifdef FEAT_DIFF
    if (foldmethodIsDiff(curwin) && curwin->w_p_scb)
    {
	win_T	    *wp;
	linenr_T    dlnum;

	/*
	 * Do the same operation in other windows in diff mode.  Calculate the
	 * line number from the diffs.
	 */
	FOR_ALL_WINDOWS(wp)
	{
	    if (wp != curwin && foldmethodIsDiff(wp) && wp->w_p_scb)
	    {
		dlnum = diff_lnum_win(curwin->w_cursor.lnum, wp);
		if (dlnum != 0)
		    (void)setManualFoldWin(wp, dlnum, opening, recurse, NULL);
	    }
	}
    }
#endif

    return setManualFoldWin(curwin, lnum, opening, recurse, donep);
}

/* setManualFoldWin() {{{2 */
/*
 * Open or close the fold in window "wp" which contains "lnum".
 * "donep", when not NULL, points to flag that is set to DONE_FOLD when some
 * fold was found and to DONE_ACTION when some fold was opened or closed.
 * When "donep" is NULL give an error message when no fold was found for
 * "lnum", but only if "wp" is "curwin".
 * Return the line number of the next line that could be closed.
 * It's only valid when "opening" is TRUE!
 */
    static linenr_T
setManualFoldWin(
    win_T	*wp,
    linenr_T	lnum,
    int		opening,    /* TRUE when opening, FALSE when closing */
    int		recurse,    /* TRUE when closing/opening recursive */
    int		*donep)
{
    fold_T	*fp;
    fold_T	*fp2;
    fold_T	*found = NULL;
    int		j;
    int		level = 0;
    int		use_level = FALSE;
    int		found_fold = FALSE;
    garray_T	*gap;
    linenr_T	next = MAXLNUM;
    linenr_T	off = 0;
    int		done = 0;

    checkupdate(wp);

    /*
     * Find the fold, open or close it.
     */
    gap = &wp->w_folds;
    for (;;)
    {
	if (!foldFind(gap, lnum, &fp))
	{
	    /* If there is a following fold, continue there next time. */
	    if (fp < (fold_T *)gap->ga_data + gap->ga_len)
		next = fp->fd_top + off;
	    break;
	}

	/* lnum is inside this fold */
	found_fold = TRUE;

	/* If there is a following fold, continue there next time. */
	if (fp + 1 < (fold_T *)gap->ga_data + gap->ga_len)
	    next = fp[1].fd_top + off;

	/* Change from level-dependent folding to manual. */
	if (use_level || fp->fd_flags == FD_LEVEL)
	{
	    use_level = TRUE;
	    if (level >= wp->w_p_fdl)
		fp->fd_flags = FD_CLOSED;
	    else
		fp->fd_flags = FD_OPEN;
	    fp2 = (fold_T *)fp->fd_nested.ga_data;
	    for (j = 0; j < fp->fd_nested.ga_len; ++j)
		fp2[j].fd_flags = FD_LEVEL;
	}

	/* Simple case: Close recursively means closing the fold. */
	if (!opening && recurse)
	{
	    if (fp->fd_flags != FD_CLOSED)
	    {
		done |= DONE_ACTION;
		fp->fd_flags = FD_CLOSED;
	    }
	}
	else if (fp->fd_flags == FD_CLOSED)
	{
	    /* When opening, open topmost closed fold. */
	    if (opening)
	    {
		fp->fd_flags = FD_OPEN;
		done |= DONE_ACTION;
		if (recurse)
		    foldOpenNested(fp);
	    }
	    break;
	}

	/* fold is open, check nested folds */
	found = fp;
	gap = &fp->fd_nested;
	lnum -= fp->fd_top;
	off += fp->fd_top;
	++level;
    }
    if (found_fold)
    {
	/* When closing and not recurse, close deepest open fold. */
	if (!opening && found != NULL)
	{
	    found->fd_flags = FD_CLOSED;
	    done |= DONE_ACTION;
	}
	wp->w_fold_manual = TRUE;
	if (done & DONE_ACTION)
	    changed_window_setting_win(wp);
	done |= DONE_FOLD;
    }
    else if (donep == NULL && wp == curwin)
	EMSG(_(e_nofold));

    if (donep != NULL)
	*donep |= done;

    return next;
}

/* foldOpenNested() {{{2 */
/*
 * Open all nested folds in fold "fpr" recursively.
 */
    static void
foldOpenNested(fold_T *fpr)
{
    int		i;
    fold_T	*fp;

    fp = (fold_T *)fpr->fd_nested.ga_data;
    for (i = 0; i < fpr->fd_nested.ga_len; ++i)
    {
	foldOpenNested(&fp[i]);
	fp[i].fd_flags = FD_OPEN;
    }
}

/* deleteFoldEntry() {{{2 */
/*
 * Delete fold "idx" from growarray "gap".
 * When "recursive" is TRUE also delete all the folds contained in it.
 * When "recursive" is FALSE contained folds are moved one level up.
 */
    static void
deleteFoldEntry(garray_T *gap, int idx, int recursive)
{
    fold_T	*fp;
    int		i;
    long	moved;
    fold_T	*nfp;

    fp = (fold_T *)gap->ga_data + idx;
    if (recursive || fp->fd_nested.ga_len == 0)
    {
	/* recursively delete the contained folds */
	deleteFoldRecurse(&fp->fd_nested);
	--gap->ga_len;
	if (idx < gap->ga_len)
	    mch_memmove(fp, fp + 1, sizeof(fold_T) * (gap->ga_len - idx));
    }
    else
    {
	/* Move nested folds one level up, to overwrite the fold that is
	 * deleted. */
	moved = fp->fd_nested.ga_len;
	if (ga_grow(gap, (int)(moved - 1)) == OK)
	{
	    /* Get "fp" again, the array may have been reallocated. */
	    fp = (fold_T *)gap->ga_data + idx;

	    /* adjust fd_top and fd_flags for the moved folds */
	    nfp = (fold_T *)fp->fd_nested.ga_data;
	    for (i = 0; i < moved; ++i)
	    {
		nfp[i].fd_top += fp->fd_top;
		if (fp->fd_flags == FD_LEVEL)
		    nfp[i].fd_flags = FD_LEVEL;
		if (fp->fd_small == MAYBE)
		    nfp[i].fd_small = MAYBE;
	    }

	    /* move the existing folds down to make room */
	    if (idx + 1 < gap->ga_len)
		mch_memmove(fp + moved, fp + 1,
				  sizeof(fold_T) * (gap->ga_len - (idx + 1)));
	    /* move the contained folds one level up */
	    mch_memmove(fp, nfp, (size_t)(sizeof(fold_T) * moved));
	    vim_free(nfp);
	    gap->ga_len += moved - 1;
	}
    }
}

/* deleteFoldRecurse() {{{2 */
/*
 * Delete nested folds in a fold.
 */
    void
deleteFoldRecurse(garray_T *gap)
{
    int		i;

    for (i = 0; i < gap->ga_len; ++i)
	deleteFoldRecurse(&(((fold_T *)(gap->ga_data))[i].fd_nested));
    ga_clear(gap);
}

/* foldMarkAdjust() {{{2 */
/*
 * Update line numbers of folds for inserted/deleted lines.
 */
    void
foldMarkAdjust(
    win_T	*wp,
    linenr_T	line1,
    linenr_T	line2,
    long	amount,
    long	amount_after)
{
    /* If deleting marks from line1 to line2, but not deleting all those
     * lines, set line2 so that only deleted lines have their folds removed. */
    if (amount == MAXLNUM && line2 >= line1 && line2 - line1 >= -amount_after)
	line2 = line1 - amount_after - 1;
    /* If appending a line in Insert mode, it should be included in the fold
     * just above the line. */
    if ((State & INSERT) && amount == (linenr_T)1 && line2 == MAXLNUM)
	--line1;
    foldMarkAdjustRecurse(&wp->w_folds, line1, line2, amount, amount_after);
}

/* foldMarkAdjustRecurse() {{{2 */
    static void
foldMarkAdjustRecurse(
    garray_T	*gap,
    linenr_T	line1,
    linenr_T	line2,
    long	amount,
    long	amount_after)
{
    fold_T	*fp;
    int		i;
    linenr_T	last;
    linenr_T	top;

    /* In Insert mode an inserted line at the top of a fold is considered part
     * of the fold, otherwise it isn't. */
    if ((State & INSERT) && amount == (linenr_T)1 && line2 == MAXLNUM)
	top = line1 + 1;
    else
	top = line1;

    /* Find the fold containing or just below "line1". */
    (void)foldFind(gap, line1, &fp);

    /*
     * Adjust all folds below "line1" that are affected.
     */
    for (i = (int)(fp - (fold_T *)gap->ga_data); i < gap->ga_len; ++i, ++fp)
    {
	/*
	 * Check for these situations:
	 *	  1  2	3
	 *	  1  2	3
	 * line1     2	3  4  5
	 *	     2	3  4  5
	 *	     2	3  4  5
	 * line2     2	3  4  5
	 *		3     5  6
	 *		3     5  6
	 */

	last = fp->fd_top + fp->fd_len - 1; /* last line of fold */

	/* 1. fold completely above line1: nothing to do */
	if (last < line1)
	    continue;

	/* 6. fold below line2: only adjust for amount_after */
	if (fp->fd_top > line2)
	{
	    if (amount_after == 0)
		break;
	    fp->fd_top += amount_after;
	}
	else
	{
	    if (fp->fd_top >= top && last <= line2)
	    {
		/* 4. fold completely contained in range */
		if (amount == MAXLNUM)
		{
		    /* Deleting lines: delete the fold completely */
		    deleteFoldEntry(gap, i, TRUE);
		    --i;    /* adjust index for deletion */
		    --fp;
		}
		else
		    fp->fd_top += amount;
	    }
	    else
	    {
		if (fp->fd_top < top)
		{
		    /* 2 or 3: need to correct nested folds too */
		    foldMarkAdjustRecurse(&fp->fd_nested, line1 - fp->fd_top,
				  line2 - fp->fd_top, amount, amount_after);
		    if (last <= line2)
		    {
			/* 2. fold contains line1, line2 is below fold */
			if (amount == MAXLNUM)
			    fp->fd_len = line1 - fp->fd_top;
			else
			    fp->fd_len += amount;
		    }
		    else
		    {
			/* 3. fold contains line1 and line2 */
			fp->fd_len += amount_after;
		    }
		}
		else
		{
		    /* 5. fold is below line1 and contains line2; need to
		     * correct nested folds too */
		    if (amount == MAXLNUM)
		    {
			foldMarkAdjustRecurse(&fp->fd_nested,
				  line1 - fp->fd_top,
				  line2 - fp->fd_top,
				  amount,
				  amount_after + (fp->fd_top - top));
			fp->fd_len -= line2 - fp->fd_top + 1;
			fp->fd_top = line1;
		    }
		    else
		    {
			foldMarkAdjustRecurse(&fp->fd_nested,
				  line1 - fp->fd_top,
				  line2 - fp->fd_top,
				  amount,
				  amount_after - amount);
			fp->fd_len += amount_after - amount;
			fp->fd_top += amount;
		    }
		}
	    }
	}
    }
}

/* getDeepestNesting() {{{2 */
/*
 * Get the lowest 'foldlevel' value that makes the deepest nested fold in the
 * current window open.
 */
    int
getDeepestNesting(void)
{
    checkupdate(curwin);
    return getDeepestNestingRecurse(&curwin->w_folds);
}

    static int
getDeepestNestingRecurse(garray_T *gap)
{
    int		i;
    int		level;
    int		maxlevel = 0;
    fold_T	*fp;

    fp = (fold_T *)gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i)
    {
	level = getDeepestNestingRecurse(&fp[i].fd_nested) + 1;
	if (level > maxlevel)
	    maxlevel = level;
    }

    return maxlevel;
}

/* check_closed() {{{2 */
/*
 * Check if a fold is closed and update the info needed to check nested folds.
 */
    static int
check_closed(
    win_T	*win,
    fold_T	*fp,
    int		*use_levelp,	    /* TRUE: outer fold had FD_LEVEL */
    int		level,		    /* folding depth */
    int		*maybe_smallp,	    /* TRUE: outer this had fd_small == MAYBE */
    linenr_T	lnum_off)	    /* line number offset for fp->fd_top */
{
    int		closed = FALSE;

    /* Check if this fold is closed.  If the flag is FD_LEVEL this
     * fold and all folds it contains depend on 'foldlevel'. */
    if (*use_levelp || fp->fd_flags == FD_LEVEL)
    {
	*use_levelp = TRUE;
	if (level >= win->w_p_fdl)
	    closed = TRUE;
    }
    else if (fp->fd_flags == FD_CLOSED)
	closed = TRUE;

    /* Small fold isn't closed anyway. */
    if (fp->fd_small == MAYBE)
	*maybe_smallp = TRUE;
    if (closed)
    {
	if (*maybe_smallp)
	    fp->fd_small = MAYBE;
	checkSmall(win, fp, lnum_off);
	if (fp->fd_small == TRUE)
	    closed = FALSE;
    }
    return closed;
}

/* checkSmall() {{{2 */
/*
 * Update fd_small field of fold "fp".
 */
    static void
checkSmall(
    win_T	*wp,
    fold_T	*fp,
    linenr_T	lnum_off)	/* offset for fp->fd_top */
{
    int		count;
    int		n;

    if (fp->fd_small == MAYBE)
    {
	/* Mark any nested folds to maybe-small */
	setSmallMaybe(&fp->fd_nested);

	if (fp->fd_len > curwin->w_p_fml)
	    fp->fd_small = FALSE;
	else
	{
	    count = 0;
	    for (n = 0; n < fp->fd_len; ++n)
	    {
		count += plines_win_nofold(wp, fp->fd_top + lnum_off + n);
		if (count > curwin->w_p_fml)
		{
		    fp->fd_small = FALSE;
		    return;
		}
	    }
	    fp->fd_small = TRUE;
	}
    }
}

/* setSmallMaybe() {{{2 */
/*
 * Set small flags in "gap" to MAYBE.
 */
    static void
setSmallMaybe(garray_T *gap)
{
    int		i;
    fold_T	*fp;

    fp = (fold_T *)gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i)
	fp[i].fd_small = MAYBE;
}

/* foldCreateMarkers() {{{2 */
/*
 * Create a fold from line "start" to line "end" (inclusive) in the current
 * window by adding markers.
 */
    static void
foldCreateMarkers(linenr_T start, linenr_T end)
{
    if (!curbuf->b_p_ma)
    {
	EMSG(_(e_modifiable));
	return;
    }
    parseMarker(curwin);

    foldAddMarker(start, curwin->w_p_fmr, foldstartmarkerlen);
    foldAddMarker(end, foldendmarker, foldendmarkerlen);

    /* Update both changes here, to avoid all folds after the start are
     * changed when the start marker is inserted and the end isn't. */
    changed_lines(start, (colnr_T)0, end, 0L);
}

/* foldAddMarker() {{{2 */
/*
 * Add "marker[markerlen]" in 'commentstring' to line "lnum".
 */
    static void
foldAddMarker(linenr_T lnum, char_u *marker, int markerlen)
{
    char_u	*cms = curbuf->b_p_cms;
    char_u	*line;
    int		line_len;
    char_u	*newline;
    char_u	*p = (char_u *)strstr((char *)curbuf->b_p_cms, "%s");
    int		line_is_comment = FALSE;

    /* Allocate a new line: old-line + 'cms'-start + marker + 'cms'-end */
    line = ml_get(lnum);
    line_len = (int)STRLEN(line);

    if (u_save(lnum - 1, lnum + 1) == OK)
    {
#if defined(FEAT_COMMENTS)
	/* Check if the line ends with an unclosed comment */
	(void)skip_comment(line, FALSE, FALSE, &line_is_comment);
#endif
	newline = alloc((unsigned)(line_len + markerlen + STRLEN(cms) + 1));
	if (newline == NULL)
	    return;
	STRCPY(newline, line);
	/* Append the marker to the end of the line */
	if (p == NULL || line_is_comment)
	    vim_strncpy(newline + line_len, marker, markerlen);
	else
	{
	    STRCPY(newline + line_len, cms);
	    STRNCPY(newline + line_len + (p - cms), marker, markerlen);
	    STRCPY(newline + line_len + (p - cms) + markerlen, p + 2);
	}

	ml_replace(lnum, newline, FALSE);
    }
}

/* deleteFoldMarkers() {{{2 */
/*
 * Delete the markers for a fold, causing it to be deleted.
 */
    static void
deleteFoldMarkers(
    fold_T	*fp,
    int		recursive,
    linenr_T	lnum_off)	/* offset for fp->fd_top */
{
    int		i;

    if (recursive)
	for (i = 0; i < fp->fd_nested.ga_len; ++i)
	    deleteFoldMarkers((fold_T *)fp->fd_nested.ga_data + i, TRUE,
						       lnum_off + fp->fd_top);
    foldDelMarker(fp->fd_top + lnum_off, curwin->w_p_fmr, foldstartmarkerlen);
    foldDelMarker(fp->fd_top + lnum_off + fp->fd_len - 1,
					     foldendmarker, foldendmarkerlen);
}

/* foldDelMarker() {{{2 */
/*
 * Delete marker "marker[markerlen]" at the end of line "lnum".
 * Delete 'commentstring' if it matches.
 * If the marker is not found, there is no error message.  Could a missing
 * close-marker.
 */
    static void
foldDelMarker(linenr_T lnum, char_u *marker, int markerlen)
{
    char_u	*line;
    char_u	*newline;
    char_u	*p;
    int		len;
    char_u	*cms = curbuf->b_p_cms;
    char_u	*cms2;

    line = ml_get(lnum);
    for (p = line; *p != NUL; ++p)
	if (STRNCMP(p, marker, markerlen) == 0)
	{
	    /* Found the marker, include a digit if it's there. */
	    len = markerlen;
	    if (VIM_ISDIGIT(p[len]))
		++len;
	    if (*cms != NUL)
	    {
		/* Also delete 'commentstring' if it matches. */
		cms2 = (char_u *)strstr((char *)cms, "%s");
		if (p - line >= cms2 - cms
			&& STRNCMP(p - (cms2 - cms), cms, cms2 - cms) == 0
			&& STRNCMP(p + len, cms2 + 2, STRLEN(cms2 + 2)) == 0)
		{
		    p -= cms2 - cms;
		    len += (int)STRLEN(cms) - 2;
		}
	    }
	    if (u_save(lnum - 1, lnum + 1) == OK)
	    {
		/* Make new line: text-before-marker + text-after-marker */
		newline = alloc((unsigned)(STRLEN(line) - len + 1));
		if (newline != NULL)
		{
		    STRNCPY(newline, line, p - line);
		    STRCPY(newline + (p - line), p + len);
		    ml_replace(lnum, newline, FALSE);
		}
	    }
	    break;
	}
}

/* get_foldtext() {{{2 */
/*
 * Return the text for a closed fold at line "lnum", with last line "lnume".
 * When 'foldtext' isn't set puts the result in "buf[FOLD_TEXT_LEN]".
 * Otherwise the result is in allocated memory.
 */
    



    
























    



    



    



    



    


    




    





    






    



    




    




    



    



    



    









    



    



    



    
 /* FEAT_SESSION */

/* }}}1 */
#endif /* defined(FEAT_FOLDING) || defined(PROTO) */
