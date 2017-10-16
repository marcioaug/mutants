#if defined(A) || defined(B)

#define X 10
#ifdef X
int func() {
   return X;
}
#endif
#endif
