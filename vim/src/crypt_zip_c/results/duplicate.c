********************************************************************************
ACFD
********************************************************************************
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

#define CRC32(c, b) (crc_32_table[((int)(c) ^ (b)) & 0xff] ^ ((c) >> 8))

#ifndef CRC32 // < ACFD
#define UPDATE_KEYS_ZIP(keys, c) { \
    keys[0] = CRC32(keys[0], (c)); \
    keys[1] += keys[0] & 0xff; \
    keys[1] = keys[1] * 134775813L + 1; \
    keys[2] = CRC32(keys[2], (int)(keys[1] >> 24)); \
}
#endif

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

********************************************************************************
RCFD
********************************************************************************
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

#define CRC32(c, b) (crc_32_table[((int)(c) ^ (b)) & 0xff] ^ ((c) >> 8))

void crypt_zip_decode(cryptstate_T *state, char_u *from, size_t	len, char_u *to) {
  zip_state_T *zs = state->method_state;fgra
  size_t	i;
  short_u	temp;

  for (i = 0; i < len; ++i) {
    temp = (short_u)zs->keys[2] | 2;
    temp = (int)(((unsigned)(temp * (temp ^ 1U)) >> 8) & 0xff);
    UPDATE_KEYS_ZIP(zs->keys, to[i] = from[i] ^ temp);
  }
}

#endif

********************************************************************************
********************************************************************************
********************************************************************************
[]
[VIM_SIZEOF_INT, CRC32]
[VIM_SIZEOF_INT]
[CRC32]

********************************************************************************
********************************************************************************
[FEAT_CRYPT]
[PROTO]
[FEAT_CRYPT, PROTO]

********************************************************************************
ACFD
********************************************************************************
typedef unsigned long u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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

********************************************************************************
RCFD
********************************************************************************
typedef unsigned long u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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

********************************************************************************
********************************************************************************
[FEAT_CRYPT, VIM_SIZEOF_INT >= 4]
[PROTO, VIM_SIZEOF_INT >= 4]
[FEAT_CRYPT, PROTO, VIM_SIZEOF_INT >= 4]

********************************************************************************
ACFD
********************************************************************************
typedef unsigned int u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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

********************************************************************************
RCFD
********************************************************************************
typedef unsigned int u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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

********************************************************************************
********************************************************************************
[FEAT_CRYPT, CRC32]
[PROTO, CRC32]
[FEAT_CRYPT, PROTO, CRC32]
********************************************************************************
ACFD
********************************************************************************
typedef unsigned long u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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

********************************************************************************
RCFD
********************************************************************************
typedef unsigned long u32_T;

typedef struct {
    u32_T keys[3];
} zip_state_T;

static u32_T crc_32_table[256];

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
********************************************************************************
********************************************************************************
[FEAT_CRYPT, VIM_SIZEOF_INT, CRC32]
[PROTO, VIM_SIZEOF_INT, CRC32]
[FEAT_CRYPT, PROTO, VIM_SIZEOF_INT, CRC32]
********************************************************************************
