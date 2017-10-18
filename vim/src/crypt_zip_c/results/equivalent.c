//15
#if defined(FEAT_CRYPT) || defined(PROTO

//77..82
#define UPDATE_KEYS_ZIP(keys, c) { \
    keys[0] = CRC32(keys[0], (c)); \
    keys[1] += keys[0] & 0xff; \
    keys[1] = keys[1] * 134775813L + 1; \
    keys[2] = CRC32(keys[2], (int)(keys[1] >> 24)); \
}

//139..151
void crypt_zip_decode(cryptstate_T *state, char_u	*from, size_t	len, char_u	*to) {
  zip_state_T *zs = state->method_state;
  size_t	i;
  short_u	temp;

  for (i = 0; i < len; ++i) {
    temp = (short_u)zs->keys[2] | 2;
    temp = (int)(((unsigned)(temp * (temp ^ 1U)) >> 8) & 0xff);
    UPDATE_KEYS_ZIP(zs->keys, to[i] = from[i] ^ temp);
  }
}

//158
#endif

********************************************************************************
AICC_23
********************************************************************************

//77..82
#define UPDATE_KEYS_ZIP(keys, c) { \
    keys[0] = CRC32(keys[0], (c)); \
    keys[1] += keys[0] & 0xff; \
    keys[1] = keys[1] * 134775813L + 1; \
    keys[2] = CRC32(keys[2], (int)(keys[1] >> 24)); \
}

//139..151
#ifdef UPDATE_KEYS_ZIP
void crypt_zip_decode(cryptstate_T *state, char_u	*from, size_t	len, char_u	*to) {
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
