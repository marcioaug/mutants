#include "vim.h"

#if defined(FEAT_CRYPT) || defined(PROTO)

# if VIM_SIZEOF_INT >= 4
typedef unsigned int u32_T;
# else
typedef unsigned long u32_T;
# endif

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

#ifndef UPDATE_KEYS_ZIP 
#define CRC32(c, b) (crc_32_table[((int)(c) ^ (b)) & 0xff] ^ ((c) >> 8))
#endif

#define UPDATE_KEYS_ZIP(keys, c) { \
    keys[0] = CRC32(keys[0], (c)); \
    keys[1] += keys[0] & 0xff; \
    keys[1] = keys[1] * 134775813L + 1; \
    keys[2] = CRC32(keys[2], (int)(keys[1] >> 24)); \
}

void crypt_zip_decode(cryptstate_T *state, char_u *from, size_t	len, char_u *to) {
  zip_state_T *zs = state->method_state;
  size_t	i;
  short_u	temp;

  for (i = 0; i < len; ++i) {
    temp = (short_u)zs->keys[2] | 2;
    temp = (int)(((unsigned)(temp * (temp ^ 1U)) >> 8) & 0xff);
    UPDATE_KEYS_ZIP(zs->keys, to[i] = from[i] ^ temp);
  }
}

#endif
