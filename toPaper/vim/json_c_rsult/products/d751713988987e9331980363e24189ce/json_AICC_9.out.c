
typedef long unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
struct _IO_FILE;

typedef struct _IO_FILE FILE;


typedef struct _IO_FILE __FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));

extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));

extern FILE *tmpfile (void) __attribute__ ((__warn_unused_result__));
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__));

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);

extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) __attribute__ ((__warn_unused_result__));
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));

extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));

extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__warn_unused_result__));
extern int scanf (const char *__restrict __format, ...) __attribute__ ((__warn_unused_result__));
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") __attribute__ ((__warn_unused_result__));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") __attribute__ ((__warn_unused_result__));
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));


extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__warn_unused_result__));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __attribute__ ((__warn_unused_result__));
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__warn_unused_result__));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) __attribute__ ((__warn_unused_result__));
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__warn_unused_result__));
extern char *gets (char *__s) __attribute__ ((__warn_unused_result__)) __attribute__ ((__deprecated__));

extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));

extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) __attribute__ ((__warn_unused_result__));
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) __attribute__ ((__warn_unused_result__));

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void perror (const char *__s);

extern int sys_nerr;
extern const char *const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern FILE *popen (const char *__command, const char *__modes) __attribute__ ((__warn_unused_result__));
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) int
getchar (void)
{
  return _IO_getc (stdin);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar (int __c)
{
  return _IO_putc (__c, stdout);
}
extern __inline __attribute__ ((__gnu_inline__)) int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x10) != 0);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x20) != 0);
}
extern int __sprintf_chk (char *__restrict __s, int __flag, size_t __slen,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int __vsprintf_chk (char *__restrict __s, int __flag, size_t __slen,
      const char *__restrict __format,
      __gnuc_va_list __ap) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) sprintf (char *__restrict __s, const char *__restrict __fmt, ...)
{
  return __builtin___sprintf_chk (__s, 2 - 1,
      __builtin_object_size (__s, 2 > 1), __fmt, __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) vsprintf (char *__restrict __s, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __builtin___vsprintf_chk (__s, 2 - 1,
       __builtin_object_size (__s, 2 > 1), __fmt, __ap);
}
extern int __snprintf_chk (char *__restrict __s, size_t __n, int __flag,
      size_t __slen, const char *__restrict __format,
      ...) __attribute__ ((__nothrow__ , __leaf__));
extern int __vsnprintf_chk (char *__restrict __s, size_t __n, int __flag,
       size_t __slen, const char *__restrict __format,
       __gnuc_va_list __ap) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) snprintf (char *__restrict __s, size_t __n, const char *__restrict __fmt, ...)
{
  return __builtin___snprintf_chk (__s, __n, 2 - 1,
       __builtin_object_size (__s, 2 > 1), __fmt, __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) vsnprintf (char *__restrict __s, size_t __n, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __builtin___vsnprintf_chk (__s, __n, 2 - 1,
        __builtin_object_size (__s, 2 > 1), __fmt, __ap);
}
extern int __fprintf_chk (FILE *__restrict __stream, int __flag,
     const char *__restrict __format, ...);
extern int __printf_chk (int __flag, const char *__restrict __format, ...);
extern int __vfprintf_chk (FILE *__restrict __stream, int __flag,
      const char *__restrict __format, __gnuc_va_list __ap);
extern int __vprintf_chk (int __flag, const char *__restrict __format,
     __gnuc_va_list __ap);
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
fprintf (FILE *__restrict __stream, const char *__restrict __fmt, ...)
{
  return __fprintf_chk (__stream, 2 - 1, __fmt,
   __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
printf (const char *__restrict __fmt, ...)
{
  return __printf_chk (2 - 1, __fmt, __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vprintf (const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vfprintf_chk (stdout, 2 - 1, __fmt, __ap);
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vfprintf (FILE *__restrict __stream,
   const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vfprintf_chk (__stream, 2 - 1, __fmt, __ap);
}
extern int __dprintf_chk (int __fd, int __flag, const char *__restrict __fmt,
     ...) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int __vdprintf_chk (int __fd, int __flag,
      const char *__restrict __fmt, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 3, 0)));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
dprintf (int __fd, const char *__restrict __fmt, ...)
{
  return __dprintf_chk (__fd, 2 - 1, __fmt,
   __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vdprintf (int __fd, const char *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vdprintf_chk (__fd, 2 - 1, __fmt, __ap);
}
extern char *__gets_chk (char *__str, size_t) __attribute__ ((__warn_unused_result__));
extern char *__gets_warn (char *__str) __asm__ ("" "gets")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("please use fgets or getline instead, gets can't " "specify buffer size")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
gets (char *__str)
{
  if (__builtin_object_size (__str, 2 > 1) != (size_t) -1)
    return __gets_chk (__str, __builtin_object_size (__str, 2 > 1));
  return __gets_warn (__str);
}
extern char *__fgets_chk (char *__restrict __s, size_t __size, int __n,
     FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern char *__fgets_alias (char *__restrict __s, int __n, FILE *__restrict __stream) __asm__ ("" "fgets") __attribute__ ((__warn_unused_result__));
extern char *__fgets_chk_warn (char *__restrict __s, size_t __size, int __n, FILE *__restrict __stream) __asm__ ("" "__fgets_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fgets called with bigger size than length " "of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n) || __n <= 0)
 return __fgets_chk (__s, __builtin_object_size (__s, 2 > 1), __n, __stream);
      if ((size_t) __n > __builtin_object_size (__s, 2 > 1))
 return __fgets_chk_warn (__s, __builtin_object_size (__s, 2 > 1), __n, __stream);
    }
  return __fgets_alias (__s, __n, __stream);
}
extern size_t __fread_chk (void *__restrict __ptr, size_t __ptrlen,
      size_t __size, size_t __n,
      FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t __fread_alias (void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "fread") __attribute__ ((__warn_unused_result__));
extern size_t __fread_chk_warn (void *__restrict __ptr, size_t __ptrlen, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "__fread_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fread called with bigger size * nmemb than length " "of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) size_t
fread (void *__restrict __ptr, size_t __size, size_t __n,
       FILE *__restrict __stream)
{
  if (__builtin_object_size (__ptr, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__size)
   || !__builtin_constant_p (__n)
   || (__size | __n) >= (((size_t) 1) << (8 * sizeof (size_t) / 2)))
 return __fread_chk (__ptr, __builtin_object_size (__ptr, 0), __size, __n, __stream);
      if (__size * __n > __builtin_object_size (__ptr, 0))
 return __fread_chk_warn (__ptr, __builtin_object_size (__ptr, 0), __size, __n, __stream);
    }
  return __fread_alias (__ptr, __size, __n, __stream);
}
extern size_t __fread_unlocked_chk (void *__restrict __ptr, size_t __ptrlen,
        size_t __size, size_t __n,
        FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern size_t __fread_unlocked_alias (void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "fread_unlocked") __attribute__ ((__warn_unused_result__));
extern size_t __fread_unlocked_chk_warn (void *__restrict __ptr, size_t __ptrlen, size_t __size, size_t __n, FILE *__restrict __stream) __asm__ ("" "__fread_unlocked_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fread_unlocked called with bigger size * nmemb than " "length of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) size_t
fread_unlocked (void *__restrict __ptr, size_t __size, size_t __n,
  FILE *__restrict __stream)
{
  if (__builtin_object_size (__ptr, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__size)
   || !__builtin_constant_p (__n)
   || (__size | __n) >= (((size_t) 1) << (8 * sizeof (size_t) / 2)))
 return __fread_unlocked_chk (__ptr, __builtin_object_size (__ptr, 0), __size, __n,
         __stream);
      if (__size * __n > __builtin_object_size (__ptr, 0))
 return __fread_unlocked_chk_warn (__ptr, __builtin_object_size (__ptr, 0), __size, __n,
       __stream);
    }
  if (__builtin_constant_p (__size)
      && __builtin_constant_p (__n)
      && (__size | __n) < (((size_t) 1) << (8 * sizeof (size_t) / 2))
      && __size * __n <= 8)
    {
      size_t __cnt = __size * __n;
      char *__cptr = (char *) __ptr;
      if (__cnt == 0)
 return 0;
      for (; __cnt > 0; --__cnt)
 {
   int __c = (__builtin_expect (((__stream)->_IO_read_ptr >= (__stream)->_IO_read_end), 0) ? __uflow (__stream) : *(unsigned char *) (__stream)->_IO_read_ptr++);
   if (__c == (-1))
     break;
   *__cptr++ = __c;
 }
      return (__cptr - (char *) __ptr) / __size;
    }
  return __fread_unlocked_alias (__ptr, __size, __n, __stream);
}


static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));

extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) tolower (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_tolower_loc ())[__c] : __c;
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) toupper (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc ())[__c] : __c;
}
typedef struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;

typedef __clock_t clock_t;



typedef __time_t time_t;


typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
extern long int __fdelt_chk (long int __d);
extern long int __fdelt_warn (long int __d)
  __attribute__((__warning__ ("bit outside of fd_set selected")));


__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern __inline __attribute__ ((__gnu_inline__)) __attribute__ ((__const__)) unsigned int
__attribute__ ((__nothrow__ , __leaf__)) gnu_dev_major (unsigned long long int __dev)
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}
__extension__ extern __inline __attribute__ ((__gnu_inline__)) __attribute__ ((__const__)) unsigned int
__attribute__ ((__nothrow__ , __leaf__)) gnu_dev_minor (unsigned long long int __dev)
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}
__extension__ extern __inline __attribute__ ((__gnu_inline__)) __attribute__ ((__const__)) unsigned long long int
__attribute__ ((__nothrow__ , __leaf__)) gnu_dev_makedev (unsigned int __major, unsigned int __minor)
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short __spins;
    short __elision;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;
    unsigned int __flags;
  } __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;


struct stat
  {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
  };
extern int stat (const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int fstatat (int __fd, const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int lstat (const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int chmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fchmodat (int __fd, const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, const char *__path,
        const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, const struct timespec __times[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int __xstat (int __ver, const char *__filename,
      struct stat *__stat_buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat (int __ver, const char *__filename,
       struct stat *__stat_buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat (int __ver, int __fildes, const char *__filename,
         struct stat *__stat_buf, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern int __xmknod (int __ver, const char *__path, __mode_t __mode,
       __dev_t *__dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int __xmknodat (int __ver, int __fd, const char *__path,
         __mode_t __mode, __dev_t *__dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 5)));
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) stat (const char *__path, struct stat *__statbuf)
{
  return __xstat (1, __path, __statbuf);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) lstat (const char *__path, struct stat *__statbuf)
{
  return __lxstat (1, __path, __statbuf);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) fstat (int __fd, struct stat *__statbuf)
{
  return __fxstat (1, __fd, __statbuf);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) fstatat (int __fd, const char *__filename, struct stat *__statbuf, int __flag)
{
  return __fxstatat (1, __fd, __filename, __statbuf, __flag);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) mknod (const char *__path, __mode_t __mode, __dev_t __dev)
{
  return __xmknod (0, __path, __mode, &__dev);
}
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) mknodat (int __fd, const char *__path, __mode_t __mode, __dev_t __dev)
{
  return __xmknodat (0, __fd, __path, __mode, &__dev);
}

typedef int wchar_t;

typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
union wait
  {
    int w_status;
    struct
      {
 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;
      } __wait_terminated;
    struct
      {
 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;
      } __wait_stopped;
  };
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;


__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;

extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));


__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));


extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) atoi (const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline __attribute__ ((__gnu_inline__)) long int
__attribute__ ((__nothrow__ , __leaf__)) atol (const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}


__extension__ extern __inline __attribute__ ((__gnu_inline__)) long long int
__attribute__ ((__nothrow__ , __leaf__)) atoll (const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}

extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));

extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__));
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__));


extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));

extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__warn_unused_result__));
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));

extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));

extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));

extern int system (const char *__command) __attribute__ ((__warn_unused_result__));

extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
typedef int (*__compar_fn_t) (const void *, const void *);

extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) void *
bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size,
  __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
    {
      __idx = (__l + __u) / 2;
      __p = (void *) (((const char *) __base) + (__idx * __size));
      __comparison = (*__compar) (__key, __p);
      if (__comparison < 0)
 __u = __idx;
      else if (__comparison > 0)
 __l = __idx + 1;
      else
 return (void *) __p;
    }
  return ((void *)0);
}
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));

__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));

extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) __attribute__ ((__warn_unused_result__));

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) __attribute__ ((__warn_unused_result__));
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) __attribute__ ((__warn_unused_result__));
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) __attribute__ ((__warn_unused_result__));
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));

extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) __attribute__ ((__warn_unused_result__));
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern __inline __attribute__ ((__gnu_inline__)) double
__attribute__ ((__nothrow__ , __leaf__)) atof (const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}

extern char *__realpath_chk (const char *__restrict __name,
        char *__restrict __resolved,
        size_t __resolvedlen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__realpath_alias (const char *__restrict __name, char *__restrict __resolved) __asm__ ("" "realpath") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__realpath_chk_warn (const char *__restrict __name, char *__restrict __resolved, size_t __resolvedlen) __asm__ ("" "__realpath_chk") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__((__warning__ ("second argument of realpath must be either NULL or at " "least PATH_MAX bytes long buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) realpath (const char *__restrict __name, char *__restrict __resolved)
{
  if (__builtin_object_size (__resolved, 2 > 1) != (size_t) -1)
    {
      return __realpath_chk (__name, __resolved, __builtin_object_size (__resolved, 2 > 1));
    }
  return __realpath_alias (__name, __resolved);
}
extern int __ptsname_r_chk (int __fd, char *__buf, size_t __buflen,
       size_t __nreal) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int __ptsname_r_alias (int __fd, char *__buf, size_t __buflen) __asm__ ("" "ptsname_r") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2)));
extern int __ptsname_r_chk_warn (int __fd, char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__ptsname_r_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2))) __attribute__((__warning__ ("ptsname_r called with buflen bigger than " "size of buf")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) ptsname_r (int __fd, char *__buf, size_t __buflen)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__buflen))
 return __ptsname_r_chk (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1));
      if (__buflen > __builtin_object_size (__buf, 2 > 1))
 return __ptsname_r_chk_warn (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1));
    }
  return __ptsname_r_alias (__fd, __buf, __buflen);
}
extern int __wctomb_chk (char *__s, wchar_t __wchar, size_t __buflen)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int __wctomb_alias (char *__s, wchar_t __wchar) __asm__ ("" "wctomb") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) int
__attribute__ ((__nothrow__ , __leaf__)) wctomb (char *__s, wchar_t __wchar)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1 && 16 > __builtin_object_size (__s, 2 > 1))
    return __wctomb_chk (__s, __wchar, __builtin_object_size (__s, 2 > 1));
  return __wctomb_alias (__s, __wchar);
}
extern size_t __mbstowcs_chk (wchar_t *__restrict __dst,
         const char *__restrict __src,
         size_t __len, size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbstowcs_alias (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len) __asm__ ("" "mbstowcs") __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbstowcs_chk_warn (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len, size_t __dstlen) __asm__ ("" "__mbstowcs_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("mbstowcs called with dst buffer smaller than len " "* sizeof (wchar_t)")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) mbstowcs (wchar_t *__restrict __dst, const char *__restrict __src, size_t __len)
{
  if (__builtin_object_size (__dst, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __mbstowcs_chk (__dst, __src, __len,
          __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t));
      if (__len > __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t))
 return __mbstowcs_chk_warn (__dst, __src, __len,
         __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t));
    }
  return __mbstowcs_alias (__dst, __src, __len);
}
extern size_t __wcstombs_chk (char *__restrict __dst,
         const wchar_t *__restrict __src,
         size_t __len, size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __wcstombs_alias (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len) __asm__ ("" "wcstombs") __attribute__ ((__nothrow__ , __leaf__));
extern size_t __wcstombs_chk_warn (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len, size_t __dstlen) __asm__ ("" "__wcstombs_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wcstombs called with dst buffer smaller than len")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) wcstombs (char *__restrict __dst, const wchar_t *__restrict __src, size_t __len)
{
  if (__builtin_object_size (__dst, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __wcstombs_chk (__dst, __src, __len, __builtin_object_size (__dst, 2 > 1));
      if (__len > __builtin_object_size (__dst, 2 > 1))
 return __wcstombs_chk_warn (__dst, __src, __len, __builtin_object_size (__dst, 2 > 1));
    }
  return __wcstombs_alias (__dst, __src, __len);
}


typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) __attribute__ ((__warn_unused_result__));
extern ssize_t write (int __fd, const void *__buf, size_t __n) __attribute__ ((__warn_unused_result__));
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) __attribute__ ((__warn_unused_result__));
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) __attribute__ ((__warn_unused_result__));
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) __attribute__ ((__warn_unused_result__));
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__warn_unused_result__));
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) __attribute__ ((__warn_unused_result__));
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) __attribute__ ((__warn_unused_result__));
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__));
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__));
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int lockf (int __fd, int __cmd, __off_t __len) __attribute__ ((__warn_unused_result__));
extern int fdatasync (int __fildes);
extern ssize_t __read_chk (int __fd, void *__buf, size_t __nbytes,
      size_t __buflen) __attribute__ ((__warn_unused_result__));
extern ssize_t __read_alias (int __fd, void *__buf, size_t __nbytes) __asm__ ("" "read") __attribute__ ((__warn_unused_result__));
extern ssize_t __read_chk_warn (int __fd, void *__buf, size_t __nbytes, size_t __buflen) __asm__ ("" "__read_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("read called with bigger length than size of " "the destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) ssize_t
read (int __fd, void *__buf, size_t __nbytes)
{
  if (__builtin_object_size (__buf, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__nbytes))
 return __read_chk (__fd, __buf, __nbytes, __builtin_object_size (__buf, 0));
      if (__nbytes > __builtin_object_size (__buf, 0))
 return __read_chk_warn (__fd, __buf, __nbytes, __builtin_object_size (__buf, 0));
    }
  return __read_alias (__fd, __buf, __nbytes);
}
extern ssize_t __readlink_chk (const char *__restrict __path,
          char *__restrict __buf, size_t __len,
          size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern ssize_t __readlink_alias (const char *__restrict __path, char *__restrict __buf, size_t __len) __asm__ ("" "readlink") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__));
extern ssize_t __readlink_chk_warn (const char *__restrict __path, char *__restrict __buf, size_t __len, size_t __buflen) __asm__ ("" "__readlink_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("readlink called with bigger length " "than size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__warn_unused_result__)) ssize_t
__attribute__ ((__nothrow__ , __leaf__)) readlink (const char *__restrict __path, char *__restrict __buf, size_t __len)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __readlink_chk (__path, __buf, __len, __builtin_object_size (__buf, 2 > 1));
      if ( __len > __builtin_object_size (__buf, 2 > 1))
 return __readlink_chk_warn (__path, __buf, __len, __builtin_object_size (__buf, 2 > 1));
    }
  return __readlink_alias (__path, __buf, __len);
}
extern ssize_t __readlinkat_chk (int __fd, const char *__restrict __path,
     char *__restrict __buf, size_t __len,
     size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__));
extern ssize_t __readlinkat_alias (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len) __asm__ ("" "readlinkat") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__));
extern ssize_t __readlinkat_chk_warn (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len, size_t __buflen) __asm__ ("" "__readlinkat_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("readlinkat called with bigger " "length than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (2, 3))) __attribute__ ((__warn_unused_result__)) ssize_t
__attribute__ ((__nothrow__ , __leaf__)) readlinkat (int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __readlinkat_chk (__fd, __path, __buf, __len, __builtin_object_size (__buf, 2 > 1));
      if (__len > __builtin_object_size (__buf, 2 > 1))
 return __readlinkat_chk_warn (__fd, __path, __buf, __len,
          __builtin_object_size (__buf, 2 > 1));
    }
  return __readlinkat_alias (__fd, __path, __buf, __len);
}
extern char *__getcwd_chk (char *__buf, size_t __size, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__getcwd_alias (char *__buf, size_t __size) __asm__ ("" "getcwd") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern char *__getcwd_chk_warn (char *__buf, size_t __size, size_t __buflen) __asm__ ("" "__getcwd_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getcwd caller with bigger length than size of " "destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) getcwd (char *__buf, size_t __size)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__size))
 return __getcwd_chk (__buf, __size, __builtin_object_size (__buf, 2 > 1));
      if (__size > __builtin_object_size (__buf, 2 > 1))
 return __getcwd_chk_warn (__buf, __size, __builtin_object_size (__buf, 2 > 1));
    }
  return __getcwd_alias (__buf, __size);
}
extern char *__getwd_chk (char *__buf, size_t buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern char *__getwd_warn (char *__buf) __asm__ ("" "getwd") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("please use getcwd instead, as getwd " "doesn't specify buffer size")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) __attribute__ ((__warn_unused_result__)) char *
__attribute__ ((__nothrow__ , __leaf__)) getwd (char *__buf)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    return __getwd_chk (__buf, __builtin_object_size (__buf, 2 > 1));
  return __getwd_warn (__buf);
}
extern size_t __confstr_chk (int __name, char *__buf, size_t __len,
        size_t __buflen) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __confstr_alias (int __name, char *__buf, size_t __len) __asm__ ("" "confstr") __attribute__ ((__nothrow__ , __leaf__));
extern size_t __confstr_chk_warn (int __name, char *__buf, size_t __len, size_t __buflen) __asm__ ("" "__confstr_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("confstr called with bigger length than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) confstr (int __name, char *__buf, size_t __len)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __confstr_chk (__name, __buf, __len, __builtin_object_size (__buf, 2 > 1));
      if (__builtin_object_size (__buf, 2 > 1) < __len)
 return __confstr_chk_warn (__name, __buf, __len, __builtin_object_size (__buf, 2 > 1));
    }
  return __confstr_alias (__name, __buf, __len);
}
extern int __getgroups_chk (int __size, __gid_t __list[], size_t __listlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int __getgroups_alias (int __size, __gid_t __list[]) __asm__ ("" "getgroups") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern int __getgroups_chk_warn (int __size, __gid_t __list[], size_t __listlen) __asm__ ("" "__getgroups_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getgroups called with bigger group count than what " "can fit into destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) getgroups (int __size, __gid_t __list[])
{
  if (__builtin_object_size (__list, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__size) || __size < 0)
 return __getgroups_chk (__size, __list, __builtin_object_size (__list, 2 > 1));
      if (__size * sizeof (__gid_t) > __builtin_object_size (__list, 2 > 1))
 return __getgroups_chk_warn (__size, __list, __builtin_object_size (__list, 2 > 1));
    }
  return __getgroups_alias (__size, __list);
}
extern int __ttyname_r_chk (int __fd, char *__buf, size_t __buflen,
       size_t __nreal) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int __ttyname_r_alias (int __fd, char *__buf, size_t __buflen) __asm__ ("" "ttyname_r") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2)));
extern int __ttyname_r_chk_warn (int __fd, char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__ttyname_r_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (2))) __attribute__((__warning__ ("ttyname_r called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) ttyname_r (int __fd, char *__buf, size_t __buflen)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__buflen))
 return __ttyname_r_chk (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1));
      if (__buflen > __builtin_object_size (__buf, 2 > 1))
 return __ttyname_r_chk_warn (__fd, __buf, __buflen, __builtin_object_size (__buf, 2 > 1));
    }
  return __ttyname_r_alias (__fd, __buf, __buflen);
}
extern int __getlogin_r_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nonnull__ (1)));
extern int __getlogin_r_alias (char *__buf, size_t __buflen) __asm__ ("" "getlogin_r") __attribute__ ((__nonnull__ (1)));
extern int __getlogin_r_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__getlogin_r_chk")
     __attribute__ ((__nonnull__ (1))) __attribute__((__warning__ ("getlogin_r called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
getlogin_r (char *__buf, size_t __buflen)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__buflen))
 return __getlogin_r_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
      if (__buflen > __builtin_object_size (__buf, 2 > 1))
 return __getlogin_r_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
    }
  return __getlogin_r_alias (__buf, __buflen);
}
extern int __gethostname_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int __gethostname_alias (char *__buf, size_t __buflen) __asm__ ("" "gethostname") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int __gethostname_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__gethostname_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__((__warning__ ("gethostname called with bigger buflen than " "size of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) gethostname (char *__buf, size_t __buflen)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__buflen))
 return __gethostname_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
      if (__buflen > __builtin_object_size (__buf, 2 > 1))
 return __gethostname_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
    }
  return __gethostname_alias (__buf, __buflen);
}
extern int __getdomainname_chk (char *__buf, size_t __buflen, size_t __nreal)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int __getdomainname_alias (char *__buf, size_t __buflen) __asm__ ("" "getdomainname") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern int __getdomainname_chk_warn (char *__buf, size_t __buflen, size_t __nreal) __asm__ ("" "__getdomainname_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("getdomainname called with bigger " "buflen than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) getdomainname (char *__buf, size_t __buflen)
{
  if (__builtin_object_size (__buf, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__buflen))
 return __getdomainname_chk (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
      if (__buflen > __builtin_object_size (__buf, 2 > 1))
 return __getdomainname_chk_warn (__buf, __buflen, __builtin_object_size (__buf, 2 > 1));
    }
  return __getdomainname_alias (__buf, __buflen);
}


extern int __sigismember (const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
extern __inline __attribute__ ((__gnu_inline__)) int __sigismember (const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline __attribute__ ((__gnu_inline__)) int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline __attribute__ ((__gnu_inline__)) int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }

typedef __sig_atomic_t sig_atomic_t;

typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
typedef __clock_t __sigchld_clock_t;
typedef struct
  {
    int si_signo;
    int si_errno;
    int si_code;
    union
      {
 int _pad[((128 / sizeof (int)) - 4)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __sigchld_clock_t si_utime;
     __sigchld_clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
     short int si_addr_lsb;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_TKILL = -6,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR,
  BUS_MCEERR_AR,
  BUS_MCEERR_AO
};
enum
{
  TRAP_BRKPT = 1,
  TRAP_TRACE
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 4)];
 __pid_t _tid;
 struct
   {
     void (*_function) (sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));

extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));

extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));

extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));

extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern void psignal (int __sig, const char *__s);
extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
extern int __sigpause (int __sig_or_mask, int __is_sig);
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));
extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
extern const char *const _sys_siglist[65];
extern const char *const sys_siglist[65];
struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;
    int sv_flags;
  };
extern int sigvec (int __sig, const struct sigvec *__vec,
     struct sigvec *__ovec) __attribute__ ((__nothrow__ , __leaf__));
struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t padding[7];
};
struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short padding[3];
};
struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t padding[24];
};
struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};
struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t reserved1[2];
  __uint64_t reserved2[5];
};
struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};
struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__));
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];
struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int padding[3];
};
struct _libc_xmmreg
{
  __uint32_t element[4];
};
struct _libc_fpstate
{
  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t padding[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct
  {
    gregset_t gregs;
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;
typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
extern int sigaltstack (const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));


struct dirent
  {
    __ino_t d_ino;
    __off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
enum
  {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
  };
typedef struct __dirstream DIR;
extern DIR *opendir (const char *__name) __attribute__ ((__nonnull__ (1)));
extern DIR *fdopendir (int __fd);
extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern struct dirent *readdir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
extern int readdir_r (DIR *__restrict __dirp,
        struct dirent *__restrict __entry,
        struct dirent **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3)));
extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int scandir (const char *__restrict __dir,
      struct dirent ***__restrict __namelist,
      int (*__selector) (const struct dirent *),
      int (*__cmp) (const struct dirent **,
      const struct dirent **))
     __attribute__ ((__nonnull__ (1, 2)));
extern int alphasort (const struct dirent **__e1,
        const struct dirent **__e2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __ssize_t getdirentries (int __fd, char *__restrict __buf,
    size_t __nbytes,
    __off_t *__restrict __basep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));



struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};


struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;

extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));

extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));

extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));

extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern int stime (const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));


struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
typedef struct timezone *__restrict __timezone_ptr_t;
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef int __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));


struct passwd
{
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
extern void setpwent (void);
extern void endpwent (void);
extern struct passwd *getpwent (void);
extern struct passwd *fgetpwent (FILE *__stream);
extern int putpwent (const struct passwd *__restrict __p,
       FILE *__restrict __f);
extern struct passwd *getpwuid (__uid_t __uid);
extern struct passwd *getpwnam (const char *__name);
extern int getpwent_r (struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);
extern int getpwuid_r (__uid_t __uid,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);
extern int getpwnam_r (const char *__restrict __name,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);
extern int fgetpwent_r (FILE *__restrict __stream,
   struct passwd *__restrict __resultbuf,
   char *__restrict __buffer, size_t __buflen,
   struct passwd **__restrict __result);



extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));

extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *__rawmemchr (const void *__s, int __c);
extern __inline __attribute__ ((__gnu_inline__)) size_t __strcspn_c1 (const char *__s, int __reject);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strcspn_c1 (const char *__s, int __reject)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) size_t __strcspn_c2 (const char *__s, int __reject1,
         int __reject2);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strcspn_c2 (const char *__s, int __reject1, int __reject2)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) size_t __strcspn_c3 (const char *__s, int __reject1,
         int __reject2, int __reject3);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strcspn_c3 (const char *__s, int __reject1, int __reject2,
       int __reject3)
{
  size_t __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2 && __s[__result] != __reject3)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) size_t __strspn_c1 (const char *__s, int __accept);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strspn_c1 (const char *__s, int __accept)
{
  size_t __result = 0;
  while (__s[__result] == __accept)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) size_t __strspn_c2 (const char *__s, int __accept1,
        int __accept2);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strspn_c2 (const char *__s, int __accept1, int __accept2)
{
  size_t __result = 0;
  while (__s[__result] == __accept1 || __s[__result] == __accept2)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) size_t __strspn_c3 (const char *__s, int __accept1,
        int __accept2, int __accept3);
extern __inline __attribute__ ((__gnu_inline__)) size_t
__strspn_c3 (const char *__s, int __accept1, int __accept2, int __accept3)
{
  size_t __result = 0;
  while (__s[__result] == __accept1 || __s[__result] == __accept2
  || __s[__result] == __accept3)
    ++__result;
  return __result;
}
extern __inline __attribute__ ((__gnu_inline__)) char *__strpbrk_c2 (const char *__s, int __accept1,
        int __accept2);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strpbrk_c2 (const char *__s, int __accept1, int __accept2)
{
  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (size_t) __s;
}
extern __inline __attribute__ ((__gnu_inline__)) char *__strpbrk_c3 (const char *__s, int __accept1,
        int __accept2, int __accept3);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strpbrk_c3 (const char *__s, int __accept1, int __accept2, int __accept3)
{
  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2
  && *__s != __accept3)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (size_t) __s;
}
extern __inline __attribute__ ((__gnu_inline__)) char *__strtok_r_1c (char *__s, char __sep, char **__nextp);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strtok_r_1c (char *__s, char __sep, char **__nextp)
{
  char *__result;
  if (__s == ((void *)0))
    __s = *__nextp;
  while (*__s == __sep)
    ++__s;
  __result = ((void *)0);
  if (*__s != '\0')
    {
      __result = __s++;
      while (*__s != '\0')
 if (*__s++ == __sep)
   {
     __s[-1] = '\0';
     break;
   }
    }
  *__nextp = __s;
  return __result;
}
extern char *__strsep_g (char **__stringp, const char *__delim);
extern __inline __attribute__ ((__gnu_inline__)) char *__strsep_1c (char **__s, char __reject);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strsep_1c (char **__s, char __reject)
{
  char *__retval = *__s;
  if (__retval != ((void *)0) && (*__s = (__extension__ (__builtin_constant_p (__reject) && !__builtin_constant_p (__retval) && (__reject) == '\0' ? (char *) __rawmemchr (__retval, __reject) : __builtin_strchr (__retval, __reject)))) != ((void *)0))
    *(*__s)++ = '\0';
  return __retval;
}
extern __inline __attribute__ ((__gnu_inline__)) char *__strsep_2c (char **__s, char __reject1, char __reject2);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strsep_2c (char **__s, char __reject1, char __reject2)
{
  char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = ((void *)0);
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}
extern __inline __attribute__ ((__gnu_inline__)) char *__strsep_3c (char **__s, char __reject1, char __reject2,
       char __reject3);
extern __inline __attribute__ ((__gnu_inline__)) char *
__strsep_3c (char **__s, char __reject1, char __reject2, char __reject3)
{
  char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = ((void *)0);
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2 || *__cp == __reject3)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}
extern char *__strdup (const char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern char *__strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern void __warn_memset_zero_len (void) __attribute__((__warning__ ("memset used with constant zero length parameter; this could be due to transposed parameters")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memcpy (void *__restrict __dest, const void *__restrict __src, size_t __len)
{
  return __builtin___memcpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memmove (void *__dest, const void *__src, size_t __len)
{
  return __builtin___memmove_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void *
__attribute__ ((__nothrow__ , __leaf__)) memset (void *__dest, int __ch, size_t __len)
{
  if (__builtin_constant_p (__len) && __len == 0
      && (!__builtin_constant_p (__ch) || __ch != 0))
    {
      __warn_memset_zero_len ();
      return __dest;
    }
  return __builtin___memset_chk (__dest, __ch, __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void
__attribute__ ((__nothrow__ , __leaf__)) bcopy (const void *__src, void *__dest, size_t __len)
{
  (void) __builtin___memmove_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) void
__attribute__ ((__nothrow__ , __leaf__)) bzero (void *__dest, size_t __len)
{
  (void) __builtin___memset_chk (__dest, '\0', __len, __builtin_object_size (__dest, 0));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strcpy (char *__restrict __dest, const char *__restrict __src)
{
  return __builtin___strcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strncpy (char *__restrict __dest, const char *__restrict __src, size_t __len)
{
  return __builtin___strncpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}
extern char *__stpncpy_chk (char *__dest, const char *__src, size_t __n,
       size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpncpy_alias (char *__dest, const char *__src, size_t __n) __asm__ ("" "stpncpy") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) stpncpy (char *__dest, const char *__src, size_t __n)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1
      && (!__builtin_constant_p (__n) || __n <= __builtin_object_size (__dest, 2 > 1)))
    return __stpncpy_chk (__dest, __src, __n, __builtin_object_size (__dest, 2 > 1));
  return __stpncpy_alias (__dest, __src, __n);
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strcat (char *__restrict __dest, const char *__restrict __src)
{
  return __builtin___strcat_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) char *
__attribute__ ((__nothrow__ , __leaf__)) strncat (char *__restrict __dest, const char *__restrict __src, size_t __len)
{
  return __builtin___strncat_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}


typedef long int __jmp_buf[8];
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };

typedef struct __jmp_buf_tag jmp_buf[1];
extern int setjmp (jmp_buf __env) __attribute__ ((__nothrow__));

extern int __sigsetjmp (struct __jmp_buf_tag __env[1], int __savemask) __attribute__ ((__nothrow__));
extern int _setjmp (struct __jmp_buf_tag __env[1]) __attribute__ ((__nothrow__));

extern void longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));

extern void _longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
typedef struct __jmp_buf_tag sigjmp_buf[1];
extern void siglongjmp (sigjmp_buf __env, int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern void longjmp (struct __jmp_buf_tag __env[1], int __val) __asm__ ("" "__longjmp_chk") __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern void _longjmp (struct __jmp_buf_tag __env[1], int __val) __asm__ ("" "__longjmp_chk") __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern void siglongjmp (struct __jmp_buf_tag __env[1], int __val) __asm__ ("" "__longjmp_chk") __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));

extern void (*sigset(int, void (*func) (int))) (int);


struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
extern char *setlocale (int __category, const char *__locale) __attribute__ ((__nothrow__ , __leaf__));
extern struct lconv *localeconv (void) __attribute__ ((__nothrow__ , __leaf__));

extern __locale_t newlocale (int __category_mask, const char *__locale,
        __locale_t __base) __attribute__ ((__nothrow__ , __leaf__));
extern __locale_t duplocale (__locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));
extern void freelocale (__locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));
extern __locale_t uselocale (__locale_t __dataset) __attribute__ ((__nothrow__ , __leaf__));

typedef unsigned char char_u;
typedef unsigned short short_u;
typedef unsigned int int_u;
typedef unsigned long long_u;
typedef long long_i;
typedef off_t off_T;
typedef char_u schar_T;
typedef unsigned short sattr_T;
typedef unsigned int u8char_T;
enum key_extra
{
    KE_NAME = 3
    , KE_S_UP = 4
    , KE_S_DOWN = 5
    , KE_S_F1 = 6
    , KE_S_F2 = 7
    , KE_S_F3 = 8
    , KE_S_F4 = 9
    , KE_S_F5 = 10
    , KE_S_F6 = 11
    , KE_S_F7 = 12
    , KE_S_F8 = 13
    , KE_S_F9 = 14
    , KE_S_F10 = 15
    , KE_S_F11 = 16
    , KE_S_F12 = 17
    , KE_S_F13 = 18
    , KE_S_F14 = 19
    , KE_S_F15 = 20
    , KE_S_F16 = 21
    , KE_S_F17 = 22
    , KE_S_F18 = 23
    , KE_S_F19 = 24
    , KE_S_F20 = 25
    , KE_S_F21 = 26
    , KE_S_F22 = 27
    , KE_S_F23 = 28
    , KE_S_F24 = 29
    , KE_S_F25 = 30
    , KE_S_F26 = 31
    , KE_S_F27 = 32
    , KE_S_F28 = 33
    , KE_S_F29 = 34
    , KE_S_F30 = 35
    , KE_S_F31 = 36
    , KE_S_F32 = 37
    , KE_S_F33 = 38
    , KE_S_F34 = 39
    , KE_S_F35 = 40
    , KE_S_F36 = 41
    , KE_S_F37 = 42
    , KE_MOUSE = 43
    , KE_LEFTMOUSE = 44
    , KE_LEFTDRAG = 45
    , KE_LEFTRELEASE = 46
    , KE_MIDDLEMOUSE = 47
    , KE_MIDDLEDRAG = 48
    , KE_MIDDLERELEASE = 49
    , KE_RIGHTMOUSE = 50
    , KE_RIGHTDRAG = 51
    , KE_RIGHTRELEASE = 52
    , KE_IGNORE = 53
    , KE_TAB = 54
    , KE_S_TAB_OLD = 55
    , KE_SNIFF_UNUSED = 56
    , KE_XF1 = 57
    , KE_XF2 = 58
    , KE_XF3 = 59
    , KE_XF4 = 60
    , KE_XEND = 61
    , KE_ZEND = 62
    , KE_XHOME = 63
    , KE_ZHOME = 64
    , KE_XUP = 65
    , KE_XDOWN = 66
    , KE_XLEFT = 67
    , KE_XRIGHT = 68
    , KE_LEFTMOUSE_NM = 69
    , KE_LEFTRELEASE_NM = 70
    , KE_S_XF1 = 71
    , KE_S_XF2 = 72
    , KE_S_XF3 = 73
    , KE_S_XF4 = 74
    , KE_MOUSEDOWN = 75
    , KE_MOUSEUP = 76
    , KE_MOUSELEFT = 77
    , KE_MOUSERIGHT = 78
    , KE_KINS = 79
    , KE_KDEL = 80
    , KE_CSI = 81
    , KE_SNR = 82
    , KE_PLUG = 83
    , KE_CMDWIN = 84
    , KE_C_LEFT = 85
    , KE_C_RIGHT = 86
    , KE_C_HOME = 87
    , KE_C_END = 88
    , KE_X1MOUSE = 89
    , KE_X1DRAG = 90
    , KE_X1RELEASE = 91
    , KE_X2MOUSE = 92
    , KE_X2DRAG = 93
    , KE_X2RELEASE = 94
    , KE_DROP = 95
    , KE_CURSORHOLD = 96
    , KE_NOP = 97
    , KE_FOCUSGAINED = 98
    , KE_FOCUSLOST = 99
};
enum SpecialKey
{
    KS_NAME = 0,
    KS_CE,
    KS_AL,
    KS_CAL,
    KS_DL,
    KS_CDL,
    KS_CS,
    KS_CL,
    KS_CD,
    KS_UT,
    KS_DA,
    KS_DB,
    KS_VI,
    KS_VE,
    KS_VS,
    KS_CVS,
    KS_CSH,
    KS_CRC,
    KS_CRS,
    KS_ME,
    KS_MR,
    KS_MD,
    KS_SE,
    KS_SO,
    KS_CZH,
    KS_CZR,
    KS_UE,
    KS_US,
    KS_UCE,
    KS_UCS,
    KS_STE,
    KS_STS,
    KS_MS,
    KS_CM,
    KS_SR,
    KS_CRI,
    KS_VB,
    KS_KS,
    KS_KE,
    KS_TI,
    KS_TE,
    KS_BC,
    KS_CCS,
    KS_CCO,
    KS_CSF,
    KS_CSB,
    KS_XS,
    KS_XN,
    KS_MB,
    KS_CAF,
    KS_CAB,
    KS_LE,
    KS_ND,
    KS_CIS,
    KS_CIE,
    KS_CSC,
    KS_CEC,
    KS_TS,
    KS_FS,
    KS_CWP,
    KS_CGP,
    KS_CWS,
    KS_CRV,
    KS_RBG,
    KS_CSI,
    KS_CEI,
    KS_CSR,
    KS_CSV,
    KS_OP,
    KS_U7,
    KS_8F,
    KS_8B,
    KS_CBE,
    KS_CBD,
    KS_CPS,
    KS_CPE
};
extern char_u *(term_strings[]);

typedef float float_t;
typedef double double_t;

extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));

extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));


extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));

extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));

extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));

extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));

extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));


extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));

extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));

extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));

extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));

extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));


extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));

extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));

extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };
typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;
extern _LIB_VERSION_TYPE _LIB_VERSION;
struct exception
  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };
extern int matherr (struct exception *__exc);

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) __signbitf (float __x)
{
  int __m;
  __asm ("pmovmskb %1, %0" : "=r" (__m) : "x" (__x));
  return (__m & 0x8) != 0;
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) __signbit (double __x)
{
  int __m;
  __asm ("pmovmskb %1, %0" : "=r" (__m) : "x" (__x));
  return (__m & 0x80) != 0;
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) __signbitl (long double __x)
{
  __extension__ union { long double __l; int __i[3]; } __u = { __l: __x };
  return (__u.__i[2] & 0x8000) != 0;
}



extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
typedef int __gwchar_t;

typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern long int __strtol_internal (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) intmax_t
__attribute__ ((__nothrow__ , __leaf__)) strtoimax (const char *__restrict nptr, char **__restrict endptr, int base)
{
  return __strtol_internal (nptr, endptr, base, 0);
}
extern unsigned long int __strtoul_internal (const char *__restrict __nptr,
          char ** __restrict __endptr,
          int __base, int __group)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) uintmax_t
__attribute__ ((__nothrow__ , __leaf__)) strtoumax (const char *__restrict nptr, char **__restrict endptr, int base)
{
  return __strtoul_internal (nptr, endptr, base, 0);
}
extern long int __wcstol_internal (const __gwchar_t * __restrict __nptr,
       __gwchar_t **__restrict __endptr,
       int __base, int __group)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) intmax_t
__attribute__ ((__nothrow__ , __leaf__)) wcstoimax (const __gwchar_t *__restrict nptr, __gwchar_t **__restrict endptr, int base)
{
  return __wcstol_internal (nptr, endptr, base, 0);
}
extern unsigned long int __wcstoul_internal (const __gwchar_t *
          __restrict __nptr,
          __gwchar_t **
          __restrict __endptr,
          int __base, int __group)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__gnu_inline__)) uintmax_t
__attribute__ ((__nothrow__ , __leaf__)) wcstoumax (const __gwchar_t *__restrict nptr, __gwchar_t **__restrict endptr, int base)
{
  return __wcstoul_internal (nptr, endptr, base, 0);
}

typedef unsigned int wint_t;

typedef unsigned long int wctype_t;

enum
{
  __ISwupper = 0,
  __ISwlower = 1,
  __ISwalpha = 2,
  __ISwdigit = 3,
  __ISwxdigit = 4,
  __ISwspace = 5,
  __ISwprint = 6,
  __ISwgraph = 7,
  __ISwblank = 8,
  __ISwcntrl = 9,
  __ISwpunct = 10,
  __ISwalnum = 11,
  _ISwupper = ((__ISwupper) < 8 ? (int) ((1UL << (__ISwupper)) << 24) : ((__ISwupper) < 16 ? (int) ((1UL << (__ISwupper)) << 8) : ((__ISwupper) < 24 ? (int) ((1UL << (__ISwupper)) >> 8) : (int) ((1UL << (__ISwupper)) >> 24)))),
  _ISwlower = ((__ISwlower) < 8 ? (int) ((1UL << (__ISwlower)) << 24) : ((__ISwlower) < 16 ? (int) ((1UL << (__ISwlower)) << 8) : ((__ISwlower) < 24 ? (int) ((1UL << (__ISwlower)) >> 8) : (int) ((1UL << (__ISwlower)) >> 24)))),
  _ISwalpha = ((__ISwalpha) < 8 ? (int) ((1UL << (__ISwalpha)) << 24) : ((__ISwalpha) < 16 ? (int) ((1UL << (__ISwalpha)) << 8) : ((__ISwalpha) < 24 ? (int) ((1UL << (__ISwalpha)) >> 8) : (int) ((1UL << (__ISwalpha)) >> 24)))),
  _ISwdigit = ((__ISwdigit) < 8 ? (int) ((1UL << (__ISwdigit)) << 24) : ((__ISwdigit) < 16 ? (int) ((1UL << (__ISwdigit)) << 8) : ((__ISwdigit) < 24 ? (int) ((1UL << (__ISwdigit)) >> 8) : (int) ((1UL << (__ISwdigit)) >> 24)))),
  _ISwxdigit = ((__ISwxdigit) < 8 ? (int) ((1UL << (__ISwxdigit)) << 24) : ((__ISwxdigit) < 16 ? (int) ((1UL << (__ISwxdigit)) << 8) : ((__ISwxdigit) < 24 ? (int) ((1UL << (__ISwxdigit)) >> 8) : (int) ((1UL << (__ISwxdigit)) >> 24)))),
  _ISwspace = ((__ISwspace) < 8 ? (int) ((1UL << (__ISwspace)) << 24) : ((__ISwspace) < 16 ? (int) ((1UL << (__ISwspace)) << 8) : ((__ISwspace) < 24 ? (int) ((1UL << (__ISwspace)) >> 8) : (int) ((1UL << (__ISwspace)) >> 24)))),
  _ISwprint = ((__ISwprint) < 8 ? (int) ((1UL << (__ISwprint)) << 24) : ((__ISwprint) < 16 ? (int) ((1UL << (__ISwprint)) << 8) : ((__ISwprint) < 24 ? (int) ((1UL << (__ISwprint)) >> 8) : (int) ((1UL << (__ISwprint)) >> 24)))),
  _ISwgraph = ((__ISwgraph) < 8 ? (int) ((1UL << (__ISwgraph)) << 24) : ((__ISwgraph) < 16 ? (int) ((1UL << (__ISwgraph)) << 8) : ((__ISwgraph) < 24 ? (int) ((1UL << (__ISwgraph)) >> 8) : (int) ((1UL << (__ISwgraph)) >> 24)))),
  _ISwblank = ((__ISwblank) < 8 ? (int) ((1UL << (__ISwblank)) << 24) : ((__ISwblank) < 16 ? (int) ((1UL << (__ISwblank)) << 8) : ((__ISwblank) < 24 ? (int) ((1UL << (__ISwblank)) >> 8) : (int) ((1UL << (__ISwblank)) >> 24)))),
  _ISwcntrl = ((__ISwcntrl) < 8 ? (int) ((1UL << (__ISwcntrl)) << 24) : ((__ISwcntrl) < 16 ? (int) ((1UL << (__ISwcntrl)) << 8) : ((__ISwcntrl) < 24 ? (int) ((1UL << (__ISwcntrl)) >> 8) : (int) ((1UL << (__ISwcntrl)) >> 24)))),
  _ISwpunct = ((__ISwpunct) < 8 ? (int) ((1UL << (__ISwpunct)) << 24) : ((__ISwpunct) < 16 ? (int) ((1UL << (__ISwpunct)) << 8) : ((__ISwpunct) < 24 ? (int) ((1UL << (__ISwpunct)) >> 8) : (int) ((1UL << (__ISwpunct)) >> 24)))),
  _ISwalnum = ((__ISwalnum) < 8 ? (int) ((1UL << (__ISwalnum)) << 24) : ((__ISwalnum) < 16 ? (int) ((1UL << (__ISwalnum)) << 8) : ((__ISwalnum) < 24 ? (int) ((1UL << (__ISwalnum)) >> 8) : (int) ((1UL << (__ISwalnum)) >> 24))))
};


extern int iswalnum (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswalpha (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswcntrl (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswdigit (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswgraph (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswlower (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswprint (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswpunct (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswspace (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswupper (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswxdigit (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern int iswblank (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern wctype_t wctype (const char *__property) __attribute__ ((__nothrow__ , __leaf__));
extern int iswctype (wint_t __wc, wctype_t __desc) __attribute__ ((__nothrow__ , __leaf__));


typedef const __int32_t *wctrans_t;


extern wint_t towlower (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));
extern wint_t towupper (wint_t __wc) __attribute__ ((__nothrow__ , __leaf__));




extern wctrans_t wctrans (const char *__property) __attribute__ ((__nothrow__ , __leaf__));
extern wint_t towctrans (wint_t __wc, wctrans_t __desc) __attribute__ ((__nothrow__ , __leaf__));

extern int iswalnum_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswalpha_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswcntrl_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswdigit_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswgraph_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswlower_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswprint_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswpunct_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswspace_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswupper_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswxdigit_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern int iswblank_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern wctype_t wctype_l (const char *__property, __locale_t __locale)
     __attribute__ ((__nothrow__ , __leaf__));
extern int iswctype_l (wint_t __wc, wctype_t __desc, __locale_t __locale)
     __attribute__ ((__nothrow__ , __leaf__));
extern wint_t towlower_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern wint_t towupper_l (wint_t __wc, __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));
extern wctrans_t wctrans_l (const char *__property, __locale_t __locale)
     __attribute__ ((__nothrow__ , __leaf__));
extern wint_t towctrans_l (wint_t __wc, wctrans_t __desc,
      __locale_t __locale) __attribute__ ((__nothrow__ , __leaf__));

typedef long int ptrdiff_t;

extern char *gettext (const char *__msgid)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (1)));
extern char *dgettext (const char *__domainname, const char *__msgid)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2)));
extern char *__dgettext (const char *__domainname, const char *__msgid)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2)));
extern char *dcgettext (const char *__domainname,
   const char *__msgid, int __category)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2)));
extern char *__dcgettext (const char *__domainname,
     const char *__msgid, int __category)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2)));
extern char *ngettext (const char *__msgid1, const char *__msgid2,
         unsigned long int __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (1))) __attribute__ ((__format_arg__ (2)));
extern char *dngettext (const char *__domainname, const char *__msgid1,
   const char *__msgid2, unsigned long int __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *dcngettext (const char *__domainname, const char *__msgid1,
    const char *__msgid2, unsigned long int __n,
    int __category)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *textdomain (const char *__domainname) __attribute__ ((__nothrow__ , __leaf__));
extern char *bindtextdomain (const char *__domainname,
        const char *__dirname) __attribute__ ((__nothrow__ , __leaf__));
extern char *bind_textdomain_codeset (const char *__domainname,
          const char *__codeset) __attribute__ ((__nothrow__ , __leaf__));

typedef enum {
    BVAL_NR,
    BVAL_STRING,
    BVAL_EMPTY
} btype_T;
typedef struct {
    btype_T bv_type;
    long bv_nr;
    char_u *bv_string;
    int bv_len;
    int bv_allocated;
} bval_T;
enum auto_event
{
    EVENT_BUFADD = 0,
    EVENT_BUFNEW,
    EVENT_BUFDELETE,
    EVENT_BUFWIPEOUT,
    EVENT_BUFENTER,
    EVENT_BUFFILEPOST,
    EVENT_BUFFILEPRE,
    EVENT_BUFLEAVE,
    EVENT_BUFNEWFILE,
    EVENT_BUFREADPOST,
    EVENT_BUFREADPRE,
    EVENT_BUFREADCMD,
    EVENT_BUFUNLOAD,
    EVENT_BUFHIDDEN,
    EVENT_BUFWINENTER,
    EVENT_BUFWINLEAVE,
    EVENT_BUFWRITEPOST,
    EVENT_BUFWRITEPRE,
    EVENT_BUFWRITECMD,
    EVENT_CMDWINENTER,
    EVENT_CMDWINLEAVE,
    EVENT_COLORSCHEME,
    EVENT_COMPLETEDONE,
    EVENT_FILEAPPENDPOST,
    EVENT_FILEAPPENDPRE,
    EVENT_FILEAPPENDCMD,
    EVENT_FILECHANGEDSHELL,
    EVENT_FILECHANGEDSHELLPOST,
    EVENT_FILECHANGEDRO,
    EVENT_FILEREADPOST,
    EVENT_FILEREADPRE,
    EVENT_FILEREADCMD,
    EVENT_FILETYPE,
    EVENT_FILEWRITEPOST,
    EVENT_FILEWRITEPRE,
    EVENT_FILEWRITECMD,
    EVENT_FILTERREADPOST,
    EVENT_FILTERREADPRE,
    EVENT_FILTERWRITEPOST,
    EVENT_FILTERWRITEPRE,
    EVENT_FOCUSGAINED,
    EVENT_FOCUSLOST,
    EVENT_GUIENTER,
    EVENT_GUIFAILED,
    EVENT_INSERTCHANGE,
    EVENT_INSERTENTER,
    EVENT_INSERTLEAVE,
    EVENT_MENUPOPUP,
    EVENT_QUICKFIXCMDPOST,
    EVENT_QUICKFIXCMDPRE,
    EVENT_QUITPRE,
    EVENT_SESSIONLOADPOST,
    EVENT_STDINREADPOST,
    EVENT_STDINREADPRE,
    EVENT_SYNTAX,
    EVENT_TERMCHANGED,
    EVENT_TERMRESPONSE,
    EVENT_USER,
    EVENT_VIMENTER,
    EVENT_VIMLEAVE,
    EVENT_VIMLEAVEPRE,
    EVENT_VIMRESIZED,
    EVENT_WINENTER,
    EVENT_WINLEAVE,
    EVENT_WINNEW,
    EVENT_ENCODINGCHANGED,
    EVENT_INSERTCHARPRE,
    EVENT_CURSORHOLD,
    EVENT_CURSORHOLDI,
    EVENT_FUNCUNDEFINED,
    EVENT_REMOTEREPLY,
    EVENT_SWAPEXISTS,
    EVENT_SOURCEPRE,
    EVENT_SOURCECMD,
    EVENT_SPELLFILEMISSING,
    EVENT_CURSORMOVED,
    EVENT_CURSORMOVEDI,
    EVENT_TABENTER,
    EVENT_TABLEAVE,
    EVENT_TABNEW,
    EVENT_TABCLOSED,
    EVENT_SHELLCMDPOST,
    EVENT_SHELLFILTERPOST,
    EVENT_TEXTCHANGED,
    EVENT_TEXTCHANGEDI,
    EVENT_CMDUNDEFINED,
    EVENT_OPTIONSET,
    NUM_EVENTS
};
typedef enum auto_event event_T;
typedef enum
{
    HLF_8 = 0
    , HLF_EOB
    , HLF_AT
    , HLF_D
    , HLF_E
    , HLF_H
    , HLF_I
    , HLF_L
    , HLF_M
    , HLF_CM
    , HLF_N
    , HLF_CLN
    , HLF_R
    , HLF_S
    , HLF_SNC
    , HLF_C
    , HLF_T
    , HLF_V
    , HLF_VNC
    , HLF_W
    , HLF_WM
    , HLF_FL
    , HLF_FC
    , HLF_ADD
    , HLF_CHD
    , HLF_DED
    , HLF_TXD
    , HLF_CONCEAL
    , HLF_SC
    , HLF_SPB
    , HLF_SPC
    , HLF_SPR
    , HLF_SPL
    , HLF_PNI
    , HLF_PSI
    , HLF_PSB
    , HLF_PST
    , HLF_TP
    , HLF_TPS
    , HLF_TPF
    , HLF_CUC
    , HLF_CUL
    , HLF_MC
    , HLF_QFL
    , HLF_ST
    , HLF_STNC
    , HLF_COUNT
} hlf_T;
typedef uint32_t UINT32_T;

struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };


extern int fcntl (int __fd, int __cmd, ...);
extern int open (const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
extern int openat (int __fd, const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
extern int creat (const char *__file, mode_t __mode) __attribute__ ((__nonnull__ (1)));
extern int posix_fadvise (int __fd, off_t __offset, off_t __len,
     int __advise) __attribute__ ((__nothrow__ , __leaf__));
extern int posix_fallocate (int __fd, off_t __offset, off_t __len);
extern int __open_2 (const char *__path, int __oflag) __attribute__ ((__nonnull__ (1)));
extern int __open_alias (const char *__path, int __oflag, ...) __asm__ ("" "open") __attribute__ ((__nonnull__ (1)));
extern void __open_too_many_args (void) __attribute__((__error__ ("open can be called either with 2 or 3 arguments, not more")));
extern void __open_missing_mode (void) __attribute__((__error__ ("open with O_CREAT in second argument needs 3 arguments")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
open (const char *__path, int __oflag, ...)
{
  if (__builtin_va_arg_pack_len () > 1)
    __open_too_many_args ();
  if (__builtin_constant_p (__oflag))
    {
      if ((__oflag & 0100) != 0 && __builtin_va_arg_pack_len () < 1)
 {
   __open_missing_mode ();
   return __open_2 (__path, __oflag);
 }
      return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
    }
  if (__builtin_va_arg_pack_len () < 1)
    return __open_2 (__path, __oflag);
  return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
}
extern int __openat_2 (int __fd, const char *__path, int __oflag)
     __attribute__ ((__nonnull__ (2)));
extern int __openat_alias (int __fd, const char *__path, int __oflag, ...) __asm__ ("" "openat")
     __attribute__ ((__nonnull__ (2)));
extern void __openat_too_many_args (void) __attribute__((__error__ ("openat can be called either with 3 or 4 arguments, not more")));
extern void __openat_missing_mode (void) __attribute__((__error__ ("openat with O_CREAT in third argument needs 4 arguments")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
openat (int __fd, const char *__path, int __oflag, ...)
{
  if (__builtin_va_arg_pack_len () > 1)
    __openat_too_many_args ();
  if (__builtin_constant_p (__oflag))
    {
      if ((__oflag & 0100) != 0 && __builtin_va_arg_pack_len () < 1)
 {
   __openat_missing_mode ();
   return __openat_2 (__fd, __path, __oflag);
 }
      return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
    }
  if (__builtin_va_arg_pack_len () < 1)
    return __openat_2 (__fd, __path, __oflag);
  return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
}

typedef long linenr_T;
typedef int colnr_T;
typedef unsigned short disptick_T;
typedef void *vim_acl_T;
typedef struct timeval proftime_T;
typedef time_t time_T;
typedef int sock_T;
extern long p_aleph;
extern int p_acd;
extern char_u *p_ambw;
extern char_u *p_emoji;
extern int p_ar;
extern int p_aw;
extern int p_awa;
extern char_u *p_bs;
extern char_u *p_bg;
extern int p_bk;
extern char_u *p_bkc;
extern unsigned bkc_flags;
extern char_u *p_bdir;
extern char_u *p_bex;
extern char_u *p_bo;
extern unsigned bo_flags;
extern char_u *p_bsk;
extern char_u *p_cm;
extern char_u *p_breakat;
extern char_u *p_cmp;
extern unsigned cmp_flags;
extern char_u *p_enc;
extern int p_deco;
extern char_u *p_ccv;
extern char_u *p_cedit;
extern long p_cwh;
extern char_u *p_cb;
extern long p_ch;
extern int p_confirm;
extern int p_cp;
extern char_u *p_cot;
extern long p_ph;
extern char_u *p_cpo;
extern char_u *p_csprg;
extern int p_csre;
extern char_u *p_csqf;
extern int p_cst;
extern long p_csto;
extern long p_cspc;
extern int p_csverbose;
extern char_u *p_debug;
extern char_u *p_def;
extern char_u *p_inc;
extern char_u *p_dip;
extern char_u *p_dex;
extern char_u *p_dict;
extern int p_dg;
extern char_u *p_dir;
extern char_u *p_dy;
extern unsigned dy_flags;
extern int p_ed;
extern char_u *p_ead;
extern int p_ea;
extern char_u *p_ep;
extern int p_eb;
extern char_u *p_ef;
extern char_u *p_efm;
extern char_u *p_gefm;
extern char_u *p_gp;
extern char_u *p_ei;
extern int p_ek;
extern int p_exrc;
extern char_u *p_fencs;
extern char_u *p_ffs;
extern long p_fic;
extern char_u *p_fcl;
extern long p_fdls;
extern char_u *p_fdo;
extern unsigned fdo_flags;
extern char_u *p_fp;
extern int p_fs;
extern int p_gd;
extern char_u *p_pdev;
extern char_u *p_penc;
extern char_u *p_pexpr;
extern char_u *p_pmfn;
extern char_u *p_pmcs;
extern char_u *p_pfn;
extern char_u *p_popt;
extern char_u *p_header;
extern int p_prompt;
extern char_u *p_guicursor;
extern char_u *p_hf;
extern long p_hh;
extern char_u *p_hlg;
extern int p_hid;
extern char_u *p_hl;
extern int p_hls;
extern long p_hi;
extern int p_hkmap;
extern int p_hkmapp;
extern int p_fkmap;
extern int p_altkeymap;
extern int p_arshape;
extern int p_icon;
extern char_u *p_iconstring;
extern int p_ic;
extern int p_imcmdline;
extern int p_imdisable;
extern int p_is;
extern int p_im;
extern char_u *p_isf;
extern char_u *p_isi;
extern char_u *p_isp;
extern int p_js;
extern char_u *p_kp;
extern char_u *p_km;
extern char_u *p_langmap;
extern int p_lnr;
extern int p_lrm;
extern char_u *p_lm;
extern char_u *p_lispwords;
extern long p_ls;
extern long p_stal;
extern char_u *p_lcs;
extern int p_lz;
extern int p_lpl;
extern int p_magic;
extern char_u *p_menc;
extern char_u *p_mef;
extern char_u *p_mp;
extern char_u *p_scl;
extern char_u *p_cc;
extern int p_cc_cols[256];
extern long p_mat;
extern long p_mco;
extern long p_mfd;
extern long p_mmd;
extern long p_mm;
extern long p_mmp;
extern long p_mmt;
extern long p_mis;
extern char_u *p_msm;
extern long p_mls;
extern char_u *p_mouse;
extern char_u *p_mousem;
extern long p_mouset;
extern int p_more;
extern char_u *p_opfunc;
extern char_u *p_para;
extern int p_paste;
extern char_u *p_pt;
extern char_u *p_pex;
extern char_u *p_pm;
extern char_u *p_path;
extern char_u *p_cdpath;
extern long p_rdt;
extern int p_remap;
extern long p_re;
extern long p_report;
extern long p_pvh;
extern int p_ari;
extern int p_ri;
extern int p_ru;
extern char_u *p_ruf;
extern char_u *p_pp;
extern char_u *p_rtp;
extern long p_sj;
extern long p_so;
extern char_u *p_sbo;
extern char_u *p_sections;
extern int p_secure;
extern char_u *p_sel;
extern char_u *p_slm;
extern char_u *p_ssop;
extern unsigned ssop_flags;
extern char_u *p_sh;
extern char_u *p_shcf;
extern char_u *p_sp;
extern char_u *p_shq;
extern char_u *p_sxq;
extern char_u *p_sxe;
extern char_u *p_srr;
extern int p_stmp;
extern char_u *p_stl;
extern int p_sr;
extern char_u *p_shm;
extern char_u *p_sbr;
extern int p_sc;
extern int p_sft;
extern int p_sm;
extern int p_smd;
extern long p_ss;
extern long p_siso;
extern int p_scs;
extern int p_sta;
extern int p_sb;
extern long p_tpm;
extern char_u *p_tal;
extern char_u *p_sps;
extern int p_spr;
extern int p_sol;
extern char_u *p_su;
extern char_u *p_sws;
extern char_u *p_swb;
extern unsigned swb_flags;
extern int p_tbs;
extern char_u *p_tc;
extern unsigned tc_flags;
extern long p_tl;
extern int p_tr;
extern char_u *p_tags;
extern int p_tgst;
extern int p_tbidi;
extern char_u *p_tenc;
extern int p_tgc;
extern int p_terse;
extern int p_ta;
extern int p_to;
extern int p_timeout;
extern long p_tm;
extern int p_title;
extern long p_titlelen;
extern char_u *p_titleold;
extern char_u *p_titlestring;
extern char_u *p_tsr;
extern int p_ttimeout;
extern long p_ttm;
extern int p_tbi;
extern int p_tf;
extern long p_ttyscroll;
extern char_u *p_ttym;
extern unsigned ttym_flags;
extern char_u *p_udir;
extern long p_ul;
extern long p_ur;
extern long p_uc;
extern long p_ut;
extern char_u *p_fcs;
extern char_u *p_viminfo;
extern char_u *p_viminfofile;
extern char_u *p_vdir;
extern char_u *p_vop;
extern unsigned vop_flags;
extern int p_vb;
extern char_u *p_ve;
extern unsigned ve_flags;
extern long p_verbose;
extern char_u *p_vfile;
extern int p_warn;
extern char_u *p_wop;
extern long p_window;
extern char_u *p_wig;
extern int p_wiv;
extern char_u *p_ww;
extern long p_wc;
extern long p_wcm;
extern long p_wic;
extern char_u *p_wim;
extern int p_wmnu;
extern long p_wh;
extern long p_wmh;
extern long p_wmw;
extern long p_wiw;
extern int p_ws;
extern int p_write;
extern int p_wa;
extern int p_wb;
extern long p_wd;
enum
{
    BV_AI = 0
    , BV_AR
    , BV_BH
    , BV_BKC
    , BV_BT
    , BV_EFM
    , BV_GP
    , BV_MP
    , BV_BIN
    , BV_BL
    , BV_BOMB
    , BV_CI
    , BV_CIN
    , BV_CINK
    , BV_CINO
    , BV_CINW
    , BV_CM
    , BV_CMS
    , BV_COM
    , BV_CPT
    , BV_DICT
    , BV_TSR
    , BV_CFU
    , BV_DEF
    , BV_INC
    , BV_EOL
    , BV_FIXEOL
    , BV_EP
    , BV_ET
    , BV_FENC
    , BV_FP
    , BV_BEXPR
    , BV_FEX
    , BV_FF
    , BV_FLP
    , BV_FO
    , BV_FT
    , BV_IMI
    , BV_IMS
    , BV_INDE
    , BV_INDK
    , BV_INEX
    , BV_INF
    , BV_ISK
    , BV_KEY
    , BV_KMAP
    , BV_KP
    , BV_LISP
    , BV_LW
    , BV_MENC
    , BV_MA
    , BV_ML
    , BV_MOD
    , BV_MPS
    , BV_NF
    , BV_OFU
    , BV_PATH
    , BV_PI
    , BV_QE
    , BV_RO
    , BV_SI
    , BV_SN
    , BV_SMC
    , BV_SYN
    , BV_SPC
    , BV_SPF
    , BV_SPL
    , BV_STS
    , BV_SUA
    , BV_SW
    , BV_SWF
    , BV_TAGS
    , BV_TC
    , BV_TS
    , BV_TW
    , BV_TX
    , BV_UDF
    , BV_UL
    , BV_WM
    , BV_COUNT
};
enum
{
    WV_LIST = 0
    , WV_ARAB
    , WV_COCU
    , WV_COLE
    , WV_TK
    , WV_TMS
    , WV_CRBIND
    , WV_BRI
    , WV_BRIOPT
    , WV_DIFF
    , WV_FDC
    , WV_FEN
    , WV_FDI
    , WV_FDL
    , WV_FDM
    , WV_FML
    , WV_FDN
    , WV_FDE
    , WV_FDT
    , WV_FMR
    , WV_LBR
    , WV_NU
    , WV_RNU
    , WV_NUW
    , WV_PVW
    , WV_RL
    , WV_RLC
    , WV_SCBIND
    , WV_SCROLL
    , WV_SPELL
    , WV_CUC
    , WV_CUL
    , WV_CC
    , WV_STL
    , WV_WFH
    , WV_WFW
    , WV_WRAP
    , WV_SCL
    , WV_COUNT
};
typedef struct
{
    linenr_T lnum;
    colnr_T col;
    colnr_T coladd;
} pos_T;
typedef struct
{
    linenr_T lnum;
    colnr_T col;
} lpos_T;
typedef struct growarray
{
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
} garray_T;
typedef struct window_S win_T;
typedef struct wininfo_S wininfo_T;
typedef struct frame_S frame_T;
typedef int scid_T;
typedef struct file_buffer buf_T;
typedef struct terminal_S term_T;
typedef struct VimMenu vimmenu_T;
typedef struct {
    buf_T *br_buf;
    int br_fnum;
    int br_buf_free_count;
} bufref_T;
typedef struct regengine regengine_T;
typedef struct regprog
{
    regengine_T *engine;
    unsigned regflags;
    unsigned re_engine;
    unsigned re_flags;
} regprog_T;
typedef struct
{
    regengine_T *engine;
    unsigned regflags;
    unsigned re_engine;
    unsigned re_flags;
    int regstart;
    char_u reganch;
    char_u *regmust;
    int regmlen;
    char_u reghasz;
    char_u program[1];
} bt_regprog_T;
typedef struct nfa_state nfa_state_T;
struct nfa_state
{
    int c;
    nfa_state_T *out;
    nfa_state_T *out1;
    int id;
    int lastlist[2];
    int val;
};
typedef struct
{
    regengine_T *engine;
    unsigned regflags;
    unsigned re_engine;
    unsigned re_flags;
    nfa_state_T *start;
    int reganch;
    int regstart;
    char_u *match_text;
    int has_zend;
    int has_backref;
    int reghasz;
    char_u *pattern;
    int nsubexp;
    int nstate;
    nfa_state_T state[1];
} nfa_regprog_T;
typedef struct
{
    regprog_T *regprog;
    char_u *startp[10];
    char_u *endp[10];
    int rm_ic;
} regmatch_T;
typedef struct
{
    regprog_T *regprog;
    lpos_T startpos[10];
    lpos_T endpos[10];
    int rmm_ic;
    colnr_T rmm_maxcol;
} regmmatch_T;
typedef struct
{
    short refcnt;
    char_u *matches[10];
} reg_extmatch_T;
struct regengine
{
    regprog_T *(*regcomp)(char_u*, int);
    void (*regfree)(regprog_T *);
    int (*regexec_nl)(regmatch_T *, char_u *, colnr_T, int);
    long (*regexec_multi)(regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
};
typedef unsigned long XID;
typedef unsigned long Mask;
typedef unsigned long Atom;
typedef unsigned long VisualID;
typedef unsigned long Time;
typedef XID Window;
typedef XID Drawable;
typedef XID Font;
typedef XID Pixmap;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;
typedef unsigned char KeyCode;
extern int
_Xmblen(
    char *str,
    int len
    );
typedef char *XPointer;
typedef struct _XExtData {
 int number;
 struct _XExtData *next;
 int (*free_private)(
 struct _XExtData *extension
 );
 XPointer private_data;
} XExtData;
typedef struct {
 int extension;
 int major_opcode;
 int first_event;
 int first_error;
} XExtCodes;
typedef struct {
    int depth;
    int bits_per_pixel;
    int scanline_pad;
} XPixmapFormatValues;
typedef struct {
 int function;
 unsigned long plane_mask;
 unsigned long foreground;
 unsigned long background;
 int line_width;
 int line_style;
 int cap_style;
 int join_style;
 int fill_style;
 int fill_rule;
 int arc_mode;
 Pixmap tile;
 Pixmap stipple;
 int ts_x_origin;
 int ts_y_origin;
        Font font;
 int subwindow_mode;
 int graphics_exposures;
 int clip_x_origin;
 int clip_y_origin;
 Pixmap clip_mask;
 int dash_offset;
 char dashes;
} XGCValues;
typedef struct _XGC
*GC;
typedef struct {
 XExtData *ext_data;
 VisualID visualid;
 int class;
 unsigned long red_mask, green_mask, blue_mask;
 int bits_per_rgb;
 int map_entries;
} Visual;
typedef struct {
 int depth;
 int nvisuals;
 Visual *visuals;
} Depth;
struct _XDisplay;
typedef struct {
 XExtData *ext_data;
 struct _XDisplay *display;
 Window root;
 int width, height;
 int mwidth, mheight;
 int ndepths;
 Depth *depths;
 int root_depth;
 Visual *root_visual;
 GC default_gc;
 Colormap cmap;
 unsigned long white_pixel;
 unsigned long black_pixel;
 int max_maps, min_maps;
 int backing_store;
 int save_unders;
 long root_input_mask;
} Screen;
typedef struct {
 XExtData *ext_data;
 int depth;
 int bits_per_pixel;
 int scanline_pad;
} ScreenFormat;
typedef struct {
    Pixmap background_pixmap;
    unsigned long background_pixel;
    Pixmap border_pixmap;
    unsigned long border_pixel;
    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    long event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Colormap colormap;
    Cursor cursor;
} XSetWindowAttributes;
typedef struct {
    int x, y;
    int width, height;
    int border_width;
    int depth;
    Visual *visual;
    Window root;
    int class;
    int bit_gravity;
    int win_gravity;
    int backing_store;
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;
    Colormap colormap;
    int map_installed;
    int map_state;
    long all_event_masks;
    long your_event_mask;
    long do_not_propagate_mask;
    int override_redirect;
    Screen *screen;
} XWindowAttributes;
typedef struct {
 int family;
 int length;
 char *address;
} XHostAddress;
typedef struct {
 int typelength;
 int valuelength;
 char *type;
 char *value;
} XServerInterpretedAddress;
typedef struct _XImage {
    int width, height;
    int xoffset;
    int format;
    char *data;
    int byte_order;
    int bitmap_unit;
    int bitmap_bit_order;
    int bitmap_pad;
    int depth;
    int bytes_per_line;
    int bits_per_pixel;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    XPointer obdata;
    struct funcs {
 struct _XImage *(*create_image)(
  struct _XDisplay* ,
  Visual* ,
  unsigned int ,
  int ,
  int ,
  char* ,
  unsigned int ,
  unsigned int ,
  int ,
  int );
 int (*destroy_image) (struct _XImage *);
 unsigned long (*get_pixel) (struct _XImage *, int, int);
 int (*put_pixel) (struct _XImage *, int, int, unsigned long);
 struct _XImage *(*sub_image)(struct _XImage *, int, int, unsigned int, unsigned int);
 int (*add_pixel) (struct _XImage *, long);
 } f;
} XImage;
typedef struct {
    int x, y;
    int width, height;
    int border_width;
    Window sibling;
    int stack_mode;
} XWindowChanges;
typedef struct {
 unsigned long pixel;
 unsigned short red, green, blue;
 char flags;
 char pad;
} XColor;
typedef struct {
    short x1, y1, x2, y2;
} XSegment;
typedef struct {
    short x, y;
} XPoint;
typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;
typedef struct {
    short x, y;
    unsigned short width, height;
    short angle1, angle2;
} XArc;
typedef struct {
        int key_click_percent;
        int bell_percent;
        int bell_pitch;
        int bell_duration;
        int led;
        int led_mode;
        int key;
        int auto_repeat_mode;
} XKeyboardControl;
typedef struct {
        int key_click_percent;
 int bell_percent;
 unsigned int bell_pitch, bell_duration;
 unsigned long led_mask;
 int global_auto_repeat;
 char auto_repeats[32];
} XKeyboardState;
typedef struct {
        Time time;
 short x, y;
} XTimeCoord;
typedef struct {
  int max_keypermod;
  KeyCode *modifiermap;
} XModifierKeymap;
typedef struct _XDisplay Display;
struct _XPrivate;
struct _XrmHashBucketRec;
typedef struct
{
 XExtData *ext_data;
 struct _XPrivate *private1;
 int fd;
 int private2;
 int proto_major_version;
 int proto_minor_version;
 char *vendor;
        XID private3;
 XID private4;
 XID private5;
 int private6;
 XID (*resource_alloc)(
  struct _XDisplay*
 );
 int byte_order;
 int bitmap_unit;
 int bitmap_pad;
 int bitmap_bit_order;
 int nformats;
 ScreenFormat *pixmap_format;
 int private8;
 int release;
 struct _XPrivate *private9, *private10;
 int qlen;
 unsigned long last_request_read;
 unsigned long request;
 XPointer private11;
 XPointer private12;
 XPointer private13;
 XPointer private14;
 unsigned max_request_size;
 struct _XrmHashBucketRec *db;
 int (*private15)(
  struct _XDisplay*
  );
 char *display_name;
 int default_screen;
 int nscreens;
 Screen *screens;
 unsigned long motion_buffer;
 unsigned long private16;
 int min_keycode;
 int max_keycode;
 XPointer private17;
 XPointer private18;
 int private19;
 char *xdefaults;
}
*_XPrivDisplay;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int keycode;
 int same_screen;
} XKeyEvent;
typedef XKeyEvent XKeyPressedEvent;
typedef XKeyEvent XKeyReleasedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 unsigned int button;
 int same_screen;
} XButtonEvent;
typedef XButtonEvent XButtonPressedEvent;
typedef XButtonEvent XButtonReleasedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 unsigned int state;
 char is_hint;
 int same_screen;
} XMotionEvent;
typedef XMotionEvent XPointerMovedEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Window root;
 Window subwindow;
 Time time;
 int x, y;
 int x_root, y_root;
 int mode;
 int detail;
 int same_screen;
 int focus;
 unsigned int state;
} XCrossingEvent;
typedef XCrossingEvent XEnterWindowEvent;
typedef XCrossingEvent XLeaveWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int mode;
 int detail;
} XFocusChangeEvent;
typedef XFocusChangeEvent XFocusInEvent;
typedef XFocusChangeEvent XFocusOutEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 char key_vector[32];
} XKeymapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int x, y;
 int width, height;
 int count;
} XExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int x, y;
 int width, height;
 int count;
 int major_code;
 int minor_code;
} XGraphicsExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Drawable drawable;
 int major_code;
 int minor_code;
} XNoExposeEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int state;
} XVisibilityEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 int override_redirect;
} XCreateWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
} XDestroyWindowEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int from_configure;
} XUnmapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int override_redirect;
} XMapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
} XMapRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 Window parent;
 int x, y;
 int override_redirect;
} XReparentEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int override_redirect;
} XConfigureEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int x, y;
} XGravityEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int width, height;
} XResizeRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int x, y;
 int width, height;
 int border_width;
 Window above;
 int detail;
 unsigned long value_mask;
} XConfigureRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window event;
 Window window;
 int place;
} XCirculateEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window parent;
 Window window;
 int place;
} XCirculateRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom atom;
 Time time;
 int state;
} XPropertyEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom selection;
 Time time;
} XSelectionClearEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window owner;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionRequestEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window requestor;
 Atom selection;
 Atom target;
 Atom property;
 Time time;
} XSelectionEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Colormap colormap;
 int new;
 int state;
} XColormapEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 Atom message_type;
 int format;
 union {
  char b[20];
  short s[10];
  long l[5];
  } data;
} XClientMessageEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
 int request;
 int first_keycode;
 int count;
} XMappingEvent;
typedef struct {
 int type;
 Display *display;
 XID resourceid;
 unsigned long serial;
 unsigned char error_code;
 unsigned char request_code;
 unsigned char minor_code;
} XErrorEvent;
typedef struct {
 int type;
 unsigned long serial;
 int send_event;
 Display *display;
 Window window;
} XAnyEvent;
typedef struct
    {
    int type;
    unsigned long serial;
    int send_event;
    Display *display;
    int extension;
    int evtype;
    } XGenericEvent;
typedef struct {
    int type;
    unsigned long serial;
    int send_event;
    Display *display;
    int extension;
    int evtype;
    unsigned int cookie;
    void *data;
} XGenericEventCookie;
typedef union _XEvent {
        int type;
 XAnyEvent xany;
 XKeyEvent xkey;
 XButtonEvent xbutton;
 XMotionEvent xmotion;
 XCrossingEvent xcrossing;
 XFocusChangeEvent xfocus;
 XExposeEvent xexpose;
 XGraphicsExposeEvent xgraphicsexpose;
 XNoExposeEvent xnoexpose;
 XVisibilityEvent xvisibility;
 XCreateWindowEvent xcreatewindow;
 XDestroyWindowEvent xdestroywindow;
 XUnmapEvent xunmap;
 XMapEvent xmap;
 XMapRequestEvent xmaprequest;
 XReparentEvent xreparent;
 XConfigureEvent xconfigure;
 XGravityEvent xgravity;
 XResizeRequestEvent xresizerequest;
 XConfigureRequestEvent xconfigurerequest;
 XCirculateEvent xcirculate;
 XCirculateRequestEvent xcirculaterequest;
 XPropertyEvent xproperty;
 XSelectionClearEvent xselectionclear;
 XSelectionRequestEvent xselectionrequest;
 XSelectionEvent xselection;
 XColormapEvent xcolormap;
 XClientMessageEvent xclient;
 XMappingEvent xmapping;
 XErrorEvent xerror;
 XKeymapEvent xkeymap;
 XGenericEvent xgeneric;
 XGenericEventCookie xcookie;
 long pad[24];
} XEvent;
typedef struct {
    short lbearing;
    short rbearing;
    short width;
    short ascent;
    short descent;
    unsigned short attributes;
} XCharStruct;
typedef struct {
    Atom name;
    unsigned long card32;
} XFontProp;
typedef struct {
    XExtData *ext_data;
    Font fid;
    unsigned direction;
    unsigned min_char_or_byte2;
    unsigned max_char_or_byte2;
    unsigned min_byte1;
    unsigned max_byte1;
    int all_chars_exist;
    unsigned default_char;
    int n_properties;
    XFontProp *properties;
    XCharStruct min_bounds;
    XCharStruct max_bounds;
    XCharStruct *per_char;
    int ascent;
    int descent;
} XFontStruct;
typedef struct {
    char *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem;
typedef struct {
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;
typedef struct {
    XChar2b *chars;
    int nchars;
    int delta;
    Font font;
} XTextItem16;
typedef union { Display *display;
  GC gc;
  Visual *visual;
  Screen *screen;
  ScreenFormat *pixmap_format;
  XFontStruct *font; } XEDataObject;
typedef struct {
    XRectangle max_ink_extent;
    XRectangle max_logical_extent;
} XFontSetExtents;
typedef struct _XOM *XOM;
typedef struct _XOC *XOC, *XFontSet;
typedef struct {
    char *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XmbTextItem;
typedef struct {
    wchar_t *chars;
    int nchars;
    int delta;
    XFontSet font_set;
} XwcTextItem;
typedef struct {
    int charset_count;
    char **charset_list;
} XOMCharSetList;
typedef enum {
    XOMOrientation_LTR_TTB,
    XOMOrientation_RTL_TTB,
    XOMOrientation_TTB_LTR,
    XOMOrientation_TTB_RTL,
    XOMOrientation_Context
} XOrientation;
typedef struct {
    int num_orientation;
    XOrientation *orientation;
} XOMOrientation;
typedef struct {
    int num_font;
    XFontStruct **font_struct_list;
    char **font_name_list;
} XOMFontInfo;
typedef struct _XIM *XIM;
typedef struct _XIC *XIC;
typedef void (*XIMProc)(
    XIM,
    XPointer,
    XPointer
);
typedef int (*XICProc)(
    XIC,
    XPointer,
    XPointer
);
typedef void (*XIDProc)(
    Display*,
    XPointer,
    XPointer
);
typedef unsigned long XIMStyle;
typedef struct {
    unsigned short count_styles;
    XIMStyle *supported_styles;
} XIMStyles;
typedef void *XVaNestedList;
typedef struct {
    XPointer client_data;
    XIMProc callback;
} XIMCallback;
typedef struct {
    XPointer client_data;
    XICProc callback;
} XICCallback;
typedef unsigned long XIMFeedback;
typedef struct _XIMText {
    unsigned short length;
    XIMFeedback *feedback;
    int encoding_is_wchar;
    union {
 char *multi_byte;
 wchar_t *wide_char;
    } string;
} XIMText;
typedef unsigned long XIMPreeditState;
typedef struct _XIMPreeditStateNotifyCallbackStruct {
    XIMPreeditState state;
} XIMPreeditStateNotifyCallbackStruct;
typedef unsigned long XIMResetState;
typedef unsigned long XIMStringConversionFeedback;
typedef struct _XIMStringConversionText {
    unsigned short length;
    XIMStringConversionFeedback *feedback;
    int encoding_is_wchar;
    union {
 char *mbs;
 wchar_t *wcs;
    } string;
} XIMStringConversionText;
typedef unsigned short XIMStringConversionPosition;
typedef unsigned short XIMStringConversionType;
typedef unsigned short XIMStringConversionOperation;
typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd,
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;
typedef struct _XIMStringConversionCallbackStruct {
    XIMStringConversionPosition position;
    XIMCaretDirection direction;
    XIMStringConversionOperation operation;
    unsigned short factor;
    XIMStringConversionText *text;
} XIMStringConversionCallbackStruct;
typedef struct _XIMPreeditDrawCallbackStruct {
    int caret;
    int chg_first;
    int chg_length;
    XIMText *text;
} XIMPreeditDrawCallbackStruct;
typedef enum {
    XIMIsInvisible,
    XIMIsPrimary,
    XIMIsSecondary
} XIMCaretStyle;
typedef struct _XIMPreeditCaretCallbackStruct {
    int position;
    XIMCaretDirection direction;
    XIMCaretStyle style;
} XIMPreeditCaretCallbackStruct;
typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;
typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
 XIMText *text;
 Pixmap bitmap;
    } data;
} XIMStatusDrawCallbackStruct;
typedef struct _XIMHotKeyTrigger {
    KeySym keysym;
    int modifier;
    int modifier_mask;
} XIMHotKeyTrigger;
typedef struct _XIMHotKeyTriggers {
    int num_hot_key;
    XIMHotKeyTrigger *key;
} XIMHotKeyTriggers;
typedef unsigned long XIMHotKeyState;
typedef struct {
    unsigned short count_values;
    char **supported_values;
} XIMValuesList;

extern int _Xdebug;
extern XFontStruct *XLoadQueryFont(
    Display* ,
    const char*
);
extern XFontStruct *XQueryFont(
    Display* ,
    XID
);
extern XTimeCoord *XGetMotionEvents(
    Display* ,
    Window ,
    Time ,
    Time ,
    int*
);
extern XModifierKeymap *XDeleteModifiermapEntry(
    XModifierKeymap* ,
    KeyCode ,
    int
);
extern XModifierKeymap *XGetModifierMapping(
    Display*
);
extern XModifierKeymap *XInsertModifiermapEntry(
    XModifierKeymap* ,
    KeyCode ,
    int
);
extern XModifierKeymap *XNewModifiermap(
    int
);
extern XImage *XCreateImage(
    Display* ,
    Visual* ,
    unsigned int ,
    int ,
    int ,
    char* ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XInitImage(
    XImage*
);
extern XImage *XGetImage(
    Display* ,
    Drawable ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    int
);
extern XImage *XGetSubImage(
    Display* ,
    Drawable ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    int ,
    XImage* ,
    int ,
    int
);
extern Display *XOpenDisplay(
    const char*
);
extern void XrmInitialize(
    void
);
extern char *XFetchBytes(
    Display* ,
    int*
);
extern char *XFetchBuffer(
    Display* ,
    int* ,
    int
);
extern char *XGetAtomName(
    Display* ,
    Atom
);
extern int XGetAtomNames(
    Display* ,
    Atom* ,
    int ,
    char**
);
extern char *XGetDefault(
    Display* ,
    const char* ,
    const char*
);
extern char *XDisplayName(
    const char*
);
extern char *XKeysymToString(
    KeySym
);
extern int (*XSynchronize(
    Display* ,
    int
))(
    Display*
);
extern int (*XSetAfterFunction(
    Display* ,
    int (*) (
      Display*
            )
))(
    Display*
);
extern Atom XInternAtom(
    Display* ,
    const char* ,
    int
);
extern int XInternAtoms(
    Display* ,
    char** ,
    int ,
    int ,
    Atom*
);
extern Colormap XCopyColormapAndFree(
    Display* ,
    Colormap
);
extern Colormap XCreateColormap(
    Display* ,
    Window ,
    Visual* ,
    int
);
extern Cursor XCreatePixmapCursor(
    Display* ,
    Pixmap ,
    Pixmap ,
    XColor* ,
    XColor* ,
    unsigned int ,
    unsigned int
);
extern Cursor XCreateGlyphCursor(
    Display* ,
    Font ,
    Font ,
    unsigned int ,
    unsigned int ,
    XColor const * ,
    XColor const *
);
extern Cursor XCreateFontCursor(
    Display* ,
    unsigned int
);
extern Font XLoadFont(
    Display* ,
    const char*
);
extern GC XCreateGC(
    Display* ,
    Drawable ,
    unsigned long ,
    XGCValues*
);
extern GContext XGContextFromGC(
    GC
);
extern void XFlushGC(
    Display* ,
    GC
);
extern Pixmap XCreatePixmap(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int
);
extern Pixmap XCreateBitmapFromData(
    Display* ,
    Drawable ,
    const char* ,
    unsigned int ,
    unsigned int
);
extern Pixmap XCreatePixmapFromBitmapData(
    Display* ,
    Drawable ,
    char* ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    unsigned long ,
    unsigned int
);
extern Window XCreateSimpleWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    unsigned long ,
    unsigned long
);
extern Window XGetSelectionOwner(
    Display* ,
    Atom
);
extern Window XCreateWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    int ,
    unsigned int ,
    Visual* ,
    unsigned long ,
    XSetWindowAttributes*
);
extern Colormap *XListInstalledColormaps(
    Display* ,
    Window ,
    int*
);
extern char **XListFonts(
    Display* ,
    const char* ,
    int ,
    int*
);
extern char **XListFontsWithInfo(
    Display* ,
    const char* ,
    int ,
    int* ,
    XFontStruct**
);
extern char **XGetFontPath(
    Display* ,
    int*
);
extern char **XListExtensions(
    Display* ,
    int*
);
extern Atom *XListProperties(
    Display* ,
    Window ,
    int*
);
extern XHostAddress *XListHosts(
    Display* ,
    int* ,
    int*
);
__attribute__((deprecated))
extern KeySym XKeycodeToKeysym(
    Display* ,
    KeyCode ,
    int
);
extern KeySym XLookupKeysym(
    XKeyEvent* ,
    int
);
extern KeySym *XGetKeyboardMapping(
    Display* ,
    KeyCode ,
    int ,
    int*
);
extern KeySym XStringToKeysym(
    const char*
);
extern long XMaxRequestSize(
    Display*
);
extern long XExtendedMaxRequestSize(
    Display*
);
extern char *XResourceManagerString(
    Display*
);
extern char *XScreenResourceString(
 Screen*
);
extern unsigned long XDisplayMotionBufferSize(
    Display*
);
extern VisualID XVisualIDFromVisual(
    Visual*
);
extern int XInitThreads(
    void
);
extern void XLockDisplay(
    Display*
);
extern void XUnlockDisplay(
    Display*
);
extern XExtCodes *XInitExtension(
    Display* ,
    const char*
);
extern XExtCodes *XAddExtension(
    Display*
);
extern XExtData *XFindOnExtensionList(
    XExtData** ,
    int
);
extern XExtData **XEHeadOfExtensionList(
    XEDataObject
);
extern Window XRootWindow(
    Display* ,
    int
);
extern Window XDefaultRootWindow(
    Display*
);
extern Window XRootWindowOfScreen(
    Screen*
);
extern Visual *XDefaultVisual(
    Display* ,
    int
);
extern Visual *XDefaultVisualOfScreen(
    Screen*
);
extern GC XDefaultGC(
    Display* ,
    int
);
extern GC XDefaultGCOfScreen(
    Screen*
);
extern unsigned long XBlackPixel(
    Display* ,
    int
);
extern unsigned long XWhitePixel(
    Display* ,
    int
);
extern unsigned long XAllPlanes(
    void
);
extern unsigned long XBlackPixelOfScreen(
    Screen*
);
extern unsigned long XWhitePixelOfScreen(
    Screen*
);
extern unsigned long XNextRequest(
    Display*
);
extern unsigned long XLastKnownRequestProcessed(
    Display*
);
extern char *XServerVendor(
    Display*
);
extern char *XDisplayString(
    Display*
);
extern Colormap XDefaultColormap(
    Display* ,
    int
);
extern Colormap XDefaultColormapOfScreen(
    Screen*
);
extern Display *XDisplayOfScreen(
    Screen*
);
extern Screen *XScreenOfDisplay(
    Display* ,
    int
);
extern Screen *XDefaultScreenOfDisplay(
    Display*
);
extern long XEventMaskOfScreen(
    Screen*
);
extern int XScreenNumberOfScreen(
    Screen*
);
typedef int (*XErrorHandler) (
    Display* ,
    XErrorEvent*
);
extern XErrorHandler XSetErrorHandler (
    XErrorHandler
);
typedef int (*XIOErrorHandler) (
    Display*
);
extern XIOErrorHandler XSetIOErrorHandler (
    XIOErrorHandler
);
extern XPixmapFormatValues *XListPixmapFormats(
    Display* ,
    int*
);
extern int *XListDepths(
    Display* ,
    int ,
    int*
);
extern int XReconfigureWMWindow(
    Display* ,
    Window ,
    int ,
    unsigned int ,
    XWindowChanges*
);
extern int XGetWMProtocols(
    Display* ,
    Window ,
    Atom** ,
    int*
);
extern int XSetWMProtocols(
    Display* ,
    Window ,
    Atom* ,
    int
);
extern int XIconifyWindow(
    Display* ,
    Window ,
    int
);
extern int XWithdrawWindow(
    Display* ,
    Window ,
    int
);
extern int XGetCommand(
    Display* ,
    Window ,
    char*** ,
    int*
);
extern int XGetWMColormapWindows(
    Display* ,
    Window ,
    Window** ,
    int*
);
extern int XSetWMColormapWindows(
    Display* ,
    Window ,
    Window* ,
    int
);
extern void XFreeStringList(
    char**
);
extern int XSetTransientForHint(
    Display* ,
    Window ,
    Window
);
extern int XActivateScreenSaver(
    Display*
);
extern int XAddHost(
    Display* ,
    XHostAddress*
);
extern int XAddHosts(
    Display* ,
    XHostAddress* ,
    int
);
extern int XAddToExtensionList(
    struct _XExtData** ,
    XExtData*
);
extern int XAddToSaveSet(
    Display* ,
    Window
);
extern int XAllocColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XAllocColorCells(
    Display* ,
    Colormap ,
    int ,
    unsigned long* ,
    unsigned int ,
    unsigned long* ,
    unsigned int
);
extern int XAllocColorPlanes(
    Display* ,
    Colormap ,
    int ,
    unsigned long* ,
    int ,
    int ,
    int ,
    int ,
    unsigned long* ,
    unsigned long* ,
    unsigned long*
);
extern int XAllocNamedColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor* ,
    XColor*
);
extern int XAllowEvents(
    Display* ,
    int ,
    Time
);
extern int XAutoRepeatOff(
    Display*
);
extern int XAutoRepeatOn(
    Display*
);
extern int XBell(
    Display* ,
    int
);
extern int XBitmapBitOrder(
    Display*
);
extern int XBitmapPad(
    Display*
);
extern int XBitmapUnit(
    Display*
);
extern int XCellsOfScreen(
    Screen*
);
extern int XChangeActivePointerGrab(
    Display* ,
    unsigned int ,
    Cursor ,
    Time
);
extern int XChangeGC(
    Display* ,
    GC ,
    unsigned long ,
    XGCValues*
);
extern int XChangeKeyboardControl(
    Display* ,
    unsigned long ,
    XKeyboardControl*
);
extern int XChangeKeyboardMapping(
    Display* ,
    int ,
    int ,
    KeySym* ,
    int
);
extern int XChangePointerControl(
    Display* ,
    int ,
    int ,
    int ,
    int ,
    int
);
extern int XChangeProperty(
    Display* ,
    Window ,
    Atom ,
    Atom ,
    int ,
    int ,
    const unsigned char* ,
    int
);
extern int XChangeSaveSet(
    Display* ,
    Window ,
    int
);
extern int XChangeWindowAttributes(
    Display* ,
    Window ,
    unsigned long ,
    XSetWindowAttributes*
);
extern int XCheckIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XCheckMaskEvent(
    Display* ,
    long ,
    XEvent*
);
extern int XCheckTypedEvent(
    Display* ,
    int ,
    XEvent*
);
extern int XCheckTypedWindowEvent(
    Display* ,
    Window ,
    int ,
    XEvent*
);
extern int XCheckWindowEvent(
    Display* ,
    Window ,
    long ,
    XEvent*
);
extern int XCirculateSubwindows(
    Display* ,
    Window ,
    int
);
extern int XCirculateSubwindowsDown(
    Display* ,
    Window
);
extern int XCirculateSubwindowsUp(
    Display* ,
    Window
);
extern int XClearArea(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int
);
extern int XClearWindow(
    Display* ,
    Window
);
extern int XCloseDisplay(
    Display*
);
extern int XConfigureWindow(
    Display* ,
    Window ,
    unsigned int ,
    XWindowChanges*
);
extern int XConnectionNumber(
    Display*
);
extern int XConvertSelection(
    Display* ,
    Atom ,
    Atom ,
    Atom ,
    Window ,
    Time
);
extern int XCopyArea(
    Display* ,
    Drawable ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XCopyGC(
    Display* ,
    GC ,
    unsigned long ,
    GC
);
extern int XCopyPlane(
    Display* ,
    Drawable ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int ,
    unsigned long
);
extern int XDefaultDepth(
    Display* ,
    int
);
extern int XDefaultDepthOfScreen(
    Screen*
);
extern int XDefaultScreen(
    Display*
);
extern int XDefineCursor(
    Display* ,
    Window ,
    Cursor
);
extern int XDeleteProperty(
    Display* ,
    Window ,
    Atom
);
extern int XDestroyWindow(
    Display* ,
    Window
);
extern int XDestroySubwindows(
    Display* ,
    Window
);
extern int XDoesBackingStore(
    Screen*
);
extern int XDoesSaveUnders(
    Screen*
);
extern int XDisableAccessControl(
    Display*
);
extern int XDisplayCells(
    Display* ,
    int
);
extern int XDisplayHeight(
    Display* ,
    int
);
extern int XDisplayHeightMM(
    Display* ,
    int
);
extern int XDisplayKeycodes(
    Display* ,
    int* ,
    int*
);
extern int XDisplayPlanes(
    Display* ,
    int
);
extern int XDisplayWidth(
    Display* ,
    int
);
extern int XDisplayWidthMM(
    Display* ,
    int
);
extern int XDrawArc(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XDrawArcs(
    Display* ,
    Drawable ,
    GC ,
    XArc* ,
    int
);
extern int XDrawImageString(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern int XDrawImageString16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const XChar2b* ,
    int
);
extern int XDrawLine(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    int ,
    int
);
extern int XDrawLines(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int
);
extern int XDrawPoint(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int
);
extern int XDrawPoints(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int
);
extern int XDrawRectangle(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XDrawRectangles(
    Display* ,
    Drawable ,
    GC ,
    XRectangle* ,
    int
);
extern int XDrawSegments(
    Display* ,
    Drawable ,
    GC ,
    XSegment* ,
    int
);
extern int XDrawString(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern int XDrawString16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    const XChar2b* ,
    int
);
extern int XDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XTextItem* ,
    int
);
extern int XDrawText16(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XTextItem16* ,
    int
);
extern int XEnableAccessControl(
    Display*
);
extern int XEventsQueued(
    Display* ,
    int
);
extern int XFetchName(
    Display* ,
    Window ,
    char**
);
extern int XFillArc(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XFillArcs(
    Display* ,
    Drawable ,
    GC ,
    XArc* ,
    int
);
extern int XFillPolygon(
    Display* ,
    Drawable ,
    GC ,
    XPoint* ,
    int ,
    int ,
    int
);
extern int XFillRectangle(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XFillRectangles(
    Display* ,
    Drawable ,
    GC ,
    XRectangle* ,
    int
);
extern int XFlush(
    Display*
);
extern int XForceScreenSaver(
    Display* ,
    int
);
extern int XFree(
    void*
);
extern int XFreeColormap(
    Display* ,
    Colormap
);
extern int XFreeColors(
    Display* ,
    Colormap ,
    unsigned long* ,
    int ,
    unsigned long
);
extern int XFreeCursor(
    Display* ,
    Cursor
);
extern int XFreeExtensionList(
    char**
);
extern int XFreeFont(
    Display* ,
    XFontStruct*
);
extern int XFreeFontInfo(
    char** ,
    XFontStruct* ,
    int
);
extern int XFreeFontNames(
    char**
);
extern int XFreeFontPath(
    char**
);
extern int XFreeGC(
    Display* ,
    GC
);
extern int XFreeModifiermap(
    XModifierKeymap*
);
extern int XFreePixmap(
    Display* ,
    Pixmap
);
extern int XGeometry(
    Display* ,
    int ,
    const char* ,
    const char* ,
    unsigned int ,
    unsigned int ,
    unsigned int ,
    int ,
    int ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XGetErrorDatabaseText(
    Display* ,
    const char* ,
    const char* ,
    const char* ,
    char* ,
    int
);
extern int XGetErrorText(
    Display* ,
    int ,
    char* ,
    int
);
extern int XGetFontProperty(
    XFontStruct* ,
    Atom ,
    unsigned long*
);
extern int XGetGCValues(
    Display* ,
    GC ,
    unsigned long ,
    XGCValues*
);
extern int XGetGeometry(
    Display* ,
    Drawable ,
    Window* ,
    int* ,
    int* ,
    unsigned int* ,
    unsigned int* ,
    unsigned int* ,
    unsigned int*
);
extern int XGetIconName(
    Display* ,
    Window ,
    char**
);
extern int XGetInputFocus(
    Display* ,
    Window* ,
    int*
);
extern int XGetKeyboardControl(
    Display* ,
    XKeyboardState*
);
extern int XGetPointerControl(
    Display* ,
    int* ,
    int* ,
    int*
);
extern int XGetPointerMapping(
    Display* ,
    unsigned char* ,
    int
);
extern int XGetScreenSaver(
    Display* ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XGetTransientForHint(
    Display* ,
    Window ,
    Window*
);
extern int XGetWindowProperty(
    Display* ,
    Window ,
    Atom ,
    long ,
    long ,
    int ,
    Atom ,
    Atom* ,
    int* ,
    unsigned long* ,
    unsigned long* ,
    unsigned char**
);
extern int XGetWindowAttributes(
    Display* ,
    Window ,
    XWindowAttributes*
);
extern int XGrabButton(
    Display* ,
    unsigned int ,
    unsigned int ,
    Window ,
    int ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor
);
extern int XGrabKey(
    Display* ,
    int ,
    unsigned int ,
    Window ,
    int ,
    int ,
    int
);
extern int XGrabKeyboard(
    Display* ,
    Window ,
    int ,
    int ,
    int ,
    Time
);
extern int XGrabPointer(
    Display* ,
    Window ,
    int ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor ,
    Time
);
extern int XGrabServer(
    Display*
);
extern int XHeightMMOfScreen(
    Screen*
);
extern int XHeightOfScreen(
    Screen*
);
extern int XIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XImageByteOrder(
    Display*
);
extern int XInstallColormap(
    Display* ,
    Colormap
);
extern KeyCode XKeysymToKeycode(
    Display* ,
    KeySym
);
extern int XKillClient(
    Display* ,
    XID
);
extern int XLookupColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor* ,
    XColor*
);
extern int XLowerWindow(
    Display* ,
    Window
);
extern int XMapRaised(
    Display* ,
    Window
);
extern int XMapSubwindows(
    Display* ,
    Window
);
extern int XMapWindow(
    Display* ,
    Window
);
extern int XMaskEvent(
    Display* ,
    long ,
    XEvent*
);
extern int XMaxCmapsOfScreen(
    Screen*
);
extern int XMinCmapsOfScreen(
    Screen*
);
extern int XMoveResizeWindow(
    Display* ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XMoveWindow(
    Display* ,
    Window ,
    int ,
    int
);
extern int XNextEvent(
    Display* ,
    XEvent*
);
extern int XNoOp(
    Display*
);
extern int XParseColor(
    Display* ,
    Colormap ,
    const char* ,
    XColor*
);
extern int XParseGeometry(
    const char* ,
    int* ,
    int* ,
    unsigned int* ,
    unsigned int*
);
extern int XPeekEvent(
    Display* ,
    XEvent*
);
extern int XPeekIfEvent(
    Display* ,
    XEvent* ,
    int (*) (
        Display* ,
               XEvent* ,
               XPointer
             ) ,
    XPointer
);
extern int XPending(
    Display*
);
extern int XPlanesOfScreen(
    Screen*
);
extern int XProtocolRevision(
    Display*
);
extern int XProtocolVersion(
    Display*
);
extern int XPutBackEvent(
    Display* ,
    XEvent*
);
extern int XPutImage(
    Display* ,
    Drawable ,
    GC ,
    XImage* ,
    int ,
    int ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XQLength(
    Display*
);
extern int XQueryBestCursor(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestSize(
    Display* ,
    int ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestStipple(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryBestTile(
    Display* ,
    Drawable ,
    unsigned int ,
    unsigned int ,
    unsigned int* ,
    unsigned int*
);
extern int XQueryColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XQueryColors(
    Display* ,
    Colormap ,
    XColor* ,
    int
);
extern int XQueryExtension(
    Display* ,
    const char* ,
    int* ,
    int* ,
    int*
);
extern int XQueryKeymap(
    Display* ,
    char [32]
);
extern int XQueryPointer(
    Display* ,
    Window ,
    Window* ,
    Window* ,
    int* ,
    int* ,
    int* ,
    int* ,
    unsigned int*
);
extern int XQueryTextExtents(
    Display* ,
    XID ,
    const char* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XQueryTextExtents16(
    Display* ,
    XID ,
    const XChar2b* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XQueryTree(
    Display* ,
    Window ,
    Window* ,
    Window* ,
    Window** ,
    unsigned int*
);
extern int XRaiseWindow(
    Display* ,
    Window
);
extern int XReadBitmapFile(
    Display* ,
    Drawable ,
    const char* ,
    unsigned int* ,
    unsigned int* ,
    Pixmap* ,
    int* ,
    int*
);
extern int XReadBitmapFileData(
    const char* ,
    unsigned int* ,
    unsigned int* ,
    unsigned char** ,
    int* ,
    int*
);
extern int XRebindKeysym(
    Display* ,
    KeySym ,
    KeySym* ,
    int ,
    const unsigned char* ,
    int
);
extern int XRecolorCursor(
    Display* ,
    Cursor ,
    XColor* ,
    XColor*
);
extern int XRefreshKeyboardMapping(
    XMappingEvent*
);
extern int XRemoveFromSaveSet(
    Display* ,
    Window
);
extern int XRemoveHost(
    Display* ,
    XHostAddress*
);
extern int XRemoveHosts(
    Display* ,
    XHostAddress* ,
    int
);
extern int XReparentWindow(
    Display* ,
    Window ,
    Window ,
    int ,
    int
);
extern int XResetScreenSaver(
    Display*
);
extern int XResizeWindow(
    Display* ,
    Window ,
    unsigned int ,
    unsigned int
);
extern int XRestackWindows(
    Display* ,
    Window* ,
    int
);
extern int XRotateBuffers(
    Display* ,
    int
);
extern int XRotateWindowProperties(
    Display* ,
    Window ,
    Atom* ,
    int ,
    int
);
extern int XScreenCount(
    Display*
);
extern int XSelectInput(
    Display* ,
    Window ,
    long
);
extern int XSendEvent(
    Display* ,
    Window ,
    int ,
    long ,
    XEvent*
);
extern int XSetAccessControl(
    Display* ,
    int
);
extern int XSetArcMode(
    Display* ,
    GC ,
    int
);
extern int XSetBackground(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetClipMask(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetClipOrigin(
    Display* ,
    GC ,
    int ,
    int
);
extern int XSetClipRectangles(
    Display* ,
    GC ,
    int ,
    int ,
    XRectangle* ,
    int ,
    int
);
extern int XSetCloseDownMode(
    Display* ,
    int
);
extern int XSetCommand(
    Display* ,
    Window ,
    char** ,
    int
);
extern int XSetDashes(
    Display* ,
    GC ,
    int ,
    const char* ,
    int
);
extern int XSetFillRule(
    Display* ,
    GC ,
    int
);
extern int XSetFillStyle(
    Display* ,
    GC ,
    int
);
extern int XSetFont(
    Display* ,
    GC ,
    Font
);
extern int XSetFontPath(
    Display* ,
    char** ,
    int
);
extern int XSetForeground(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetFunction(
    Display* ,
    GC ,
    int
);
extern int XSetGraphicsExposures(
    Display* ,
    GC ,
    int
);
extern int XSetIconName(
    Display* ,
    Window ,
    const char*
);
extern int XSetInputFocus(
    Display* ,
    Window ,
    int ,
    Time
);
extern int XSetLineAttributes(
    Display* ,
    GC ,
    unsigned int ,
    int ,
    int ,
    int
);
extern int XSetModifierMapping(
    Display* ,
    XModifierKeymap*
);
extern int XSetPlaneMask(
    Display* ,
    GC ,
    unsigned long
);
extern int XSetPointerMapping(
    Display* ,
    const unsigned char* ,
    int
);
extern int XSetScreenSaver(
    Display* ,
    int ,
    int ,
    int ,
    int
);
extern int XSetSelectionOwner(
    Display* ,
    Atom ,
    Window ,
    Time
);
extern int XSetState(
    Display* ,
    GC ,
    unsigned long ,
    unsigned long ,
    int ,
    unsigned long
);
extern int XSetStipple(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetSubwindowMode(
    Display* ,
    GC ,
    int
);
extern int XSetTSOrigin(
    Display* ,
    GC ,
    int ,
    int
);
extern int XSetTile(
    Display* ,
    GC ,
    Pixmap
);
extern int XSetWindowBackground(
    Display* ,
    Window ,
    unsigned long
);
extern int XSetWindowBackgroundPixmap(
    Display* ,
    Window ,
    Pixmap
);
extern int XSetWindowBorder(
    Display* ,
    Window ,
    unsigned long
);
extern int XSetWindowBorderPixmap(
    Display* ,
    Window ,
    Pixmap
);
extern int XSetWindowBorderWidth(
    Display* ,
    Window ,
    unsigned int
);
extern int XSetWindowColormap(
    Display* ,
    Window ,
    Colormap
);
extern int XStoreBuffer(
    Display* ,
    const char* ,
    int ,
    int
);
extern int XStoreBytes(
    Display* ,
    const char* ,
    int
);
extern int XStoreColor(
    Display* ,
    Colormap ,
    XColor*
);
extern int XStoreColors(
    Display* ,
    Colormap ,
    XColor* ,
    int
);
extern int XStoreName(
    Display* ,
    Window ,
    const char*
);
extern int XStoreNamedColor(
    Display* ,
    Colormap ,
    const char* ,
    unsigned long ,
    int
);
extern int XSync(
    Display* ,
    int
);
extern int XTextExtents(
    XFontStruct* ,
    const char* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XTextExtents16(
    XFontStruct* ,
    const XChar2b* ,
    int ,
    int* ,
    int* ,
    int* ,
    XCharStruct*
);
extern int XTextWidth(
    XFontStruct* ,
    const char* ,
    int
);
extern int XTextWidth16(
    XFontStruct* ,
    const XChar2b* ,
    int
);
extern int XTranslateCoordinates(
    Display* ,
    Window ,
    Window ,
    int ,
    int ,
    int* ,
    int* ,
    Window*
);
extern int XUndefineCursor(
    Display* ,
    Window
);
extern int XUngrabButton(
    Display* ,
    unsigned int ,
    unsigned int ,
    Window
);
extern int XUngrabKey(
    Display* ,
    int ,
    unsigned int ,
    Window
);
extern int XUngrabKeyboard(
    Display* ,
    Time
);
extern int XUngrabPointer(
    Display* ,
    Time
);
extern int XUngrabServer(
    Display*
);
extern int XUninstallColormap(
    Display* ,
    Colormap
);
extern int XUnloadFont(
    Display* ,
    Font
);
extern int XUnmapSubwindows(
    Display* ,
    Window
);
extern int XUnmapWindow(
    Display* ,
    Window
);
extern int XVendorRelease(
    Display*
);
extern int XWarpPointer(
    Display* ,
    Window ,
    Window ,
    int ,
    int ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XWidthMMOfScreen(
    Screen*
);
extern int XWidthOfScreen(
    Screen*
);
extern int XWindowEvent(
    Display* ,
    Window ,
    long ,
    XEvent*
);
extern int XWriteBitmapFile(
    Display* ,
    const char* ,
    Pixmap ,
    unsigned int ,
    unsigned int ,
    int ,
    int
);
extern int XSupportsLocale (void);
extern char *XSetLocaleModifiers(
    const char*
);
extern XOM XOpenOM(
    Display* ,
    struct _XrmHashBucketRec* ,
    const char* ,
    const char*
);
extern int XCloseOM(
    XOM
);
extern char *XSetOMValues(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetOMValues(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Display *XDisplayOfOM(
    XOM
);
extern char *XLocaleOfOM(
    XOM
);
extern XOC XCreateOC(
    XOM ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XDestroyOC(
    XOC
);
extern XOM XOMOfOC(
    XOC
);
extern char *XSetOCValues(
    XOC ,
    ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetOCValues(
    XOC ,
    ...
) __attribute__ ((__sentinel__(0)));
extern XFontSet XCreateFontSet(
    Display* ,
    const char* ,
    char*** ,
    int* ,
    char**
);
extern void XFreeFontSet(
    Display* ,
    XFontSet
);
extern int XFontsOfFontSet(
    XFontSet ,
    XFontStruct*** ,
    char***
);
extern char *XBaseFontNameListOfFontSet(
    XFontSet
);
extern char *XLocaleOfFontSet(
    XFontSet
);
extern int XContextDependentDrawing(
    XFontSet
);
extern int XDirectionalDependentDrawing(
    XFontSet
);
extern int XContextualDrawing(
    XFontSet
);
extern XFontSetExtents *XExtentsOfFontSet(
    XFontSet
);
extern int XmbTextEscapement(
    XFontSet ,
    const char* ,
    int
);
extern int XwcTextEscapement(
    XFontSet ,
    const wchar_t* ,
    int
);
extern int Xutf8TextEscapement(
    XFontSet ,
    const char* ,
    int
);
extern int XmbTextExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int XwcTextExtents(
    XFontSet ,
    const wchar_t* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int Xutf8TextExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle*
);
extern int XmbTextPerCharExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern int XwcTextPerCharExtents(
    XFontSet ,
    const wchar_t* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern int Xutf8TextPerCharExtents(
    XFontSet ,
    const char* ,
    int ,
    XRectangle* ,
    XRectangle* ,
    int ,
    int* ,
    XRectangle* ,
    XRectangle*
);
extern void XmbDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XmbTextItem* ,
    int
);
extern void XwcDrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XwcTextItem* ,
    int
);
extern void Xutf8DrawText(
    Display* ,
    Drawable ,
    GC ,
    int ,
    int ,
    XmbTextItem* ,
    int
);
extern void XmbDrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XwcDrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const wchar_t* ,
    int
);
extern void Xutf8DrawString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XmbDrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern void XwcDrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const wchar_t* ,
    int
);
extern void Xutf8DrawImageString(
    Display* ,
    Drawable ,
    XFontSet ,
    GC ,
    int ,
    int ,
    const char* ,
    int
);
extern XIM XOpenIM(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char*
);
extern int XCloseIM(
    XIM
);
extern char *XGetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern char *XSetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern Display *XDisplayOfIM(
    XIM
);
extern char *XLocaleOfIM(
    XIM
);
extern XIC XCreateIC(
    XIM , ...
) __attribute__ ((__sentinel__(0)));
extern void XDestroyIC(
    XIC
);
extern void XSetICFocus(
    XIC
);
extern void XUnsetICFocus(
    XIC
);
extern wchar_t *XwcResetIC(
    XIC
);
extern char *XmbResetIC(
    XIC
);
extern char *Xutf8ResetIC(
    XIC
);
extern char *XSetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));
extern char *XGetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));
extern XIM XIMOfIC(
    XIC
);
extern int XFilterEvent(
    XEvent* ,
    Window
);
extern int XmbLookupString(
    XIC ,
    XKeyPressedEvent* ,
    char* ,
    int ,
    KeySym* ,
    int*
);
extern int XwcLookupString(
    XIC ,
    XKeyPressedEvent* ,
    wchar_t* ,
    int ,
    KeySym* ,
    int*
);
extern int Xutf8LookupString(
    XIC ,
    XKeyPressedEvent* ,
    char* ,
    int ,
    KeySym* ,
    int*
);
extern XVaNestedList XVaCreateNestedList(
    int , ...
) __attribute__ ((__sentinel__(0)));
extern int XRegisterIMInstantiateCallback(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char* ,
    XIDProc ,
    XPointer
);
extern int XUnregisterIMInstantiateCallback(
    Display* ,
    struct _XrmHashBucketRec* ,
    char* ,
    char* ,
    XIDProc ,
    XPointer
);
typedef void (*XConnectionWatchProc)(
    Display* ,
    XPointer ,
    int ,
    int ,
    XPointer*
);
extern int XInternalConnectionNumbers(
    Display* ,
    int** ,
    int*
);
extern void XProcessInternalConnection(
    Display* ,
    int
);
extern int XAddConnectionWatch(
    Display* ,
    XConnectionWatchProc ,
    XPointer
);
extern void XRemoveConnectionWatch(
    Display* ,
    XConnectionWatchProc ,
    XPointer
);
extern void XSetAuthorization(
    char * ,
    int ,
    char * ,
    int
);
extern int _Xmbtowc(
    wchar_t * ,
    char * ,
    int
);
extern int _Xwctomb(
    char * ,
    wchar_t
);
extern int XGetEventData(
    Display* ,
    XGenericEventCookie*
);
extern void XFreeEventData(
    Display* ,
    XGenericEventCookie*
);

typedef struct {
     long flags;
 int x, y;
 int width, height;
 int min_width, min_height;
 int max_width, max_height;
     int width_inc, height_inc;
 struct {
  int x;
  int y;
 } min_aspect, max_aspect;
 int base_width, base_height;
 int win_gravity;
} XSizeHints;
typedef struct {
 long flags;
 int input;
 int initial_state;
 Pixmap icon_pixmap;
 Window icon_window;
 int icon_x, icon_y;
 Pixmap icon_mask;
 XID window_group;
} XWMHints;
typedef struct {
    unsigned char *value;
    Atom encoding;
    int format;
    unsigned long nitems;
} XTextProperty;
typedef enum {
    XStringStyle,
    XCompoundTextStyle,
    XTextStyle,
    XStdICCTextStyle,
    XUTF8StringStyle
} XICCEncodingStyle;
typedef struct {
 int min_width, min_height;
 int max_width, max_height;
 int width_inc, height_inc;
} XIconSize;
typedef struct {
 char *res_name;
 char *res_class;
} XClassHint;
typedef struct _XComposeStatus {
    XPointer compose_ptr;
    int chars_matched;
} XComposeStatus;
typedef struct _XRegion *Region;
typedef struct {
  Visual *visual;
  VisualID visualid;
  int screen;
  int depth;
  int class;
  unsigned long red_mask;
  unsigned long green_mask;
  unsigned long blue_mask;
  int colormap_size;
  int bits_per_rgb;
} XVisualInfo;
typedef struct {
 Colormap colormap;
 unsigned long red_max;
 unsigned long red_mult;
 unsigned long green_max;
 unsigned long green_mult;
 unsigned long blue_max;
 unsigned long blue_mult;
 unsigned long base_pixel;
 VisualID visualid;
 XID killid;
} XStandardColormap;
typedef int XContext;

extern XClassHint *XAllocClassHint (
    void
);
extern XIconSize *XAllocIconSize (
    void
);
extern XSizeHints *XAllocSizeHints (
    void
);
extern XStandardColormap *XAllocStandardColormap (
    void
);
extern XWMHints *XAllocWMHints (
    void
);
extern int XClipBox(
    Region ,
    XRectangle*
);
extern Region XCreateRegion(
    void
);
extern const char *XDefaultString (void);
extern int XDeleteContext(
    Display* ,
    XID ,
    XContext
);
extern int XDestroyRegion(
    Region
);
extern int XEmptyRegion(
    Region
);
extern int XEqualRegion(
    Region ,
    Region
);
extern int XFindContext(
    Display* ,
    XID ,
    XContext ,
    XPointer*
);
extern int XGetClassHint(
    Display* ,
    Window ,
    XClassHint*
);
extern int XGetIconSizes(
    Display* ,
    Window ,
    XIconSize** ,
    int*
);
extern int XGetNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XGetRGBColormaps(
    Display* ,
    Window ,
    XStandardColormap** ,
    int* ,
    Atom
);
extern int XGetSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XGetStandardColormap(
    Display* ,
    Window ,
    XStandardColormap* ,
    Atom
);
extern int XGetTextProperty(
    Display* ,
    Window ,
    XTextProperty* ,
    Atom
);
extern XVisualInfo *XGetVisualInfo(
    Display* ,
    long ,
    XVisualInfo* ,
    int*
);
extern int XGetWMClientMachine(
    Display* ,
    Window ,
    XTextProperty*
);
extern XWMHints *XGetWMHints(
    Display* ,
    Window
);
extern int XGetWMIconName(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XGetWMName(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XGetWMNormalHints(
    Display* ,
    Window ,
    XSizeHints* ,
    long*
);
extern int XGetWMSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    long* ,
    Atom
);
extern int XGetZoomHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XIntersectRegion(
    Region ,
    Region ,
    Region
);
extern void XConvertCase(
    KeySym ,
    KeySym* ,
    KeySym*
);
extern int XLookupString(
    XKeyEvent* ,
    char* ,
    int ,
    KeySym* ,
    XComposeStatus*
);
extern int XMatchVisualInfo(
    Display* ,
    int ,
    int ,
    int ,
    XVisualInfo*
);
extern int XOffsetRegion(
    Region ,
    int ,
    int
);
extern int XPointInRegion(
    Region ,
    int ,
    int
);
extern Region XPolygonRegion(
    XPoint* ,
    int ,
    int
);
extern int XRectInRegion(
    Region ,
    int ,
    int ,
    unsigned int ,
    unsigned int
);
extern int XSaveContext(
    Display* ,
    XID ,
    XContext ,
    const char*
);
extern int XSetClassHint(
    Display* ,
    Window ,
    XClassHint*
);
extern int XSetIconSizes(
    Display* ,
    Window ,
    XIconSize* ,
    int
);
extern int XSetNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern void XSetRGBColormaps(
    Display* ,
    Window ,
    XStandardColormap* ,
    int ,
    Atom
);
extern int XSetSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XSetStandardProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    Pixmap ,
    char** ,
    int ,
    XSizeHints*
);
extern void XSetTextProperty(
    Display* ,
    Window ,
    XTextProperty* ,
    Atom
);
extern void XSetWMClientMachine(
    Display* ,
    Window ,
    XTextProperty*
);
extern int XSetWMHints(
    Display* ,
    Window ,
    XWMHints*
);
extern void XSetWMIconName(
    Display* ,
    Window ,
    XTextProperty*
);
extern void XSetWMName(
    Display* ,
    Window ,
    XTextProperty*
);
extern void XSetWMNormalHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern void XSetWMProperties(
    Display* ,
    Window ,
    XTextProperty* ,
    XTextProperty* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void XmbSetWMProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void Xutf8SetWMProperties(
    Display* ,
    Window ,
    const char* ,
    const char* ,
    char** ,
    int ,
    XSizeHints* ,
    XWMHints* ,
    XClassHint*
);
extern void XSetWMSizeHints(
    Display* ,
    Window ,
    XSizeHints* ,
    Atom
);
extern int XSetRegion(
    Display* ,
    GC ,
    Region
);
extern void XSetStandardColormap(
    Display* ,
    Window ,
    XStandardColormap* ,
    Atom
);
extern int XSetZoomHints(
    Display* ,
    Window ,
    XSizeHints*
);
extern int XShrinkRegion(
    Region ,
    int ,
    int
);
extern int XStringListToTextProperty(
    char** ,
    int ,
    XTextProperty*
);
extern int XSubtractRegion(
    Region ,
    Region ,
    Region
);
extern int XmbTextListToTextProperty(
    Display* display,
    char** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern int XwcTextListToTextProperty(
    Display* display,
    wchar_t** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern int Xutf8TextListToTextProperty(
    Display* display,
    char** list,
    int count,
    XICCEncodingStyle style,
    XTextProperty* text_prop_return
);
extern void XwcFreeStringList(
    wchar_t** list
);
extern int XTextPropertyToStringList(
    XTextProperty* ,
    char*** ,
    int*
);
extern int XmbTextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    char*** list_return,
    int* count_return
);
extern int XwcTextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    wchar_t*** list_return,
    int* count_return
);
extern int Xutf8TextPropertyToTextList(
    Display* display,
    const XTextProperty* text_prop,
    char*** list_return,
    int* count_return
);
extern int XUnionRectWithRegion(
    XRectangle* ,
    Region ,
    Region
);
extern int XUnionRegion(
    Region ,
    Region ,
    Region
);
extern int XWMGeometry(
    Display* ,
    int ,
    const char* ,
    const char* ,
    unsigned int ,
    XSizeHints* ,
    int* ,
    int* ,
    int* ,
    int* ,
    int*
);
extern int XXorRegion(
    Region ,
    Region ,
    Region
);


extern char *Xpermalloc(
    unsigned int
);
typedef int XrmQuark, *XrmQuarkList;
typedef char *XrmString;
extern XrmQuark XrmStringToQuark(
    const char*
);
extern XrmQuark XrmPermStringToQuark(
    const char*
);
extern XrmString XrmQuarkToString(
    XrmQuark
);
extern XrmQuark XrmUniqueQuark(
    void
);
typedef enum {XrmBindTightly, XrmBindLoosely} XrmBinding, *XrmBindingList;
extern void XrmStringToQuarkList(
    const char* ,
    XrmQuarkList
);
extern void XrmStringToBindingQuarkList(
    const char* ,
    XrmBindingList ,
    XrmQuarkList
);
typedef XrmQuark XrmName;
typedef XrmQuarkList XrmNameList;
typedef XrmQuark XrmClass;
typedef XrmQuarkList XrmClassList;
typedef XrmQuark XrmRepresentation;
typedef struct {
    unsigned int size;
    XPointer addr;
} XrmValue, *XrmValuePtr;
typedef struct _XrmHashBucketRec *XrmHashBucket;
typedef XrmHashBucket *XrmHashTable;
typedef XrmHashTable XrmSearchList[];
typedef struct _XrmHashBucketRec *XrmDatabase;
extern void XrmDestroyDatabase(
    XrmDatabase
);
extern void XrmQPutResource(
    XrmDatabase* ,
    XrmBindingList ,
    XrmQuarkList ,
    XrmRepresentation ,
    XrmValue*
);
extern void XrmPutResource(
    XrmDatabase* ,
    const char* ,
    const char* ,
    XrmValue*
);
extern void XrmQPutStringResource(
    XrmDatabase* ,
    XrmBindingList ,
    XrmQuarkList ,
    const char*
);
extern void XrmPutStringResource(
    XrmDatabase* ,
    const char* ,
    const char*
);
extern void XrmPutLineResource(
    XrmDatabase* ,
    const char*
);
extern int XrmQGetResource(
    XrmDatabase ,
    XrmNameList ,
    XrmClassList ,
    XrmRepresentation* ,
    XrmValue*
);
extern int XrmGetResource(
    XrmDatabase ,
    const char* ,
    const char* ,
    char** ,
    XrmValue*
);
extern int XrmQGetSearchList(
    XrmDatabase ,
    XrmNameList ,
    XrmClassList ,
    XrmSearchList ,
    int
);
extern int XrmQGetSearchResource(
    XrmSearchList ,
    XrmName ,
    XrmClass ,
    XrmRepresentation* ,
    XrmValue*
);
extern void XrmSetDatabase(
    Display* ,
    XrmDatabase
);
extern XrmDatabase XrmGetDatabase(
    Display*
);
extern XrmDatabase XrmGetFileDatabase(
    const char*
);
extern int XrmCombineFileDatabase(
    const char* ,
    XrmDatabase* ,
    int
);
extern XrmDatabase XrmGetStringDatabase(
    const char*
);
extern void XrmPutFileDatabase(
    XrmDatabase ,
    const char*
);
extern void XrmMergeDatabases(
    XrmDatabase ,
    XrmDatabase*
);
extern void XrmCombineDatabase(
    XrmDatabase ,
    XrmDatabase* ,
    int
);
extern int XrmEnumerateDatabase(
    XrmDatabase ,
    XrmNameList ,
    XrmClassList ,
    int ,
    int (*)(
      XrmDatabase* ,
      XrmBindingList ,
      XrmQuarkList ,
      XrmRepresentation* ,
      XrmValue* ,
      XPointer
      ) ,
    XPointer
);
extern const char *XrmLocaleOfDatabase(
    XrmDatabase
);
typedef enum {
    XrmoptionNoArg,
    XrmoptionIsArg,
    XrmoptionStickyArg,
    XrmoptionSepArg,
    XrmoptionResArg,
    XrmoptionSkipArg,
    XrmoptionSkipLine,
    XrmoptionSkipNArgs
} XrmOptionKind;
typedef struct {
    char *option;
    char *specifier;
    XrmOptionKind argKind;
    XPointer value;
} XrmOptionDescRec, *XrmOptionDescList;
extern void XrmParseCommand(
    XrmDatabase* ,
    XrmOptionDescList ,
    int ,
    const char* ,
    int* ,
    char**
);

typedef char *String;
typedef struct _WidgetRec *Widget;
typedef Widget *WidgetList;
typedef struct _WidgetClassRec *WidgetClass;
typedef struct _CompositeRec *CompositeWidget;
typedef struct _XtActionsRec *XtActionList;
typedef struct _XtEventRec *XtEventTable;
typedef struct _XtAppStruct *XtAppContext;
typedef unsigned long XtValueMask;
typedef unsigned long XtIntervalId;
typedef unsigned long XtInputId;
typedef unsigned long XtWorkProcId;
typedef unsigned long XtSignalId;
typedef unsigned int XtGeometryMask;
typedef unsigned long XtGCMask;
typedef unsigned long Pixel;
typedef int XtCacheType;
typedef char Boolean;
typedef long XtArgVal;
typedef unsigned char XtEnum;
typedef unsigned int Cardinal;
typedef unsigned short Dimension;
typedef short Position;
typedef void* XtPointer;
typedef XtPointer Opaque;

typedef struct _WidgetClassRec *CoreWidgetClass;
typedef struct _WidgetRec *CoreWidget;
extern WidgetClass coreWidgetClass;
extern WidgetClass widgetClass;

typedef struct _CompositeClassRec *CompositeWidgetClass;
typedef Cardinal (*XtOrderProc)(
    Widget
);

extern void XtManageChildren(
    WidgetList ,
    Cardinal
);
extern void XtManageChild(
    Widget
);
extern void XtUnmanageChildren(
    WidgetList ,
    Cardinal
);
extern void XtUnmanageChild(
    Widget
);
typedef void (*XtDoChangeProc)(
    Widget ,
    WidgetList ,
    Cardinal * ,
    WidgetList ,
    Cardinal * ,
    XtPointer
);
extern void XtChangeManagedSet(
    WidgetList ,
    Cardinal ,
    XtDoChangeProc ,
    XtPointer ,
    WidgetList ,
    Cardinal
);

extern WidgetClass compositeWidgetClass;

typedef struct _ConstraintClassRec *ConstraintWidgetClass;
extern WidgetClass constraintWidgetClass;


typedef struct _ObjectRec *Object;
typedef struct _ObjectClassRec *ObjectClass;
extern WidgetClass objectClass;


typedef struct _RectObjRec *RectObj;
typedef struct _RectObjClassRec *RectObjClass;
extern WidgetClass rectObjClass;

typedef struct _TranslationData *XtTranslations;
typedef struct _TranslationData *XtAccelerators;
typedef unsigned int Modifiers;
typedef void (*XtActionProc)(
    Widget ,
    XEvent* ,
    String* ,
    Cardinal*
);
typedef XtActionProc* XtBoundActions;
typedef struct _XtActionsRec{
    String string;
    XtActionProc proc;
} XtActionsRec;
typedef enum {
    XtAddress,
    XtBaseOffset,
    XtImmediate,
    XtResourceString,
    XtResourceQuark,
    XtWidgetBaseOffset,
    XtProcedureArg
} XtAddressMode;
typedef struct {
    XtAddressMode address_mode;
    XtPointer address_id;
    Cardinal size;
} XtConvertArgRec, *XtConvertArgList;
typedef void (*XtConvertArgProc)(
    Widget ,
    Cardinal* ,
    XrmValue*
);
typedef struct {
    XtGeometryMask request_mode;
    Position x, y;
    Dimension width, height, border_width;
    Widget sibling;
    int stack_mode;
} XtWidgetGeometry;
typedef void (*XtConverter)(
    XrmValue* ,
    Cardinal* ,
    XrmValue* ,
    XrmValue*
);
typedef Boolean (*XtTypeConverter)(
    Display* ,
    XrmValue* ,
    Cardinal* ,
    XrmValue* ,
    XrmValue* ,
    XtPointer*
);
typedef void (*XtDestructor)(
    XtAppContext ,
    XrmValue* ,
    XtPointer ,
    XrmValue* ,
    Cardinal*
);
typedef Opaque XtCacheRef;
typedef Opaque XtActionHookId;
typedef void (*XtActionHookProc)(
    Widget ,
    XtPointer ,
    String ,
    XEvent* ,
    String* ,
    Cardinal*
);
typedef unsigned long XtBlockHookId;
typedef void (*XtBlockHookProc)(
    XtPointer
);
typedef void (*XtKeyProc)(
    Display* ,
    KeyCode ,
    Modifiers ,
    Modifiers* ,
    KeySym*
);
typedef void (*XtCaseProc)(
    Display* ,
    KeySym ,
    KeySym* ,
    KeySym*
);
typedef void (*XtEventHandler)(
    Widget ,
    XtPointer ,
    XEvent* ,
    Boolean*
);
typedef unsigned long EventMask;
typedef enum {XtListHead, XtListTail } XtListPosition;
typedef unsigned long XtInputMask;
typedef void (*XtTimerCallbackProc)(
    XtPointer ,
    XtIntervalId*
);
typedef void (*XtInputCallbackProc)(
    XtPointer ,
    int* ,
    XtInputId*
);
typedef void (*XtSignalCallbackProc)(
    XtPointer ,
    XtSignalId*
);
typedef struct {
    String name;
    XtArgVal value;
} Arg, *ArgList;
typedef XtPointer XtVarArgsList;
typedef void (*XtCallbackProc)(
    Widget ,
    XtPointer ,
    XtPointer
);
typedef struct _XtCallbackRec {
    XtCallbackProc callback;
    XtPointer closure;
} XtCallbackRec, *XtCallbackList;
typedef enum {
 XtCallbackNoList,
 XtCallbackHasNone,
 XtCallbackHasSome
} XtCallbackStatus;
typedef enum {
    XtGeometryYes,
    XtGeometryNo,
    XtGeometryAlmost,
    XtGeometryDone
} XtGeometryResult;
typedef enum {XtGrabNone, XtGrabNonexclusive, XtGrabExclusive} XtGrabKind;
typedef struct {
    Widget shell_widget;
    Widget enable_widget;
} XtPopdownIDRec, *XtPopdownID;
typedef struct _XtResource {
    String resource_name;
    String resource_class;
    String resource_type;
    Cardinal resource_size;
    Cardinal resource_offset;
    String default_type;
    XtPointer default_addr;
} XtResource, *XtResourceList;
typedef void (*XtResourceDefaultProc)(
    Widget ,
    int ,
    XrmValue*
);
typedef String (*XtLanguageProc)(
    Display* ,
    String ,
    XtPointer
);
typedef void (*XtErrorMsgHandler)(
    String ,
    String ,
    String ,
    String ,
    String* ,
    Cardinal*
);
typedef void (*XtErrorHandler)(
  String
);
typedef void (*XtCreatePopupChildProc)(
    Widget
);
typedef Boolean (*XtWorkProc)(
    XtPointer
);
typedef struct {
    char match;
    String substitution;
} SubstitutionRec, *Substitution;
typedef Boolean (*XtFilePredicate)(
   String
);
typedef XtPointer XtRequestId;
typedef Boolean (*XtConvertSelectionProc)(
    Widget ,
    Atom* ,
    Atom* ,
    Atom* ,
    XtPointer* ,
    unsigned long* ,
    int*
);
typedef void (*XtLoseSelectionProc)(
    Widget ,
    Atom*
);
typedef void (*XtSelectionDoneProc)(
    Widget ,
    Atom* ,
    Atom*
);
typedef void (*XtSelectionCallbackProc)(
    Widget ,
    XtPointer ,
    Atom* ,
    Atom* ,
    XtPointer ,
    unsigned long* ,
    int*
);
typedef void (*XtLoseSelectionIncrProc)(
    Widget ,
    Atom* ,
    XtPointer
);
typedef void (*XtSelectionDoneIncrProc)(
    Widget ,
    Atom* ,
    Atom* ,
    XtRequestId* ,
    XtPointer
);
typedef Boolean (*XtConvertSelectionIncrProc)(
    Widget ,
    Atom* ,
    Atom* ,
    Atom* ,
    XtPointer* ,
    unsigned long* ,
    int* ,
    unsigned long* ,
    XtPointer ,
    XtRequestId*
);
typedef void (*XtCancelConvertSelectionProc)(
    Widget ,
    Atom* ,
    Atom* ,
    XtRequestId* ,
    XtPointer
);
typedef Boolean (*XtEventDispatchProc)(
    XEvent*
);
typedef void (*XtExtensionSelectProc)(
    Widget ,
    int* ,
    XtPointer* ,
    int ,
    XtPointer
);

extern Boolean XtConvertAndStore(
    Widget ,
    const char* ,
    XrmValue* ,
    const char* ,
    XrmValue*
);
extern Boolean XtCallConverter(
    Display* ,
    XtTypeConverter ,
    XrmValuePtr ,
    Cardinal ,
    XrmValuePtr ,
    XrmValue* ,
    XtCacheRef*
);
extern Boolean XtDispatchEvent(
    XEvent*
);
extern Boolean XtCallAcceptFocus(
    Widget ,
    Time*
);
extern Boolean XtPeekEvent(
    XEvent*
);
extern Boolean XtAppPeekEvent(
    XtAppContext ,
    XEvent*
);
extern Boolean XtIsSubclass(
    Widget ,
    WidgetClass
);
extern Boolean XtIsObject(
    Widget
);
extern Boolean _XtCheckSubclassFlag(
    Widget ,
    XtEnum
);
extern Boolean _XtIsSubclassOf(
    Widget ,
    WidgetClass ,
    WidgetClass ,
    XtEnum
);
extern Boolean XtIsManaged(
    Widget
);
extern Boolean XtIsRealized(
    Widget
);
extern Boolean XtIsSensitive(
    Widget
);
extern Boolean XtOwnSelection(
    Widget ,
    Atom ,
    Time ,
    XtConvertSelectionProc ,
    XtLoseSelectionProc ,
    XtSelectionDoneProc
);
extern Boolean XtOwnSelectionIncremental(
    Widget ,
    Atom ,
    Time ,
    XtConvertSelectionIncrProc ,
    XtLoseSelectionIncrProc ,
    XtSelectionDoneIncrProc ,
    XtCancelConvertSelectionProc ,
    XtPointer
);
extern XtGeometryResult XtMakeResizeRequest(
    Widget ,
    Dimension ,
    Dimension ,
    Dimension* ,
    Dimension*
);
extern void XtTranslateCoords(
    Widget ,
    Position ,
    Position ,
    Position* ,
    Position*
);
extern KeySym* XtGetKeysymTable(
    Display* ,
    KeyCode* ,
    int*
);
extern void XtKeysymToKeycodeList(
    Display* ,
    KeySym ,
    KeyCode** ,
    Cardinal*
);
extern void XtStringConversionWarning(
    const char* ,
    const char*
);
extern void XtDisplayStringConversionWarning(
    Display* ,
    const char* ,
    const char*
);
extern XtConvertArgRec const colorConvertArgs[];
extern XtConvertArgRec const screenConvertArg[];
extern void XtAppAddConverter(
    XtAppContext ,
    const char* ,
    const char* ,
    XtConverter ,
    XtConvertArgList ,
    Cardinal
);
extern void XtAddConverter(
    const char* ,
    const char* ,
    XtConverter ,
    XtConvertArgList ,
    Cardinal
);
extern void XtSetTypeConverter(
    const char* ,
    const char* ,
    XtTypeConverter ,
    XtConvertArgList ,
    Cardinal ,
    XtCacheType ,
    XtDestructor
);
extern void XtAppSetTypeConverter(
    XtAppContext ,
    const char* ,
    const char* ,
    XtTypeConverter ,
    XtConvertArgList ,
    Cardinal ,
    XtCacheType ,
    XtDestructor
);
extern void XtConvert(
    Widget ,
    const char* ,
    XrmValue* ,
    const char* ,
    XrmValue*
);
extern void XtDirectConvert(
    XtConverter ,
    XrmValuePtr ,
    Cardinal ,
    XrmValuePtr ,
    XrmValue*
);
extern XtTranslations XtParseTranslationTable(
    const char*
);
extern XtAccelerators XtParseAcceleratorTable(
    const char*
);
extern void XtOverrideTranslations(
    Widget ,
    XtTranslations
);
extern void XtAugmentTranslations(
    Widget ,
    XtTranslations
);
extern void XtInstallAccelerators(
    Widget ,
    Widget
);
extern void XtInstallAllAccelerators(
    Widget ,
    Widget
);
extern void XtUninstallTranslations(
    Widget
);
extern void XtAppAddActions(
    XtAppContext ,
    XtActionList ,
    Cardinal
);
extern void XtAddActions(
    XtActionList ,
    Cardinal
);
extern XtActionHookId XtAppAddActionHook(
    XtAppContext ,
    XtActionHookProc ,
    XtPointer
);
extern void XtRemoveActionHook(
    XtActionHookId
);
extern void XtGetActionList(
    WidgetClass ,
    XtActionList* ,
    Cardinal*
);
extern void XtCallActionProc(
    Widget ,
    const char* ,
    XEvent* ,
    String* ,
    Cardinal
);
extern void XtRegisterGrabAction(
    XtActionProc ,
    Boolean ,
    unsigned int ,
    int ,
    int
);
extern void XtSetMultiClickTime(
    Display* ,
    int
);
extern int XtGetMultiClickTime(
    Display*
);
extern KeySym XtGetActionKeysym(
    XEvent* ,
    Modifiers*
);
extern void XtTranslateKeycode(
    Display* ,
    KeyCode ,
    Modifiers ,
    Modifiers* ,
    KeySym*
);
extern void XtTranslateKey(
    Display* ,
    KeyCode ,
    Modifiers ,
    Modifiers* ,
    KeySym*
);
extern void XtSetKeyTranslator(
    Display* ,
    XtKeyProc
);
extern void XtRegisterCaseConverter(
    Display* ,
    XtCaseProc ,
    KeySym ,
    KeySym
);
extern void XtConvertCase(
    Display* ,
    KeySym ,
    KeySym* ,
    KeySym*
);
extern void XtAddEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer
);
extern void XtRemoveEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer
);
extern void XtAddRawEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer
);
extern void XtRemoveRawEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer
);
extern void XtInsertEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer ,
    XtListPosition
);
extern void XtInsertRawEventHandler(
    Widget ,
    EventMask ,
    Boolean ,
    XtEventHandler ,
    XtPointer ,
    XtListPosition
);
extern XtEventDispatchProc XtSetEventDispatcher(
    Display* ,
    int ,
    XtEventDispatchProc
);
extern Boolean XtDispatchEventToWidget(
    Widget ,
    XEvent*
);
extern void XtInsertEventTypeHandler(
    Widget ,
    int ,
    XtPointer ,
    XtEventHandler ,
    XtPointer ,
    XtListPosition
);
extern void XtRemoveEventTypeHandler(
    Widget ,
    int ,
    XtPointer ,
    XtEventHandler ,
    XtPointer
);
extern EventMask XtBuildEventMask(
    Widget
);
extern void XtRegisterExtensionSelector(
    Display* ,
    int ,
    int ,
    XtExtensionSelectProc ,
    XtPointer
);
extern void XtAddGrab(
    Widget ,
    Boolean ,
    Boolean
);
extern void XtRemoveGrab(
    Widget
);
extern void XtProcessEvent(
    XtInputMask
);
extern void XtAppProcessEvent(
    XtAppContext ,
    XtInputMask
);
extern void XtMainLoop(
    void
);
extern void XtAppMainLoop(
    XtAppContext
);
extern void XtAddExposureToRegion(
    XEvent* ,
    Region
);
extern void XtSetKeyboardFocus(
    Widget ,
    Widget
);
extern Widget XtGetKeyboardFocusWidget(
    Widget
);
extern XEvent* XtLastEventProcessed(
    Display*
);
extern Time XtLastTimestampProcessed(
    Display*
);
extern XtIntervalId XtAddTimeOut(
    unsigned long ,
    XtTimerCallbackProc ,
    XtPointer
);
extern XtIntervalId XtAppAddTimeOut(
    XtAppContext ,
    unsigned long ,
    XtTimerCallbackProc ,
    XtPointer
);
extern void XtRemoveTimeOut(
    XtIntervalId
);
extern XtInputId XtAddInput(
    int ,
    XtPointer ,
    XtInputCallbackProc ,
    XtPointer
);
extern XtInputId XtAppAddInput(
    XtAppContext ,
    int ,
    XtPointer ,
    XtInputCallbackProc ,
    XtPointer
);
extern void XtRemoveInput(
    XtInputId
);
extern XtSignalId XtAddSignal(
    XtSignalCallbackProc ,
    XtPointer );
extern XtSignalId XtAppAddSignal(
    XtAppContext ,
    XtSignalCallbackProc ,
    XtPointer
);
extern void XtRemoveSignal(
    XtSignalId
);
extern void XtNoticeSignal(
    XtSignalId
);
extern void XtNextEvent(
    XEvent*
);
extern void XtAppNextEvent(
    XtAppContext ,
    XEvent*
);
extern Boolean XtPending(
    void
);
extern XtInputMask XtAppPending(
    XtAppContext
);
extern XtBlockHookId XtAppAddBlockHook(
    XtAppContext ,
    XtBlockHookProc ,
    XtPointer
);
extern void XtRemoveBlockHook(
    XtBlockHookId
);
extern Boolean XtIsOverrideShell(Widget );
extern Boolean XtIsVendorShell(Widget );
extern Boolean XtIsTransientShell(Widget );
extern Boolean XtIsApplicationShell(Widget );
extern Boolean XtIsSessionShell(Widget );
extern void XtRealizeWidget(
    Widget
);
void XtUnrealizeWidget(
    Widget
);
extern void XtDestroyWidget(
    Widget
);
extern void XtSetSensitive(
    Widget ,
    Boolean
);
extern void XtSetMappedWhenManaged(
    Widget ,
    Boolean
);
extern Widget XtNameToWidget(
    Widget ,
    const char*
);
extern Widget XtWindowToWidget(
    Display* ,
    Window
);
extern XtPointer XtGetClassExtension(
    WidgetClass ,
    Cardinal ,
    XrmQuark ,
    long ,
    Cardinal
);
extern ArgList XtMergeArgLists(
    ArgList ,
    Cardinal ,
    ArgList ,
    Cardinal
);
extern XtVarArgsList XtVaCreateArgsList(
    XtPointer , ...
) __attribute__ ((__sentinel__(0)));
extern Display *XtDisplay(
    Widget
);
extern Display *XtDisplayOfObject(
    Widget
);
extern Screen *XtScreen(
    Widget
);
extern Screen *XtScreenOfObject(
    Widget
);
extern Window XtWindow(
    Widget
);
extern Window XtWindowOfObject(
    Widget
);
extern String XtName(
    Widget
);
extern WidgetClass XtSuperclass(
    Widget
);
extern WidgetClass XtClass(
    Widget
);
extern Widget XtParent(
    Widget
);
extern void XtMapWidget(Widget );
extern void XtUnmapWidget(Widget );
extern void XtAddCallback(
    Widget ,
    const char* ,
    XtCallbackProc ,
    XtPointer
);
extern void XtRemoveCallback(
    Widget ,
    const char* ,
    XtCallbackProc ,
    XtPointer
);
extern void XtAddCallbacks(
    Widget ,
    const char* ,
    XtCallbackList
);
extern void XtRemoveCallbacks(
    Widget ,
    const char* ,
    XtCallbackList
);
extern void XtRemoveAllCallbacks(
    Widget ,
    const char*
);
extern void XtCallCallbacks(
    Widget ,
    const char* ,
    XtPointer
);
extern void XtCallCallbackList(
    Widget ,
    XtCallbackList ,
    XtPointer
);
extern XtCallbackStatus XtHasCallbacks(
    Widget ,
    const char*
);
extern XtGeometryResult XtMakeGeometryRequest(
    Widget ,
    XtWidgetGeometry* ,
    XtWidgetGeometry*
);
extern XtGeometryResult XtQueryGeometry(
    Widget ,
    XtWidgetGeometry* ,
    XtWidgetGeometry*
);
extern Widget XtCreatePopupShell(
    const char* ,
    WidgetClass ,
    Widget ,
    ArgList ,
    Cardinal
);
extern Widget XtVaCreatePopupShell(
    const char* ,
    WidgetClass ,
    Widget ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtPopup(
    Widget ,
    XtGrabKind
);
extern void XtPopupSpringLoaded(
    Widget
);
extern void XtCallbackNone(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtCallbackNonexclusive(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtCallbackExclusive(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtPopdown(
    Widget
);
extern void XtCallbackPopdown(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtMenuPopupAction(
    Widget ,
    XEvent* ,
    String* ,
    Cardinal*
);
extern Widget XtCreateWidget(
    const char* ,
    WidgetClass ,
    Widget ,
    ArgList ,
    Cardinal
);
extern Widget XtCreateManagedWidget(
    const char* ,
    WidgetClass ,
    Widget ,
    ArgList ,
    Cardinal
);
extern Widget XtVaCreateWidget(
    const char* ,
    WidgetClass ,
    Widget ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Widget XtVaCreateManagedWidget(
    const char* ,
    WidgetClass ,
    Widget ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Widget XtCreateApplicationShell(
    const char* ,
    WidgetClass ,
    ArgList ,
    Cardinal
);
extern Widget XtAppCreateShell(
    const char* ,
    const char* ,
    WidgetClass ,
    Display* ,
    ArgList ,
    Cardinal
);
extern Widget XtVaAppCreateShell(
    const char* ,
    const char* ,
    WidgetClass ,
    Display* ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtToolkitInitialize(
    void
);
extern XtLanguageProc XtSetLanguageProc(
    XtAppContext ,
    XtLanguageProc ,
    XtPointer
);
extern void XtDisplayInitialize(
    XtAppContext ,
    Display* ,
    const char* ,
    const char* ,
    XrmOptionDescRec* ,
    Cardinal ,
    int* ,
    char**
);
extern Widget XtOpenApplication(
    XtAppContext* ,
    const char* ,
    XrmOptionDescList ,
    Cardinal ,
    int* ,
    String* ,
    String* ,
    WidgetClass ,
    ArgList ,
    Cardinal
);
extern Widget XtVaOpenApplication(
    XtAppContext* ,
    const char* ,
    XrmOptionDescList ,
    Cardinal ,
    int* ,
    String* ,
    String* ,
    WidgetClass ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Widget XtAppInitialize(
    XtAppContext* ,
    const char* ,
    XrmOptionDescList ,
    Cardinal ,
    int* ,
    String* ,
    String* ,
    ArgList ,
    Cardinal
);
extern Widget XtVaAppInitialize(
    XtAppContext* ,
    const char* ,
    XrmOptionDescList ,
    Cardinal ,
    int* ,
    String* ,
    String* ,
    ...
) __attribute__ ((__sentinel__(0)));
extern Widget XtInitialize(
    const char* ,
    const char* ,
    XrmOptionDescRec* ,
    Cardinal ,
    int* ,
    char**
);
extern Display *XtOpenDisplay(
    XtAppContext ,
    const char* ,
    const char* ,
    const char* ,
    XrmOptionDescRec* ,
    Cardinal ,
    int* ,
    char**
);
extern XtAppContext XtCreateApplicationContext(
    void
);
extern void XtAppSetFallbackResources(
    XtAppContext ,
    String*
);
extern void XtDestroyApplicationContext(
    XtAppContext
);
extern void XtInitializeWidgetClass(
    WidgetClass
);
extern XtAppContext XtWidgetToApplicationContext(
    Widget
);
extern XtAppContext XtDisplayToApplicationContext(
    Display*
);
extern XrmDatabase XtDatabase(
    Display*
);
extern XrmDatabase XtScreenDatabase(
    Screen*
);
extern void XtCloseDisplay(
    Display*
);
extern void XtGetApplicationResources(
    Widget ,
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ArgList ,
    Cardinal
);
extern void XtVaGetApplicationResources(
    Widget ,
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtGetSubresources(
    Widget ,
    XtPointer ,
    const char* ,
    const char* ,
    XtResourceList ,
    Cardinal ,
    ArgList ,
    Cardinal
);
extern void XtVaGetSubresources(
    Widget ,
    XtPointer ,
    const char* ,
    const char* ,
    XtResourceList ,
    Cardinal ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtSetValues(
    Widget ,
    ArgList ,
    Cardinal
);
extern void XtVaSetValues(
    Widget ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtGetValues(
    Widget ,
    ArgList ,
    Cardinal
);
extern void XtVaGetValues(
    Widget ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtSetSubvalues(
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ArgList ,
    Cardinal
);
extern void XtVaSetSubvalues(
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtGetSubvalues(
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ArgList ,
    Cardinal
);
extern void XtVaGetSubvalues(
    XtPointer ,
    XtResourceList ,
    Cardinal ,
    ...
) __attribute__ ((__sentinel__(0)));
extern void XtGetResourceList(
    WidgetClass ,
    XtResourceList* ,
    Cardinal*
);
extern void XtGetConstraintResourceList(
    WidgetClass ,
    XtResourceList* ,
    Cardinal*
);
typedef struct _XtCheckpointTokenRec {
    int save_type;
    int interact_style;
    Boolean shutdown;
    Boolean fast;
    Boolean cancel_shutdown;
    int phase;
    int interact_dialog_type;
    Boolean request_cancel;
    Boolean request_next_phase;
    Boolean save_success;
    int type;
    Widget widget;
} XtCheckpointTokenRec, *XtCheckpointToken;
XtCheckpointToken XtSessionGetToken(
    Widget
);
void XtSessionReturnToken(
    XtCheckpointToken
);
extern XtErrorMsgHandler XtAppSetErrorMsgHandler(
    XtAppContext ,
    XtErrorMsgHandler
);
extern void XtSetErrorMsgHandler(
    XtErrorMsgHandler
);
extern XtErrorMsgHandler XtAppSetWarningMsgHandler(
    XtAppContext ,
    XtErrorMsgHandler
);
extern void XtSetWarningMsgHandler(
    XtErrorMsgHandler
);
extern void XtAppErrorMsg(
    XtAppContext ,
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String* ,
    Cardinal*
);
extern void XtErrorMsg(
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String* ,
    Cardinal*
);
extern void XtAppWarningMsg(
    XtAppContext ,
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String* ,
    Cardinal*
);
extern void XtWarningMsg(
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String* ,
    Cardinal*
);
extern XtErrorHandler XtAppSetErrorHandler(
    XtAppContext ,
    XtErrorHandler
);
extern void XtSetErrorHandler(
    XtErrorHandler
);
extern XtErrorHandler XtAppSetWarningHandler(
    XtAppContext ,
    XtErrorHandler
);
extern void XtSetWarningHandler(
    XtErrorHandler
);
extern void XtAppError(
    XtAppContext ,
    const char*
);
extern void XtError(
    const char*
);
extern void XtAppWarning(
    XtAppContext ,
    const char*
);
extern void XtWarning(
    const char*
);
extern XrmDatabase *XtAppGetErrorDatabase(
    XtAppContext
);
extern XrmDatabase *XtGetErrorDatabase(
    void
);
extern void XtAppGetErrorDatabaseText(
    XtAppContext ,
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String ,
    int ,
    XrmDatabase
);
extern void XtGetErrorDatabaseText(
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    String ,
    int
);
extern char *XtMalloc(
    Cardinal
);
extern char *XtCalloc(
    Cardinal ,
    Cardinal
);
extern char *XtRealloc(
    char* ,
    Cardinal
);
extern void XtFree(
    char*
);
extern Cardinal XtAsprintf(
    String *new_string,
    const char * __restrict__ format,
    ...
) __attribute__((__format__(__printf__,2,3)));
extern String XtNewString(String );
extern XtWorkProcId XtAddWorkProc(
    XtWorkProc ,
    XtPointer
);
extern XtWorkProcId XtAppAddWorkProc(
    XtAppContext ,
    XtWorkProc ,
    XtPointer
);
extern void XtRemoveWorkProc(
    XtWorkProcId
);
extern GC XtGetGC(
    Widget ,
    XtGCMask ,
    XGCValues*
);
extern GC XtAllocateGC(
    Widget ,
    Cardinal ,
    XtGCMask ,
    XGCValues* ,
    XtGCMask ,
    XtGCMask
);
extern void XtDestroyGC(
    GC
);
extern void XtReleaseGC(
    Widget ,
    GC
);
extern void XtAppReleaseCacheRefs(
    XtAppContext ,
    XtCacheRef*
);
extern void XtCallbackReleaseCacheRef(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtCallbackReleaseCacheRefList(
    Widget ,
    XtPointer ,
    XtPointer
);
extern void XtSetWMColormapWindows(
    Widget ,
    Widget* ,
    Cardinal
);
extern String XtFindFile(
    const char* ,
    Substitution ,
    Cardinal ,
    XtFilePredicate
);
extern String XtResolvePathname(
    Display* ,
    const char* ,
    const char* ,
    const char* ,
    const char* ,
    Substitution ,
    Cardinal ,
    XtFilePredicate
);
extern void XtDisownSelection(
    Widget ,
    Atom ,
    Time
);
extern void XtGetSelectionValue(
    Widget ,
    Atom ,
    Atom ,
    XtSelectionCallbackProc ,
    XtPointer ,
    Time
);
extern void XtGetSelectionValues(
    Widget ,
    Atom ,
    Atom* ,
    int ,
    XtSelectionCallbackProc ,
    XtPointer* ,
    Time
);
extern void XtAppSetSelectionTimeout(
    XtAppContext ,
    unsigned long
);
extern void XtSetSelectionTimeout(
    unsigned long
);
extern unsigned long XtAppGetSelectionTimeout(
    XtAppContext
);
extern unsigned long XtGetSelectionTimeout(
    void
);
extern XSelectionRequestEvent *XtGetSelectionRequest(
    Widget ,
    Atom ,
    XtRequestId
);
extern void XtGetSelectionValueIncremental(
    Widget ,
    Atom ,
    Atom ,
    XtSelectionCallbackProc ,
    XtPointer ,
    Time
);
extern void XtGetSelectionValuesIncremental(
    Widget ,
    Atom ,
    Atom* ,
    int ,
    XtSelectionCallbackProc ,
    XtPointer* ,
    Time
);
extern void XtSetSelectionParameters(
    Widget ,
    Atom ,
    Atom ,
    XtPointer ,
    unsigned long ,
    int
);
extern void XtGetSelectionParameters(
    Widget ,
    Atom ,
    XtRequestId ,
    Atom* ,
    XtPointer* ,
    unsigned long* ,
    int*
);
extern void XtCreateSelectionRequest(
    Widget ,
    Atom
);
extern void XtSendSelectionRequest(
    Widget ,
    Atom ,
    Time
);
extern void XtCancelSelectionRequest(
    Widget ,
    Atom
);
extern Atom XtReservePropertyAtom(
    Widget
);
extern void XtReleasePropertyAtom(
    Widget ,
    Atom
);
extern void XtGrabKey(
    Widget ,
    KeyCode ,
    Modifiers ,
    Boolean ,
    int ,
    int
);
extern void XtUngrabKey(
    Widget ,
    KeyCode ,
    Modifiers
);
extern int XtGrabKeyboard(
    Widget ,
    Boolean ,
    int ,
    int ,
    Time
);
extern void XtUngrabKeyboard(
    Widget ,
    Time
);
extern void XtGrabButton(
    Widget ,
    int ,
    Modifiers ,
    Boolean ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor
);
extern void XtUngrabButton(
    Widget ,
    unsigned int ,
    Modifiers
);
extern int XtGrabPointer(
    Widget ,
    Boolean ,
    unsigned int ,
    int ,
    int ,
    Window ,
    Cursor ,
    Time
);
extern void XtUngrabPointer(
    Widget ,
    Time
);
extern void XtGetApplicationNameAndClass(
    Display* ,
    String* ,
    String*
);
extern void XtRegisterDrawable(
    Display* ,
    Drawable ,
    Widget
);
extern void XtUnregisterDrawable(
    Display* ,
    Drawable
);
extern Widget XtHooksOfDisplay(
    Display*
);
typedef struct {
    String type;
    Widget widget;
    ArgList args;
    Cardinal num_args;
} XtCreateHookDataRec, *XtCreateHookData;
typedef struct {
    String type;
    Widget widget;
    XtPointer event_data;
    Cardinal num_event_data;
} XtChangeHookDataRec, *XtChangeHookData;
typedef struct {
    Widget old, req;
    ArgList args;
    Cardinal num_args;
} XtChangeHookSetValuesDataRec, *XtChangeHookSetValuesData;
typedef struct {
    String type;
    Widget widget;
    XtGeometryMask changeMask;
    XWindowChanges changes;
} XtConfigureHookDataRec, *XtConfigureHookData;
typedef struct {
    String type;
    Widget widget;
    XtWidgetGeometry* request;
    XtWidgetGeometry* reply;
    XtGeometryResult result;
} XtGeometryHookDataRec, *XtGeometryHookData;
typedef struct {
    String type;
    Widget widget;
} XtDestroyHookDataRec, *XtDestroyHookData;
extern void XtGetDisplays(
    XtAppContext ,
    Display*** ,
    Cardinal*
);
extern Boolean XtToolkitThreadInitialize(
    void
);
extern void XtAppSetExitFlag(
    XtAppContext
);
extern Boolean XtAppGetExitFlag(
    XtAppContext
);
extern void XtAppLock(
    XtAppContext
);
extern void XtAppUnlock(
    XtAppContext
);
extern Boolean XtCvtStringToAcceleratorTable(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToAtom(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToBool(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToBoolean(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToCommandArgArray(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToCursor(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToDimension(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToDirectoryString(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToDisplay(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToFile(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToFloat(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToFont(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToFontSet(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToFontStruct(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToGravity(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToInitialState(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToInt(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToPixel(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToRestartStyle(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToShort(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToTranslationTable(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToUnsignedChar(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtStringToVisual(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToBool(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToBoolean(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToColor(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToFloat(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToFont(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToPixel(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToPixmap(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToShort(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtIntToUnsignedChar(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);
extern Boolean XtCvtColorToPixel(
    Display* ,
    XrmValuePtr ,
    Cardinal* ,
    XrmValuePtr ,
    XrmValuePtr ,
    XtPointer*
);

typedef struct filemark
{
    pos_T mark;
    int fnum;
} fmark_T;
typedef struct xfilemark
{
    fmark_T fmark;
    char_u *fname;
    time_T time_set;
} xfmark_T;
typedef struct taggy
{
    char_u *tagname;
    fmark_T fmark;
    int cur_match;
    int cur_fnum;
} taggy_T;
typedef struct
{
    int wo_arab;
    int wo_bri;
    char_u *wo_briopt;
    int wo_diff;
    long wo_fdc;
    int wo_fdc_save;
    int wo_fen;
    int wo_fen_save;
    char_u *wo_fdi;
    long wo_fdl;
    int wo_fdl_save;
    char_u *wo_fdm;
    char_u *wo_fdm_save;
    long wo_fml;
    long wo_fdn;
    char_u *wo_fde;
    char_u *wo_fdt;
    char_u *wo_fmr;
    int wo_lbr;
    int wo_list;
    int wo_nu;
    int wo_rnu;
    long wo_nuw;
    int wo_wfh;
    int wo_wfw;
    int wo_pvw;
    int wo_rl;
    char_u *wo_rlc;
    long wo_scr;
    int wo_spell;
    int wo_cuc;
    int wo_cul;
    char_u *wo_cc;
    char_u *wo_stl;
    int wo_scb;
    int wo_diff_saved;
    int wo_scb_save;
    int wo_wrap;
    int wo_wrap_save;
    char_u *wo_cocu;
    long wo_cole;
    int wo_crb;
    int wo_crb_save;
    char_u *wo_scl;
    char_u *wo_tk;
    char_u *wo_tms;
    int wo_scriptID[WV_COUNT];
} winopt_T;
struct wininfo_S
{
    wininfo_T *wi_next;
    wininfo_T *wi_prev;
    win_T *wi_win;
    pos_T wi_fpos;
    int wi_optset;
    winopt_T wi_opt;
    int wi_fold_manual;
    garray_T wi_folds;
};
typedef struct foldinfo
{
    int fi_level;
    int fi_lnum;
    int fi_low_level;
} foldinfo_T;
typedef struct
{
    pos_T vi_start;
    pos_T vi_end;
    int vi_mode;
    colnr_T vi_curswant;
} visualinfo_T;
typedef struct u_entry u_entry_T;
typedef struct u_header u_header_T;
struct u_entry
{
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long ue_size;
};
struct u_header
{
    union {
 u_header_T *ptr;
 long seq;
    } uh_next;
    union {
 u_header_T *ptr;
 long seq;
    } uh_prev;
    union {
 u_header_T *ptr;
 long seq;
    } uh_alt_next;
    union {
 u_header_T *ptr;
 long seq;
    } uh_alt_prev;
    long uh_seq;
    int uh_walk;
    u_entry_T *uh_entry;
    u_entry_T *uh_getbot_entry;
    pos_T uh_cursor;
    long uh_cursor_vcol;
    int uh_flags;
    pos_T uh_namedm[('z' - 'a' + 1)];
    visualinfo_T uh_visual;
    time_T uh_time;
    long uh_save_nr;
};
typedef struct m_info minfo_T;
struct m_info
{
    long_u m_size;
    minfo_T *m_next;
};
typedef struct block_hdr bhdr_T;
typedef struct memfile memfile_T;
typedef long blocknr_T;
typedef struct mf_hashitem_S mf_hashitem_T;
struct mf_hashitem_S
{
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
};
typedef struct mf_hashtab_S
{
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets[64];
    char mht_fixed;
} mf_hashtab_T;
struct block_hdr
{
    mf_hashitem_T bh_hashitem;
    bhdr_T *bh_next;
    bhdr_T *bh_prev;
    char_u *bh_data;
    int bh_page_count;
    char bh_flags;
};
typedef struct nr_trans NR_TRANS;
struct nr_trans
{
    mf_hashitem_T nt_hashitem;
    blocknr_T nt_new_bnum;
};
typedef struct buffblock buffblock_T;
typedef struct buffheader buffheader_T;
struct buffblock
{
    buffblock_T *b_next;
    char_u b_str[1];
};
struct buffheader
{
    buffblock_T bh_first;
    buffblock_T *bh_curr;
    int bh_index;
    int bh_space;
};
typedef struct
{
    buffheader_T sr_redobuff;
    buffheader_T sr_old_redobuff;
} save_redo_T;
typedef struct expand
{
    int xp_context;
    char_u *xp_pattern;
    int xp_pattern_len;
    char_u *xp_arg;
    int xp_scriptID;
    int xp_backslash;
    int xp_shell;
    int xp_numfiles;
    char_u **xp_files;
    char_u *xp_line;
    int xp_col;
} expand_T;
typedef struct
{
    int hide;
    int browse;
    int split;
    int tab;
    int confirm;
    int keepalt;
    int keepmarks;
    int keepjumps;
    int lockmarks;
    int keeppatterns;
    int noswapfile;
    char_u *save_ei;
    regmatch_T filter_regmatch;
    int filter_force;
} cmdmod_T;
struct memfile
{
    char_u *mf_fname;
    char_u *mf_ffname;
    int mf_fd;
    bhdr_T *mf_free_first;
    bhdr_T *mf_used_first;
    bhdr_T *mf_used_last;
    unsigned mf_used_count;
    unsigned mf_used_count_max;
    mf_hashtab_T mf_hash;
    mf_hashtab_T mf_trans;
    blocknr_T mf_blocknr_max;
    blocknr_T mf_blocknr_min;
    blocknr_T mf_neg_count;
    blocknr_T mf_infile_count;
    unsigned mf_page_size;
    int mf_dirty;
    buf_T *mf_buffer;
    char_u mf_seed[8];
    char_u *mf_old_key;
    int mf_old_cm;
    char_u mf_old_seed[8];
};
typedef struct info_pointer
{
    blocknr_T ip_bnum;
    linenr_T ip_low;
    linenr_T ip_high;
    int ip_index;
} infoptr_T;
typedef struct ml_chunksize
{
    int mlcs_numlines;
    long mlcs_totalsize;
} chunksize_T;
typedef struct memline
{
    linenr_T ml_line_count;
    memfile_T *ml_mfp;
    int ml_flags;
    infoptr_T *ml_stack;
    int ml_stack_top;
    int ml_stack_size;
    linenr_T ml_line_lnum;
    char_u *ml_line_ptr;
    bhdr_T *ml_locked;
    linenr_T ml_locked_low;
    linenr_T ml_locked_high;
    int ml_locked_lineadd;
    chunksize_T *ml_chunksize;
    int ml_numchunks;
    int ml_usedchunks;
} memline_T;
typedef struct signlist signlist_T;
struct signlist
{
    int id;
    linenr_T lnum;
    int typenr;
    signlist_T *next;
    signlist_T *prev;
};
typedef struct arglist
{
    garray_T al_ga;
    int al_refcount;
    int id;
} alist_T;
typedef struct argentry
{
    char_u *ae_fname;
    int ae_fnum;
} aentry_T;
typedef struct eslist_elem eslist_T;
struct eslist_elem
{
    int saved_emsg_silent;
    eslist_T *next;
};
struct condstack
{
    short cs_flags[50];
    char cs_pending[50];
    union {
 void *csp_rv[50];
 void *csp_ex[50];
    } cs_pend;
    void *cs_forinfo[50];
    int cs_line[50];
    int cs_idx;
    int cs_looplevel;
    int cs_trylevel;
    eslist_T *cs_emsg_silent_list;
    char cs_lflags;
};
struct msglist
{
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
};
typedef enum
{
    ET_USER,
    ET_ERROR,
    ET_INTERRUPT
} except_type_T;
typedef struct vim_exception except_T;
struct vim_exception
{
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
};
typedef struct cleanup_stuff cleanup_T;
struct cleanup_stuff
{
    int pending;
    except_T *exception;
};
struct sp_syn
{
    int inc_tag;
    short id;
    short *cont_in_list;
};
typedef struct keyentry keyentry_T;
struct keyentry
{
    keyentry_T *ke_next;
    struct sp_syn k_syn;
    short *next_list;
    int flags;
    int k_char;
    char_u keyword[1];
};
typedef struct buf_state
{
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
} bufstate_T;
typedef struct syn_state synstate_T;
struct syn_state
{
    synstate_T *sst_next;
    linenr_T sst_lnum;
    union
    {
 bufstate_T sst_stack[7];
 garray_T sst_ga;
    } sst_union;
    int sst_next_flags;
    int sst_stacksize;
    short *sst_next_list;
    disptick_T sst_tick;
    linenr_T sst_change_lnum;
};
typedef struct attr_entry
{
    short ae_attr;
    union
    {
 struct
 {
     char_u *start;
     char_u *stop;
 } term;
 struct
 {
     short_u fg_color;
     short_u bg_color;
     long fg_rgb;
     long bg_rgb;
 } cterm;
    } ae_u;
} attrentry_T;

typedef void *iconv_t;
extern iconv_t iconv_open (const char *__tocode, const char *__fromcode);
extern size_t iconv (iconv_t __cd, char **__restrict __inbuf,
       size_t *__restrict __inbytesleft,
       char **__restrict __outbuf,
       size_t *__restrict __outbytesleft);
extern int iconv_close (iconv_t __cd);

typedef struct
{
    char_u *tb_buf;
    char_u *tb_noremap;
    int tb_buflen;
    int tb_off;
    int tb_len;
    int tb_maplen;
    int tb_silent;
    int tb_no_abbr_cnt;
    int tb_change_cnt;
} typebuf_T;
typedef struct
{
    typebuf_T save_typebuf;
    int typebuf_valid;
    int old_char;
    int old_mod_mask;
    buffheader_T save_readbuf1;
    buffheader_T save_readbuf2;
    char_u *save_inputbuf;
} tasave_T;
typedef struct
{
    int vc_type;
    int vc_factor;
    iconv_t vc_fd;
    int vc_fail;
} vimconv_T;
typedef struct
{
    char_u *vir_line;
    FILE *vir_fd;
    vimconv_T vir_conv;
    int vir_version;
    garray_T vir_barlines;
} vir_T;
typedef struct mapblock mapblock_T;
struct mapblock
{
    mapblock_T *m_next;
    char_u *m_keys;
    char_u *m_str;
    char_u *m_orig_str;
    int m_keylen;
    int m_mode;
    int m_noremap;
    char m_silent;
    char m_nowait;
    char m_expr;
    scid_T m_script_ID;
};
struct stl_hlrec
{
    char_u *start;
    int userhl;
};
typedef struct hashitem_S
{
    long_u hi_hash;
    char_u *hi_key;
} hashitem_T;
typedef struct hashtable_S
{
    long_u ht_mask;
    long_u ht_used;
    long_u ht_filled;
    int ht_locked;
    int ht_error;
    hashitem_T *ht_array;
    hashitem_T ht_smallarray[16];
} hashtab_T;
typedef long_u hash_T;
typedef int64_t varnumber_T;
typedef uint64_t uvarnumber_T;
typedef double float_T;
typedef struct listvar_S list_T;
typedef struct dictvar_S dict_T;
typedef struct partial_S partial_T;
typedef struct jobvar_S job_T;
typedef struct readq_S readq_T;
typedef struct writeq_S writeq_T;
typedef struct jsonq_S jsonq_T;
typedef struct cbq_S cbq_T;
typedef struct channel_S channel_T;
typedef enum
{
    VAR_UNKNOWN = 0,
    VAR_NUMBER,
    VAR_STRING,
    VAR_FUNC,
    VAR_PARTIAL,
    VAR_LIST,
    VAR_DICT,
    VAR_FLOAT,
    VAR_SPECIAL,
    VAR_JOB,
    VAR_CHANNEL
} vartype_T;
typedef struct
{
    vartype_T v_type;
    char v_lock;
    union
    {
 varnumber_T v_number;
 float_T v_float;
 char_u *v_string;
 list_T *v_list;
 dict_T *v_dict;
 partial_T *v_partial;
 job_T *v_job;
 channel_T *v_channel;
    } vval;
} typval_T;
typedef struct listitem_S listitem_T;
struct listitem_S
{
    listitem_T *li_next;
    listitem_T *li_prev;
    typval_T li_tv;
};
typedef struct listwatch_S listwatch_T;
struct listwatch_S
{
    listitem_T *lw_item;
    listwatch_T *lw_next;
};
struct listvar_S
{
    listitem_T *lv_first;
    listitem_T *lv_last;
    int lv_refcount;
    int lv_len;
    listwatch_T *lv_watch;
    int lv_idx;
    listitem_T *lv_idx_item;
    int lv_copyID;
    list_T *lv_copylist;
    char lv_lock;
    list_T *lv_used_next;
    list_T *lv_used_prev;
};
typedef struct {
    list_T sl_list;
    listitem_T sl_items[10];
} staticList10_T;
struct dictitem_S
{
    typval_T di_tv;
    char_u di_flags;
    char_u di_key[1];
};
typedef struct dictitem_S dictitem_T;
struct dictitem16_S
{
    typval_T di_tv;
    char_u di_flags;
    char_u di_key[17];
};
typedef struct dictitem16_S dictitem16_T;
struct dictvar_S
{
    char dv_lock;
    char dv_scope;
    int dv_refcount;
    int dv_copyID;
    hashtab_T dv_hashtab;
    dict_T *dv_copydict;
    dict_T *dv_used_next;
    dict_T *dv_used_prev;
};
typedef struct funccall_S funccall_T;
typedef struct
{
    int uf_varargs;
    int uf_flags;
    int uf_calls;
    int uf_cleared;
    garray_T uf_args;
    garray_T uf_lines;
    int uf_profiling;
    int uf_tm_count;
    proftime_T uf_tm_total;
    proftime_T uf_tm_self;
    proftime_T uf_tm_children;
    int *uf_tml_count;
    proftime_T *uf_tml_total;
    proftime_T *uf_tml_self;
    proftime_T uf_tml_start;
    proftime_T uf_tml_children;
    proftime_T uf_tml_wait;
    int uf_tml_idx;
    int uf_tml_execed;
    scid_T uf_script_ID;
    int uf_refcount;
    funccall_T *uf_scoped;
    char_u uf_name[1];
} ufunc_T;
struct funccall_S
{
    ufunc_T *func;
    int linenr;
    int returned;
    struct
    {
 dictitem_T var;
 char_u room[20];
    } fixvar[12];
    dict_T l_vars;
    dictitem_T l_vars_var;
    dict_T l_avars;
    dictitem_T l_avars_var;
    list_T l_varlist;
    listitem_T l_listitems[20];
    typval_T *rettv;
    linenr_T breakpoint;
    int dbg_tick;
    int level;
    proftime_T prof_child;
    funccall_T *caller;
    int fc_refcount;
    int fc_copyID;
    garray_T fc_funcs;
};
typedef struct
{
    dict_T *fd_dict;
    char_u *fd_newkey;
    dictitem_T *fd_di;
} funcdict_T;
struct partial_S
{
    int pt_refcount;
    char_u *pt_name;
    ufunc_T *pt_func;
    int pt_auto;
    int pt_argc;
    typval_T *pt_argv;
    dict_T *pt_dict;
};
typedef struct {
    int backspace;
    int enter;
    int interrupt;
    int nl_does_cr;
} ttyinfo_T;
typedef enum
{
    JOB_FAILED,
    JOB_STARTED,
    JOB_ENDED,
    JOB_FINISHED
} jobstatus_T;
struct jobvar_S
{
    job_T *jv_next;
    job_T *jv_prev;
    pid_t jv_pid;
    char_u *jv_tty_in;
    char_u *jv_tty_out;
    jobstatus_T jv_status;
    char_u *jv_stoponexit;
    int jv_exitval;
    char_u *jv_exit_cb;
    partial_T *jv_exit_partial;
    buf_T *jv_in_buf;
    int jv_refcount;
    int jv_copyID;
    channel_T *jv_channel;
};
struct readq_S
{
    char_u *rq_buffer;
    long_u rq_buflen;
    readq_T *rq_next;
    readq_T *rq_prev;
};
struct writeq_S
{
    garray_T wq_ga;
    writeq_T *wq_next;
    writeq_T *wq_prev;
};
struct jsonq_S
{
    typval_T *jq_value;
    jsonq_T *jq_next;
    jsonq_T *jq_prev;
    int jq_no_callback;
};
struct cbq_S
{
    char_u *cq_callback;
    partial_T *cq_partial;
    int cq_seq_nr;
    cbq_T *cq_next;
    cbq_T *cq_prev;
};
typedef enum
{
    MODE_NL = 0,
    MODE_RAW,
    MODE_JSON,
    MODE_JS
} ch_mode_T;
typedef enum {
    JIO_PIPE,
    JIO_NULL,
    JIO_FILE,
    JIO_BUFFER,
    JIO_OUT
} job_io_T;
typedef enum {
    PART_SOCK = 0,
    PART_OUT,
    PART_ERR,
    PART_IN,
    PART_COUNT
} ch_part_T;
typedef struct {
    sock_T ch_fd;
    ch_mode_T ch_mode;
    job_io_T ch_io;
    int ch_timeout;
    readq_T ch_head;
    jsonq_T ch_json_head;
    int ch_block_id;
    size_t ch_wait_len;
    struct timeval ch_deadline;
    int ch_block_write;
    int ch_nonblocking;
    writeq_T ch_writeque;
    cbq_T ch_cb_head;
    char_u *ch_callback;
    partial_T *ch_partial;
    bufref_T ch_bufref;
    int ch_nomodifiable;
    int ch_nomod_error;
    int ch_buf_append;
    linenr_T ch_buf_top;
    linenr_T ch_buf_bot;
} chanpart_T;
struct channel_S {
    channel_T *ch_next;
    channel_T *ch_prev;
    int ch_id;
    int ch_last_msg_id;
    chanpart_T ch_part[PART_COUNT];
    int ch_write_text_mode;
    char *ch_hostname;
    int ch_port;
    int ch_to_be_closed;
    int ch_to_be_freed;
    int ch_error;
    void (*ch_nb_close_cb)(void);
    char_u *ch_callback;
    partial_T *ch_partial;
    char_u *ch_close_cb;
    partial_T *ch_close_partial;
    int ch_drop_never;
    int ch_keep_open;
    job_T *ch_job;
    int ch_job_killed;
    int ch_refcount;
    int ch_copyID;
};
typedef struct
{
    int jo_set;
    int jo_set2;
    ch_mode_T jo_mode;
    ch_mode_T jo_in_mode;
    ch_mode_T jo_out_mode;
    ch_mode_T jo_err_mode;
    job_io_T jo_io[4];
    char_u jo_io_name_buf[4][65];
    char_u *jo_io_name[4];
    int jo_io_buf[4];
    int jo_pty;
    int jo_modifiable[4];
    int jo_message[4];
    channel_T *jo_channel;
    linenr_T jo_in_top;
    linenr_T jo_in_bot;
    char_u *jo_callback;
    partial_T *jo_partial;
    char_u *jo_out_cb;
    partial_T *jo_out_partial;
    char_u *jo_err_cb;
    partial_T *jo_err_partial;
    char_u *jo_close_cb;
    partial_T *jo_close_partial;
    char_u *jo_exit_cb;
    partial_T *jo_exit_partial;
    int jo_drop_never;
    int jo_waittime;
    int jo_timeout;
    int jo_out_timeout;
    int jo_err_timeout;
    int jo_block_write;
    int jo_part;
    int jo_id;
    char_u jo_soe_buf[65];
    char_u *jo_stoponexit;
    dict_T *jo_env;
    char_u jo_cwd_buf[65];
    char_u *jo_cwd;
    int jo_term_rows;
    int jo_term_cols;
    int jo_vertical;
    int jo_curwin;
    int jo_hidden;
    char_u *jo_term_name;
    char_u *jo_term_opencmd;
    int jo_term_finish;
    char_u *jo_eof_chars;
} jobopt_T;
typedef struct ht_stack_S
{
    hashtab_T *ht;
    struct ht_stack_S *prev;
} ht_stack_T;
typedef struct list_stack_S
{
    list_T *list;
    struct list_stack_S *prev;
} list_stack_T;
typedef struct qf_info_S qf_info_T;
typedef struct {
    proftime_T total;
    proftime_T slowest;
    long count;
    long match;
} syn_time_T;
typedef struct {
    int method_nr;
    void *method_state;
} cryptstate_T;
typedef struct {
    hashtab_T b_keywtab;
    hashtab_T b_keywtab_ic;
    int b_syn_error;
    int b_syn_slow;
    int b_syn_ic;
    int b_syn_spell;
    garray_T b_syn_patterns;
    garray_T b_syn_clusters;
    int b_spell_cluster_id;
    int b_nospell_cluster_id;
    int b_syn_containedin;
    int b_syn_sync_flags;
    short b_syn_sync_id;
    long b_syn_sync_minlines;
    long b_syn_sync_maxlines;
    long b_syn_sync_linebreaks;
    char_u *b_syn_linecont_pat;
    regprog_T *b_syn_linecont_prog;
    syn_time_T b_syn_linecont_time;
    int b_syn_linecont_ic;
    int b_syn_topgrp;
    int b_syn_conceal;
    int b_syn_folditems;
    synstate_T *b_sst_array;
    int b_sst_len;
    synstate_T *b_sst_first;
    synstate_T *b_sst_firstfree;
    int b_sst_freecount;
    linenr_T b_sst_check_lnum;
    short_u b_sst_lasttick;
    garray_T b_langp;
    char_u b_spell_ismw[256];
    char_u *b_spell_ismw_mb;
    char_u *b_p_spc;
    regprog_T *b_cap_prog;
    char_u *b_p_spf;
    char_u *b_p_spl;
    int b_cjk;
    char_u b_syn_chartab[32];
    char_u *b_syn_isk;
} synblock_T;
struct file_buffer
{
    memline_T b_ml;
    buf_T *b_next;
    buf_T *b_prev;
    int b_nwindows;
    int b_flags;
    int b_locked;
    char_u *b_ffname;
    char_u *b_sfname;
    char_u *b_fname;
    int b_dev_valid;
    dev_t b_dev;
    ino_t b_ino;
    int b_fnum;
    char_u b_key[4 * 2 + 1];
    int b_changed;
    dictitem16_T b_ct_di;
    int b_saving;
    int b_mod_set;
    linenr_T b_mod_top;
    linenr_T b_mod_bot;
    long b_mod_xlines;
    wininfo_T *b_wininfo;
    long b_mtime;
    long b_mtime_read;
    off_T b_orig_size;
    int b_orig_mode;
    time_T b_last_used;
    pos_T b_namedm[('z' - 'a' + 1)];
    visualinfo_T b_visual;
    int b_visual_mode_eval;
    pos_T b_last_cursor;
    pos_T b_last_insert;
    pos_T b_last_change;
    pos_T b_changelist[100];
    int b_changelistlen;
    int b_new_change;
    char_u b_chartab[32];
    mapblock_T *(b_maphash[256]);
    mapblock_T *b_first_abbr;
    garray_T b_ucmds;
    pos_T b_op_start;
    pos_T b_op_start_orig;
    pos_T b_op_end;
    int b_marks_read;
    u_header_T *b_u_oldhead;
    u_header_T *b_u_newhead;
    u_header_T *b_u_curhead;
    int b_u_numhead;
    int b_u_synced;
    long b_u_seq_last;
    long b_u_save_nr_last;
    long b_u_seq_cur;
    time_T b_u_time_cur;
    long b_u_save_nr_cur;
    char_u *b_u_line_ptr;
    linenr_T b_u_line_lnum;
    colnr_T b_u_line_colnr;
    int b_scanned;
    long b_p_iminsert;
    long b_p_imsearch;
    short b_kmap_state;
    garray_T b_kmap_ga;
    int b_p_initialized;
    int b_p_scriptID[BV_COUNT];
    int b_p_ai;
    int b_p_ai_nopaste;
    char_u *b_p_bkc;
    unsigned b_bkc_flags;
    int b_p_ci;
    int b_p_bin;
    int b_p_bomb;
    char_u *b_p_bh;
    char_u *b_p_bt;
    int b_has_qf_entry;
    int b_p_bl;
    int b_p_cin;
    char_u *b_p_cino;
    char_u *b_p_cink;
    char_u *b_p_cinw;
    char_u *b_p_com;
    char_u *b_p_cms;
    char_u *b_p_cpt;
    char_u *b_p_cfu;
    char_u *b_p_ofu;
    int b_p_eol;
    int b_p_fixeol;
    int b_p_et;
    int b_p_et_nobin;
    int b_p_et_nopaste;
    char_u *b_p_fenc;
    char_u *b_p_ff;
    char_u *b_p_ft;
    char_u *b_p_fo;
    char_u *b_p_flp;
    int b_p_inf;
    char_u *b_p_isk;
    char_u *b_p_def;
    char_u *b_p_inc;
    char_u *b_p_inex;
    long_u b_p_inex_flags;
    char_u *b_p_inde;
    long_u b_p_inde_flags;
    char_u *b_p_indk;
    char_u *b_p_fp;
    char_u *b_p_fex;
    long_u b_p_fex_flags;
    char_u *b_p_key;
    char_u *b_p_kp;
    int b_p_lisp;
    char_u *b_p_menc;
    char_u *b_p_mps;
    int b_p_ml;
    int b_p_ml_nobin;
    int b_p_ma;
    char_u *b_p_nf;
    int b_p_pi;
    char_u *b_p_qe;
    int b_p_ro;
    long b_p_sw;
    int b_p_sn;
    int b_p_si;
    long b_p_sts;
    long b_p_sts_nopaste;
    char_u *b_p_sua;
    int b_p_swf;
    long b_p_smc;
    char_u *b_p_syn;
    long b_p_ts;
    int b_p_tx;
    long b_p_tw;
    long b_p_tw_nobin;
    long b_p_tw_nopaste;
    long b_p_wm;
    long b_p_wm_nobin;
    long b_p_wm_nopaste;
    char_u *b_p_keymap;
    char_u *b_p_gp;
    char_u *b_p_mp;
    char_u *b_p_efm;
    char_u *b_p_ep;
    char_u *b_p_path;
    int b_p_ar;
    char_u *b_p_tags;
    char_u *b_p_tc;
    unsigned b_tc_flags;
    char_u *b_p_dict;
    char_u *b_p_tsr;
    long b_p_ul;
    int b_p_udf;
    char_u *b_p_lw;
    int b_ind_level;
    int b_ind_open_imag;
    int b_ind_no_brace;
    int b_ind_first_open;
    int b_ind_open_extra;
    int b_ind_close_extra;
    int b_ind_open_left_imag;
    int b_ind_jump_label;
    int b_ind_case;
    int b_ind_case_code;
    int b_ind_case_break;
    int b_ind_param;
    int b_ind_func_type;
    int b_ind_comment;
    int b_ind_in_comment;
    int b_ind_in_comment2;
    int b_ind_cpp_baseclass;
    int b_ind_continuation;
    int b_ind_unclosed;
    int b_ind_unclosed2;
    int b_ind_unclosed_noignore;
    int b_ind_unclosed_wrapped;
    int b_ind_unclosed_whiteok;
    int b_ind_matching_paren;
    int b_ind_paren_prev;
    int b_ind_maxparen;
    int b_ind_maxcomment;
    int b_ind_scopedecl;
    int b_ind_scopedecl_code;
    int b_ind_java;
    int b_ind_js;
    int b_ind_keep_case_label;
    int b_ind_hash_comment;
    int b_ind_cpp_namespace;
    int b_ind_if_for_while;
    int b_ind_cpp_extern_c;
    linenr_T b_no_eol_lnum;
    int b_start_eol;
    int b_start_ffc;
    char_u *b_start_fenc;
    int b_bad_char;
    int b_start_bomb;
    dictitem_T b_bufvar;
    dict_T *b_vars;
    char_u *b_p_cm;
    int b_may_swap;
    int b_did_warn;
    int b_help;
    int b_spell;
    int b_shortname;
    synblock_T b_s;
    signlist_T *b_signlist;
    int b_has_sign_column;
    int b_netbeans_file;
    int b_was_netbeans_file;
    int b_write_to_channel;
    cryptstate_T *b_cryptstate;
    int b_mapped_ctrl_c;
    term_T *b_term;
};
typedef struct diffblock_S diff_T;
struct diffblock_S
{
    diff_T *df_next;
    linenr_T df_lnum[8];
    linenr_T df_count[8];
};
typedef struct tabpage_S tabpage_T;
struct tabpage_S
{
    tabpage_T *tp_next;
    frame_T *tp_topframe;
    win_T *tp_curwin;
    win_T *tp_prevwin;
    win_T *tp_firstwin;
    win_T *tp_lastwin;
    long tp_old_Rows;
    long tp_old_Columns;
    long tp_ch_used;
    diff_T *tp_first_diff;
    buf_T *(tp_diffbuf[8]);
    int tp_diff_invalid;
    frame_T *(tp_snapshot[2]);
    dictitem_T tp_winvar;
    dict_T *tp_vars;
};
typedef struct w_line
{
    linenr_T wl_lnum;
    short_u wl_size;
    char wl_valid;
    char wl_folded;
    linenr_T wl_lastlnum;
} wline_T;
struct frame_S
{
    char fr_layout;
    int fr_width;
    int fr_newwidth;
    int fr_height;
    int fr_newheight;
    frame_T *fr_parent;
    frame_T *fr_next;
    frame_T *fr_prev;
    frame_T *fr_child;
    win_T *fr_win;
};
typedef struct
{
    regmmatch_T rm;
    buf_T *buf;
    linenr_T lnum;
    int attr;
    int attr_cur;
    linenr_T first_lnum;
    colnr_T startcol;
    colnr_T endcol;
    int is_addpos;
    proftime_T tm;
} match_T;
typedef struct
{
    linenr_T lnum;
    colnr_T col;
    int len;
} llpos_T;
typedef struct posmatch posmatch_T;
struct posmatch
{
    llpos_T pos[8];
    int cur;
    linenr_T toplnum;
    linenr_T botlnum;
};
typedef struct matchitem matchitem_T;
struct matchitem
{
    matchitem_T *next;
    int id;
    int priority;
    char_u *pattern;
    int hlg_id;
    regmmatch_T match;
    posmatch_T pos;
    match_T hl;
    int conceal_char;
};
typedef struct {
    int wb_startcol;
    int wb_endcol;
    vimmenu_T *wb_menu;
} winbar_item_T;
struct window_S
{
    int w_id;
    buf_T *w_buffer;
    synblock_T *w_s;
    win_T *w_prev;
    win_T *w_next;
    int w_closing;
    frame_T *w_frame;
    pos_T w_cursor;
    colnr_T w_curswant;
    int w_set_curswant;
    char w_old_visual_mode;
    linenr_T w_old_cursor_lnum;
    colnr_T w_old_cursor_fcol;
    colnr_T w_old_cursor_lcol;
    linenr_T w_old_visual_lnum;
    colnr_T w_old_visual_col;
    colnr_T w_old_curswant;
    linenr_T w_topline;
    char w_topline_was_set;
    int w_topfill;
    int w_old_topfill;
    int w_botfill;
    int w_old_botfill;
    colnr_T w_leftcol;
    colnr_T w_skipcol;
    int w_winrow;
    int w_height;
    int w_status_height;
    int w_wincol;
    int w_width;
    int w_vsep_width;
    int w_valid;
    pos_T w_valid_cursor;
    colnr_T w_valid_leftcol;
    int w_cline_height;
    int w_cline_folded;
    int w_cline_row;
    colnr_T w_virtcol;
    int w_wrow, w_wcol;
    linenr_T w_botline;
    int w_empty_rows;
    int w_filler_rows;
    int w_lines_valid;
    wline_T *w_lines;
    garray_T w_folds;
    char w_fold_manual;
    char w_foldinvalid;
    int w_nrwidth;
    int w_redr_type;
    int w_upd_rows;
    linenr_T w_redraw_top;
    linenr_T w_redraw_bot;
    int w_redr_status;
    pos_T w_ru_cursor;
    colnr_T w_ru_virtcol;
    linenr_T w_ru_topline;
    linenr_T w_ru_line_count;
    int w_ru_topfill;
    char w_ru_empty;
    int w_alt_fnum;
    alist_T *w_alist;
    int w_arg_idx;
    int w_arg_idx_invalid;
    char_u *w_localdir;
    vimmenu_T *w_winbar;
    winbar_item_T *w_winbar_items;
    int w_winbar_height;
    winopt_T w_onebuf_opt;
    winopt_T w_allbuf_opt;
    long_u w_p_stl_flags;
    long_u w_p_fde_flags;
    long_u w_p_fdt_flags;
    int *w_p_cc_cols;
    int w_p_brimin;
    int w_p_brishift;
    int w_p_brisbr;
    long w_scbind_pos;
    dictitem_T w_winvar;
    dict_T *w_vars;
    int w_farsi;
    pos_T w_pcmark;
    pos_T w_prev_pcmark;
    xfmark_T w_jumplist[100];
    int w_jumplistlen;
    int w_jumplistidx;
    int w_changelistidx;
    matchitem_T *w_match_head;
    int w_next_match_id;
    taggy_T w_tagstack[20];
    int w_tagstackidx;
    int w_tagstacklen;
    int w_fraction;
    int w_prev_fraction_row;
    linenr_T w_nrwidth_line_count;
    long w_nuw_cached;
    int w_nrwidth_width;
    qf_info_T *w_llist;
    qf_info_T *w_llist_ref;
};
typedef struct oparg_S
{
    int op_type;
    int regname;
    int motion_type;
    int motion_force;
    int use_reg_one;
    int inclusive;
    int end_adjusted;
    pos_T start;
    pos_T end;
    pos_T cursor_start;
    long line_count;
    int empty;
    int is_VIsual;
    int block_mode;
    colnr_T start_vcol;
    colnr_T end_vcol;
    long prev_opcount;
    long prev_count0;
} oparg_T;
typedef struct cmdarg_S
{
    oparg_T *oap;
    int prechar;
    int cmdchar;
    int nchar;
    int ncharC1;
    int ncharC2;
    int extra_char;
    long opcount;
    long count0;
    long count1;
    int arg;
    int retval;
    char_u *searchbuf;
} cmdarg_T;
typedef struct cursor_entry
{
    int shape;
    int mshape;
    int percentage;
    long blinkwait;
    long blinkon;
    long blinkoff;
    int id;
    int id_lm;
    char *name;
    char used_for;
} cursorentry_T;
struct VimMenu
{
    int modes;
    int enabled;
    char_u *name;
    char_u *dname;
    char_u *en_name;
    char_u *en_dname;
    int mnemonic;
    char_u *actext;
    int priority;
    char_u *strings[7];
    int noremap[7];
    char silent[7];
    vimmenu_T *children;
    vimmenu_T *parent;
    vimmenu_T *next;
};
typedef struct
{
    buf_T *save_curbuf;
    int use_aucmd_win;
    win_T *save_curwin;
    win_T *new_curwin;
    bufref_T new_curbuf;
    char_u *globaldir;
} aco_save_T;
typedef struct
{
    const char *name;
    int hasnum;
    long number;
    char_u *string;
    int strlen;
    int present;
} option_table_T;
typedef struct
{
    long_u fg_color;
    long_u bg_color;
    int bold;
    int italic;
    int underline;
    int undercurl;
} prt_text_attr_T;
typedef struct
{
    int n_collated_copies;
    int n_uncollated_copies;
    int duplex;
    int chars_per_line;
    int lines_per_page;
    int has_color;
    prt_text_attr_T number;
    int modec;
    int do_syntax;
    int user_abort;
    char_u *jobname;
    char_u *outfile;
    char_u *arguments;
} prt_settings_T;
typedef struct
{
    char_u *pum_text;
    char_u *pum_kind;
    char_u *pum_extra;
    char_u *pum_info;
} pumitem_T;
typedef struct
{
    char_u *tn_tags;
    char_u *tn_np;
    int tn_did_filefind_init;
    int tn_hf_idx;
    void *tn_search_ctx;
} tagname_T;
typedef struct {
  UINT32_T total[2];
  UINT32_T state[8];
  char_u buffer[64];
} context_sha256_T;
struct js_reader
{
    char_u *js_buf;
    char_u *js_end;
    int js_used;
    int (*js_fill)(struct js_reader *);
    void *js_cookie;
    int js_cookie_arg;
};
typedef struct js_reader js_read_T;
typedef struct timer_S timer_T;
struct timer_S
{
    long tr_id;
    timer_T *tr_next;
    timer_T *tr_prev;
    proftime_T tr_due;
    char tr_firing;
    char tr_paused;
    int tr_repeat;
    long tr_interval;
    char_u *tr_callback;
    partial_T *tr_partial;
    int tr_emsg_count;
};
typedef struct
{
    int argc;
    char **argv;
    char_u *fname;
    int evim_mode;
    char_u *use_vimrc;
    int n_commands;
    char_u *commands[10];
    char_u cmds_tofree[10];
    int n_pre_commands;
    char_u *pre_commands[10];
    int edit_type;
    char_u *tagname;
    char_u *use_ef;
    int want_full_screen;
    int not_a_term;
    int tty_fail;
    char_u *term;
    int ask_for_key;
    int no_swap_file;
    int use_debug_break_level;
    int window_count;
    int window_layout;
    int serverArg;
    char_u *serverName_arg;
    char_u *serverStr;
    char_u *serverStrEnc;
    char_u *servername;
    int diff_mode;
} mparm_T;
typedef struct lval_S
{
    char_u *ll_name;
    char_u *ll_exp_name;
    typval_T *ll_tv;
    listitem_T *ll_li;
    list_T *ll_list;
    int ll_range;
    long ll_n1;
    long ll_n2;
    int ll_empty2;
    dict_T *ll_dict;
    dictitem_T *ll_di;
    char_u *ll_newkey;
} lval_T;
typedef struct {
    int save_msg_scroll;
    int save_restart_edit;
    int save_msg_didout;
    int save_State;
    int save_insertmode;
    int save_finish_op;
    int save_opcount;
    tasave_T tabuf;
} save_state_T;
typedef enum {
 aid_none = 0,
 aid_qf_dirname_start,
 aid_qf_dirname_now,
 aid_qf_namebuf,
 aid_qf_errmsg,
 aid_qf_pattern,
 aid_last
} alloc_id_T;
typedef struct VimClipboard
{
    int available;
    int owned;
    pos_T start;
    pos_T end;
    int vmode;
    short_u origin_row;
    short_u origin_start_col;
    short_u origin_end_col;
    short_u word_start_col;
    short_u word_end_col;
    pos_T prev;
    short_u state;
    short_u mode;
    Atom sel_atom;
} VimClipboard;
typedef struct stat stat_T;
typedef enum
{
    ASSERT_EQUAL,
    ASSERT_NOTEQUAL,
    ASSERT_MATCH,
    ASSERT_NOTMATCH,
    ASSERT_OTHER
} assert_type_T;
typedef enum {
    PASTE_INSERT,
    PASTE_CMDLINE,
    PASTE_EX,
    PASTE_ONE_CHAR
} paste_mode_T;
typedef struct exarg exarg_T;
enum CMD_index
{
CMD_append,
CMD_abbreviate,
CMD_abclear,
CMD_aboveleft,
CMD_all,
CMD_amenu,
CMD_anoremenu,
CMD_args,
CMD_argadd,
CMD_argdelete,
CMD_argdo,
CMD_argedit,
CMD_argglobal,
CMD_arglocal,
CMD_argument,
CMD_ascii,
CMD_autocmd,
CMD_augroup,
CMD_aunmenu,
CMD_buffer,
CMD_bNext,
CMD_ball,
CMD_badd,
CMD_bdelete,
CMD_behave,
CMD_belowright,
CMD_bfirst,
CMD_blast,
CMD_bmodified,
CMD_bnext,
CMD_botright,
CMD_bprevious,
CMD_brewind,
CMD_break,
CMD_breakadd,
CMD_breakdel,
CMD_breaklist,
CMD_browse,
CMD_buffers,
CMD_bufdo,
CMD_bunload,
CMD_bwipeout,
CMD_change,
CMD_cNext,
CMD_cNfile,
CMD_cabbrev,
CMD_cabclear,
CMD_caddbuffer,
CMD_caddexpr,
CMD_caddfile,
CMD_call,
CMD_catch,
CMD_cbuffer,
CMD_cbottom,
CMD_cc,
CMD_cclose,
CMD_cd,
CMD_cdo,
CMD_center,
CMD_cexpr,
CMD_cfile,
CMD_cfdo,
CMD_cfirst,
CMD_cgetfile,
CMD_cgetbuffer,
CMD_cgetexpr,
CMD_chdir,
CMD_changes,
CMD_checkpath,
CMD_checktime,
CMD_chistory,
CMD_clist,
CMD_clast,
CMD_close,
CMD_clearjumps,
CMD_cmap,
CMD_cmapclear,
CMD_cmenu,
CMD_cnext,
CMD_cnewer,
CMD_cnfile,
CMD_cnoremap,
CMD_cnoreabbrev,
CMD_cnoremenu,
CMD_copy,
CMD_colder,
CMD_colorscheme,
CMD_command,
CMD_comclear,
CMD_compiler,
CMD_continue,
CMD_confirm,
CMD_copen,
CMD_cprevious,
CMD_cpfile,
CMD_cquit,
CMD_crewind,
CMD_cscope,
CMD_cstag,
CMD_cunmap,
CMD_cunabbrev,
CMD_cunmenu,
CMD_cwindow,
CMD_delete,
CMD_delmarks,
CMD_debug,
CMD_debuggreedy,
CMD_delcommand,
CMD_delfunction,
CMD_display,
CMD_diffupdate,
CMD_diffget,
CMD_diffoff,
CMD_diffpatch,
CMD_diffput,
CMD_diffsplit,
CMD_diffthis,
CMD_digraphs,
CMD_djump,
CMD_dlist,
CMD_doautocmd,
CMD_doautoall,
CMD_drop,
CMD_dsearch,
CMD_dsplit,
CMD_edit,
CMD_earlier,
CMD_echo,
CMD_echoerr,
CMD_echohl,
CMD_echomsg,
CMD_echon,
CMD_else,
CMD_elseif,
CMD_emenu,
CMD_endif,
CMD_endfunction,
CMD_endfor,
CMD_endtry,
CMD_endwhile,
CMD_enew,
CMD_ex,
CMD_execute,
CMD_exit,
CMD_exusage,
CMD_file,
CMD_files,
CMD_filetype,
CMD_filter,
CMD_find,
CMD_finally,
CMD_finish,
CMD_first,
CMD_fixdel,
CMD_fold,
CMD_foldclose,
CMD_folddoopen,
CMD_folddoclosed,
CMD_foldopen,
CMD_for,
CMD_function,
CMD_global,
CMD_goto,
CMD_grep,
CMD_grepadd,
CMD_gui,
CMD_gvim,
CMD_help,
CMD_helpclose,
CMD_helpfind,
CMD_helpgrep,
CMD_helptags,
CMD_hardcopy,
CMD_highlight,
CMD_hide,
CMD_history,
CMD_insert,
CMD_iabbrev,
CMD_iabclear,
CMD_if,
CMD_ijump,
CMD_ilist,
CMD_imap,
CMD_imapclear,
CMD_imenu,
CMD_inoremap,
CMD_inoreabbrev,
CMD_inoremenu,
CMD_intro,
CMD_isearch,
CMD_isplit,
CMD_iunmap,
CMD_iunabbrev,
CMD_iunmenu,
CMD_join,
CMD_jumps,
CMD_k,
CMD_keepmarks,
CMD_keepjumps,
CMD_keeppatterns,
CMD_keepalt,
CMD_list,
CMD_lNext,
CMD_lNfile,
CMD_last,
CMD_language,
CMD_laddexpr,
CMD_laddbuffer,
CMD_laddfile,
CMD_later,
CMD_lbuffer,
CMD_lbottom,
CMD_lcd,
CMD_lchdir,
CMD_lclose,
CMD_lcscope,
CMD_ldo,
CMD_left,
CMD_leftabove,
CMD_let,
CMD_lexpr,
CMD_lfile,
CMD_lfdo,
CMD_lfirst,
CMD_lgetfile,
CMD_lgetbuffer,
CMD_lgetexpr,
CMD_lgrep,
CMD_lgrepadd,
CMD_lhelpgrep,
CMD_lhistory,
CMD_ll,
CMD_llast,
CMD_llist,
CMD_lmap,
CMD_lmapclear,
CMD_lmake,
CMD_lnoremap,
CMD_lnext,
CMD_lnewer,
CMD_lnfile,
CMD_loadview,
CMD_loadkeymap,
CMD_lockmarks,
CMD_lockvar,
CMD_lolder,
CMD_lopen,
CMD_lprevious,
CMD_lpfile,
CMD_lrewind,
CMD_ltag,
CMD_lunmap,
CMD_lua,
CMD_luado,
CMD_luafile,
CMD_lvimgrep,
CMD_lvimgrepadd,
CMD_lwindow,
CMD_ls,
CMD_move,
CMD_mark,
CMD_make,
CMD_map,
CMD_mapclear,
CMD_marks,
CMD_match,
CMD_menu,
CMD_menutranslate,
CMD_messages,
CMD_mkexrc,
CMD_mksession,
CMD_mkspell,
CMD_mkvimrc,
CMD_mkview,
CMD_mode,
CMD_mzscheme,
CMD_mzfile,
CMD_next,
CMD_nbkey,
CMD_nbclose,
CMD_nbstart,
CMD_new,
CMD_nmap,
CMD_nmapclear,
CMD_nmenu,
CMD_nnoremap,
CMD_nnoremenu,
CMD_noremap,
CMD_noautocmd,
CMD_nohlsearch,
CMD_noreabbrev,
CMD_noremenu,
CMD_noswapfile,
CMD_normal,
CMD_number,
CMD_nunmap,
CMD_nunmenu,
CMD_open,
CMD_oldfiles,
CMD_omap,
CMD_omapclear,
CMD_omenu,
CMD_only,
CMD_onoremap,
CMD_onoremenu,
CMD_options,
CMD_ounmap,
CMD_ounmenu,
CMD_ownsyntax,
CMD_print,
CMD_packadd,
CMD_packloadall,
CMD_pclose,
CMD_perl,
CMD_perldo,
CMD_pedit,
CMD_pop,
CMD_popup,
CMD_ppop,
CMD_preserve,
CMD_previous,
CMD_promptfind,
CMD_promptrepl,
CMD_profile,
CMD_profdel,
CMD_psearch,
CMD_ptag,
CMD_ptNext,
CMD_ptfirst,
CMD_ptjump,
CMD_ptlast,
CMD_ptnext,
CMD_ptprevious,
CMD_ptrewind,
CMD_ptselect,
CMD_put,
CMD_pwd,
CMD_python,
CMD_pydo,
CMD_pyfile,
CMD_py3,
CMD_py3do,
CMD_python3,
CMD_py3file,
CMD_pyx,
CMD_pyxdo,
CMD_pythonx,
CMD_pyxfile,
CMD_quit,
CMD_quitall,
CMD_qall,
CMD_read,
CMD_recover,
CMD_redo,
CMD_redir,
CMD_redraw,
CMD_redrawstatus,
CMD_registers,
CMD_resize,
CMD_retab,
CMD_return,
CMD_rewind,
CMD_right,
CMD_rightbelow,
CMD_runtime,
CMD_ruby,
CMD_rubydo,
CMD_rubyfile,
CMD_rundo,
CMD_rviminfo,
CMD_substitute,
CMD_sNext,
CMD_sargument,
CMD_sall,
CMD_sandbox,
CMD_saveas,
CMD_sbuffer,
CMD_sbNext,
CMD_sball,
CMD_sbfirst,
CMD_sblast,
CMD_sbmodified,
CMD_sbnext,
CMD_sbprevious,
CMD_sbrewind,
CMD_scriptnames,
CMD_scriptencoding,
CMD_scscope,
CMD_set,
CMD_setfiletype,
CMD_setglobal,
CMD_setlocal,
CMD_sfind,
CMD_sfirst,
CMD_shell,
CMD_simalt,
CMD_sign,
CMD_silent,
CMD_sleep,
CMD_slast,
CMD_smagic,
CMD_smap,
CMD_smapclear,
CMD_smenu,
CMD_snext,
CMD_snomagic,
CMD_snoremap,
CMD_snoremenu,
CMD_source,
CMD_sort,
CMD_split,
CMD_spellgood,
CMD_spelldump,
CMD_spellinfo,
CMD_spellrepall,
CMD_spellundo,
CMD_spellwrong,
CMD_sprevious,
CMD_srewind,
CMD_stop,
CMD_stag,
CMD_startinsert,
CMD_startgreplace,
CMD_startreplace,
CMD_stopinsert,
CMD_stjump,
CMD_stselect,
CMD_sunhide,
CMD_sunmap,
CMD_sunmenu,
CMD_suspend,
CMD_sview,
CMD_swapname,
CMD_syntax,
CMD_syntime,
CMD_syncbind,
CMD_smile,
CMD_t,
CMD_tNext,
CMD_tag,
CMD_tags,
CMD_tab,
CMD_tabclose,
CMD_tabdo,
CMD_tabedit,
CMD_tabfind,
CMD_tabfirst,
CMD_tabmove,
CMD_tablast,
CMD_tabnext,
CMD_tabnew,
CMD_tabonly,
CMD_tabprevious,
CMD_tabNext,
CMD_tabrewind,
CMD_tabs,
CMD_tcl,
CMD_tcldo,
CMD_tclfile,
CMD_tearoff,
CMD_terminal,
CMD_tfirst,
CMD_throw,
CMD_tjump,
CMD_tlast,
CMD_tmenu,
CMD_tmap,
CMD_tmapclear,
CMD_tnext,
CMD_tnoremap,
CMD_topleft,
CMD_tprevious,
CMD_trewind,
CMD_try,
CMD_tselect,
CMD_tunmenu,
CMD_tunmap,
CMD_undo,
CMD_undojoin,
CMD_undolist,
CMD_unabbreviate,
CMD_unhide,
CMD_unlet,
CMD_unlockvar,
CMD_unmap,
CMD_unmenu,
CMD_unsilent,
CMD_update,
CMD_vglobal,
CMD_version,
CMD_verbose,
CMD_vertical,
CMD_visual,
CMD_view,
CMD_vimgrep,
CMD_vimgrepadd,
CMD_viusage,
CMD_vmap,
CMD_vmapclear,
CMD_vmenu,
CMD_vnoremap,
CMD_vnew,
CMD_vnoremenu,
CMD_vsplit,
CMD_vunmap,
CMD_vunmenu,
CMD_write,
CMD_wNext,
CMD_wall,
CMD_while,
CMD_winsize,
CMD_wincmd,
CMD_windo,
CMD_winpos,
CMD_wnext,
CMD_wprevious,
CMD_wq,
CMD_wqall,
CMD_wsverb,
CMD_wundo,
CMD_wviminfo,
CMD_xit,
CMD_xall,
CMD_xmap,
CMD_xmapclear,
CMD_xmenu,
CMD_xnoremap,
CMD_xnoremenu,
CMD_xunmap,
CMD_xunmenu,
CMD_yank,
CMD_z,
CMD_bang,
CMD_pound,
CMD_and,
CMD_star,
CMD_lshift,
CMD_equal,
CMD_rshift,
CMD_at,
CMD_Next,
CMD_Print,
CMD_X,
CMD_tilde,
    CMD_SIZE,
    CMD_USER = -1,
    CMD_USER_BUF = -2
};
typedef enum CMD_index cmdidx_T;
struct exarg
{
    char_u *arg;
    char_u *nextcmd;
    char_u *cmd;
    char_u **cmdlinep;
    cmdidx_T cmdidx;
    long argt;
    int skip;
    int forceit;
    int addr_count;
    linenr_T line1;
    linenr_T line2;
    int addr_type;
    int flags;
    char_u *do_ecmd_cmd;
    linenr_T do_ecmd_lnum;
    int append;
    int usefilter;
    int amount;
    int regname;
    int force_bin;
    int read_edit;
    int force_ff;
    int force_enc;
    int bad_char;
    int useridx;
    char_u *errmsg;
    char_u *(*getline)(int, void *, int);
    void *cookie;
    struct condstack *cstack;
};
typedef int idx_T;
typedef int salfirst_T;
typedef struct slang_S slang_T;
struct slang_S
{
    slang_T *sl_next;
    char_u *sl_name;
    char_u *sl_fname;
    int sl_add;
    char_u *sl_fbyts;
    idx_T *sl_fidxs;
    char_u *sl_kbyts;
    idx_T *sl_kidxs;
    char_u *sl_pbyts;
    idx_T *sl_pidxs;
    char_u *sl_info;
    char_u sl_regions[17];
    char_u *sl_midword;
    hashtab_T sl_wordcount;
    int sl_compmax;
    int sl_compminlen;
    int sl_compsylmax;
    int sl_compoptions;
    garray_T sl_comppat;
    regprog_T *sl_compprog;
    char_u *sl_comprules;
    char_u *sl_compstartflags;
    char_u *sl_compallflags;
    char_u sl_nobreak;
    char_u *sl_syllable;
    garray_T sl_syl_items;
    int sl_prefixcnt;
    regprog_T **sl_prefprog;
    garray_T sl_rep;
    short sl_rep_first[256];
    garray_T sl_sal;
    salfirst_T sl_sal_first[256];
    int sl_followup;
    int sl_collapse;
    int sl_rem_accents;
    int sl_sofo;
    garray_T sl_repsal;
    short sl_repsal_first[256];
    int sl_nosplitsugs;
    int sl_nocompoundsugs;
    time_t sl_sugtime;
    char_u *sl_sbyts;
    idx_T *sl_sidxs;
    buf_T *sl_sugbuf;
    int sl_sugloaded;
    int sl_has_map;
    hashtab_T sl_map_hash;
    int sl_map_array[256];
    hashtab_T sl_sounddone;
};
typedef struct fromto_S
{
    char_u *ft_from;
    char_u *ft_to;
} fromto_T;
typedef struct salitem_S
{
    char_u *sm_lead;
    int sm_leadlen;
    char_u *sm_oneof;
    char_u *sm_rules;
    char_u *sm_to;
    int *sm_lead_w;
    int *sm_oneof_w;
    int *sm_to_w;
} salitem_T;
typedef struct langp_S
{
    slang_T *lp_slang;
    slang_T *lp_sallang;
    slang_T *lp_replang;
    int lp_region;
} langp_T;
typedef struct spelltab_S
{
    char_u st_isw[256];
    char_u st_isu[256];
    char_u st_fold[256];
    char_u st_upper[256];
} spelltab_T;

typedef __mbstate_t mbstate_t;



struct tm;



extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcscat (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

extern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ , __leaf__));
extern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,
   size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
    __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
     size_t __n, __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));

extern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsxfrm (wchar_t *__restrict __s1,
         const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,
        __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,
    size_t __n, __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcsdup (const wchar_t *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));

extern wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));


extern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcspbrk (const wchar_t *__wcs, const wchar_t *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcsstr (const wchar_t *__haystack, const wchar_t *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wcstok (wchar_t *__restrict __s,
   const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcslen (const wchar_t *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

extern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

extern wchar_t *wmemchr (const wchar_t *__s, wchar_t __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern int wmemcmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern wint_t btowc (int __c) __attribute__ ((__nothrow__ , __leaf__));
extern int wctob (wint_t __c) __attribute__ ((__nothrow__ , __leaf__));
extern int mbsinit (const mbstate_t *__ps) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
extern size_t mbrtowc (wchar_t *__restrict __pwc,
         const char *__restrict __s, size_t __n,
         mbstate_t *__restrict __p) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbrlen (const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbrlen (const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));

extern wint_t __btowc_alias (int __c) __asm ("btowc");
extern __inline __attribute__ ((__gnu_inline__)) wint_t
__attribute__ ((__nothrow__ , __leaf__)) btowc (int __c)
{ return (__builtin_constant_p (__c) && __c >= '\0' && __c <= '\x7f'
   ? (wint_t) __c : __btowc_alias (__c)); }
extern int __wctob_alias (wint_t __c) __asm ("wctob");
extern __inline __attribute__ ((__gnu_inline__)) int
__attribute__ ((__nothrow__ , __leaf__)) wctob (wint_t __wc)
{ return (__builtin_constant_p (__wc) && __wc >= L'\0' && __wc <= L'\x7f'
   ? (int) __wc : __wctob_alias (__wc)); }
extern __inline __attribute__ ((__gnu_inline__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) mbrlen (const char *__restrict __s, size_t __n, mbstate_t *__restrict __ps)
{ return (__ps != ((void *)0)
   ? mbrtowc (((void *)0), __s, __n, __ps) : __mbrlen (__s, __n, ((void *)0))); }

extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsrtombs (char *__restrict __dst,
    const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));

extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcsnrtombs (char *__restrict __dst,
     const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) __attribute__ ((__nothrow__ , __leaf__));

extern double wcstod (const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));


extern float wcstof (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));
extern long double wcstold (const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__));


extern long int wcstol (const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned long int wcstoul (const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));


__extension__
extern long long int wcstoll (const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern unsigned long long int wcstoull (const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) __attribute__ ((__nothrow__ , __leaf__));

extern wchar_t *wcpcpy (wchar_t *__restrict __dest,
   const wchar_t *__restrict __src) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *wcpncpy (wchar_t *__restrict __dest,
    const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__));

extern int fwide (__FILE *__fp, int __mode) __attribute__ ((__nothrow__ , __leaf__));
extern int fwprintf (__FILE *__restrict __stream,
       const wchar_t *__restrict __format, ...)
                                                           ;
extern int wprintf (const wchar_t *__restrict __format, ...)
                                                           ;
extern int swprintf (wchar_t *__restrict __s, size_t __n,
       const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int vfwprintf (__FILE *__restrict __s,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;
extern int vwprintf (const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;
extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fwscanf (__FILE *__restrict __stream,
      const wchar_t *__restrict __format, ...)
                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...)
                                                          ;
extern int swscanf (const wchar_t *__restrict __s,
      const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fwscanf (__FILE *__restrict __stream, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_fwscanf")
                                                          ;
extern int wscanf (const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_wscanf")
                                                          ;
extern int swscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, ...) __asm__ ("" "__isoc99_swscanf") __attribute__ ((__nothrow__ , __leaf__))
                                                          ;


extern int vfwscanf (__FILE *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;
extern int vwscanf (const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;
extern int vswscanf (const wchar_t *__restrict __s,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int vfwscanf (__FILE *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfwscanf")
                                                          ;
extern int vwscanf (const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vwscanf")
                                                          ;
extern int vswscanf (const wchar_t *__restrict __s, const wchar_t *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vswscanf") __attribute__ ((__nothrow__ , __leaf__))
                                                          ;


extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);
extern wint_t getwchar (void);
extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar (wchar_t __wc);
extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);
extern int fputws (const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);
extern wint_t ungetwc (wint_t __wc, __FILE *__stream);


extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   const wchar_t *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

extern wchar_t *__wmemcpy_chk (wchar_t *__restrict __s1,
          const wchar_t *__restrict __s2, size_t __n,
          size_t __ns1) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemcpy_alias (wchar_t *__restrict __s1, const wchar_t *__restrict __s2, size_t __n) __asm__ ("" "wmemcpy") __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemcpy_chk_warn (wchar_t *__restrict __s1, const wchar_t *__restrict __s2, size_t __n, size_t __ns1) __asm__ ("" "__wmemcpy_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wmemcpy called with length bigger than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wmemcpy (wchar_t *__restrict __s1, const wchar_t *__restrict __s2, size_t __n)
{
  if (__builtin_object_size (__s1, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n))
 return __wmemcpy_chk (__s1, __s2, __n,
         __builtin_object_size (__s1, 0) / sizeof (wchar_t));
      if (__n > __builtin_object_size (__s1, 0) / sizeof (wchar_t))
 return __wmemcpy_chk_warn (__s1, __s2, __n,
       __builtin_object_size (__s1, 0) / sizeof (wchar_t));
    }
  return __wmemcpy_alias (__s1, __s2, __n);
}
extern wchar_t *__wmemmove_chk (wchar_t *__s1, const wchar_t *__s2,
    size_t __n, size_t __ns1) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemmove_alias (wchar_t *__s1, const wchar_t *__s2, size_t __n) __asm__ ("" "wmemmove") __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemmove_chk_warn (wchar_t *__s1, const wchar_t *__s2, size_t __n, size_t __ns1) __asm__ ("" "__wmemmove_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wmemmove called with length bigger than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
{
  if (__builtin_object_size (__s1, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n))
 return __wmemmove_chk (__s1, __s2, __n,
          __builtin_object_size (__s1, 0) / sizeof (wchar_t));
      if (__n > __builtin_object_size (__s1, 0) / sizeof (wchar_t))
 return __wmemmove_chk_warn (__s1, __s2, __n,
        __builtin_object_size (__s1, 0) / sizeof (wchar_t));
    }
  return __wmemmove_alias (__s1, __s2, __n);
}
extern wchar_t *__wmemset_chk (wchar_t *__s, wchar_t __c, size_t __n,
          size_t __ns) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemset_alias (wchar_t *__s, wchar_t __c, size_t __n) __asm__ ("" "wmemset") __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wmemset_chk_warn (wchar_t *__s, wchar_t __c, size_t __n, size_t __ns) __asm__ ("" "__wmemset_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wmemset called with length bigger than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wmemset (wchar_t *__s, wchar_t __c, size_t __n)
{
  if (__builtin_object_size (__s, 0) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n))
 return __wmemset_chk (__s, __c, __n, __builtin_object_size (__s, 0) / sizeof (wchar_t));
      if (__n > __builtin_object_size (__s, 0) / sizeof (wchar_t))
 return __wmemset_chk_warn (__s, __c, __n,
       __builtin_object_size (__s, 0) / sizeof (wchar_t));
    }
  return __wmemset_alias (__s, __c, __n);
}
extern wchar_t *__wcscpy_chk (wchar_t *__restrict __dest,
         const wchar_t *__restrict __src,
         size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcscpy_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src) __asm__ ("" "wcscpy") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcscpy (wchar_t *__restrict __dest, const wchar_t *__restrict __src)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    return __wcscpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
  return __wcscpy_alias (__dest, __src);
}
extern wchar_t *__wcpcpy_chk (wchar_t *__restrict __dest,
         const wchar_t *__restrict __src,
         size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcpcpy_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src) __asm__ ("" "wcpcpy") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcpcpy (wchar_t *__restrict __dest, const wchar_t *__restrict __src)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    return __wcpcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
  return __wcpcpy_alias (__dest, __src);
}
extern wchar_t *__wcsncpy_chk (wchar_t *__restrict __dest,
          const wchar_t *__restrict __src, size_t __n,
          size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcsncpy_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n) __asm__ ("" "wcsncpy") __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcsncpy_chk_warn (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n, size_t __destlen) __asm__ ("" "__wcsncpy_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wcsncpy called with length bigger than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcsncpy (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n))
 return __wcsncpy_chk (__dest, __src, __n,
         __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
      if (__n > __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t))
 return __wcsncpy_chk_warn (__dest, __src, __n,
       __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
    }
  return __wcsncpy_alias (__dest, __src, __n);
}
extern wchar_t *__wcpncpy_chk (wchar_t *__restrict __dest,
          const wchar_t *__restrict __src, size_t __n,
          size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcpncpy_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n) __asm__ ("" "wcpncpy") __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcpncpy_chk_warn (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n, size_t __destlen) __asm__ ("" "__wcpncpy_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("wcpncpy called with length bigger than size of destination " "buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcpncpy (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n))
 return __wcpncpy_chk (__dest, __src, __n,
         __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
      if (__n > __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t))
 return __wcpncpy_chk_warn (__dest, __src, __n,
       __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
    }
  return __wcpncpy_alias (__dest, __src, __n);
}
extern wchar_t *__wcscat_chk (wchar_t *__restrict __dest,
         const wchar_t *__restrict __src,
         size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcscat_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src) __asm__ ("" "wcscat") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcscat (wchar_t *__restrict __dest, const wchar_t *__restrict __src)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    return __wcscat_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
  return __wcscat_alias (__dest, __src);
}
extern wchar_t *__wcsncat_chk (wchar_t *__restrict __dest,
          const wchar_t *__restrict __src,
          size_t __n, size_t __destlen) __attribute__ ((__nothrow__ , __leaf__));
extern wchar_t *__wcsncat_alias (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n) __asm__ ("" "wcsncat") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) wchar_t *
__attribute__ ((__nothrow__ , __leaf__)) wcsncat (wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)
{
  if (__builtin_object_size (__dest, 2 > 1) != (size_t) -1)
    return __wcsncat_chk (__dest, __src, __n,
     __builtin_object_size (__dest, 2 > 1) / sizeof (wchar_t));
  return __wcsncat_alias (__dest, __src, __n);
}
extern int __swprintf_chk (wchar_t *__restrict __s, size_t __n,
      int __flag, size_t __s_len,
      const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int __swprintf_alias (wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt, ...) __asm__ ("" "swprintf") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) swprintf (wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt, ...)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1 || 2 > 1)
    return __swprintf_chk (__s, __n, 2 - 1,
      __builtin_object_size (__s, 2 > 1) / sizeof (wchar_t),
      __fmt, __builtin_va_arg_pack ());
  return __swprintf_alias (__s, __n, __fmt, __builtin_va_arg_pack ());
}
extern int __vswprintf_chk (wchar_t *__restrict __s, size_t __n,
       int __flag, size_t __s_len,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int __vswprintf_alias (wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt, __gnuc_va_list __ap) __asm__ ("" "vswprintf") __attribute__ ((__nothrow__ , __leaf__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
__attribute__ ((__nothrow__ , __leaf__)) vswprintf (wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt, __gnuc_va_list __ap)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1 || 2 > 1)
    return __vswprintf_chk (__s, __n, 2 - 1,
       __builtin_object_size (__s, 2 > 1) / sizeof (wchar_t), __fmt, __ap);
  return __vswprintf_alias (__s, __n, __fmt, __ap);
}
extern int __fwprintf_chk (__FILE *__restrict __stream, int __flag,
      const wchar_t *__restrict __format, ...);
extern int __wprintf_chk (int __flag, const wchar_t *__restrict __format,
     ...);
extern int __vfwprintf_chk (__FILE *__restrict __stream, int __flag,
       const wchar_t *__restrict __format,
       __gnuc_va_list __ap);
extern int __vwprintf_chk (int __flag, const wchar_t *__restrict __format,
      __gnuc_va_list __ap);
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
wprintf (const wchar_t *__restrict __fmt, ...)
{
  return __wprintf_chk (2 - 1, __fmt, __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
fwprintf (__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ...)
{
  return __fwprintf_chk (__stream, 2 - 1, __fmt,
    __builtin_va_arg_pack ());
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vwprintf (const wchar_t *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vwprintf_chk (2 - 1, __fmt, __ap);
}
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) int
vfwprintf (__FILE *__restrict __stream,
    const wchar_t *__restrict __fmt, __gnuc_va_list __ap)
{
  return __vfwprintf_chk (__stream, 2 - 1, __fmt, __ap);
}
extern wchar_t *__fgetws_chk (wchar_t *__restrict __s, size_t __size, int __n,
         __FILE *__restrict __stream) __attribute__ ((__warn_unused_result__));
extern wchar_t *__fgetws_alias (wchar_t *__restrict __s, int __n, __FILE *__restrict __stream) __asm__ ("" "fgetws") __attribute__ ((__warn_unused_result__));
extern wchar_t *__fgetws_chk_warn (wchar_t *__restrict __s, size_t __size, int __n, __FILE *__restrict __stream) __asm__ ("" "__fgetws_chk")
     __attribute__ ((__warn_unused_result__)) __attribute__((__warning__ ("fgetws called with bigger size than length " "of destination buffer")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) wchar_t *
fgetws (wchar_t *__restrict __s, int __n, __FILE *__restrict __stream)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__n) || __n <= 0)
 return __fgetws_chk (__s, __builtin_object_size (__s, 2 > 1) / sizeof (wchar_t),
        __n, __stream);
      if ((size_t) __n > __builtin_object_size (__s, 2 > 1) / sizeof (wchar_t))
 return __fgetws_chk_warn (__s, __builtin_object_size (__s, 2 > 1) / sizeof (wchar_t),
      __n, __stream);
    }
  return __fgetws_alias (__s, __n, __stream);
}
extern size_t __wcrtomb_chk (char *__restrict __s, wchar_t __wchar,
        mbstate_t *__restrict __p,
        size_t __buflen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern size_t __wcrtomb_alias (char *__restrict __s, wchar_t __wchar, mbstate_t *__restrict __ps) __asm__ ("" "wcrtomb") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) __attribute__ ((__warn_unused_result__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) wcrtomb (char *__restrict __s, wchar_t __wchar, mbstate_t *__restrict __ps)
{
  if (__builtin_object_size (__s, 2 > 1) != (size_t) -1 && 16 > __builtin_object_size (__s, 2 > 1))
    return __wcrtomb_chk (__s, __wchar, __ps, __builtin_object_size (__s, 2 > 1));
  return __wcrtomb_alias (__s, __wchar, __ps);
}
extern size_t __mbsrtowcs_chk (wchar_t *__restrict __dst,
          const char **__restrict __src,
          size_t __len, mbstate_t *__restrict __ps,
          size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbsrtowcs_alias (wchar_t *__restrict __dst, const char **__restrict __src, size_t __len, mbstate_t *__restrict __ps) __asm__ ("" "mbsrtowcs") __attribute__ ((__nothrow__ , __leaf__));
extern size_t __mbsrtowcs_chk_warn (wchar_t *__restrict __dst, const char **__restrict __src, size_t __len, mbstate_t *__restrict __ps, size_t __dstlen) __asm__ ("" "__mbsrtowcs_chk") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__((__warning__ ("mbsrtowcs called with dst buffer smaller than len " "* sizeof (wchar_t)")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) mbsrtowcs (wchar_t *__restrict __dst, const char **__restrict __src, size_t __len, mbstate_t *__restrict __ps)
{
  if (__builtin_object_size (__dst, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __mbsrtowcs_chk (__dst, __src, __len, __ps,
    __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t));
      if (__len > __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t))
 return __mbsrtowcs_chk_warn (__dst, __src, __len, __ps,
         __builtin_object_size (__dst, 2 > 1) / sizeof (wchar_t));
    }
  return __mbsrtowcs_alias (__dst, __src, __len, __ps);
}
extern size_t __wcsrtombs_chk (char *__restrict __dst,
          const wchar_t **__restrict __src,
          size_t __len, mbstate_t *__restrict __ps,
          size_t __dstlen) __attribute__ ((__nothrow__ , __leaf__));
extern size_t __wcsrtombs_alias (char *__restrict __dst, const wchar_t **__restrict __src, size_t __len, mbstate_t *__restrict __ps) __asm__ ("" "wcsrtombs") __attribute__ ((__nothrow__ , __leaf__));
extern size_t __wcsrtombs_chk_warn (char *__restrict __dst, const wchar_t **__restrict __src, size_t __len, mbstate_t *__restrict __ps, size_t __dstlen) __asm__ ("" "__wcsrtombs_chk") __attribute__ ((__nothrow__ , __leaf__))
    __attribute__((__warning__ ("wcsrtombs called with dst buffer smaller than len")));
extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) __attribute__ ((__artificial__)) size_t
__attribute__ ((__nothrow__ , __leaf__)) wcsrtombs (char *__restrict __dst, const wchar_t **__restrict __src, size_t __len, mbstate_t *__restrict __ps)
{
  if (__builtin_object_size (__dst, 2 > 1) != (size_t) -1)
    {
      if (!__builtin_constant_p (__len))
 return __wcsrtombs_chk (__dst, __src, __len, __ps, __builtin_object_size (__dst, 2 > 1));
      if (__len > __builtin_object_size (__dst, 2 > 1))
 return __wcsrtombs_chk_warn (__dst, __src, __len, __ps, __builtin_object_size (__dst, 2 > 1));
    }
  return __wcsrtombs_alias (__dst, __src, __len, __ps);
}

extern slang_T *first_lang ;
extern char_u *int_wordlist ;
extern char e_format[] ;
extern spelltab_T spelltab;
extern int did_set_spelltab;
int mch_chdir(char *path);
void mch_write(char_u *s, int len);
int mch_inchar(char_u *buf, int maxlen, long wtime, int tb_change_cnt);
int mch_char_avail(void);
int mch_check_messages(void);
long_u mch_total_mem(int special);
void mch_delay(long msec, int ignoreinput);
int mch_stackcheck(char *p);
void mch_startjmp(void);
void mch_endjmp(void);
void mch_didjmp(void);
void mch_suspend(void);
void mch_init(void);
void reset_signals(void);
int vim_handle_signal(int sig);
int mch_check_win(int argc, char **argv);
int mch_input_isatty(void);
int mch_can_restore_title(void);
int mch_can_restore_icon(void);
void mch_settitle(char_u *title, char_u *icon);
void mch_restore_title(int which);
int vim_is_xterm(char_u *name);
int use_xterm_like_mouse(char_u *name);
int use_xterm_mouse(void);
int vim_is_iris(char_u *name);
int vim_is_vt300(char_u *name);
int vim_is_fastterm(char_u *name);
int mch_get_user_name(char_u *s, int len);
int mch_get_uname(uid_t uid, char_u *s, int len);
void mch_get_host_name(char_u *s, int len);
long mch_get_pid(void);
int mch_dirname(char_u *buf, int len);
int mch_FullName(char_u *fname, char_u *buf, int len, int force);
int mch_isFullName(char_u *fname);
void fname_case(char_u *name, int len);
long mch_getperm(char_u *name);
int mch_setperm(char_u *name, long perm);
void mch_copy_sec(char_u *from_file, char_u *to_file);
vim_acl_T mch_get_acl(char_u *fname);
void mch_set_acl(char_u *fname, vim_acl_T aclent);
void mch_free_acl(vim_acl_T aclent);
void mch_hide(char_u *name);
int mch_isdir(char_u *name);
int mch_isrealdir(char_u *name);
int mch_can_exe(char_u *name, char_u **path, int use_path);
int mch_nodetype(char_u *name);
void mch_early_init(void);
void mch_free_mem(void);
void mch_exit(int r);
void mch_settmode(int tmode);
void get_stty(void);
int get_tty_info(int fd, ttyinfo_T *info);
void mch_setmouse(int on);
void check_mouse_termcode(void);
int mch_screenmode(char_u *arg);
int mch_get_shellsize(void);
int mch_report_winsize(int fd, int rows, int cols);
void mch_set_shellsize(void);
void mch_new_shellsize(void);
int mch_parse_cmd(char_u *cmd, int use_shcf, char ***argv, int *argc);
void may_send_sigint(int c, pid_t pid, pid_t wpid);
int mch_call_shell(char_u *cmd, int options);
void mch_job_start(char **argv, job_T *job, jobopt_T *options);
char *mch_job_status(job_T *job);
job_T *mch_detect_ended_job(job_T *job_list);
int mch_signal_job(job_T *job, char_u *how);
void mch_clear_job(job_T *job);
int mch_create_pty_channel(job_T *job, jobopt_T *options);
void mch_breakcheck(int force);
int mch_expandpath(garray_T *gap, char_u *path, int flags);
int mch_expand_wildcards(int num_pat, char_u **pat, int *num_file, char_u ***file, int flags);
int mch_has_exp_wildcard(char_u *p);
int mch_has_wildcard(char_u *p);
int rename(const char *src, const char *dest);
int mch_libcall(char_u *libname, char_u *funcname, char_u *argstring, int argint, char_u **string_result, int *number_result);
void setup_term_clip(void);
void start_xterm_trace(int button);
void stop_xterm_trace(void);
void clear_xterm_clip(void);
int clip_xterm_own_selection(VimClipboard *cbd);
void clip_xterm_lose_selection(VimClipboard *cbd);
void clip_xterm_request_selection(VimClipboard *cbd);
void clip_xterm_set_selection(VimClipboard *cbd);
int xsmp_handle_requests(void);
void xsmp_init(void);
void xsmp_close(void);
void crypt_blowfish_encode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
void crypt_blowfish_decode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
void crypt_blowfish_init(cryptstate_T *state, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len);
int blowfish_self_test(void);
int crypt_method_nr_from_name(char_u *name);
int crypt_method_nr_from_magic(char *ptr, int len);
int crypt_works_inplace(cryptstate_T *state);
int crypt_get_method_nr(buf_T *buf);
int crypt_whole_undofile(int method_nr);
int crypt_get_header_len(int method_nr);
void crypt_set_cm_option(buf_T *buf, int method_nr);
int crypt_self_test(void);
cryptstate_T *crypt_create(int method_nr, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len);
cryptstate_T *crypt_create_from_header(int method_nr, char_u *key, char_u *header);
cryptstate_T *crypt_create_from_file(FILE *fp, char_u *key);
cryptstate_T *crypt_create_for_writing(int method_nr, char_u *key, char_u **header, int *header_len);
void crypt_free_state(cryptstate_T *state);
long crypt_encode_alloc(cryptstate_T *state, char_u *from, size_t len, char_u **newptr);
long crypt_decode_alloc(cryptstate_T *state, char_u *ptr, long len, char_u **newptr);
void crypt_encode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
void crypt_decode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
void crypt_encode_inplace(cryptstate_T *state, char_u *buf, size_t len);
void crypt_decode_inplace(cryptstate_T *state, char_u *buf, size_t len);
void crypt_free_key(char_u *key);
void crypt_check_method(int method);
void crypt_check_current_method(void);
char_u *crypt_get_key(int store, int twice);
void crypt_append_msg(buf_T *buf);
void crypt_zip_init(cryptstate_T *state, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len);
void crypt_zip_encode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
void crypt_zip_decode(cryptstate_T *state, char_u *from, size_t len, char_u *to);
int open_buffer(int read_stdin, exarg_T *eap, int flags);
void set_bufref(bufref_T *bufref, buf_T *buf);
int bufref_valid(bufref_T *bufref);
int buf_valid(buf_T *buf);
void close_buffer(win_T *win, buf_T *buf, int action, int abort_if_last);
void buf_clear_file(buf_T *buf);
void buf_freeall(buf_T *buf, int flags);
void goto_buffer(exarg_T *eap, int start, int dir, int count);
void handle_swap_exists(bufref_T *old_curbuf);
char_u *do_bufdel(int command, char_u *arg, int addr_count, int start_bnr, int end_bnr, int forceit);
int do_buffer(int action, int start, int dir, int count, int forceit);
void set_curbuf(buf_T *buf, int action);
void enter_buffer(buf_T *buf);
void do_autochdir(void);
void no_write_message(void);
void no_write_message_nobang(void);
buf_T *buflist_new(char_u *ffname, char_u *sfname, linenr_T lnum, int flags);
void free_buf_options(buf_T *buf, int free_p_ff);
int buflist_getfile(int n, linenr_T lnum, int options, int forceit);
void buflist_getfpos(void);
buf_T *buflist_findname_exp(char_u *fname);
buf_T *buflist_findname(char_u *ffname);
int buflist_findpat(char_u *pattern, char_u *pattern_end, int unlisted, int diffmode, int curtab_only);
int ExpandBufnames(char_u *pat, int *num_file, char_u ***file, int options);
buf_T *buflist_findnr(int nr);
char_u *buflist_nr2name(int n, int fullname, int helptail);
void get_winopts(buf_T *buf);
pos_T *buflist_findfpos(buf_T *buf);
linenr_T buflist_findlnum(buf_T *buf);
void buflist_list(exarg_T *eap);
int buflist_name_nr(int fnum, char_u **fname, linenr_T *lnum);
int setfname(buf_T *buf, char_u *ffname, char_u *sfname, int message);
void buf_set_name(int fnum, char_u *name);
void buf_name_changed(buf_T *buf);
buf_T *setaltfname(char_u *ffname, char_u *sfname, linenr_T lnum);
char_u *getaltfname(int errmsg);
int buflist_add(char_u *fname, int flags);
void buflist_slash_adjust(void);
void buflist_altfpos(win_T *win);
int otherfile(char_u *ffname);
void buf_setino(buf_T *buf);
void fileinfo(int fullname, int shorthelp, int dont_truncate);
void col_print(char_u *buf, size_t buflen, int col, int vcol);
void maketitle(void);
void resettitle(void);
void free_titles(void);
int build_stl_str_hl(win_T *wp, char_u *out, size_t outlen, char_u *fmt, int use_sandbox, int fillchar, int maxwidth, struct stl_hlrec *hltab, struct stl_hlrec *tabtab);
void get_rel_pos(win_T *wp, char_u *buf, int buflen);
char_u *fix_fname(char_u *fname);
void fname_expand(buf_T *buf, char_u **ffname, char_u **sfname);
char_u *alist_name(aentry_T *aep);
void do_arg_all(int count, int forceit, int keep_tabs);
void ex_buffer_all(exarg_T *eap);
void do_modelines(int flags);
int read_viminfo_bufferlist(vir_T *virp, int writing);
void write_viminfo_bufferlist(FILE *fp);
int bt_quickfix(buf_T *buf);
int bt_terminal(buf_T *buf);
int bt_help(buf_T *buf);
int bt_nofile(buf_T *buf);
int bt_dontwrite(buf_T *buf);
int bt_dontwrite_msg(buf_T *buf);
int buf_hide(buf_T *buf);
char_u *buf_spname(buf_T *buf);
void switch_to_win_for_buf(buf_T *buf, win_T **save_curwinp, tabpage_T **save_curtabp, bufref_T *save_curbuf);
void restore_win_for_buf(win_T *save_curwin, tabpage_T *save_curtab, bufref_T *save_curbuf);
int find_win_for_buf(buf_T *buf, win_T **wp, tabpage_T **tp);
void buf_addsign(buf_T *buf, int id, linenr_T lnum, int typenr);
linenr_T buf_change_sign_type(buf_T *buf, int markId, int typenr);
int buf_getsigntype(buf_T *buf, linenr_T lnum, int type);
linenr_T buf_delsign(buf_T *buf, int id);
int buf_findsign(buf_T *buf, int id);
int buf_findsign_id(buf_T *buf, linenr_T lnum);
int buf_findsigntype_id(buf_T *buf, linenr_T lnum, int typenr);
int buf_signcount(buf_T *buf, linenr_T lnum);
void buf_delete_signs(buf_T *buf);
void buf_delete_all_signs(void);
void sign_list_placed(buf_T *rbuf);
void sign_mark_adjust(linenr_T line1, linenr_T line2, long amount, long amount_after);
void set_buflisted(int on);
int buf_contents_changed(buf_T *buf);
void wipe_buffer(buf_T *buf, int aucmd);
int init_chartab(void);
int buf_init_chartab(buf_T *buf, int global);
void trans_characters(char_u *buf, int bufsize);
char_u *transstr(char_u *s);
char_u *str_foldcase(char_u *str, int orglen, char_u *buf, int buflen);
char_u *transchar(int c);
char_u *transchar_byte(int c);
void transchar_nonprint(char_u *buf, int c);
void transchar_hex(char_u *buf, int c);
int byte2cells(int b);
int char2cells(int c);
int ptr2cells(char_u *p);
int vim_strsize(char_u *s);
int vim_strnsize(char_u *s, int len);
int chartabsize(char_u *p, colnr_T col);
int linetabsize(char_u *s);
int linetabsize_col(int startcol, char_u *s);
int win_linetabsize(win_T *wp, char_u *line, colnr_T len);
int vim_isIDc(int c);
int vim_iswordc(int c);
int vim_iswordc_buf(int c, buf_T *buf);
int vim_iswordp(char_u *p);
int vim_iswordp_buf(char_u *p, buf_T *buf);
int vim_isfilec(int c);
int vim_isfilec_or_wc(int c);
int vim_isprintc(int c);
int vim_isprintc_strict(int c);
int lbr_chartabsize(char_u *line, unsigned char *s, colnr_T col);
int lbr_chartabsize_adv(char_u *line, char_u **s, colnr_T col);
int win_lbr_chartabsize(win_T *wp, char_u *line, char_u *s, colnr_T col, int *headp);
int in_win_border(win_T *wp, colnr_T vcol);
void getvcol(win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cursor, colnr_T *end);
colnr_T getvcol_nolist(pos_T *posp);
void getvvcol(win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cursor, colnr_T *end);
void getvcols(win_T *wp, pos_T *pos1, pos_T *pos2, colnr_T *left, colnr_T *right);
char_u *skipwhite(char_u *q);
int getwhitecols_curline(void);
int getwhitecols(char_u *p);
char_u *skipdigits(char_u *q);
char_u *skipbin(char_u *q);
char_u *skiphex(char_u *q);
char_u *skiptobin(char_u *q);
char_u *skiptodigit(char_u *q);
char_u *skiptohex(char_u *q);
int vim_isdigit(int c);
int vim_isxdigit(int c);
int vim_isbdigit(int c);
int vim_islower(int c);
int vim_isupper(int c);
int vim_toupper(int c);
int vim_tolower(int c);
char_u *skiptowhite(char_u *p);
char_u *skiptowhite_esc(char_u *p);
long getdigits(char_u **pp);
int vim_isblankline(char_u *lbuf);
void vim_str2nr(char_u *start, int *prep, int *len, int what, varnumber_T *nptr, uvarnumber_T *unptr, int maxlen);
int hex2nr(int c);
int hexhex2nr(char_u *p);
int rem_backslash(char_u *str);
void backslash_halve(char_u *p);
char_u *backslash_halve_save(char_u *p);
void ebcdic2ascii(char_u *buffer, int len);
char_u *get_cscope_name(expand_T *xp, int idx);
void set_context_in_cscope_cmd(expand_T *xp, char_u *arg, cmdidx_T cmdidx);
void ex_cscope(exarg_T *eap);
void ex_scscope(exarg_T *eap);
void ex_cstag(exarg_T *eap);
int cs_fgets(char_u *buf, int size);
void cs_free_tags(void);
void cs_print_tags(void);
int cs_connection(int num, char_u *dbpath, char_u *ppath);
void cs_end(void);
dict_T *dict_alloc(void);
int rettv_dict_alloc(typval_T *rettv);
void rettv_dict_set(typval_T *rettv, dict_T *d);
void dict_unref(dict_T *d);
int dict_free_nonref(int copyID);
void dict_free_items(int copyID);
dictitem_T *dictitem_alloc(char_u *key);
void dictitem_remove(dict_T *dict, dictitem_T *item);
void dictitem_free(dictitem_T *item);
dict_T *dict_copy(dict_T *orig, int deep, int copyID);
int dict_add(dict_T *d, dictitem_T *item);
int dict_add_nr_str(dict_T *d, char *key, varnumber_T nr, char_u *str);
int dict_add_list(dict_T *d, char *key, list_T *list);
int dict_add_dict(dict_T *d, char *key, dict_T *dict);
long dict_len(dict_T *d);
dictitem_T *dict_find(dict_T *d, char_u *key, int len);
char_u *get_dict_string(dict_T *d, char_u *key, int save);
varnumber_T get_dict_number(dict_T *d, char_u *key);
char_u *dict2string(typval_T *tv, int copyID, int restore_copyID);
int get_dict_tv(char_u **arg, typval_T *rettv, int evaluate);
void dict_extend(dict_T *d1, dict_T *d2, char_u *action);
dictitem_T *dict_lookup(hashitem_T *hi);
int dict_equal(dict_T *d1, dict_T *d2, int ic, int recursive);
void dict_list(typval_T *argvars, typval_T *rettv, int what);
void diff_buf_delete(buf_T *buf);
void diff_buf_adjust(win_T *win);
void diff_buf_add(buf_T *buf);
void diff_invalidate(buf_T *buf);
void diff_mark_adjust(linenr_T line1, linenr_T line2, long amount, long amount_after);
void ex_diffupdate(exarg_T *eap);
void ex_diffpatch(exarg_T *eap);
void ex_diffsplit(exarg_T *eap);
void ex_diffthis(exarg_T *eap);
void diff_win_options(win_T *wp, int addbuf);
void ex_diffoff(exarg_T *eap);
void diff_clear(tabpage_T *tp);
int diff_check(win_T *wp, linenr_T lnum);
int diff_check_fill(win_T *wp, linenr_T lnum);
void diff_set_topline(win_T *fromwin, win_T *towin);
int diffopt_changed(void);
int diffopt_horizontal(void);
int diff_find_change(win_T *wp, linenr_T lnum, int *startp, int *endp);
int diff_infold(win_T *wp, linenr_T lnum);
void nv_diffgetput(int put, long count);
void ex_diffgetput(exarg_T *eap);
int diff_mode_buf(buf_T *buf);
int diff_move_to(int dir, long count);
linenr_T diff_get_corresponding_line(buf_T *buf1, linenr_T lnum1);
linenr_T diff_lnum_win(linenr_T lnum, win_T *wp);
int do_digraph(int c);
int get_digraph(int cmdline);
int getdigraph(int char1, int char2, int meta_char);
void putdigraph(char_u *str);
void listdigraphs(void);
char_u *keymap_init(void);
void ex_loadkeymap(exarg_T *eap);
int edit(int cmdchar, int startln, long count);
void edit_putchar(int c, int highlight);
void edit_unputchar(void);
void display_dollar(colnr_T col);
void change_indent(int type, int amount, int round, int replaced, int call_changed_bytes);
void truncate_spaces(char_u *line);
void backspace_until_column(int col);
int vim_is_ctrl_x_key(int c);
int ins_compl_add_infercase(char_u *str, int len, int icase, char_u *fname, int dir, int flags);
void completeopt_was_set(void);
void set_completion(colnr_T startcol, list_T *list);
void ins_compl_show_pum(void);
char_u *find_word_start(char_u *ptr);
char_u *find_word_end(char_u *ptr);
int ins_compl_active(void);
int ins_compl_add_tv(typval_T *tv, int dir);
void ins_compl_check_keys(int frequency, int in_compl_func);
int get_literal(void);
void insertchar(int c, int flags, int second_indent);
void auto_format(int trailblank, int prev_line);
int comp_textwidth(int ff);
int stop_arrow(void);
void set_last_insert(int c);
void free_last_insert(void);
char_u *add_char2buf(int c, char_u *s);
void beginline(int flags);
int oneright(void);
int oneleft(void);
int cursor_up(long n, int upd_topline);
int cursor_down(long n, int upd_topline);
int stuff_inserted(int c, long count, int no_esc);
char_u *get_last_insert(void);
char_u *get_last_insert_save(void);
void replace_push(int c);
int replace_push_mb(char_u *p);
void fixthisline(int (*get_the_indent)(void));
void fix_indent(void);
int in_cinkeys(int keytyped, int when, int line_is_empty);
int hkmap(int c);
int bracketed_paste(paste_mode_T mode, int drop, garray_T *gap);
void ins_scroll(void);
void ins_horscroll(void);
int ins_copychar(linenr_T lnum);
void eval_init(void);
void eval_clear(void);
void set_internal_string_var(char_u *name, char_u *value);
int var_redir_start(char_u *name, int append);
void var_redir_str(char_u *value, int value_len);
void var_redir_stop(void);
int eval_charconvert(char_u *enc_from, char_u *enc_to, char_u *fname_from, char_u *fname_to);
int eval_printexpr(char_u *fname, char_u *args);
void eval_diff(char_u *origfile, char_u *newfile, char_u *outfile);
void eval_patch(char_u *origfile, char_u *difffile, char_u *outfile);
int eval_to_bool(char_u *arg, int *error, char_u **nextcmd, int skip);
char_u *eval_to_string_skip(char_u *arg, char_u **nextcmd, int skip);
int skip_expr(char_u **pp);
char_u *eval_to_string(char_u *arg, char_u **nextcmd, int convert);
char_u *eval_to_string_safe(char_u *arg, char_u **nextcmd, int use_sandbox);
varnumber_T eval_to_number(char_u *expr);
list_T *eval_spell_expr(char_u *badword, char_u *expr);
int get_spellword(list_T *list, char_u **pp);
typval_T *eval_expr(char_u *arg, char_u **nextcmd);
int call_vim_function(char_u *func, int argc, char_u **argv, int safe, int str_arg_only, typval_T *rettv);
varnumber_T call_func_retnr(char_u *func, int argc, char_u **argv, int safe);
void *call_func_retstr(char_u *func, int argc, char_u **argv, int safe);
void *call_func_retlist(char_u *func, int argc, char_u **argv, int safe);
int eval_foldexpr(char_u *arg, int *cp);
void ex_let(exarg_T *eap);
void list_hashtable_vars(hashtab_T *ht, char_u *prefix, int empty, int *first);
char_u *get_lval(char_u *name, typval_T *rettv, lval_T *lp, int unlet, int skip, int flags, int fne_flags);
void clear_lval(lval_T *lp);
void *eval_for_line(char_u *arg, int *errp, char_u **nextcmdp, int skip);
int next_for_item(void *fi_void, char_u *arg);
void free_for_info(void *fi_void);
void set_context_for_expression(expand_T *xp, char_u *arg, cmdidx_T cmdidx);
void ex_unlet(exarg_T *eap);
void ex_lockvar(exarg_T *eap);
int do_unlet(char_u *name, int forceit);
void del_menutrans_vars(void);
char_u *get_user_var_name(expand_T *xp, int idx);
int eval0(char_u *arg, typval_T *rettv, char_u **nextcmd, int evaluate);
int eval1(char_u **arg, typval_T *rettv, int evaluate);
int get_option_tv(char_u **arg, typval_T *rettv, int evaluate);
char_u *partial_name(partial_T *pt);
void partial_unref(partial_T *pt);
int tv_equal(typval_T *tv1, typval_T *tv2, int ic, int recursive);
int get_copyID(void);
int garbage_collect(int testing);
int set_ref_in_ht(hashtab_T *ht, int copyID, list_stack_T **list_stack);
int set_ref_in_list(list_T *l, int copyID, ht_stack_T **ht_stack);
int set_ref_in_item(typval_T *tv, int copyID, ht_stack_T **ht_stack, list_stack_T **list_stack);
char_u *echo_string_core(typval_T *tv, char_u **tofree, char_u *numbuf, int copyID, int echo_style, int restore_copyID, int dict_val);
char_u *echo_string(typval_T *tv, char_u **tofree, char_u *numbuf, int copyID);
char_u *tv2string(typval_T *tv, char_u **tofree, char_u *numbuf, int copyID);
char_u *string_quote(char_u *str, int function);
int string2float(char_u *text, float_T *value);
pos_T *var2fpos(typval_T *varp, int dollar_lnum, int *fnum);
int list2fpos(typval_T *arg, pos_T *posp, int *fnump, colnr_T *curswantp);
int get_id_len(char_u **arg);
int get_name_len(char_u **arg, char_u **alias, int evaluate, int verbose);
char_u *find_name_end(char_u *arg, char_u **expr_start, char_u **expr_end, int flags);
int eval_isnamec(int c);
int eval_isnamec1(int c);
void set_vim_var_nr(int idx, varnumber_T val);
varnumber_T get_vim_var_nr(int idx);
char_u *get_vim_var_str(int idx);
list_T *get_vim_var_list(int idx);
void set_vim_var_char(int c);
void set_vcount(long count, long count1, int set_prevcount);
void set_vim_var_string(int idx, char_u *val, int len);
void set_vim_var_list(int idx, list_T *val);
void set_vim_var_dict(int idx, dict_T *val);
void set_reg_var(int c);
char_u *v_exception(char_u *oldval);
char_u *v_throwpoint(char_u *oldval);
char_u *set_cmdarg(exarg_T *eap, char_u *oldarg);
int get_var_tv(char_u *name, int len, typval_T *rettv, dictitem_T **dip, int verbose, int no_autoload);
int handle_subscript(char_u **arg, typval_T *rettv, int evaluate, int verbose);
typval_T *alloc_tv(void);
void free_tv(typval_T *varp);
void clear_tv(typval_T *varp);
void init_tv(typval_T *varp);
varnumber_T get_tv_number(typval_T *varp);
varnumber_T get_tv_number_chk(typval_T *varp, int *denote);
float_T get_tv_float(typval_T *varp);
char_u *get_tv_string(typval_T *varp);
char_u *get_tv_string_buf(typval_T *varp, char_u *buf);
char_u *get_tv_string_chk(typval_T *varp);
char_u *get_tv_string_buf_chk(typval_T *varp, char_u *buf);
dictitem_T *find_var(char_u *name, hashtab_T **htp, int no_autoload);
dictitem_T *find_var_in_ht(hashtab_T *ht, int htname, char_u *varname, int no_autoload);
hashtab_T *find_var_ht(char_u *name, char_u **varname);
char_u *get_var_value(char_u *name);
void new_script_vars(scid_T id);
void init_var_dict(dict_T *dict, dictitem_T *dict_var, int scope);
void unref_var_dict(dict_T *dict);
void vars_clear(hashtab_T *ht);
void vars_clear_ext(hashtab_T *ht, int free_val);
void set_var(char_u *name, typval_T *tv, int copy);
int var_check_ro(int flags, char_u *name, int use_gettext);
int var_check_fixed(int flags, char_u *name, int use_gettext);
int var_check_func_name(char_u *name, int new_var);
int valid_varname(char_u *varname);
int tv_check_lock(int lock, char_u *name, int use_gettext);
void copy_tv(typval_T *from, typval_T *to);
int item_copy(typval_T *from, typval_T *to, int deep, int copyID);
void get_user_input(typval_T *argvars, typval_T *rettv, int inputdialog, int secret);
void ex_echo(exarg_T *eap);
void ex_echohl(exarg_T *eap);
void ex_execute(exarg_T *eap);
win_T *find_win_by_nr(typval_T *vp, tabpage_T *tp);
win_T *find_tabwin(typval_T *wvp, typval_T *tvp);
void getwinvar(typval_T *argvars, typval_T *rettv, int off);
void setwinvar(typval_T *argvars, typval_T *rettv, int off);
char_u *autoload_name(char_u *name);
int script_autoload(char_u *name, int reload);
int read_viminfo_varlist(vir_T *virp, int writing);
void write_viminfo_varlist(FILE *fp);
int store_session_globals(FILE *fd);
void last_set_msg(scid_T scriptID);
void reset_v_option_vars(void);
void prepare_assert_error(garray_T *gap);
void assert_error(garray_T *gap);
void assert_equal_common(typval_T *argvars, assert_type_T atype);
void assert_match_common(typval_T *argvars, assert_type_T atype);
void assert_inrange(typval_T *argvars);
void assert_bool(typval_T *argvars, int isTrue);
void assert_report(typval_T *argvars);
void assert_exception(typval_T *argvars);
void assert_fails(typval_T *argvars);
void fill_assert_error(garray_T *gap, typval_T *opt_msg_tv, char_u *exp_str, typval_T *exp_tv, typval_T *got_tv, assert_type_T atype);
int modify_fname(char_u *src, int *usedlen, char_u **fnamep, char_u **bufp, int *fnamelen);
char_u *do_string_sub(char_u *str, char_u *pat, char_u *sub, typval_T *expr, char_u *flags);
void filter_map(typval_T *argvars, typval_T *rettv, int map);
buf_T* get_buf_tv(typval_T *tv, int curtab_only);
char_u *get_function_name(expand_T *xp, int idx);
char_u *get_expr_name(expand_T *xp, int idx);
int find_internal_func(char_u *name);
int call_internal_func(char_u *name, int argcount, typval_T *argvars, typval_T *rettv);
buf_T *buflist_find_by_name(char_u *name, int curtab_only);
void execute_redir_str(char_u *value, int value_len);
void mzscheme_call_vim(char_u *name, typval_T *args, typval_T *rettv);
float_T vim_round(float_T f);
long do_searchpair(char_u *spat, char_u *mpat, char_u *epat, int dir, char_u *skip, int flags, pos_T *match_pos, linenr_T lnum_stop, long time_limit);
char_u *get_callback(typval_T *arg, partial_T **pp);
void free_callback(char_u *callback, partial_T *partial);
void do_ascii(exarg_T *eap);
void ex_align(exarg_T *eap);
void ex_sort(exarg_T *eap);
void ex_retab(exarg_T *eap);
int do_move(linenr_T line1, linenr_T line2, linenr_T dest);
void ex_copy(linenr_T line1, linenr_T line2, linenr_T n);
void free_prev_shellcmd(void);
void do_bang(int addr_count, exarg_T *eap, int forceit, int do_in, int do_out);
void do_shell(char_u *cmd, int flags);
char_u *make_filter_cmd(char_u *cmd, char_u *itmp, char_u *otmp);
void append_redir(char_u *buf, int buflen, char_u *opt, char_u *fname);
int viminfo_error(char *errnum, char *message, char_u *line);
int read_viminfo(char_u *file, int flags);
void write_viminfo(char_u *file, int forceit);
int viminfo_readline(vir_T *virp);
char_u *viminfo_readstring(vir_T *virp, int off, int convert);
void viminfo_writestring(FILE *fd, char_u *p);
int barline_writestring(FILE *fd, char_u *s, int remaining_start);
time_T vim_time(void);
void do_fixdel(exarg_T *eap);
void print_line_no_prefix(linenr_T lnum, int use_number, int list);
void print_line(linenr_T lnum, int use_number, int list);
int rename_buffer(char_u *new_fname);
void ex_file(exarg_T *eap);
void ex_update(exarg_T *eap);
void ex_write(exarg_T *eap);
int do_write(exarg_T *eap);
int check_overwrite(exarg_T *eap, buf_T *buf, char_u *fname, char_u *ffname, int other);
void ex_wnext(exarg_T *eap);
void do_wqall(exarg_T *eap);
int not_writing(void);
int getfile(int fnum, char_u *ffname, char_u *sfname, int setpm, linenr_T lnum, int forceit);
int do_ecmd(int fnum, char_u *ffname, char_u *sfname, exarg_T *eap, linenr_T newlnum, int flags, win_T *oldwin);
void ex_append(exarg_T *eap);
void ex_change(exarg_T *eap);
void ex_z(exarg_T *eap);
int check_restricted(void);
int check_secure(void);
void do_sub(exarg_T *eap);
int do_sub_msg(int count_only);
void ex_global(exarg_T *eap);
void global_exe(char_u *cmd);
int read_viminfo_sub_string(vir_T *virp, int force);
void write_viminfo_sub_string(FILE *fp);
void free_old_sub(void);
int prepare_tagpreview(int undo_sync);
void ex_help(exarg_T *eap);
void ex_helpclose(exarg_T *eap);
char_u *check_help_lang(char_u *arg);
int help_heuristic(char_u *matched_string, int offset, int wrong_case);
int find_help_tags(char_u *arg, int *num_matches, char_u ***matches, int keep_lang);
void fix_help_buffer(void);
void ex_exusage(exarg_T *eap);
void ex_viusage(exarg_T *eap);
void ex_helptags(exarg_T *eap);
void ex_sign(exarg_T *eap);
void sign_gui_started(void);
int sign_get_attr(int typenr, int line);
char_u *sign_get_text(int typenr);
void *sign_get_image(int typenr);
char_u *sign_typenr2name(int typenr);
void free_signs(void);
char_u *get_sign_name(expand_T *xp, int idx);
void set_context_in_sign_cmd(expand_T *xp, char_u *arg);
void ex_smile(exarg_T *eap);
void ex_drop(exarg_T *eap);
char_u *skip_vimgrep_pat(char_u *p, char_u **s, int *flags);
void ex_oldfiles(exarg_T *eap);
void do_debug(char_u *cmd);
void ex_debug(exarg_T *eap);
void dbg_check_breakpoint(exarg_T *eap);
int dbg_check_skipped(exarg_T *eap);
void ex_breakadd(exarg_T *eap);
void ex_debuggreedy(exarg_T *eap);
void ex_breakdel(exarg_T *eap);
void ex_breaklist(exarg_T *eap);
linenr_T dbg_find_breakpoint(int file, char_u *fname, linenr_T after);
int has_profiling(int file, char_u *fname, int *fp);
void dbg_breakpoint(char_u *name, linenr_T lnum);
void profile_start(proftime_T *tm);
void profile_end(proftime_T *tm);
void profile_sub(proftime_T *tm, proftime_T *tm2);
char *profile_msg(proftime_T *tm);
float_T profile_float(proftime_T *tm);
void profile_setlimit(long msec, proftime_T *tm);
int profile_passed_limit(proftime_T *tm);
void profile_zero(proftime_T *tm);
timer_T *create_timer(long msec, int repeat);
long check_due_timer(void);
timer_T *find_timer(long id);
void stop_timer(timer_T *timer);
void stop_all_timers(void);
void add_timer_info(typval_T *rettv, timer_T *timer);
void add_timer_info_all(typval_T *rettv);
int set_ref_in_timer(int copyID);
void timer_free_all(void);
void profile_divide(proftime_T *tm, int count, proftime_T *tm2);
void profile_add(proftime_T *tm, proftime_T *tm2);
void profile_self(proftime_T *self, proftime_T *total, proftime_T *children);
void profile_get_wait(proftime_T *tm);
void profile_sub_wait(proftime_T *tm, proftime_T *tma);
int profile_equal(proftime_T *tm1, proftime_T *tm2);
int profile_cmp(const proftime_T *tm1, const proftime_T *tm2);
void ex_profile(exarg_T *eap);
char_u *get_profile_name(expand_T *xp, int idx);
void set_context_in_profile_cmd(expand_T *xp, char_u *arg);
void profile_dump(void);
void script_prof_save(proftime_T *tm);
void script_prof_restore(proftime_T *tm);
void prof_inchar_enter(void);
void prof_inchar_exit(void);
int prof_def_func(void);
int autowrite(buf_T *buf, int forceit);
void autowrite_all(void);
int check_changed(buf_T *buf, int flags);
void browse_save_fname(buf_T *buf);
void dialog_changed(buf_T *buf, int checkall);
int can_abandon(buf_T *buf, int forceit);
int check_changed_any(int hidden, int unload);
int check_fname(void);
int buf_write_all(buf_T *buf, int forceit);
int get_arglist_exp(char_u *str, int *fcountp, char_u ***fnamesp, int wig);
void set_arglist(char_u *str);
void check_arg_idx(win_T *win);
void ex_args(exarg_T *eap);
void ex_previous(exarg_T *eap);
void ex_rewind(exarg_T *eap);
void ex_last(exarg_T *eap);
void ex_argument(exarg_T *eap);
void do_argfile(exarg_T *eap, int argn);
void ex_next(exarg_T *eap);
void ex_argedit(exarg_T *eap);
void ex_argadd(exarg_T *eap);
void ex_argdelete(exarg_T *eap);
void ex_listdo(exarg_T *eap);
void ex_compiler(exarg_T *eap);
void ex_runtime(exarg_T *eap);
int do_in_path(char_u *path, char_u *name, int flags, void (*callback)(char_u *fname, void *ck), void *cookie);
int do_in_runtimepath(char_u *name, int flags, void (*callback)(char_u *fname, void *ck), void *cookie);
int source_runtime(char_u *name, int flags);
int source_in_path(char_u *path, char_u *name, int flags);
void add_pack_start_dirs(void);
void load_start_packages(void);
void ex_packloadall(exarg_T *eap);
void ex_packadd(exarg_T *eap);
void ex_options(exarg_T *eap);
void init_pyxversion(void);
void ex_pyxfile(exarg_T *eap);
void ex_pyx(exarg_T *eap);
void ex_pyxdo(exarg_T *eap);
void ex_source(exarg_T *eap);
linenr_T *source_breakpoint(void *cookie);
int *source_dbg_tick(void *cookie);
int source_level(void *cookie);
int do_source(char_u *fname, int check_other, int is_vimrc);
void ex_scriptnames(exarg_T *eap);
void scriptnames_slash_adjust(void);
char_u *get_scriptname(scid_T id);
void free_scriptnames(void);
char *fgets_cr(char *s, int n, FILE *stream);
char_u *getsourceline(int c, void *cookie, int indent);
void script_line_start(void);
void script_line_exec(void);
void script_line_end(void);
void ex_scriptencoding(exarg_T *eap);
void ex_finish(exarg_T *eap);
void do_finish(exarg_T *eap, int reanimate);
int source_finished(char_u *(*fgetline)(int, void *, int), void *cookie);
void ex_checktime(exarg_T *eap);
char_u *get_mess_lang(void);
void set_lang_var(void);
void ex_language(exarg_T *eap);
void free_locales(void);
char_u *get_lang_arg(expand_T *xp, int idx);
char_u *get_locales(expand_T *xp, int idx);
void do_exmode(int improved);
int do_cmdline_cmd(char_u *cmd);
int do_cmdline(char_u *cmdline, char_u *(*fgetline)(int, void *, int), void *cookie, int flags);
int getline_equal(char_u *(*fgetline)(int, void *, int), void *cookie, char_u *(*func)(int, void *, int));
void *getline_cookie(char_u *(*fgetline)(int, void *, int), void *cookie);
int checkforcmd(char_u **pp, char *cmd, int len);
int modifier_len(char_u *cmd);
int cmd_exists(char_u *name);
char_u *set_one_cmd_context(expand_T *xp, char_u *buff);
char_u *skip_range(char_u *cmd, int *ctx);
void ex_ni(exarg_T *eap);
int expand_filename(exarg_T *eap, char_u **cmdlinep, char_u **errormsgp);
void separate_nextcmd(exarg_T *eap);
int ends_excmd(int c);
char_u *find_nextcmd(char_u *p);
char_u *check_nextcmd(char_u *p);
char_u *get_command_name(expand_T *xp, int idx);
void ex_comclear(exarg_T *eap);
void uc_clear(garray_T *gap);
char_u *get_user_commands(expand_T *xp, int idx);
char_u *get_user_cmd_addr_type(expand_T *xp, int idx);
char_u *get_user_cmd_flags(expand_T *xp, int idx);
char_u *get_user_cmd_nargs(expand_T *xp, int idx);
char_u *get_user_cmd_complete(expand_T *xp, int idx);
int parse_addr_type_arg(char_u *value, int vallen, long *argt, int *addr_type_arg);
int parse_compl_arg(char_u *value, int vallen, int *complp, long *argt, char_u **compl_arg);
int cmdcomplete_str_to_type(char_u *complete_str);
void not_exiting(void);
void tabpage_close(int forceit);
void tabpage_close_other(tabpage_T *tp, int forceit);
void ex_all(exarg_T *eap);
void handle_drop(int filec, char_u **filev, int split);
void alist_clear(alist_T *al);
void alist_init(alist_T *al);
void alist_unlink(alist_T *al);
void alist_new(void);
void alist_expand(int *fnum_list, int fnum_len);
void alist_set(alist_T *al, int count, char_u **files, int use_curbuf, int *fnum_list, int fnum_len);
void alist_add(alist_T *al, char_u *fname, int set_fnum);
void alist_slash_adjust(void);
void ex_splitview(exarg_T *eap);
void tabpage_new(void);
void do_exedit(exarg_T *eap, win_T *old_curwin);
void free_cd_dir(void);
void post_chdir(int local);
void ex_cd(exarg_T *eap);
void do_sleep(long msec);
void ex_may_print(exarg_T *eap);
void ex_redraw(exarg_T *eap);
int vim_mkdir_emsg(char_u *name, int prot);
FILE *open_exfile(char_u *fname, int forceit, char *mode);
void update_topline_cursor(void);
int save_current_state(save_state_T *sst);
void restore_current_state(save_state_T *sst);
void ex_normal(exarg_T *eap);
void exec_normal_cmd(char_u *cmd, int remap, int silent);
void exec_normal(int was_typed);
int find_cmdline_var(char_u *src, int *usedlen);
char_u *eval_vars(char_u *src, char_u *srcstart, int *usedlen, linenr_T *lnump, char_u **errormsg, int *escaped);
char_u *expand_sfile(char_u *arg);
int put_eol(FILE *fd);
int put_line(FILE *fd, char *s);
void dialog_msg(char_u *buff, char *format, char_u *fname);
char_u *get_behave_arg(expand_T *xp, int idx);
char_u *get_messages_arg(expand_T *xp, int idx);
char_u *get_mapclear_arg(expand_T *xp, int idx);
int get_pressedreturn(void);
void set_pressedreturn(int val);
int aborting(void);
void update_force_abort(void);
int should_abort(int retcode);
int aborted_in_try(void);
int cause_errthrow(char_u *mesg, int severe, int *ignore);
void free_global_msglist(void);
void do_errthrow(struct condstack *cstack, char_u *cmdname);
int do_intthrow(struct condstack *cstack);
char_u *get_exception_string(void *value, except_type_T type, char_u *cmdname, int *should_free);
void discard_current_exception(void);
void report_make_pending(int pending, void *value);
void report_resume_pending(int pending, void *value);
void report_discard_pending(int pending, void *value);
void ex_if(exarg_T *eap);
void ex_endif(exarg_T *eap);
void ex_else(exarg_T *eap);
void ex_while(exarg_T *eap);
void ex_continue(exarg_T *eap);
void ex_break(exarg_T *eap);
void ex_endwhile(exarg_T *eap);
void ex_throw(exarg_T *eap);
void do_throw(struct condstack *cstack);
void ex_try(exarg_T *eap);
void ex_catch(exarg_T *eap);
void ex_finally(exarg_T *eap);
void ex_endtry(exarg_T *eap);
void enter_cleanup(cleanup_T *csp);
void leave_cleanup(cleanup_T *csp);
int cleanup_conditionals(struct condstack *cstack, int searched_cond, int inclusive);
void rewind_conditionals(struct condstack *cstack, int idx, int cond_type, int *cond_level);
void ex_endfunction(exarg_T *eap);
int has_loop_cmd(char_u *p);
char_u *getcmdline(int firstc, long count, int indent);
char_u *getcmdline_prompt(int firstc, char_u *prompt, int attr, int xp_context, char_u *xp_arg);
int text_locked(void);
void text_locked_msg(void);
char_u *get_text_locked_msg(void);
int curbuf_locked(void);
int allbuf_locked(void);
char_u *getexline(int c, void *cookie, int indent);
char_u *getexmodeline(int promptc, void *cookie, int indent);
int cmdline_overstrike(void);
int cmdline_at_end(void);
colnr_T cmdline_getvcol_cursor(void);
void free_cmdline_buf(void);
void putcmdline(int c, int shift);
void unputcmdline(void);
int put_on_cmdline(char_u *str, int len, int redraw);
char_u *save_cmdline_alloc(void);
void restore_cmdline_alloc(char_u *p);
void cmdline_paste_str(char_u *s, int literally);
void redrawcmdline(void);
void redrawcmdline_ex(int do_compute_cmdrow);
void redrawcmd(void);
void compute_cmdrow(void);
void gotocmdline(int clr);
char_u *ExpandOne(expand_T *xp, char_u *str, char_u *orig, int options, int mode);
void ExpandInit(expand_T *xp);
void ExpandCleanup(expand_T *xp);
void ExpandEscape(expand_T *xp, char_u *str, int numfiles, char_u **files, int options);
char_u *vim_strsave_fnameescape(char_u *fname, int shell);
void tilde_replace(char_u *orig_pat, int num_files, char_u **files);
char_u *sm_gettail(char_u *s);
char_u *addstar(char_u *fname, int len, int context);
void set_cmd_context(expand_T *xp, char_u *str, int len, int col, int use_ccline);
int expand_cmdline(expand_T *xp, char_u *str, int col, int *matchcount, char_u ***matches);
int ExpandGeneric(expand_T *xp, regmatch_T *regmatch, int *num_file, char_u ***file, char_u *((*func)(expand_T *, int)), int escaped);
void globpath(char_u *path, char_u *file, garray_T *ga, int expand_options);
void init_history(void);
int get_histtype(char_u *name);
void add_to_history(int histype, char_u *new_entry, int in_map, int sep);
int get_history_idx(int histype);
char_u *get_history_entry(int histype, int idx);
int clr_history(int histype);
int del_history_entry(int histype, char_u *str);
int del_history_idx(int histype, int idx);
void remove_key_from_history(void);
char_u *get_cmdline_str(void);
int get_cmdline_pos(void);
int set_cmdline_pos(int pos);
int get_cmdline_type(void);
int get_list_range(char_u **str, int *num1, int *num2);
void ex_history(exarg_T *eap);
void prepare_viminfo_history(int asklen, int writing);
int read_viminfo_history(vir_T *virp, int writing);
void handle_viminfo_history(garray_T *values, int writing);
void finish_viminfo_history(vir_T *virp);
void write_viminfo_history(FILE *fp, int merge);
void cmd_pchar(int c, int offset);
int cmd_gchar(int offset);
char_u *script_get(exarg_T *eap, char_u *cmd);
void filemess(buf_T *buf, char_u *name, char_u *s, int attr);
int readfile(char_u *fname, char_u *sfname, linenr_T from, linenr_T lines_to_skip, linenr_T lines_to_read, exarg_T *eap, int flags);
int is_dev_fd_file(char_u *fname);
int prep_exarg(exarg_T *eap, buf_T *buf);
void set_file_options(int set_options, exarg_T *eap);
void set_forced_fenc(exarg_T *eap);
int check_file_readonly(char_u *fname, int perm);
int buf_write(buf_T *buf, char_u *fname, char_u *sfname, linenr_T start, linenr_T end, exarg_T *eap, int append, int forceit, int reset_changed, int filtering);
void msg_add_fname(buf_T *buf, char_u *fname);
void msg_add_lines(int insert_space, long lnum, off_T nchars);
char_u *shorten_fname1(char_u *full_path);
char_u *shorten_fname(char_u *full_path, char_u *dir_name);
void shorten_fnames(int force);
void shorten_filenames(char_u **fnames, int count);
char_u *modname(char_u *fname, char_u *ext, int prepend_dot);
char_u *buf_modname(int shortname, char_u *fname, char_u *ext, int prepend_dot);
int vim_fgets(char_u *buf, int size, FILE *fp);
int tag_fgets(char_u *buf, int size, FILE *fp);
int vim_rename(char_u *from, char_u *to);
int check_timestamps(int focus);
int buf_check_timestamp(buf_T *buf, int focus);
void buf_reload(buf_T *buf, int orig_mode);
void buf_store_time(buf_T *buf, stat_T *st, char_u *fname);
void write_lnum_adjust(linenr_T offset);
int delete_recursive(char_u *name);
void vim_deltempdir(void);
char_u *vim_tempname(int extra_char, int keep);
void forward_slash(char_u *fname);
void aubuflocal_remove(buf_T *buf);
int au_has_group(char_u *name);
void do_augroup(char_u *arg, int del_group);
void free_all_autocmds(void);
int check_ei(void);
char_u *au_event_disable(char *what);
void au_event_restore(char_u *old_ei);
void do_autocmd(char_u *arg_in, int forceit);
int do_doautocmd(char_u *arg, int do_msg, int *did_something);
void ex_doautoall(exarg_T *eap);
int check_nomodeline(char_u **argp);
void aucmd_prepbuf(aco_save_T *aco, buf_T *buf);
void aucmd_restbuf(aco_save_T *aco);
int apply_autocmds(event_T event, char_u *fname, char_u *fname_io, int force, buf_T *buf);
int apply_autocmds_retval(event_T event, char_u *fname, char_u *fname_io, int force, buf_T *buf, int *retval);
int has_cursorhold(void);
int trigger_cursorhold(void);
int has_cursormoved(void);
int has_cursormovedI(void);
int has_textchanged(void);
int has_textchangedI(void);
int has_insertcharpre(void);
int has_cmdundefined(void);
int has_funcundefined(void);
void block_autocmds(void);
void unblock_autocmds(void);
int is_autocmd_blocked(void);
char_u *getnextac(int c, void *cookie, int indent);
int has_autocmd(event_T event, char_u *sfname, buf_T *buf);
char_u *get_augroup_name(expand_T *xp, int idx);
char_u *set_context_in_autocmd(expand_T *xp, char_u *arg, int doautocmd);
char_u *get_event_name(expand_T *xp, int idx);
int autocmd_supported(char_u *name);
int au_exists(char_u *arg);
int match_file_list(char_u *list, char_u *sfname, char_u *ffname);
char_u *file_pat_to_reg_pat(char_u *pat, char_u *pat_end, char *allow_dirs, int no_bslash);
long read_eintr(int fd, void *buf, size_t bufsize);
long write_eintr(int fd, void *buf, size_t bufsize);
void copyFoldingState(win_T *wp_from, win_T *wp_to);
int hasAnyFolding(win_T *win);
int hasFolding(linenr_T lnum, linenr_T *firstp, linenr_T *lastp);
int hasFoldingWin(win_T *win, linenr_T lnum, linenr_T *firstp, linenr_T *lastp, int cache, foldinfo_T *infop);
int foldLevel(linenr_T lnum);
int lineFolded(win_T *win, linenr_T lnum);
long foldedCount(win_T *win, linenr_T lnum, foldinfo_T *infop);
int foldmethodIsManual(win_T *wp);
int foldmethodIsIndent(win_T *wp);
int foldmethodIsExpr(win_T *wp);
int foldmethodIsMarker(win_T *wp);
int foldmethodIsSyntax(win_T *wp);
int foldmethodIsDiff(win_T *wp);
void closeFold(linenr_T lnum, long count);
void closeFoldRecurse(linenr_T lnum);
void opFoldRange(linenr_T first, linenr_T last, int opening, int recurse, int had_visual);
void openFold(linenr_T lnum, long count);
void openFoldRecurse(linenr_T lnum);
void foldOpenCursor(void);
void newFoldLevel(void);
void foldCheckClose(void);
int foldManualAllowed(int create);
void foldCreate(linenr_T start, linenr_T end);
void deleteFold(linenr_T start, linenr_T end, int recursive, int had_visual);
void clearFolding(win_T *win);
void foldUpdate(win_T *wp, linenr_T top, linenr_T bot);
void foldUpdateAll(win_T *win);
int foldMoveTo(int updown, int dir, long count);
void foldInitWin(win_T *new_win);
int find_wl_entry(win_T *win, linenr_T lnum);
void foldAdjustVisual(void);
void foldAdjustCursor(void);
void foldMoveRange(garray_T *gap, linenr_T line1, linenr_T line2, linenr_T dest);
void cloneFoldGrowArray(garray_T *from, garray_T *to);
void deleteFoldRecurse(garray_T *gap);
void foldMarkAdjust(win_T *wp, linenr_T line1, linenr_T line2, long amount, long amount_after);
int getDeepestNesting(void);
char_u *get_foldtext(win_T *wp, linenr_T lnum, linenr_T lnume, foldinfo_T *foldinfo, char_u *buf);
void foldtext_cleanup(char_u *str);
int put_folds(FILE *fd, win_T *wp);
void free_buff(buffheader_T *buf);
char_u *get_recorded(void);
char_u *get_inserted(void);
int stuff_empty(void);
int readbuf1_empty(void);
void typeahead_noflush(int c);
void flush_buffers(int flush_typeahead);
void ResetRedobuff(void);
void CancelRedo(void);
void saveRedobuff(save_redo_T *save_redo);
void restoreRedobuff(save_redo_T *save_redo);
void AppendToRedobuff(char_u *s);
void AppendToRedobuffLit(char_u *str, int len);
void AppendCharToRedobuff(int c);
void AppendNumberToRedobuff(long n);
void stuffReadbuff(char_u *s);
void stuffRedoReadbuff(char_u *s);
void stuffReadbuffLen(char_u *s, long len);
void stuffReadbuffSpec(char_u *s);
void stuffcharReadbuff(int c);
void stuffnumReadbuff(long n);
int start_redo(long count, int old_redo);
int start_redo_ins(void);
void stop_redo_ins(void);
int ins_typebuf(char_u *str, int noremap, int offset, int nottyped, int silent);
void ins_char_typebuf(int c);
int typebuf_changed(int tb_change_cnt);
int typebuf_typed(void);
int typebuf_maplen(void);
void del_typebuf(int len, int offset);
int alloc_typebuf(void);
void free_typebuf(void);
int save_typebuf(void);
void save_typeahead(tasave_T *tp);
void restore_typeahead(tasave_T *tp);
void openscript(char_u *name, int directly);
void close_all_scripts(void);
int using_script(void);
void before_blocking(void);
void updatescript(int c);
int vgetc(void);
int safe_vgetc(void);
int plain_vgetc(void);
int vpeekc(void);
int vpeekc_nomap(void);
int vpeekc_any(void);
int char_avail(void);
void vungetc(int c);
int fix_input_buffer(char_u *buf, int len);
int input_available(void);
int do_map(int maptype, char_u *arg, int mode, int abbrev);
int get_map_mode(char_u **cmdp, int forceit);
void map_clear(char_u *cmdp, char_u *arg, int forceit, int abbr);
void map_clear_int(buf_T *buf, int mode, int local, int abbr);
char_u *map_mode_to_chars(int mode);
int map_to_exists(char_u *str, char_u *modechars, int abbr);
int map_to_exists_mode(char_u *rhs, int mode, int abbr);
char_u *set_context_in_map_cmd(expand_T *xp, char_u *cmd, char_u *arg, int forceit, int isabbrev, int isunmap, cmdidx_T cmdidx);
int ExpandMappings(regmatch_T *regmatch, int *num_file, char_u ***file);
int check_abbr(int c, char_u *ptr, int col, int mincol);
char_u *vim_strsave_escape_csi(char_u *p);
void vim_unescape_csi(char_u *p);
int makemap(FILE *fd, buf_T *buf);
int put_escstr(FILE *fd, char_u *strstart, int what);
void check_map_keycodes(void);
char_u *check_map(char_u *keys, int mode, int exact, int ign_mod, int abbr, mapblock_T **mp_ptr, int *local_ptr);
void init_mappings(void);
void add_map(char_u *map, int mode);
char_u *parse_printoptions(void);
char_u *parse_printmbfont(void);
int prt_header_height(void);
int prt_use_number(void);
int prt_get_unit(int idx);
void ex_hardcopy(exarg_T *eap);
void mch_print_cleanup(void);
int mch_print_init(prt_settings_T *psettings, char_u *jobname, int forceit);
int mch_print_begin(prt_settings_T *psettings);
void mch_print_end(prt_settings_T *psettings);
int mch_print_end_page(void);
int mch_print_begin_page(char_u *str);
int mch_print_blank_page(void);
void mch_print_start_line(int margin, int page_line);
int mch_print_text_out(char_u *p, int len);
void mch_print_set_font(int iBold, int iItalic, int iUnderline);
void mch_print_set_bg(long_u bgcol);
void mch_print_set_fg(long_u fgcol);
void hash_init(hashtab_T *ht);
void hash_clear(hashtab_T *ht);
void hash_clear_all(hashtab_T *ht, int off);
hashitem_T *hash_find(hashtab_T *ht, char_u *key);
hashitem_T *hash_lookup(hashtab_T *ht, char_u *key, hash_T hash);
void hash_debug_results(void);
int hash_add(hashtab_T *ht, char_u *key);
int hash_add_item(hashtab_T *ht, hashitem_T *hi, char_u *key, hash_T hash);
void hash_remove(hashtab_T *ht, hashitem_T *hi);
void hash_lock(hashtab_T *ht);
void hash_unlock(hashtab_T *ht);
hash_T hash_hash(char_u *key);
char_u *json_encode(typval_T *val, int options);
char_u *json_encode_nr_expr(int nr, typval_T *val, int options);
int json_decode_all(js_read_T *reader, typval_T *res, int options);
int json_decode(js_read_T *reader, typval_T *res, int options);
int json_find_end(js_read_T *reader, int options);
void list_add_watch(list_T *l, listwatch_T *lw);
void list_rem_watch(list_T *l, listwatch_T *lwrem);
void list_fix_watch(list_T *l, listitem_T *item);
list_T *list_alloc(void);
int rettv_list_alloc(typval_T *rettv);
void rettv_list_set(typval_T *rettv, list_T *l);
void list_unref(list_T *l);
int list_free_nonref(int copyID);
void list_free_items(int copyID);
void list_free(list_T *l);
listitem_T *listitem_alloc(void);
void listitem_free(listitem_T *item);
void listitem_remove(list_T *l, listitem_T *item);
long list_len(list_T *l);
int list_equal(list_T *l1, list_T *l2, int ic, int recursive);
listitem_T *list_find(list_T *l, long n);
long list_find_nr(list_T *l, long idx, int *errorp);
char_u *list_find_str(list_T *l, long idx);
long list_idx_of_item(list_T *l, listitem_T *item);
void list_append(list_T *l, listitem_T *item);
int list_append_tv(list_T *l, typval_T *tv);
int list_append_dict(list_T *list, dict_T *dict);
int list_append_string(list_T *l, char_u *str, int len);
int list_append_number(list_T *l, varnumber_T n);
int list_insert_tv(list_T *l, typval_T *tv, listitem_T *item);
void list_insert(list_T *l, listitem_T *ni, listitem_T *item);
int list_extend(list_T *l1, list_T *l2, listitem_T *bef);
int list_concat(list_T *l1, list_T *l2, typval_T *tv);
list_T *list_copy(list_T *orig, int deep, int copyID);
void vimlist_remove(list_T *l, listitem_T *item, listitem_T *item2);
char_u *list2string(typval_T *tv, int copyID, int restore_copyID);
int list_join(garray_T *gap, list_T *l, char_u *sep, int echo_style, int restore_copyID, int copyID);
int get_list_tv(char_u **arg, typval_T *rettv, int evaluate);
int write_list(FILE *fd, list_T *list, int binary);
void init_static_list(staticList10_T *sl);
int vim_main2(void);
void common_init(mparm_T *paramp);
int is_not_a_term(void);
void main_loop(int cmdwin, int noexmode);
void getout_preserve_modified(int exitval);
void getout(int exitval);
int process_env(char_u *env, int is_viminit);
void mainerr_arg_missing(char_u *str);
void time_push(void *tv_rel, void *tv_start);
void time_pop(void *tp);
void time_msg(char *mesg, void *tv_start);
void server_to_input_buf(char_u *str);
char_u *eval_client_expr_to_string(char_u *expr);
int sendToLocalVim(char_u *cmd, int asExpr, char_u **result);
char_u *serverConvert(char_u *client_enc, char_u *data, char_u **tofree);
int setmark(int c);
int setmark_pos(int c, pos_T *pos, int fnum);
void setpcmark(void);
void checkpcmark(void);
pos_T *movemark(int count);
pos_T *movechangelist(int count);
pos_T *getmark_buf(buf_T *buf, int c, int changefile);
pos_T *getmark(int c, int changefile);
pos_T *getmark_buf_fnum(buf_T *buf, int c, int changefile, int *fnum);
pos_T *getnextmark(pos_T *startpos, int dir, int begin_line);
void fmarks_check_names(buf_T *buf);
int check_mark(pos_T *pos);
void clrallmarks(buf_T *buf);
char_u *fm_getname(fmark_T *fmark, int lead_len);
void do_marks(exarg_T *eap);
void ex_delmarks(exarg_T *eap);
void ex_jumps(exarg_T *eap);
void ex_clearjumps(exarg_T *eap);
void ex_changes(exarg_T *eap);
void mark_adjust(linenr_T line1, linenr_T line2, long amount, long amount_after);
void mark_adjust_nofold(linenr_T line1, linenr_T line2, long amount, long amount_after);
void mark_col_adjust(linenr_T lnum, colnr_T mincol, long lnum_amount, long col_amount);
void copy_jumplist(win_T *from, win_T *to);
void free_jumplist(win_T *wp);
void set_last_cursor(win_T *win);
void free_all_marks(void);
int read_viminfo_filemark(vir_T *virp, int force);
void prepare_viminfo_marks(void);
void finish_viminfo_marks(void);
void handle_viminfo_mark(garray_T *values, int force);
void write_viminfo_filemarks(FILE *fp);
int removable(char_u *name);
void write_viminfo_marks(FILE *fp_out, garray_T *buflist);
void copy_viminfo_marks(vir_T *virp, FILE *fp_out, garray_T *buflist, int eof, int flags);
memfile_T *mf_open(char_u *fname, int flags);
int mf_open_file(memfile_T *mfp, char_u *fname);
void mf_close(memfile_T *mfp, int del_file);
void mf_close_file(buf_T *buf, int getlines);
void mf_new_page_size(memfile_T *mfp, unsigned new_size);
bhdr_T *mf_new(memfile_T *mfp, int negative, int page_count);
bhdr_T *mf_get(memfile_T *mfp, blocknr_T nr, int page_count);
void mf_put(memfile_T *mfp, bhdr_T *hp, int dirty, int infile);
void mf_free(memfile_T *mfp, bhdr_T *hp);
int mf_sync(memfile_T *mfp, int flags);
void mf_set_dirty(memfile_T *mfp);
int mf_release_all(void);
blocknr_T mf_trans_del(memfile_T *mfp, blocknr_T old_nr);
void mf_set_ffname(memfile_T *mfp);
void mf_fullname(memfile_T *mfp);
int mf_need_trans(memfile_T *mfp);
int ml_open(buf_T *buf);
void ml_set_crypt_key(buf_T *buf, char_u *old_key, char_u *old_cm);
void ml_setname(buf_T *buf);
void ml_open_files(void);
void ml_open_file(buf_T *buf);
void check_need_swap(int newfile);
void ml_close(buf_T *buf, int del_file);
void ml_close_all(int del_file);
void ml_close_notmod(void);
void ml_timestamp(buf_T *buf);
void ml_recover(void);
int recover_names(char_u *fname, int list, int nr, char_u **fname_out);
void ml_sync_all(int check_file, int check_char);
void ml_preserve(buf_T *buf, int message);
char_u *ml_get(linenr_T lnum);
char_u *ml_get_pos(pos_T *pos);
char_u *ml_get_curline(void);
char_u *ml_get_cursor(void);
char_u *ml_get_buf(buf_T *buf, linenr_T lnum, int will_change);
int ml_line_alloced(void);
int ml_append(linenr_T lnum, char_u *line, colnr_T len, int newfile);
int ml_append_buf(buf_T *buf, linenr_T lnum, char_u *line, colnr_T len, int newfile);
int ml_replace(linenr_T lnum, char_u *line, int copy);
int ml_delete(linenr_T lnum, int message);
void ml_setmarked(linenr_T lnum);
linenr_T ml_firstmarked(void);
void ml_clearmarked(void);
int resolve_symlink(char_u *fname, char_u *buf);
char_u *makeswapname(char_u *fname, char_u *ffname, buf_T *buf, char_u *dir_name);
char_u *get_file_in_dir(char_u *fname, char_u *dname);
void ml_setflags(buf_T *buf);
char_u *ml_encrypt_data(memfile_T *mfp, char_u *data, off_T offset, unsigned size);
void ml_decrypt_data(memfile_T *mfp, char_u *data, off_T offset, unsigned size);
long ml_find_line_or_offset(buf_T *buf, linenr_T lnum, long *offp);
void goto_byte(long cnt);
int winbar_height(win_T *wp);
void ex_menu(exarg_T *eap);
void remove_winbar(win_T *wp);
char_u *set_context_in_menu_cmd(expand_T *xp, char_u *cmd, char_u *arg, int forceit);
char_u *get_menu_name(expand_T *xp, int idx);
char_u *get_menu_names(expand_T *xp, int idx);
char_u *menu_name_skip(char_u *name);
int get_menu_index(vimmenu_T *menu, int state);
int menu_is_menubar(char_u *name);
int menu_is_popup(char_u *name);
int menu_is_child_of_popup(vimmenu_T *menu);
int menu_is_toolbar(char_u *name);
int menu_is_separator(char_u *name);
int check_menu_pointer(vimmenu_T *root, vimmenu_T *menu_to_check);
void gui_create_initial_menus(vimmenu_T *menu);
void gui_update_menus(int modes);
int gui_is_menu_shortcut(int key);
void gui_show_popupmenu(void);
void gui_mch_toggle_tearoffs(int enable);
void ex_emenu(exarg_T *eap);
void winbar_click(win_T *wp, int col);
vimmenu_T *gui_find_menu(char_u *path_name);
void ex_menutranslate(exarg_T *eap);
int fkmap(int c);
char_u *lrswap(char_u *ibuf);
char_u *lrFswap(char_u *cmdbuf, int len);
char_u *lrF_sub(char_u *ibuf);
int cmdl_fkmap(int c);
int F_isalpha(int c);
int F_isdigit(int c);
int F_ischar(int c);
void farsi_f8(cmdarg_T *cap);
void farsi_f9(cmdarg_T *cap);
int arabic_shape(int c, int *ccp, int *c1p, int prev_c, int prev_c1, int next_c);
int
smsg(char_u *, ...);
int
smsg_attr(int, char_u *, ...);
int
vim_snprintf_add(char *, size_t, char *, ...);
int
vim_snprintf(char *, size_t, char *, ...);
int vim_vsnprintf(char *str, size_t str_m, char *fmt, va_list ap);
int vim_vsnprintf_typval(char *str, size_t str_m, char *fmt, va_list ap, typval_T *tvs);
int msg(char_u *s);
int verb_msg(char_u *s);
int msg_attr(char_u *s, int attr);
int msg_attr_keep(char_u *s, int attr, int keep);
char_u *msg_strtrunc(char_u *s, int force);
void trunc_string(char_u *s, char_u *buf, int room_in, int buflen);
void reset_last_sourcing(void);
void msg_source(int attr);
int emsg_not_now(void);
void ignore_error_for_testing(char_u *error);
void do_perror(char *msg);
int emsg(char_u *s);
int emsg2(char_u *s, char_u *a1);
int emsg3(char_u *s, char_u *a1, char_u *a2);
int emsgn(char_u *s, long n);
void iemsg(char_u *s);
void iemsg2(char_u *s, char_u *a1);
void iemsgn(char_u *s, long n);
void internal_error(char *where);
void emsg_invreg(int name);
char_u *msg_trunc_attr(char_u *s, int force, int attr);
char_u *msg_may_trunc(int force, char_u *s);
int delete_first_msg(void);
void ex_messages(exarg_T *eap);
void msg_end_prompt(void);
void wait_return(int redraw);
void set_keep_msg(char_u *s, int attr);
void set_keep_msg_from_hist(void);
void msg_start(void);
void msg_starthere(void);
void msg_putchar(int c);
void msg_putchar_attr(int c, int attr);
void msg_outnum(long n);
void msg_home_replace(char_u *fname);
void msg_home_replace_hl(char_u *fname);
int msg_outtrans(char_u *str);
int msg_outtrans_attr(char_u *str, int attr);
int msg_outtrans_len(char_u *str, int len);
char_u *msg_outtrans_one(char_u *p, int attr);
int msg_outtrans_len_attr(char_u *msgstr, int len, int attr);
void msg_make(char_u *arg);
int msg_outtrans_special(char_u *strstart, int from);
char_u *str2special_save(char_u *str, int is_lhs);
char_u *str2special(char_u **sp, int from);
void str2specialbuf(char_u *sp, char_u *buf, int len);
void msg_prt_line(char_u *s, int list);
void msg_puts(char_u *s);
void msg_puts_title(char_u *s);
void msg_puts_long_attr(char_u *longstr, int attr);
void msg_puts_long_len_attr(char_u *longstr, int len, int attr);
void msg_puts_attr(char_u *s, int attr);
int message_filtered(char_u *msg);
void may_clear_sb_text(void);
void sb_text_start_cmdline(void);
void sb_text_end_cmdline(void);
void clear_sb_text(int all);
void show_sb_text(void);
void msg_sb_eol(void);
int msg_use_printf(void);
void mch_errmsg(char *str);
void mch_msg(char *str);
void msg_moremsg(int full);
void repeat_message(void);
void msg_clr_eos(void);
void msg_clr_eos_force(void);
void msg_clr_cmdline(void);
int msg_end(void);
void msg_check(void);
int redirecting(void);
void verbose_enter(void);
void verbose_leave(void);
void verbose_enter_scroll(void);
void verbose_leave_scroll(void);
void verbose_stop(void);
int verbose_open(void);
void give_warning(char_u *message, int hl);
void give_warning2(char_u *message, char_u *a1, int hl);
void msg_advance(int col);
int do_dialog(int type, char_u *title, char_u *message, char_u *buttons, int dfltbutton, char_u *textfield, int ex_cmd);
void display_confirm_msg(void);
int vim_dialog_yesno(int type, char_u *title, char_u *message, int dflt);
int vim_dialog_yesnocancel(int type, char_u *title, char_u *message, int dflt);
int vim_dialog_yesnoallcancel(int type, char_u *title, char_u *message, int dflt);
char_u *do_browse(int flags, char_u *title, char_u *dflt, char_u *ext, char_u *initdir, char_u *filter, buf_T *buf);
int get_whitespace_line_start(linenr_T lnum);
int get_indent(void);
int get_indent_lnum(linenr_T lnum);
int get_indent_buf(buf_T *buf, linenr_T lnum);
int get_indent_str(char_u *ptr, int ts, int list);
int set_indent(int size, int flags);
int get_number_indent(linenr_T lnum);
int get_breakindent_win(win_T *wp, char_u *line);
int open_line(int dir, int flags, int second_line_indent);
int get_leader_len(char_u *line, char_u **flags, int backward, int include_space);
int get_last_leader_offset(char_u *line, char_u **flags);
int plines(linenr_T lnum);
int plines_win(win_T *wp, linenr_T lnum, int winheight);
int plines_nofill(linenr_T lnum);
int plines_win_nofill(win_T *wp, linenr_T lnum, int winheight);
int plines_win_nofold(win_T *wp, linenr_T lnum);
int plines_win_col(win_T *wp, linenr_T lnum, long column);
int plines_m_win(win_T *wp, linenr_T first, linenr_T last);
void ins_bytes(char_u *p);
void ins_bytes_len(char_u *p, int len);
void ins_char(int c);
void ins_char_bytes(char_u *buf, int charlen);
void ins_str(char_u *s);
int del_char(int fixpos);
int del_chars(long count, int fixpos);
int del_bytes(long count, int fixpos_arg, int use_delcombine);
int truncate_line(int fixpos);
void del_lines(long nlines, int undo);
int gchar_pos(pos_T *pos);
int gchar_cursor(void);
void pchar_cursor(int c);
int inindent(int extra);
char_u *skip_to_option_part(char_u *p);
void changed(void);
void changed_int(void);
void changed_bytes(linenr_T lnum, colnr_T col);
void appended_lines(linenr_T lnum, long count);
void appended_lines_mark(linenr_T lnum, long count);
void deleted_lines(linenr_T lnum, long count);
void deleted_lines_mark(linenr_T lnum, long count);
void changed_lines(linenr_T lnum, colnr_T col, linenr_T lnume, long xtra);
void unchanged(buf_T *buf, int ff);
void check_status(buf_T *buf);
void change_warning(int col);
int ask_yesno(char_u *str, int direct);
int is_mouse_key(int c);
int get_keystroke(void);
int get_number(int colon, int *mouse_used);
int prompt_for_number(int *mouse_used);
void msgmore(long n);
void beep_flush(void);
void vim_beep(unsigned val);
void init_homedir(void);
void free_homedir(void);
void free_users(void);
char_u *expand_env_save(char_u *src);
char_u *expand_env_save_opt(char_u *src, int one);
void expand_env(char_u *src, char_u *dst, int dstlen);
void expand_env_esc(char_u *srcp, char_u *dst, int dstlen, int esc, int one, char_u *startstr);
char_u *vim_getenv(char_u *name, int *mustfree);
void vim_setenv(char_u *name, char_u *val);
char_u *get_env_name(expand_T *xp, int idx);
char_u *get_users(expand_T *xp, int idx);
int match_user(char_u *name);
void home_replace(buf_T *buf, char_u *src, char_u *dst, int dstlen, int one);
char_u *home_replace_save(buf_T *buf, char_u *src);
int fullpathcmp(char_u *s1, char_u *s2, int checkname);
char_u *gettail(char_u *fname);
char_u *gettail_sep(char_u *fname);
char_u *getnextcomp(char_u *fname);
char_u *get_past_head(char_u *path);
int vim_ispathsep(int c);
int vim_ispathsep_nocolon(int c);
int vim_ispathlistsep(int c);
void shorten_dir(char_u *str);
int dir_of_file_exists(char_u *fname);
int vim_fnamecmp(char_u *x, char_u *y);
int vim_fnamencmp(char_u *x, char_u *y, size_t len);
char_u *concat_fnames(char_u *fname1, char_u *fname2, int sep);
char_u *concat_str(char_u *str1, char_u *str2);
void add_pathsep(char_u *p);
char_u *FullName_save(char_u *fname, int force);
pos_T *find_start_comment(int ind_maxcomment);
void do_c_expr_indent(void);
int cin_islabel(void);
int cin_iscase(char_u *s, int strict);
int cin_isscopedecl(char_u *s);
void parse_cino(buf_T *buf);
int get_c_indent(void);
int get_expr_indent(void);
int get_lisp_indent(void);
void prepare_to_exit(void);
void preserve_exit(void);
int vim_fexists(char_u *fname);
void line_breakcheck(void);
void fast_breakcheck(void);
int expand_wildcards_eval(char_u **pat, int *num_file, char_u ***file, int flags);
int expand_wildcards(int num_pat, char_u **pat, int *num_files, char_u ***files, int flags);
int match_suffix(char_u *fname);
int unix_expandpath(garray_T *gap, char_u *path, int wildoff, int flags, int didstar);
void remove_duplicates(garray_T *gap);
int gen_expand_wildcards(int num_pat, char_u **pat, int *num_file, char_u ***file, int flags);
void addfile(garray_T *gap, char_u *f, int flags);
char_u *get_cmd_output(char_u *cmd, char_u *infile, int flags, int *ret_len);
void FreeWild(int count, char_u **files);
int goto_im(void);
char_u *get_isolated_shell_name(void);
int virtual_active(void);
int getviscol(void);
int getviscol2(colnr_T col, colnr_T coladd);
int coladvance_force(colnr_T wcol);
int coladvance(colnr_T wcol);
int getvpos(pos_T *pos, colnr_T wcol);
int inc_cursor(void);
int inc(pos_T *lp);
int incl(pos_T *lp);
int dec_cursor(void);
int dec(pos_T *lp);
int decl(pos_T *lp);
linenr_T get_cursor_rel_lnum(win_T *wp, linenr_T lnum);
void check_pos(buf_T *buf, pos_T *pos);
void check_cursor_lnum(void);
void check_cursor_col(void);
void check_cursor_col_win(win_T *win);
void check_cursor(void);
void adjust_cursor_col(void);
int leftcol_changed(void);
void vim_mem_profile_dump(void);
char_u *alloc(unsigned size);
char_u *alloc_id(unsigned size, alloc_id_T id);
char_u *alloc_clear(unsigned size);
char_u *alloc_check(unsigned size);
char_u *lalloc_clear(long_u size, int message);
char_u *lalloc(long_u size, int message);
char_u *lalloc_id(long_u size, int message, alloc_id_T id);
void *mem_realloc(void *ptr, size_t size);
void do_outofmem_msg(long_u size);
void free_all_mem(void);
char_u *vim_strsave(char_u *string);
char_u *vim_strnsave(char_u *string, int len);
char_u *vim_strsave_escaped(char_u *string, char_u *esc_chars);
char_u *vim_strsave_escaped_ext(char_u *string, char_u *esc_chars, int cc, int bsl);
int csh_like_shell(void);
char_u *vim_strsave_shellescape(char_u *string, int do_special, int do_newline);
char_u *vim_strsave_up(char_u *string);
char_u *vim_strnsave_up(char_u *string, int len);
void vim_strup(char_u *p);
char_u *strup_save(char_u *orig);
char_u *strlow_save(char_u *orig);
void del_trailing_spaces(char_u *ptr);
void vim_strncpy(char_u *to, char_u *from, size_t len);
void vim_strcat(char_u *to, char_u *from, size_t tosize);
int copy_option_part(char_u **option, char_u *buf, int maxlen, char *sep_chars);
void vim_free(void *x);
int vim_stricmp(char *s1, char *s2);
int vim_strnicmp(char *s1, char *s2, size_t len);
char_u *vim_strchr(char_u *string, int c);
char_u *vim_strbyte(char_u *string, int c);
char_u *vim_strrchr(char_u *string, int c);
int vim_isspace(int x);
void ga_clear(garray_T *gap);
void ga_clear_strings(garray_T *gap);
void ga_init(garray_T *gap);
void ga_init2(garray_T *gap, int itemsize, int growsize);
int ga_grow(garray_T *gap, int n);
char_u *ga_concat_strings(garray_T *gap, char *sep);
void ga_add_string(garray_T *gap, char_u *p);
void ga_concat(garray_T *gap, char_u *s);
void ga_append(garray_T *gap, int c);
void append_ga_line(garray_T *gap);
int name_to_mod_mask(int c);
int simplify_key(int key, int *modifiers);
int handle_x_keys(int key);
char_u *get_special_key_name(int c, int modifiers);
int trans_special(char_u **srcp, char_u *dst, int keycode, int in_string);
int find_special_key(char_u **srcp, int *modp, int keycode, int keep_x_key, int in_string);
int extract_modifiers(int key, int *modp);
int find_special_key_in_table(int c);
int get_special_key_code(char_u *name);
char_u *get_key_name(int i);
int get_mouse_button(int code, int *is_click, int *is_drag);
int get_pseudo_mouse_code(int button, int is_click, int is_drag);
int get_fileformat(buf_T *buf);
int get_fileformat_force(buf_T *buf, exarg_T *eap);
void set_fileformat(int t, int opt_flags);
int default_fileformat(void);
int call_shell(char_u *cmd, int opt);
int get_real_state(void);
int after_pathsep(char_u *b, char_u *p);
int same_directory(char_u *f1, char_u *f2);
int vim_chdirfile(char_u *fname);
int vim_stat(const char *name, stat_T *stp);
char_u *parse_shape_opt(int what);
int get_shape_idx(int mouse);
void update_mouseshape(int shape_idx);
void *vim_findfile_init(char_u *path, char_u *filename, char_u *stopdirs, int level, int free_visited, int find_what, void *search_ctx_arg, int tagfile, char_u *rel_fname);
char_u *vim_findfile_stopdir(char_u *buf);
void vim_findfile_cleanup(void *ctx);
char_u *vim_findfile(void *search_ctx_arg);
void vim_findfile_free_visited(void *search_ctx_arg);
char_u *find_file_in_path(char_u *ptr, int len, int options, int first, char_u *rel_fname);
char_u *find_directory_in_path(char_u *ptr, int len, int options, char_u *rel_fname);
char_u *find_file_in_path_option(char_u *ptr, int len, int options, int first, char_u *path_option, int find_what, char_u *rel_fname, char_u *suffixes);
int vim_chdir(char_u *new_dir);
int get_user_name(char_u *buf, int len);
void sort_strings(char_u **files, int count);
int pathcmp(const char *p, const char *q, int maxlen);
int filewritable(char_u *fname);
int get2c(FILE *fd);
int get3c(FILE *fd);
int get4c(FILE *fd);
time_T get8ctime(FILE *fd);
char_u *read_string(FILE *fd, int cnt);
int put_bytes(FILE *fd, long_u nr, int len);
int put_time(FILE *fd, time_T the_time);
void time_to_bytes(time_T the_time, char_u *buf);
int has_non_ascii(char_u *s);
void parse_queued_messages(void);
void update_topline_redraw(void);
void update_topline(void);
void update_curswant(void);
void check_cursor_moved(win_T *wp);
void changed_window_setting(void);
void changed_window_setting_win(win_T *wp);
void set_topline(win_T *wp, linenr_T lnum);
void changed_cline_bef_curs(void);
void changed_cline_bef_curs_win(win_T *wp);
void changed_line_abv_curs(void);
void changed_line_abv_curs_win(win_T *wp);
void validate_botline(void);
void invalidate_botline(void);
void invalidate_botline_win(win_T *wp);
void approximate_botline_win(win_T *wp);
int cursor_valid(void);
void validate_cursor(void);
void validate_cline_row(void);
void validate_virtcol(void);
void validate_virtcol_win(win_T *wp);
void validate_cursor_col(void);
int win_col_off(win_T *wp);
int curwin_col_off(void);
int win_col_off2(win_T *wp);
int curwin_col_off2(void);
void curs_columns(int may_scroll);
void scrolldown(long line_count, int byfold);
void scrollup(long line_count, int byfold);
void check_topfill(win_T *wp, int down);
void scrolldown_clamp(void);
void scrollup_clamp(void);
void scroll_cursor_top(int min_scroll, int always);
void set_empty_rows(win_T *wp, int used);
void scroll_cursor_bot(int min_scroll, int set_topbot);
void scroll_cursor_halfway(int atend);
void cursor_correct(void);
int onepage(int dir, long count);
void halfpage(int flag, linenr_T Prenum);
void do_check_cursorbind(void);
int enc_canon_props(char_u *name);
char_u *mb_init(void);
int bomb_size(void);
void remove_bom(char_u *s);
int mb_get_class(char_u *p);
int mb_get_class_buf(char_u *p, buf_T *buf);
int dbcs_class(unsigned lead, unsigned trail);
int latin_char2len(int c);
int latin_char2bytes(int c, char_u *buf);
int latin_ptr2len(char_u *p);
int latin_ptr2len_len(char_u *p, int size);
int utf_uint2cells(UINT32_T c);
int utf_char2cells(int c);
int latin_ptr2cells(char_u *p);
int utf_ptr2cells(char_u *p);
int dbcs_ptr2cells(char_u *p);
int latin_ptr2cells_len(char_u *p, int size);
int latin_char2cells(int c);
int mb_string2cells(char_u *p, int len);
int latin_off2cells(unsigned off, unsigned max_off);
int dbcs_off2cells(unsigned off, unsigned max_off);
int utf_off2cells(unsigned off, unsigned max_off);
int latin_ptr2char(char_u *p);
int utf_ptr2char(char_u *p);
int mb_ptr2char_adv(char_u **pp);
int mb_cptr2char_adv(char_u **pp);
int arabic_combine(int one, int two);
int arabic_maycombine(int two);
int utf_composinglike(char_u *p1, char_u *p2);
int utfc_ptr2char(char_u *p, int *pcc);
int utfc_ptr2char_len(char_u *p, int *pcc, int maxlen);
int utfc_char2bytes(int off, char_u *buf);
int utf_ptr2len(char_u *p);
int utf_byte2len(int b);
int utf_ptr2len_len(char_u *p, int size);
int utfc_ptr2len(char_u *p);
int utfc_ptr2len_len(char_u *p, int size);
int utf_char2len(int c);
int utf_char2bytes(int c, char_u *buf);
int utf_iscomposing_uint(UINT32_T c);
int utf_iscomposing(int c);
int utf_printable(int c);
int utf_class(int c);
int utf_class_buf(int c, buf_T *buf);
int utf_ambiguous_width(int c);
int utf_fold(int a);
int utf_toupper(int a);
int utf_islower(int a);
int utf_tolower(int a);
int utf_isupper(int a);
int mb_strnicmp(char_u *s1, char_u *s2, size_t nn);
void show_utf8(void);
int latin_head_off(char_u *base, char_u *p);
int dbcs_head_off(char_u *base, char_u *p);
int dbcs_screen_head_off(char_u *base, char_u *p);
int utf_head_off(char_u *base, char_u *p);
void mb_copy_char(char_u **fp, char_u **tp);
int mb_off_next(char_u *base, char_u *p);
int mb_tail_off(char_u *base, char_u *p);
void utf_find_illegal(void);
int utf_valid_string(char_u *s, char_u *end);
int dbcs_screen_tail_off(char_u *base, char_u *p);
void mb_adjust_cursor(void);
void mb_adjustpos(buf_T *buf, pos_T *lp);
char_u *mb_prevptr(char_u *line, char_u *p);
int mb_charlen(char_u *str);
int mb_charlen_len(char_u *str, int len);
char_u *mb_unescape(char_u **pp);
int mb_lefthalve(int row, int col);
int mb_fix_col(int col, int row);
char_u *enc_skip(char_u *p);
char_u *enc_canonize(char_u *enc);
char_u *enc_locale_env(char *locale);
char_u *enc_locale(void);
int encname2codepage(char_u *name);
void *my_iconv_open(char_u *to, char_u *from);
int iconv_enabled(int verbose);
void iconv_end(void);
void im_set_active(int active);
void xim_set_focus(int focus);
void im_set_position(int row, int col);
void xim_set_preedit(void);
int im_get_feedback_attr(int col);
void xim_init(void);
void im_shutdown(void);
int im_xim_isvalid_imactivate(void);
void xim_reset(void);
int xim_queue_key_press_event(int *event, int down);
int im_get_status(void);
int preedit_get_status(void);
int im_is_preediting(void);
void xim_set_status_area(void);
int xim_get_status_area_height(void);
int convert_setup(vimconv_T *vcp, char_u *from, char_u *to);
int convert_setup_ext(vimconv_T *vcp, char_u *from, int from_unicode_is_utf8, char_u *to, int to_unicode_is_utf8);
int convert_input(char_u *ptr, int len, int maxlen);
int convert_input_safe(char_u *ptr, int len, int maxlen, char_u **restp, int *restlenp);
char_u *string_convert(vimconv_T *vcp, char_u *ptr, int *lenp);
char_u *string_convert_ext(vimconv_T *vcp, char_u *ptr, int *lenp, int *unconvlenp);
void init_normal_cmds(void);
void normal_cmd(oparg_T *oap, int toplevel);
void do_pending_operator(cmdarg_T *cap, int old_col, int gui_yank);
int do_mouse(oparg_T *oap, int c, int dir, long count, int fixindent);
void check_visual_highlight(void);
void end_visual_mode(void);
void reset_VIsual_and_resel(void);
void reset_VIsual(void);
int find_ident_under_cursor(char_u **string, int find_type);
int find_ident_at_pos(win_T *wp, linenr_T lnum, colnr_T startcol, char_u **string, int find_type);
void clear_showcmd(void);
int add_to_showcmd(int c);
void add_to_showcmd_c(int c);
void push_showcmd(void);
void pop_showcmd(void);
void do_check_scrollbind(int check);
void check_scrollbind(linenr_T topline_diff, long leftcol_diff);
int find_decl(char_u *ptr, int len, int locally, int thisblock, int flags_arg);
void scroll_redraw(int up, long count);
void handle_tabmenu(void);
void do_nv_ident(int c1, int c2);
int get_visual_text(cmdarg_T *cap, char_u **pp, int *lenp);
void start_selection(void);
void may_start_select(int c);
int get_op_type(int char1, int char2);
int op_on_lines(int op);
int get_op_char(int optype);
int get_extra_op_char(int optype);
void op_shift(oparg_T *oap, int curs_top, int amount);
void shift_line(int left, int round, int amount, int call_changed_bytes);
void op_reindent(oparg_T *oap, int (*how)(void));
int get_expr_register(void);
void set_expr_line(char_u *new_line);
char_u *get_expr_line(void);
char_u *get_expr_line_src(void);
int valid_yank_reg(int regname, int writing);
void get_yank_register(int regname, int writing);
int may_get_selection(int regname);
void *get_register(int name, int copy);
void put_register(int name, void *reg);
void free_register(void *reg);
int yank_register_mline(int regname);
int do_record(int c);
int do_execreg(int regname, int colon, int addcr, int silent);
int insert_reg(int regname, int literally);
int get_spec_reg(int regname, char_u **argp, int *allocated, int errmsg);
int cmdline_paste_reg(int regname, int literally, int remcr);
void adjust_clip_reg(int *rp);
void shift_delete_registers(void);
int op_delete(oparg_T *oap);
int op_replace(oparg_T *oap, int c);
void op_tilde(oparg_T *oap);
int swapchar(int op_type, pos_T *pos);
void op_insert(oparg_T *oap, long count1);
int op_change(oparg_T *oap);
void init_yank(void);
void clear_registers(void);
int op_yank(oparg_T *oap, int deleting, int mess);
void do_put(int regname, int dir, long count, int flags);
void adjust_cursor_eol(void);
int preprocs_left(void);
int get_register_name(int num);
void ex_display(exarg_T *eap);
char_u *skip_comment(char_u *line, int process, int include_space, int *is_comment);
int do_join(long count, int insert_space, int save_undo, int use_formatoptions, int setmark);
void op_format(oparg_T *oap, int keep_cursor);
void op_formatexpr(oparg_T *oap);
int fex_format(linenr_T lnum, long count, int c);
void format_lines(linenr_T line_count, int avoid_fex);
int paragraph_start(linenr_T lnum);
void op_addsub(oparg_T *oap, linenr_T Prenum1, int g_cmd);
void prepare_viminfo_registers(void);
void finish_viminfo_registers(void);
int read_viminfo_register(vir_T *virp, int force);
void handle_viminfo_register(garray_T *values, int force);
void write_viminfo_registers(FILE *fp);
void x11_export_final_selection(void);
void clip_free_selection(VimClipboard *cbd);
void clip_get_selection(VimClipboard *cbd);
void clip_yank_selection(int type, char_u *str, long len, VimClipboard *cbd);
int clip_convert_selection(char_u **str, long_u *len, VimClipboard *cbd);
void dnd_yank_drag_data(char_u *str, long len);
char_u get_reg_type(int regname, long *reglen);
char_u *get_reg_contents(int regname, int flags);
void write_reg_contents(int name, char_u *str, int maxlen, int must_append);
void write_reg_contents_lst(int name, char_u **strings, int maxlen, int must_append, int yank_type, long block_len);
void write_reg_contents_ex(int name, char_u *str, int maxlen, int must_append, int yank_type, long block_len);
void clear_oparg(oparg_T *oap);
void cursor_pos_info(dict_T *dict);
void set_init_1(void);
void set_string_default(char *name, char_u *val);
void set_number_default(char *name, long val);
void free_all_options(void);
void set_init_2(void);
void set_init_3(void);
void set_helplang_default(char_u *lang);
void init_gui_options(void);
void set_title_defaults(void);
int do_set(char_u *arg, int opt_flags);
int string_to_key(char_u *arg, int multi_byte);
void set_options_bin(int oldval, int newval, int opt_flags);
int get_viminfo_parameter(int type);
char_u *find_viminfo_parameter(int type);
void check_options(void);
void check_buf_options(buf_T *buf);
void free_string_option(char_u *p);
void clear_string_option(char_u **pp);
void set_term_option_alloced(char_u **p);
int was_set_insecurely(char_u *opt, int opt_flags);
void set_string_option_direct(char_u *name, int opt_idx, char_u *val, int opt_flags, int set_sid);
char_u *check_colorcolumn(win_T *wp);
char_u *check_stl_option(char_u *s);
int get_option_value(char_u *name, long *numval, char_u **stringval, int opt_flags);
int get_option_value_strict(char_u *name, long *numval, char_u **stringval, int opt_type, void *from);
char_u *option_iter_next(void **option, int opt_type);
char_u *set_option_value(char_u *name, long number, char_u *string, int opt_flags);
char_u *get_term_code(char_u *tname);
char_u *get_highlight_default(void);
char_u *get_encoding_default(void);
int makeset(FILE *fd, int opt_flags, int local_only);
int makefoldset(FILE *fd);
void clear_termoptions(void);
void free_termoptions(void);
void free_one_termoption(char_u *var);
void set_term_defaults(void);
void comp_col(void);
void unset_global_local_option(char_u *name, void *from);
char_u *get_equalprg(void);
void win_copy_options(win_T *wp_from, win_T *wp_to);
void copy_winopt(winopt_T *from, winopt_T *to);
void check_win_options(win_T *win);
void clear_winopt(winopt_T *wop);
void buf_copy_options(buf_T *buf, int flags);
void reset_modifiable(void);
void set_iminsert_global(void);
void set_imsearch_global(void);
void set_context_in_set_cmd(expand_T *xp, char_u *arg, int opt_flags);
int ExpandSettings(expand_T *xp, regmatch_T *regmatch, int *num_file, char_u ***file);
int ExpandOldSetting(int *num_file, char_u ***file);
int langmap_adjust_mb(int c);
int has_format_option(int x);
int shortmess(int x);
void vimrc_found(char_u *fname, char_u *envname);
void change_compatible(int on);
int option_was_set(char_u *name);
void reset_option_was_set(char_u *name);
int can_bs(int what);
void save_file_ff(buf_T *buf);
int file_ff_differs(buf_T *buf, int ignore_empty);
int check_ff_value(char_u *p);
long get_sw_value(buf_T *buf);
long get_sts_value(void);
void find_mps_values(int *initc, int *findc, int *backwards, int switchit);
unsigned int get_bkc_value(buf_T *buf);
int signcolumn_on(win_T *wp);
dict_T *get_winbuf_options(int bufopt);
void pum_display(pumitem_T *array, int size, int selected);
void pum_redraw(void);
void pum_undisplay(void);
void pum_clear(void);
int pum_visible(void);
int pum_get_height(void);
int qf_init(win_T *wp, char_u *efile, char_u *errorformat, int newlist, char_u *qf_title, char_u *enc);
void qf_free_all(win_T *wp);
void copy_loclist(win_T *from, win_T *to);
void qf_jump(qf_info_T *qi, int dir, int errornr, int forceit);
void qf_list(exarg_T *eap);
void qf_age(exarg_T *eap);
void qf_history(exarg_T *eap);
void qf_mark_adjust(win_T *wp, linenr_T line1, linenr_T line2, long amount, long amount_after);
void ex_cwindow(exarg_T *eap);
void ex_cclose(exarg_T *eap);
void ex_copen(exarg_T *eap);
void ex_cbottom(exarg_T *eap);
linenr_T qf_current_entry(win_T *wp);
int grep_internal(cmdidx_T cmdidx);
void ex_make(exarg_T *eap);
int qf_get_size(exarg_T *eap);
int qf_get_cur_idx(exarg_T *eap);
int qf_get_cur_valid_idx(exarg_T *eap);
void ex_cc(exarg_T *eap);
void ex_cnext(exarg_T *eap);
void ex_cfile(exarg_T *eap);
void ex_vimgrep(exarg_T *eap);
int get_errorlist(qf_info_T *qi, win_T *wp, int qf_idx, list_T *list);
int qf_get_properties(win_T *wp, dict_T *what, dict_T *retdict);
int set_errorlist(win_T *wp, list_T *list, int action, char_u *title, dict_T *what);
int set_ref_in_quickfix(int copyID);
void ex_cbuffer(exarg_T *eap);
void ex_cexpr(exarg_T *eap);
void ex_helpgrep(exarg_T *eap);
int re_multiline(regprog_T *prog);
int re_lookbehind(regprog_T *prog);
char_u *skip_regexp(char_u *startp, int dirc, int magic, char_u **newp);
int vim_regcomp_had_eol(void);
void free_regexp_stuff(void);
reg_extmatch_T *ref_extmatch(reg_extmatch_T *em);
void unref_extmatch(reg_extmatch_T *em);
char_u *regtilde(char_u *source, int magic);
int vim_regsub(regmatch_T *rmp, char_u *source, typval_T *expr, char_u *dest, int copy, int magic, int backslash);
int vim_regsub_multi(regmmatch_T *rmp, linenr_T lnum, char_u *source, char_u *dest, int copy, int magic, int backslash);
char_u *reg_submatch(int no);
list_T *reg_submatch_list(int no);
regprog_T *vim_regcomp(char_u *expr_arg, int re_flags);
void vim_regfree(regprog_T *prog);
int vim_regexec_prog(regprog_T **prog, int ignore_case, char_u *line, colnr_T col);
int vim_regexec(regmatch_T *rmp, char_u *line, colnr_T col);
int vim_regexec_nl(regmatch_T *rmp, char_u *line, colnr_T col);
long vim_regexec_multi(regmmatch_T *rmp, win_T *win, buf_T *buf, linenr_T lnum, colnr_T col, proftime_T *tm, int *timed_out);
void redraw_later(int type);
void redraw_win_later(win_T *wp, int type);
void redraw_later_clear(void);
void redraw_all_later(int type);
void redraw_curbuf_later(int type);
void redraw_buf_later(buf_T *buf, int type);
void redraw_buf_and_status_later(buf_T *buf, int type);
int redraw_asap(int type);
void redraw_after_callback(int call_update_screen);
void redrawWinline(linenr_T lnum, int invalid);
void update_curbuf(int type);
int update_screen(int type_arg);
int conceal_cursor_line(win_T *wp);
void conceal_check_cursur_line(void);
void update_single_line(win_T *wp, linenr_T lnum);
void update_debug_sign(buf_T *buf, linenr_T lnum);
void updateWindow(win_T *wp);
int screen_get_current_line_off(void);
void screen_line(int row, int coloff, int endcol, int clear_width, int rlflag);
void rl_mirror(char_u *str);
void status_redraw_all(void);
void status_redraw_curbuf(void);
void redraw_statuslines(void);
void win_redraw_last_status(frame_T *frp);
void win_redr_status_matches(expand_T *xp, int num_matches, char_u **matches, int match, int showtail);
void win_redr_status(win_T *wp);
int stl_connected(win_T *wp);
int get_keymap_str(win_T *wp, char_u *fmt, char_u *buf, int len);
void screen_putchar(int c, int row, int col, int attr);
void screen_getbytes(int row, int col, char_u *bytes, int *attrp);
void screen_puts(char_u *text, int row, int col, int attr);
void screen_puts_len(char_u *text, int textlen, int row, int col, int attr);
void screen_stop_highlight(void);
void reset_cterm_colors(void);
void screen_draw_rectangle(int row, int col, int height, int width, int invert);
void screen_fill(int start_row, int end_row, int start_col, int end_col, int c1, int c2, int attr);
void check_for_delay(int check_msg_scroll);
int screen_valid(int doclear);
void screenalloc(int doclear);
void free_screenlines(void);
void screenclear(void);
int can_clear(char_u *p);
void screen_start(void);
void windgoto(int row, int col);
void setcursor(void);
int win_ins_lines(win_T *wp, int row, int line_count, int invalid, int mayclear);
int win_del_lines(win_T *wp, int row, int line_count, int invalid, int mayclear, int clear_attr);
int screen_ins_lines(int off, int row, int line_count, int end, int clear_attr, win_T *wp);
int screen_del_lines(int off, int row, int line_count, int end, int force, int clear_attr, win_T *wp);
int showmode(void);
void unshowmode(int force);
void clearmode(void);
void get_trans_bufname(buf_T *buf);
int redrawing(void);
int messaging(void);
void showruler(int always);
int number_width(win_T *wp);
int screen_screencol(void);
int screen_screenrow(void);
void sha256_start(context_sha256_T *ctx);
void sha256_update(context_sha256_T *ctx, char_u *input, UINT32_T length);
void sha256_finish(context_sha256_T *ctx, char_u digest[32]);
char_u *sha256_bytes(char_u *buf, int buf_len, char_u *salt, int salt_len);
char_u *sha256_key(char_u *buf, char_u *salt, int salt_len);
int sha256_self_test(void);
void sha2_seed(char_u *header, int header_len, char_u *salt, int salt_len);
int search_regcomp(char_u *pat, int pat_save, int pat_use, int options, regmmatch_T *regmatch);
char_u *get_search_pat(void);
char_u *reverse_text(char_u *s);
void save_re_pat(int idx, char_u *pat, int magic);
void save_search_patterns(void);
void restore_search_patterns(void);
void free_search_patterns(void);
int ignorecase(char_u *pat);
int ignorecase_opt(char_u *pat, int ic_in, int scs);
int pat_has_uppercase(char_u *pat);
char_u *last_csearch(void);
int last_csearch_forward(void);
int last_csearch_until(void);
void set_last_csearch(int c, char_u *s, int len);
void set_csearch_direction(int cdir);
void set_csearch_until(int t_cmd);
char_u *last_search_pat(void);
void reset_search_dir(void);
void set_last_search_pat(char_u *s, int idx, int magic, int setlast);
void last_pat_prog(regmmatch_T *regmatch);
int searchit(win_T *win, buf_T *buf, pos_T *pos, int dir, char_u *pat, long count, int options, int pat_use, linenr_T stop_lnum, proftime_T *tm, int *timed_out);
void set_search_direction(int cdir);
int do_search(oparg_T *oap, int dirc, char_u *pat, long count, int options, proftime_T *tm, int *timed_out);
int search_for_exact_line(buf_T *buf, pos_T *pos, int dir, char_u *pat);
int searchc(cmdarg_T *cap, int t_cmd);
pos_T *findmatch(oparg_T *oap, int initc);
pos_T *findmatchlimit(oparg_T *oap, int initc, int flags, int maxtravel);
void showmatch(int c);
int findsent(int dir, long count);
int findpar(int *pincl, int dir, long count, int what, int both);
int startPS(linenr_T lnum, int para, int both);
int fwd_word(long count, int bigword, int eol);
int bck_word(long count, int bigword, int stop);
int end_word(long count, int bigword, int stop, int empty);
int bckend_word(long count, int bigword, int eol);
int current_word(oparg_T *oap, long count, int include, int bigword);
int current_sent(oparg_T *oap, long count, int include);
int current_block(oparg_T *oap, long count, int include, int what, int other);
int current_tagblock(oparg_T *oap, long count_arg, int include);
int current_par(oparg_T *oap, long count, int include, int type);
int current_quote(oparg_T *oap, long count, int include, int quotechar);
int current_search(long count, int forward);
int linewhite(linenr_T lnum);
void find_pattern_in_path(char_u *ptr, int dir, int len, int whole, int skip_comments, int type, long count, int action, linenr_T start_lnum, linenr_T end_lnum);
int read_viminfo_search_pattern(vir_T *virp, int force);
void write_viminfo_search_pattern(FILE *fp);
int spell_check(win_T *wp, char_u *ptr, hlf_T *attrp, int *capcol, int docount);
int spell_move_to(win_T *wp, int dir, int allwords, int curline, hlf_T *attrp);
void spell_cat_line(char_u *buf, char_u *line, int maxlen);
char_u *spell_enc(void);
slang_T *slang_alloc(char_u *lang);
void slang_free(slang_T *lp);
void slang_clear(slang_T *lp);
void slang_clear_sug(slang_T *lp);
void count_common_word(slang_T *lp, char_u *word, int len, int count);
int byte_in_str(char_u *str, int n);
int init_syl_tab(slang_T *slang);
char_u *did_set_spelllang(win_T *wp);
int captype(char_u *word, char_u *end);
void spell_delete_wordlist(void);
void spell_free_all(void);
void spell_reload(void);
buf_T *open_spellbuf(void);
void close_spellbuf(buf_T *buf);
void clear_spell_chartab(spelltab_T *sp);
void init_spell_chartab(void);
int spell_iswordp_nmw(char_u *p, win_T *wp);
int spell_casefold(char_u *str, int len, char_u *buf, int buflen);
int spell_check_sps(void);
void spell_suggest(int count);
void ex_spellrepall(exarg_T *eap);
void spell_suggest_list(garray_T *gap, char_u *word, int maxcount, int need_cap, int interactive);
void onecap_copy(char_u *word, char_u *wcopy, int upper);
char_u *eval_soundfold(char_u *word);
void spell_soundfold(slang_T *slang, char_u *inword, int folded, char_u *res);
void ex_spellinfo(exarg_T *eap);
void ex_spelldump(exarg_T *eap);
void spell_dump_compl(char_u *pat, int ic, int *dir, int dumpflags_arg);
char_u *spell_to_word_end(char_u *start, win_T *win);
int spell_word_start(int startcol);
void spell_expand_check_cap(colnr_T col);
int expand_spelling(linenr_T lnum, char_u *pat, char_u ***matchp);
slang_T *spell_load_file(char_u *fname, char_u *lang, slang_T *old_lp, int silent);
void suggest_load_files(void);
int spell_check_msm(void);
void ex_mkspell(exarg_T *eap);
void mkspell(int fcount, char_u **fnames, int ascii, int over_write, int added_word);
void ex_spell(exarg_T *eap);
void spell_add_word(char_u *word, int len, int bad, int idx, int undo);
void syn_set_timeout(proftime_T *tm);
void syntax_start(win_T *wp, linenr_T lnum);
void syn_stack_free_all(synblock_T *block);
void syn_stack_apply_changes(buf_T *buf);
void syntax_end_parsing(linenr_T lnum);
int syntax_check_changed(linenr_T lnum);
int get_syntax_attr(colnr_T col, int *can_spell, int keep_state);
void syntax_clear(synblock_T *block);
void reset_synblock(win_T *wp);
void ex_syntax(exarg_T *eap);
void ex_ownsyntax(exarg_T *eap);
int syntax_present(win_T *win);
void reset_expand_highlight(void);
void set_context_in_echohl_cmd(expand_T *xp, char_u *arg);
void set_context_in_syntax_cmd(expand_T *xp, char_u *arg);
char_u *get_syntax_name(expand_T *xp, int idx);
int syn_get_id(win_T *wp, long lnum, colnr_T col, int trans, int *spellp, int keep_state);
int get_syntax_info(int *seqnrp);
int syn_get_sub_char(void);
int syn_get_stack_item(int i);
int syn_get_foldlevel(win_T *wp, long lnum);
void ex_syntime(exarg_T *eap);
char_u *get_syntime_arg(expand_T *xp, int idx);
void init_highlight(int both, int reset);
int load_colors(char_u *name);
int lookup_color(int idx, int foreground, int *boldp);
void do_highlight(char_u *line, int forceit, int init);
void free_highlight(void);
void restore_cterm_colors(void);
void set_normal_colors(void);
char_u *hl_get_font_name(void);
void hl_set_font_name(char_u *font_name);
void hl_set_bg_color_name(char_u *name);
void hl_set_fg_color_name(char_u *name);
long color_name2handle(char_u *name);
int get_cterm_attr_idx(int attr, int fg, int bg);
int get_tgc_attr_idx(int attr, long fg, long bg);
int get_gui_attr_idx(int attr, long fg, long bg);
void clear_hl_tables(void);
int hl_combine_attr(int char_attr, int prim_attr);
attrentry_T *syn_gui_attr2entry(int attr);
int syn_attr2attr(int attr);
attrentry_T *syn_term_attr2entry(int attr);
attrentry_T *syn_cterm_attr2entry(int attr);
char_u *highlight_has_attr(int id, int flag, int modec);
char_u *highlight_color(int id, char_u *what, int modec);
long_u highlight_gui_color_rgb(int id, int fg);
int syn_name2id(char_u *name);
int syn_name2attr(char_u *name);
int highlight_exists(char_u *name);
char_u *syn_id2name(int id);
int syn_namen2id(char_u *linep, int len);
int syn_check_group(char_u *pp, int len);
int syn_id2attr(int hl_id);
int syn_id2colors(int hl_id, long *fgp, long *bgp);
void syn_id2cterm_bg(int hl_id, int *fgp, int *bgp);
int syn_get_final_id(int hl_id);
void highlight_gui_started(void);
int highlight_changed(void);
void set_context_in_highlight_cmd(expand_T *xp, char_u *arg);
char_u *get_highlight_name(expand_T *xp, int idx);
char_u *get_highlight_name_ext(expand_T *xp, int idx, int skip_cleared);
void free_highlight_fonts(void);
int do_tag(char_u *tag, int type, int count, int forceit, int verbose);
void tag_freematch(void);
void do_tags(exarg_T *eap);
int find_tags(char_u *pat, int *num_matches, char_u ***matchesp, int flags, int mincount, char_u *buf_ffname);
void free_tag_stuff(void);
int get_tagfname(tagname_T *tnp, int first, char_u *buf);
void tagname_free(tagname_T *tnp);
void simplify_filename(char_u *filename);
int expand_tags(int tagnames, char_u *pat, int *num_file, char_u ***file);
int get_tags(list_T *list, char_u *pat, char_u *buf_fname);
long termgui_mch_get_color(char_u *name);
long termgui_get_color(char_u *name);
long termgui_mch_get_rgb(long color);
int set_termname(char_u *term);
void set_mouse_termcode(int n, char_u *s);
void del_mouse_termcode(int n);
void getlinecol(long *cp, long *rp);
int add_termcap_entry(char_u *name, int force);
int term_is_8bit(char_u *name);
int term_is_gui(char_u *name);
char_u *tltoa(unsigned long i);
void termcapinit(char_u *name);
void out_flush(void);
void out_flush_check(void);
void out_trash(void);
void out_char(unsigned c);
void out_str_nf(char_u *s);
void out_str_cf(char_u *s);
void out_str(char_u *s);
void term_windgoto(int row, int col);
void term_cursor_right(int i);
void term_append_lines(int line_count);
void term_delete_lines(int line_count);
void term_set_winpos(int x, int y);
int term_get_winpos(int *x, int *y);
void term_set_winsize(int height, int width);
void term_fg_color(int n);
void term_bg_color(int n);
void term_fg_rgb_color(long rgb);
void term_bg_rgb_color(long rgb);
void term_settitle(char_u *title);
void ttest(int pairs);
void add_long_to_buf(long_u val, char_u *dst);
void check_shellsize(void);
void limit_screen_size(void);
void win_new_shellsize(void);
void shell_resized(void);
void shell_resized_check(void);
void set_shellsize(int width, int height, int mustset);
void settmode(int tmode);
void starttermcap(void);
void stoptermcap(void);
void may_req_termresponse(void);
void may_req_ambiguous_char_width(void);
void may_req_bg_color(void);
int swapping_screen(void);
void setmouse(void);
int mouse_has(int c);
int mouse_model_popup(void);
void scroll_start(void);
void cursor_on(void);
void cursor_off(void);
void term_cursor_mode(int forced);
void term_cursor_color(char_u *color);
int blink_state_is_inverted(void);
void term_cursor_shape(int shape, int blink);
void scroll_region_set(win_T *wp, int off);
void scroll_region_reset(void);
void clear_termcodes(void);
void add_termcode(char_u *name, char_u *string, int flags);
char_u *find_termcode(char_u *name);
char_u *get_termcode(int i);
void del_termcode(char_u *name);
void set_mouse_topline(win_T *wp);
int check_termcode(int max_offset, char_u *buf, int bufsize, int *buflen);
char_u *replace_termcodes(char_u *from, char_u **bufp, int from_part, int do_lt, int special);
int find_term_bykeys(char_u *src);
void show_termcodes(void);
int show_one_termcode(char_u *name, char_u *code, int printit);
char_u *translate_mapping(char_u *str, int expmap);
void update_tcap(int attr);
long gui_get_color_cmn(char_u *name);
long gui_get_rgb_color_cmn(int r, int g, int b);
void ex_terminal(exarg_T *eap);
void free_terminal(buf_T *buf);
void write_to_term(buf_T *buffer, char_u *msg, channel_T *channel);
int term_job_running(term_T *term);
int term_none_open(term_T *term);
int term_in_normal_mode(void);
void term_enter_job_mode(void);
int send_keys_to_term(term_T *term, int c, int typed);
int terminal_is_active(void);
cursorentry_T *term_get_cursor_shape(long *fg, long *bg);
int term_use_loop(void);
int terminal_loop(int blocking);
void term_job_ended(job_T *job);
void term_channel_closed(channel_T *ch);
int term_update_window(win_T *wp);
int term_is_finished(buf_T *buf);
int term_show_buffer(buf_T *buf);
void term_change_in_curbuf(void);
int term_get_attr(buf_T *buf, linenr_T lnum, int col);
char_u *term_get_status_text(term_T *term);
int set_ref_in_term(int copyID);
void f_term_getaltscreen(typval_T *argvars, typval_T *rettv);
void f_term_getattr(typval_T *argvars, typval_T *rettv);
void f_term_getcursor(typval_T *argvars, typval_T *rettv);
void f_term_getjob(typval_T *argvars, typval_T *rettv);
void f_term_getline(typval_T *argvars, typval_T *rettv);
void f_term_getscrolled(typval_T *argvars, typval_T *rettv);
void f_term_getsize(typval_T *argvars, typval_T *rettv);
void f_term_getstatus(typval_T *argvars, typval_T *rettv);
void f_term_gettitle(typval_T *argvars, typval_T *rettv);
void f_term_gettty(typval_T *argvars, typval_T *rettv);
void f_term_list(typval_T *argvars, typval_T *rettv);
void f_term_scrape(typval_T *argvars, typval_T *rettv);
void f_term_sendkeys(typval_T *argvars, typval_T *rettv);
void f_term_start(typval_T *argvars, typval_T *rettv);
void f_term_wait(typval_T *argvars, typval_T *rettv);
void term_send_eof(channel_T *ch);
int terminal_enabled(void);
void ui_write(char_u *s, int len);
void ui_inchar_undo(char_u *s, int len);
int ui_inchar(char_u *buf, int maxlen, long wtime, int tb_change_cnt);
int ui_char_avail(void);
void ui_delay(long msec, int ignoreinput);
void ui_suspend(void);
void suspend_shell(void);
int ui_get_shellsize(void);
void ui_set_shellsize(int mustset);
void ui_new_shellsize(void);
void ui_breakcheck(void);
void ui_breakcheck_force(int force);
void clip_init(int can_use);
void clip_update_selection(VimClipboard *clip);
void clip_own_selection(VimClipboard *cbd);
void clip_lose_selection(VimClipboard *cbd);
void start_global_changes(void);
int is_clipboard_needs_update(void);
void end_global_changes(void);
void clip_auto_select(void);
int clip_isautosel_star(void);
int clip_isautosel_plus(void);
void clip_modeless(int button, int is_click, int is_drag);
void clip_start_selection(int col, int row, int repeated_click);
void clip_process_selection(int button, int col, int row, int_u repeated_click);
void clip_may_redraw_selection(int row, int col, int len);
void clip_clear_selection(VimClipboard *cbd);
void clip_may_clear_selection(int row1, int row2);
void clip_scroll_selection(int rows);
void clip_copy_modeless_selection(int both);
int clip_gen_own_selection(VimClipboard *cbd);
void clip_gen_lose_selection(VimClipboard *cbd);
void clip_gen_set_selection(VimClipboard *cbd);
void clip_gen_request_selection(VimClipboard *cbd);
int clip_gen_owner_exists(VimClipboard *cbd);
int vim_is_input_buf_full(void);
int vim_is_input_buf_empty(void);
int vim_free_in_input_buf(void);
int vim_used_in_input_buf(void);
char_u *get_input_buf(void);
void set_input_buf(char_u *p);
void add_to_input_buf(char_u *s, int len);
void add_to_input_buf_csi(char_u *str, int len);
void push_raw_key(char_u *s, int len);
void trash_input_buf(void);
int read_from_input_buf(char_u *buf, long maxlen);
void fill_input_buf(int exit_on_error);
void read_error_exit(void);
void ui_cursor_shape_forced(int forced);
void ui_cursor_shape(void);
int check_col(int col);
int check_row(int row);
void open_app_context(void);
void x11_setup_atoms(Display *dpy);
void x11_setup_selection(Widget w);
void clip_x11_request_selection(Widget myShell, Display *dpy, VimClipboard *cbd);
void clip_x11_lose_selection(Widget myShell, VimClipboard *cbd);
int clip_x11_own_selection(Widget myShell, VimClipboard *cbd);
void clip_x11_set_selection(VimClipboard *cbd);
int clip_x11_owner_exists(VimClipboard *cbd);
void yank_cut_buffer0(Display *dpy, VimClipboard *cbd);
int jump_to_mouse(int flags, int *inclusive, int which_button);
int mouse_comp_pos(win_T *win, int *rowp, int *colp, linenr_T *lnump);
win_T *mouse_find_win(int *rowp, int *colp);
int get_fpos_of_mouse(pos_T *mpos);
int vcol2col(win_T *wp, linenr_T lnum, int vcol);
void ui_focus_change(int in_focus);
void im_save_status(long *psave);
int u_save_cursor(void);
int u_save(linenr_T top, linenr_T bot);
int u_savesub(linenr_T lnum);
int u_inssub(linenr_T lnum);
int u_savedel(linenr_T lnum, long nlines);
int undo_allowed(void);
int u_savecommon(linenr_T top, linenr_T bot, linenr_T newbot, int reload);
void u_compute_hash(char_u *hash);
char_u *u_get_undo_file_name(char_u *buf_ffname, int reading);
void u_write_undo(char_u *name, int forceit, buf_T *buf, char_u *hash);
void u_read_undo(char_u *name, char_u *hash, char_u *orig_name);
void u_undo(int count);
void u_redo(int count);
void undo_time(long step, int sec, int file, int absolute);
void u_sync(int force);
void ex_undolist(exarg_T *eap);
void ex_undojoin(exarg_T *eap);
void u_unchanged(buf_T *buf);
void u_find_first_changed(void);
void u_update_save_nr(buf_T *buf);
void u_clearall(buf_T *buf);
void u_saveline(linenr_T lnum);
void u_clearline(void);
void u_undoline(void);
void u_blockfree(buf_T *buf);
int bufIsChanged(buf_T *buf);
int curbufIsChanged(void);
void u_eval_tree(u_header_T *first_uhp, list_T *list);
void func_init(void);
int get_lambda_tv(char_u **arg, typval_T *rettv, int evaluate);
char_u *deref_func_name(char_u *name, int *lenp, partial_T **partialp, int no_autoload);
int get_func_tv(char_u *name, int len, typval_T *rettv, char_u **arg, linenr_T firstline, linenr_T lastline, int *doesrange, int evaluate, partial_T *partial, dict_T *selfdict);
ufunc_T *find_func(char_u *name);
void free_all_functions(void);
int func_call(char_u *name, typval_T *args, partial_T *partial, dict_T *selfdict, typval_T *rettv);
int call_func(char_u *funcname, int len, typval_T *rettv, int argcount_in, typval_T *argvars_in, int (*argv_func)(int, typval_T *, int), linenr_T firstline, linenr_T lastline, int *doesrange, int evaluate, partial_T *partial, dict_T *selfdict_in);
char_u *trans_function_name(char_u **pp, int skip, int flags, funcdict_T *fdp, partial_T **partial);
void ex_function(exarg_T *eap);
int eval_fname_script(char_u *p);
int translated_function_exists(char_u *name);
int function_exists(char_u *name, int no_deref);
char_u *get_expanded_name(char_u *name, int check);
void func_dump_profile(FILE *fd);
void prof_child_enter(proftime_T *tm);
void prof_child_exit(proftime_T *tm);
char_u *get_user_func_name(expand_T *xp, int idx);
void ex_delfunction(exarg_T *eap);
void func_unref(char_u *name);
void func_ptr_unref(ufunc_T *fp);
void func_ref(char_u *name);
void func_ptr_ref(ufunc_T *fp);
void ex_return(exarg_T *eap);
void ex_call(exarg_T *eap);
int do_return(exarg_T *eap, int reanimate, int is_cmd, void *rettv);
void discard_pending_return(void *rettv);
char_u *get_return_cmd(void *rettv);
char_u *get_func_line(int c, void *cookie, int indent);
void func_line_start(void *cookie);
void func_line_exec(void *cookie);
void func_line_end(void *cookie);
int func_has_ended(void *cookie);
int func_has_abort(void *cookie);
dict_T *make_partial(dict_T *selfdict_in, typval_T *rettv);
char_u *func_name(void *cookie);
linenr_T *func_breakpoint(void *cookie);
int *func_dbg_tick(void *cookie);
int func_level(void *cookie);
int current_func_returned(void);
void *save_funccal(void);
void restore_funccal(void *vfc);
int free_unref_funccal(int copyID, int testing);
hashtab_T *get_funccal_local_ht(void);
dictitem_T *get_funccal_local_var(void);
hashtab_T *get_funccal_args_ht(void);
dictitem_T *get_funccal_args_var(void);
void *clear_current_funccal(void);
void restore_current_funccal(void *f);
void list_func_vars(int *first);
dict_T *get_current_funccal_dict(hashtab_T *ht);
hashitem_T *find_hi_in_scoped_ht(char_u *name, hashtab_T **pht);
dictitem_T *find_var_in_scoped_ht(char_u *name, int no_autoload);
int set_ref_in_previous_funccal(int copyID);
int set_ref_in_call_stack(int copyID);
int set_ref_in_functions(int copyID);
int set_ref_in_func_args(int copyID);
int set_ref_in_func(char_u *name, ufunc_T *fp_in, int copyID);
void make_version(void);
int highest_patch(void);
int has_patch(int n);
void ex_version(exarg_T *eap);
void list_version(void);
void maybe_intro_message(void);
void intro_message(int colon);
void ex_intro(exarg_T *eap);
void do_window(int nchar, long Prenum, int xchar);
void get_wincmd_addr_type(char_u *arg, exarg_T *eap);
int win_split(int size, int flags);
int win_split_ins(int size, int flags, win_T *new_wp, int dir);
int win_valid(win_T *win);
int win_valid_any_tab(win_T *win);
int win_count(void);
int make_windows(int count, int vertical);
void win_move_after(win_T *win1, win_T *win2);
void win_equal(win_T *next_curwin, int current, int dir);
void close_windows(buf_T *buf, int keep_curwin);
int one_window(void);
int win_close(win_T *win, int free_buf);
void win_close_othertab(win_T *win, int free_buf, tabpage_T *tp);
void win_free_all(void);
win_T *winframe_remove(win_T *win, int *dirp, tabpage_T *tp);
void close_others(int message, int forceit);
void curwin_init(void);
void win_init_empty(win_T *wp);
int win_alloc_first(void);
void win_alloc_aucmd_win(void);
void win_init_size(void);
void free_tabpage(tabpage_T *tp);
int win_new_tabpage(int after);
int may_open_tabpage(void);
int make_tabpages(int maxcount);
int valid_tabpage(tabpage_T *tpc);
int valid_tabpage_win(tabpage_T *tpc);
void close_tabpage(tabpage_T *tpc);
tabpage_T *find_tabpage(int n);
int tabpage_index(tabpage_T *ftp);
void goto_tabpage(int n);
void goto_tabpage_tp(tabpage_T *tp, int trigger_enter_autocmds, int trigger_leave_autocmds);
void goto_tabpage_win(tabpage_T *tp, win_T *wp);
void tabpage_move(int nr);
void win_goto(win_T *wp);
win_T *win_find_nr(int winnr);
tabpage_T *win_find_tabpage(win_T *win);
void win_enter(win_T *wp, int undo_sync);
win_T *buf_jump_open_win(buf_T *buf);
win_T *buf_jump_open_tab(buf_T *buf);
void win_append(win_T *after, win_T *wp);
void win_remove(win_T *wp, tabpage_T *tp);
int win_alloc_lines(win_T *wp);
void win_free_lsize(win_T *wp);
void shell_new_rows(void);
void shell_new_columns(void);
void win_size_save(garray_T *gap);
void win_size_restore(garray_T *gap);
int win_comp_pos(void);
void win_setheight(int height);
void win_setheight_win(int height, win_T *win);
void win_setwidth(int width);
void win_setwidth_win(int width, win_T *wp);
void win_setminheight(void);
void win_drag_status_line(win_T *dragwin, int offset);
void win_drag_vsep_line(win_T *dragwin, int offset);
void set_fraction(win_T *wp);
void win_new_height(win_T *wp, int height);
void scroll_to_fraction(win_T *wp, int prev_height);
void win_new_width(win_T *wp, int width);
void win_comp_scroll(win_T *wp);
void command_height(void);
void last_status(int morewin);
int tabline_height(void);
char_u *grab_file_name(long count, linenr_T *file_lnum);
char_u *file_name_at_cursor(int options, long count, linenr_T *file_lnum);
char_u *file_name_in_line(char_u *line, int col, int options, long count, char_u *rel_fname, linenr_T *file_lnum);
char_u *find_file_name_in_path(char_u *ptr, int len, int options, long count, char_u *rel_fname);
int path_with_url(char_u *fname);
int vim_isAbsName(char_u *name);
int vim_FullName(char_u *fname, char_u *buf, int len, int force);
int min_rows(void);
int only_one_window(void);
void check_lnums(int do_curwin);
void make_snapshot(int idx);
void restore_snapshot(int idx, int close_curwin);
int switch_win(win_T **save_curwin, tabpage_T **save_curtab, win_T *win, tabpage_T *tp, int no_display);
void restore_win(win_T *save_curwin, tabpage_T *save_curtab, int no_display);
void switch_buffer(bufref_T *save_curbuf, buf_T *buf);
void restore_buffer(bufref_T *save_curbuf);
int win_hasvertsplit(void);
int match_add(win_T *wp, char_u *grp, char_u *pat, int prio, int id, list_T *pos_list, char_u *conceal_char);
int match_delete(win_T *wp, int id, int perr);
void clear_matches(win_T *wp);
matchitem_T *get_match(win_T *wp, int id);
int get_win_number(win_T *wp, win_T *first_win);
int get_tab_number(tabpage_T *tp);
int win_getid(typval_T *argvars);
int win_gotoid(typval_T *argvars);
void win_id2tabwin(typval_T *argvars, list_T *list);
win_T *win_id2wp(typval_T *argvars);
int win_id2win(typval_T *argvars);
void win_findbuf(typval_T *argvars, list_T *list);
void netbeans_parse_messages(void);
int isNetbeansBuffer(buf_T *bufp);
int isNetbeansModified(buf_T *bufp);
void netbeans_end(void);
void ex_nbclose(exarg_T *eap);
void ex_nbkey(exarg_T *eap);
void ex_nbstart(exarg_T *eap);
void netbeans_beval_cb(int *beval, int state);
int netbeans_active(void);
void netbeans_open(char *params, int doabort);
void netbeans_send_disconnect(void);
int set_ref_in_nb_channel(int copyID);
void netbeans_frame_moved(int new_x, int new_y);
void netbeans_file_activated(buf_T *bufp);
void netbeans_file_opened(buf_T *bufp);
void netbeans_file_killed(buf_T *bufp);
void netbeans_inserted(buf_T *bufp, linenr_T linenr, colnr_T col, char_u *txt, int newlen);
void netbeans_removed(buf_T *bufp, linenr_T linenr, colnr_T col, long len);
void netbeans_unmodified(buf_T *bufp);
void netbeans_button_release(int button);
int netbeans_keycommand(int key);
void netbeans_save_buffer(buf_T *bufp);
void netbeans_deleted_all_lines(buf_T *bufp);
int netbeans_is_guarded(linenr_T top, linenr_T bot);
void netbeans_draw_multisign_indicator(int row);
void netbeans_gutter_click(linenr_T lnum);
void ch_logfile(char_u *fname, char_u *opt);
int ch_log_active(void);
void ch_log(channel_T *ch, const char *fmt, ...);
channel_T *add_channel(void);
int has_any_channel(void);
int channel_unref(channel_T *channel);
int free_unused_channels_contents(int copyID, int mask);
void free_unused_channels(int copyID, int mask);
void channel_gui_register_all(void);
channel_T *channel_open(char *hostname, int port_in, int waittime, void (*nb_close_cb)(void));
channel_T *channel_open_func(typval_T *argvars);
void channel_set_pipes(channel_T *channel, sock_T in, sock_T out, sock_T err);
void channel_set_job(channel_T *channel, job_T *job, jobopt_T *options);
void channel_set_options(channel_T *channel, jobopt_T *opt);
void channel_set_req_callback(channel_T *channel, ch_part_T part, char_u *callback, partial_T *partial, int id);
void channel_buffer_free(buf_T *buf);
void channel_write_any_lines(void);
void channel_write_new_lines(buf_T *buf);
readq_T *channel_peek(channel_T *channel, ch_part_T part);
char_u *channel_first_nl(readq_T *node);
char_u *channel_get(channel_T *channel, ch_part_T part);
void channel_consume(channel_T *channel, ch_part_T part, int len);
int channel_collapse(channel_T *channel, ch_part_T part, int want_nl);
int channel_can_write_to(channel_T *channel);
int channel_is_open(channel_T *channel);
int channel_has_readahead(channel_T *channel, ch_part_T part);
char *channel_status(channel_T *channel, int req_part);
void channel_info(channel_T *channel, dict_T *dict);
void channel_close(channel_T *channel, int invoke_close_cb);
void channel_close_in(channel_T *channel);
void channel_clear(channel_T *channel);
void channel_free_all(void);
char_u *channel_read_block(channel_T *channel, ch_part_T part, int timeout);
void common_channel_read(typval_T *argvars, typval_T *rettv, int raw);
channel_T *channel_fd2channel(sock_T fd, ch_part_T *partp);
void channel_handle_events(int only_keep_open);
int channel_any_keep_open(void);
void channel_set_nonblock(channel_T *channel, ch_part_T part);
int channel_send(channel_T *channel, ch_part_T part, char_u *buf_arg, int len_arg, char *fun);
void ch_expr_common(typval_T *argvars, typval_T *rettv, int eval);
void ch_raw_common(typval_T *argvars, typval_T *rettv, int eval);
int channel_poll_setup(int nfd_in, void *fds_in, int *towait);
int channel_poll_check(int ret_in, void *fds_in);
int channel_select_setup(int maxfd_in, void *rfds_in, void *wfds_in, struct timeval *tv, struct timeval **tvp);
int channel_select_check(int ret_in, void *rfds_in, void *wfds_in);
int channel_parse_messages(void);
int channel_any_readahead(void);
int set_ref_in_channel(int copyID);
ch_part_T channel_part_send(channel_T *channel);
ch_part_T channel_part_read(channel_T *channel);
ch_mode_T channel_get_mode(channel_T *channel, ch_part_T part);
int channel_get_timeout(channel_T *channel, ch_part_T part);
void clear_job_options(jobopt_T *opt);
void free_job_options(jobopt_T *opt);
int get_job_options(typval_T *tv, jobopt_T *opt, int supported, int supported2);
channel_T *get_channel_arg(typval_T *tv, int check_open, int reading, ch_part_T part);
void job_free_all(void);
int win32_build_cmd(list_T *l, garray_T *gap);
void job_cleanup(job_T *job);
int set_ref_in_job(int copyID);
void job_unref(job_T *job);
int free_unused_jobs_contents(int copyID, int mask);
void free_unused_jobs(int copyID, int mask);
job_T *job_alloc(void);
void job_set_options(job_T *job, jobopt_T *opt);
void job_stop_on_exit(void);
int has_pending_job(void);
void job_check_ended(void);
job_T *job_start(typval_T *argvars, jobopt_T *opt_arg);
char *job_status(job_T *job);
void job_info(job_T *job, dict_T *dict);
int job_stop(job_T *job, typval_T *argvars, char *type);
int SetupSlavePTY(int fd);
int OpenPTY(char **ttyn);
int serverRegisterName(Display *dpy, char_u *name);
void serverChangeRegisteredWindow(Display *dpy, Window newwin);
int serverSendToVim(Display *dpy, char_u *name, char_u *cmd, char_u **result, Window *server, int asExpr, int timeout, int localLoop, int silent);
char_u *serverGetVimNames(Display *dpy);
Window serverStrToWin(char_u *str);
int serverSendReply(char_u *name, char_u *str);
int serverReadReply(Display *dpy, Window win, char_u **str, int localLoop, int timeout);
int serverPeekReply(Display *dpy, Window win, char_u **str);
void serverEventProc(Display *dpy, XEvent *eventPtr, int immediate);
void server_parse_messages(void);
int server_waiting(void);
extern long Rows
       ;
extern long Columns ;
extern schar_T *ScreenLines ;
extern sattr_T *ScreenAttrs ;
extern unsigned *LineOffset ;
extern char_u *LineWraps ;
extern u8char_T *ScreenLinesUC ;
extern u8char_T *ScreenLinesC[6];
extern int Screen_mco ;
extern schar_T *ScreenLines2 ;
extern short *TabPageIdxs ;
extern int screen_Rows ;
extern int screen_Columns ;
extern int mod_mask ;
extern int cmdline_row;
extern int redraw_cmdline ;
extern int clear_cmdline ;
extern int mode_displayed ;
extern int no_win_do_lines_ins ;
extern int cmdline_star ;
extern int exec_from_reg ;
extern int screen_cleared ;
extern colnr_T dollar_vcol ;
extern int compl_length ;
extern int compl_interrupted ;
extern int compl_cont_status ;
extern int cmdmsg_rl ;
extern int msg_col;
extern int msg_row;
extern int msg_scrolled;
extern int msg_scrolled_ign ;
extern char_u *keep_msg ;
extern int keep_msg_attr ;
extern int keep_msg_more ;
extern int need_fileinfo ;
extern int msg_scroll ;
extern int msg_didout ;
extern int msg_didany ;
extern int msg_nowait ;
extern int emsg_off ;
extern int info_message ;
extern int msg_hist_off ;
extern int need_clr_eos ;
extern int emsg_skip ;
extern int emsg_severe ;
extern int did_endif ;
extern dict_T vimvardict;
extern dict_T globvardict;
extern int did_emsg;
extern int did_uncaught_emsg;
extern int did_emsg_syntax;
extern int called_emsg;
extern int ex_exitval ;
extern int emsg_on_display ;
extern int rc_did_emsg ;
extern int no_wait_return ;
extern int need_wait_return ;
extern int did_wait_return ;
extern int need_maketitle ;
extern int quit_more ;
extern int newline_on_exit ;
extern int intr_char ;
extern int x_no_connect ;
extern int x_force_connect ;
extern int ex_keep_indent ;
extern int vgetc_busy ;
extern int didset_vim ;
extern int didset_vimruntime ;
extern int lines_left ;
extern int msg_no_more ;
extern char_u *sourcing_name ;
extern linenr_T sourcing_lnum ;
extern int ex_nesting_level ;
extern int debug_break_level ;
extern int debug_did_msg ;
extern int debug_tick ;
extern int debug_backtrace_level ;
extern int do_profiling ;
extern except_T *current_exception;
extern int did_throw ;
extern int need_rethrow ;
extern int check_cstack ;
extern int trylevel ;
extern int force_abort ;
extern struct msglist **msg_list ;
extern int suppress_errthrow ;
extern except_T *caught_stack ;
extern int may_garbage_collect ;
extern int want_garbage_collect ;
extern int garbage_collect_at_exit ;
extern scid_T current_SID ;
extern int did_source_packages ;
extern char_u hash_removed;
extern int scroll_region ;
extern int t_colors ;
extern int highlight_match ;
extern linenr_T search_match_lines;
extern colnr_T search_match_endcol;
extern int no_smartcase ;
extern int need_check_timestamps ;
extern int did_check_timestamps ;
extern int no_check_timestamps ;
extern int highlight_attr[HLF_COUNT];
extern int highlight_user[9];
extern int highlight_stlnc[9];
extern int highlight_stlterm[9];
extern int highlight_stltermnc[9];
extern int cterm_normal_fg_color ;
extern int cterm_normal_fg_bold ;
extern int cterm_normal_bg_color ;
extern long cterm_normal_fg_gui_color ;
extern long cterm_normal_bg_gui_color ;
extern int is_mac_terminal ;
extern int autocmd_busy ;
extern int autocmd_no_enter ;
extern int autocmd_no_leave ;
extern int modified_was_set;
extern int did_filetype ;
extern int keep_filetype ;
extern bufref_T au_new_curbuf ;
extern buf_T *au_pending_free_buf ;
extern win_T *au_pending_free_win ;
extern int mouse_row;
extern int mouse_col;
extern int mouse_past_bottom ;
extern int mouse_past_eol ;
extern int mouse_dragging ;
extern int WantQueryMouse ;
extern int diff_context ;
extern int diff_foldcolumn ;
extern int diff_need_scrollbind ;
extern vimmenu_T *root_menu ;
extern int sys_menu ;
extern int updating_screen ;
extern VimClipboard clip_star;
extern VimClipboard clip_plus;
extern int clip_unnamed ;
extern int clip_autoselect_star ;
extern int clip_autoselect_plus ;
extern int clip_autoselectml ;
extern int clip_html ;
extern regprog_T *clip_exclude_prog ;
extern int clip_unnamed_saved ;
extern win_T *firstwin;
extern win_T *lastwin;
extern win_T *prevwin ;
extern win_T *curwin;
extern win_T *aucmd_win;
extern int aucmd_win_used ;
extern frame_T *topframe;
extern tabpage_T *first_tabpage;
extern tabpage_T *curtab;
extern int redraw_tabline ;
extern buf_T *firstbuf ;
extern buf_T *lastbuf ;
extern buf_T *curbuf ;
extern int mf_dont_release ;
extern alist_T global_alist;
extern int max_alist_id ;
extern int arg_had_last ;
extern int ru_col;
extern int ru_wid;
extern int sc_col;
extern char_u *vim_tempdir ;
extern int starting ;
extern int exiting ;
extern int really_exiting ;
extern int stdout_isatty ;
extern int test_autochdir ;
extern volatile int full_screen ;
extern int restricted ;
extern int secure ;
extern int textlock ;
extern int curbuf_lock ;
extern int allbuf_lock ;
extern int sandbox ;
extern int silent_mode ;
extern pos_T VIsual;
extern int VIsual_active ;
extern int VIsual_select ;
extern int VIsual_reselect;
extern int VIsual_mode ;
extern int redo_VIsual_busy ;
extern pos_T where_paste_started;
extern int did_ai ;
extern colnr_T ai_col ;
extern int end_comment_pending ;
extern int did_syncbind ;
extern int did_si ;
extern int can_si ;
extern int can_si_back ;
extern pos_T saved_cursor
 ;
extern pos_T Insstart;
extern pos_T Insstart_orig;
extern int orig_line_count ;
extern int vr_lines_changed ;
extern jmp_buf x_jump_env;
extern jmp_buf lc_jump_env;
extern volatile int lc_signal;
extern volatile int lc_active ;
extern int enc_dbcs ;
extern int enc_unicode ;
extern int enc_utf8 ;
extern int enc_latin1like ;
extern int has_mbyte ;
extern char mb_bytelen_tab[256];
extern vimconv_T input_conv;
extern vimconv_T output_conv;
extern int (*mb_ptr2len)(char_u *p) ;
extern int (*mb_ptr2len_len)(char_u *p, int size) ;
extern int (*mb_char2len)(int c) ;
extern int (*mb_char2bytes)(int c, char_u *buf) ;
extern int (*mb_ptr2cells)(char_u *p) ;
extern int (*mb_ptr2cells_len)(char_u *p, int size) ;
extern int (*mb_char2cells)(int c) ;
extern int (*mb_off2cells)(unsigned off, unsigned max_off) ;
extern int (*mb_ptr2char)(char_u *p) ;
extern int (*mb_head_off)(char_u *base, char_u *p) ;
extern XIC xic ;
extern int State ;
extern int finish_op ;
extern long opcount ;
extern int exmode_active ;
extern int ex_no_reprint ;
extern int Recording ;
extern int Exec_reg ;
extern int no_mapping ;
extern int no_zero_mapping ;
extern int allow_keys ;
extern int no_u_sync ;
extern int u_sync_once ;
extern int restart_edit ;
extern int arrow_used;
extern int ins_at_eol ;
extern char_u *edit_submode ;
extern char_u *edit_submode_pre ;
extern char_u *edit_submode_extra ;
extern hlf_T edit_submode_highl;
extern int ctrl_x_mode ;
extern int no_abbr ;
extern int mapped_ctrl_c ;
extern int ctrl_c_interrupts ;
extern cmdmod_T cmdmod;
extern int msg_silent ;
extern int emsg_silent ;
extern int emsg_noredir ;
extern int cmd_silent ;
extern int swap_exists_action ;
extern int swap_exists_did_quit ;
extern char_u *IObuff;
extern char_u *NameBuff;
extern char_u msg_buf[480];
extern int RedrawingDisabled ;
extern int readonlymode ;
extern int recoverymode ;
extern typebuf_T typebuf
      ;
extern int ex_normal_busy ;
extern int ex_normal_lock ;
extern int ignore_script ;
extern int stop_insert_mode;
extern int KeyTyped;
extern int KeyStuffed;
extern int vgetc_im_active;
extern int maptick ;
extern int must_redraw ;
extern int skip_redraw ;
extern int do_redraw ;
extern int need_highlight_changed ;
extern FILE *scriptin[15];
extern int curscript ;
extern FILE *scriptout ;
extern int read_cmd_fd ;
extern volatile int got_int ;
extern int termcap_active ;
extern int cur_tmode ;
extern int bangredo ;
extern int searchcmdlen;
extern int reg_do_extmatch ;
extern reg_extmatch_T *re_extmatch_in ;
extern reg_extmatch_T *re_extmatch_out ;
extern int did_outofmem_msg ;
extern int did_swapwrite_msg ;
extern int undo_off ;
extern int global_busy ;
extern int listcmd_busy ;
extern int need_start_insertmode ;
extern char_u *last_cmdline ;
extern char_u *repeat_cmdline ;
extern char_u *new_last_cmdline ;
extern char_u *autocmd_fname ;
extern int autocmd_fname_full;
extern int autocmd_bufnr ;
extern char_u *autocmd_match ;
extern int did_cursorhold ;
extern pos_T last_cursormoved
   ;
extern varnumber_T last_changedtick ;
extern buf_T *last_changedtick_buf ;
extern int postponed_split ;
extern int postponed_split_flags ;
extern int postponed_split_tab ;
extern int g_do_tagpreview ;
extern int replace_offset ;
extern char_u *escape_chars ;
extern int keep_help_flag ;
extern char_u *empty_option ;
extern int redir_off ;
extern FILE *redir_fd ;
extern int redir_reg ;
extern int redir_vname ;
extern int redir_execute ;
extern char_u langmap_mapchar[256];
extern int save_p_ls ;
extern int save_p_wmh ;
extern int wild_menu_showing ;
extern char breakat_flags[256];
extern char *Version;
extern char *longVersion;
extern char_u *default_vim_dir;
extern char_u *default_vimruntime_dir;
extern char_u *all_cflags;
extern char_u *all_lflags;
extern char_u *compiled_user;
extern char_u *compiled_sys;
extern char_u *globaldir ;
extern int lcs_eol ;
extern int lcs_ext ;
extern int lcs_prec ;
extern int lcs_nbsp ;
extern int lcs_space ;
extern int lcs_tab1 ;
extern int lcs_tab2 ;
extern int lcs_trail ;
extern int lcs_conceal ;
extern int fill_stl ;
extern int fill_stlnc ;
extern int fill_vert ;
extern int fill_fold ;
extern int fill_diff ;
extern int disable_fold_update ;
extern int km_stopsel ;
extern int km_startsel ;
extern int cedit_key ;
extern int cmdwin_type ;
extern int cmdwin_result ;
extern char_u no_lines_msg[] ;
extern long sub_nsubs;
extern linenr_T sub_nlines;
extern char_u wim_flags[4];
extern int stl_syntax ;
extern int no_hlsearch ;
extern cursorentry_T shape_table[17];
extern option_table_T printer_opts[14]
;
extern linenr_T printer_page_num;
extern char *xterm_display ;
extern Display *xterm_dpy ;
extern XtAppContext app_context ;
extern int typebuf_was_filled ;
extern char_u *serverName ;
extern Window commWindow ;
extern Window clientWindow ;
extern Atom commProperty ;
extern char_u *serverDelayedStartName ;
extern int term_is_xterm ;
extern int virtual_op ;
extern disptick_T display_tick ;
extern linenr_T spell_redraw_lnum ;
extern int need_cursor_line_redraw ;
extern char *netbeansArg ;
extern int netbeansFireChanges ;
extern int netbeansForcedQuit ;
extern int netbeansReadFile ;
extern int netbeansSuppressNoLines ;
extern char_u e_abort[] ;
extern char_u e_argreq[] ;
extern char_u e_backslash[] ;
extern char_u e_cmdwin[] ;
extern char_u e_curdir[] ;
extern char_u e_endif[] ;
extern char_u e_endtry[] ;
extern char_u e_endwhile[] ;
extern char_u e_endfor[] ;
extern char_u e_while[] ;
extern char_u e_for[] ;
extern char_u e_exists[] ;
extern char_u e_failed[] ;
extern char_u e_internal[] ;
extern char_u e_intern2[] ;
extern char_u e_interr[] ;
extern char_u e_invaddr[] ;
extern char_u e_invarg[] ;
extern char_u e_invarg2[] ;
extern char_u e_invexpr2[] ;
extern char_u e_invrange[] ;
extern char_u e_invcmd[] ;
extern char_u e_isadir2[] ;
extern char_u e_libcall[] ;
extern char_u e_markinval[] ;
extern char_u e_marknotset[] ;
extern char_u e_modifiable[] ;
extern char_u e_nesting[] ;
extern char_u e_noalt[] ;
extern char_u e_noabbr[] ;
extern char_u e_nobang[] ;
extern char_u e_nogvim[] ;
extern char_u e_nogroup[] ;
extern char_u e_noinstext[] ;
extern char_u e_nolastcmd[] ;
extern char_u e_nomap[] ;
extern char_u e_nomatch[] ;
extern char_u e_nomatch2[] ;
extern char_u e_noname[] ;
extern char_u e_nopresub[] ;
extern char_u e_noprev[] ;
extern char_u e_noprevre[] ;
extern char_u e_norange[] ;
extern char_u e_noroom[] ;
extern char_u e_noserver[] ;
extern char_u e_notcreate[] ;
extern char_u e_notmp[] ;
extern char_u e_notopen[] ;
extern char_u e_notread[] ;
extern char_u e_null[] ;
extern char_u e_number_exp[] ;
extern char_u e_openerrf[] ;
extern char_u e_outofmem[] ;
extern char_u e_patnotf[] ;
extern char_u e_patnotf2[] ;
extern char_u e_positive[] ;
extern char_u e_prev_dir[] ;
extern char_u e_quickfix[] ;
extern char_u e_loclist[] ;
extern char_u e_re_damg[] ;
extern char_u e_re_corr[] ;
extern char_u e_readonly[] ;
extern char_u e_readonlyvar[] ;
extern char_u e_readonlysbx[] ;
extern char_u e_emptykey[] ;
extern char_u e_dictreq[] ;
extern char_u e_listidx[] ;
extern char_u e_toomanyarg[] ;
extern char_u e_dictkey[] ;
extern char_u e_listreq[] ;
extern char_u e_listdictarg[] ;
extern char_u e_readerrf[] ;
extern char_u e_sandbox[] ;
extern char_u e_secure[] ;
extern char_u e_screenmode[] ;
extern char_u e_scroll[] ;
extern char_u e_shellempty[] ;
extern char_u e_swapclose[] ;
extern char_u e_tagstack[] ;
extern char_u e_toocompl[] ;
extern char_u e_longname[] ;
extern char_u e_toomsbra[] ;
extern char_u e_toomany[] ;
extern char_u e_trailing[] ;
extern char_u e_umark[] ;
extern char_u e_wildexpand[] ;
extern char_u e_winheight[] ;
extern char_u e_winwidth[] ;
extern char_u e_write[] ;
extern char_u e_zerocount[] ;
extern char_u e_usingsid[] ;
extern char_u e_invexprmsg[] ;
extern char_u e_guarded[] ;
extern char_u e_nbreadonly[] ;
extern char_u e_maxmempat[] ;
extern char_u e_emptybuf[] ;
extern char_u e_nobufnr[] ;
extern char_u e_invalpat[] ;
extern char_u e_bufloaded[] ;
extern char_u e_notset[] ;
extern char_u e_dirnotf[] ;
extern char top_bot_msg[] ;
extern char bot_top_msg[] ;
extern char need_key_msg[] ;
extern int xsmp_icefd ;
extern time_T starttime;
extern FILE *time_fd ;
extern int ignored;
extern char *ignoredp;
extern alloc_id_T alloc_fail_id ;
extern int alloc_fail_countdown ;
extern int alloc_fail_repeat ;
extern int disable_char_avail_for_testing ;
extern int disable_redraw_for_testing ;
extern int in_free_unref_items ;
extern int did_add_timer ;
extern int timer_busy ;
extern time_T time_for_testing ;
extern int did_echo_string_emsg ;
extern int *eval_lavars_used ;
extern char_u farsi_text_1[]
       ;
extern char_u farsi_text_2[]
       ;
extern char_u farsi_text_3[]
      ;
extern char_u farsi_text_5[]
      ;
    long elapsed(struct timeval *start_tv);
static int json_encode_item(garray_T *gap, typval_T *val, int copyID, int options);
static int json_decode_item(js_read_T *reader, typval_T *res, int options);
    static int
json_encode_gap(garray_T *gap, typval_T *val, int options)
{
    if (json_encode_item(gap, val, get_copyID(), options) == 0)
    {
 ga_clear(gap);
 gap->ga_data = vim_strsave((char_u *)"");
 return 0;
    }
    return 1;
}
    char_u *
json_encode(typval_T *val, int options)
{
    garray_T ga;
    ga_init2(&ga, 1, 4000);
    json_encode_gap(&ga, val, options);
    return ga.ga_data;
}
    char_u *
json_encode_nr_expr(int nr, typval_T *val, int options)
{
    typval_T listtv;
    typval_T nrtv;
    garray_T ga;
    nrtv.v_type = VAR_NUMBER;
    nrtv.vval.v_number = nr;
    if (rettv_list_alloc(&listtv) == 0)
 return ((void *)0);
    if (list_append_tv(listtv.vval.v_list, &nrtv) == 0
     || list_append_tv(listtv.vval.v_list, val) == 0)
    {
 list_unref(listtv.vval.v_list);
 return ((void *)0);
    }
    ga_init2(&ga, 1, 4000);
    if (json_encode_gap(&ga, &listtv, options) == 1 && (options & 4))
 ga_append(&ga, '\n');
    list_unref(listtv.vval.v_list);
    return ga.ga_data;
}
    static void
write_string(garray_T *gap, char_u *str)
{
    char_u *res = str;
    char_u numbuf[65];
    if (res == ((void *)0))
 ga_concat(gap, (char_u *)"null");
    else
    {
 vimconv_T conv;
 char_u *converted = ((void *)0);
 if (!enc_utf8)
 {
     conv.vc_type = 0;
     convert_setup(&conv, p_enc, (char_u*)"utf-8");
     if (conv.vc_type != 0)
  converted = res = string_convert(&conv, res, ((void *)0));
     convert_setup(&conv, ((void *)0), ((void *)0));
 }
 ga_append(gap, '"');
 while (*res != '\000')
 {
     int c;
     c = utf_ptr2char(res);
     switch (c)
     {
  case 0x08:
      ga_append(gap, '\\'); ga_append(gap, 'b'); break;
  case 0x09:
      ga_append(gap, '\\'); ga_append(gap, 't'); break;
  case 0x0a:
      ga_append(gap, '\\'); ga_append(gap, 'n'); break;
  case 0x0c:
      ga_append(gap, '\\'); ga_append(gap, 'f'); break;
  case 0x0d:
      ga_append(gap, '\\'); ga_append(gap, 'r'); break;
  case 0x22:
  case 0x5c:
      ga_append(gap, '\\');
      ga_append(gap, c);
      break;
  default:
      if (c >= 0x20)
      {
   numbuf[utf_char2bytes(c, numbuf)] = '\000';
   ga_concat(gap, numbuf);
      }
      else
      {
   vim_snprintf((char *)numbuf, 65,
        "\\u%04lx", (long)c);
   ga_concat(gap, numbuf);
      }
     }
     res += utf_ptr2len(res);
 }
 ga_append(gap, '"');
 vim_free(converted);
    }
}
static int
is_simple_key(char_u *key)
{
    char_u *p;
    if (!(((unsigned)(*key) - 'A' < 26) || ((unsigned)(*key) - 'a' < 26)))
 return 0;
    for (p = key + 1; *p != '\000'; ++p)
 if (!(((unsigned)(*p) - 'A' < 26) || ((unsigned)(*p) - 'a' < 26)) && *p != '_' && !vim_isdigit(*p))
     return 0;
    return 1;
}
    static int
json_encode_item(garray_T *gap, typval_T *val, int copyID, int options)
{
    char_u numbuf[65];
    char_u *res;
    list_T *l;
    dict_T *d;
    switch (val->v_type)
    {
 case VAR_SPECIAL:
     switch (val->vval.v_number)
     {
  case 0L: ga_concat(gap, (char_u *)"false"); break;
  case 1L: ga_concat(gap, (char_u *)"true"); break;
  case 2L: if ((options & 1) != 0
          && (options & 2) == 0)
        break;
  case 3L: ga_concat(gap, (char_u *)"null"); break;
     }
     break;
 case VAR_NUMBER:
     vim_snprintf((char *)numbuf, 65, "%lld",
          val->vval.v_number);
     ga_concat(gap, numbuf);
     break;
 case VAR_STRING:
     res = val->vval.v_string;
     write_string(gap, res);
     break;
 case VAR_FUNC:
 case VAR_PARTIAL:
 case VAR_JOB:
 case VAR_CHANNEL:
     emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
     return 0;
 case VAR_LIST:
     l = val->vval.v_list;
     if (l == ((void *)0))
  ga_concat(gap, (char_u *)"null");
     else
     {
  if (l->lv_copyID == copyID)
      ga_concat(gap, (char_u *)"[]");
  else
  {
      listitem_T *li;
      l->lv_copyID = copyID;
      ga_append(gap, '[');
      for (li = l->lv_first; li != ((void *)0) && !got_int; )
      {
   if (json_encode_item(gap, &li->li_tv, copyID,
         options & 1) == 0)
       return 0;
   if ((options & 1)
    && li->li_next == ((void *)0)
    && li->li_tv.v_type == VAR_SPECIAL
    && li->li_tv.vval.v_number == 2L)
       ga_append(gap, ',');
   li = li->li_next;
   if (li != ((void *)0))
       ga_append(gap, ',');
      }
      ga_append(gap, ']');
      l->lv_copyID = 0;
  }
     }
     break;
 case VAR_DICT:
     d = val->vval.v_dict;
     if (d == ((void *)0))
  ga_concat(gap, (char_u *)"null");
     else
     {
  if (d->dv_copyID == copyID)
      ga_concat(gap, (char_u *)"{}");
  else
  {
      int first = 1;
      int todo = (int)d->dv_hashtab.ht_used;
      hashitem_T *hi;
      d->dv_copyID = copyID;
      ga_append(gap, '{');
      for (hi = d->dv_hashtab.ht_array; todo > 0 && !got_int;
          ++hi)
   if (!((hi)->hi_key == ((void *)0) || (hi)->hi_key == &hash_removed))
   {
       --todo;
       if (first)
    first = 0;
       else
    ga_append(gap, ',');
       if ((options & 1)
       && is_simple_key(hi->hi_key))
    ga_concat(gap, hi->hi_key);
       else
    write_string(gap, hi->hi_key);
       ga_append(gap, ':');
       if (json_encode_item(gap, &dict_lookup(hi)->di_tv,
          copyID, options | 2) == 0)
    return 0;
   }
      ga_append(gap, '}');
      d->dv_copyID = 0;
  }
     }
     break;
 case VAR_FLOAT:
     if ((sizeof (val->vval.v_float) == sizeof (float) ? __isnanf (val->vval.v_float) : sizeof (val->vval.v_float) == sizeof (double) ? __isnan (val->vval.v_float) : __isnanl (val->vval.v_float)))
  ga_concat(gap, (char_u *)"NaN");
     else if ((sizeof (val->vval.v_float) == sizeof (float) ? __isinff (val->vval.v_float) : sizeof (val->vval.v_float) == sizeof (double) ? __isinf (val->vval.v_float) : __isinfl (val->vval.v_float)))
  ga_concat(gap, (char_u *)"Infinity");
     else
     {
  vim_snprintf((char *)numbuf, 65, "%g",
          val->vval.v_float);
  ga_concat(gap, numbuf);
     }
     break;
 case VAR_UNKNOWN:
     internal_error("json_encode_item()");
     return 0;
    }
    return 1;
}
    static void
fill_numbuflen(js_read_T *reader)
{
    if (reader->js_fill != ((void *)0) && (int)(reader->js_end - reader->js_buf)
      - reader->js_used < 65)
    {
 if (reader->js_fill(reader))
     reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
    }
}
    static void
json_skip_white(js_read_T *reader)
{
    int c;
    for (;;)
    {
 c = reader->js_buf[reader->js_used];
 if (reader->js_fill != ((void *)0) && c == '\000')
 {
     if (reader->js_fill(reader))
     {
  reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
  continue;
     }
 }
 if (c == '\000' || c > ' ')
     break;
 ++reader->js_used;
    }
    fill_numbuflen(reader);
}
    static int
json_decode_string(js_read_T *reader, typval_T *res, int quote)
{
    garray_T ga;
    int len;
    char_u *p;
    int c;
    varnumber_T nr;
    if (res != ((void *)0))
 ga_init2(&ga, 1, 200);
    p = reader->js_buf + reader->js_used + 1;
    while (*p != quote)
    {
 if (*p == '\000' || p[1] == '\000'
  || utf_ptr2len(p) < utf_byte2len(*p)
  )
 {
     if (reader->js_fill == ((void *)0))
  break;
     len = (int)(reader->js_end - p);
     reader->js_used = (int)(p - reader->js_buf);
     if (!reader->js_fill(reader))
  break;
     p = reader->js_buf + reader->js_used;
     reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
     continue;
 }
 if (*p == '\\')
 {
     c = -1;
     switch (p[1])
     {
  case '\\': c = '\\'; break;
  case '"': c = '"'; break;
  case 'b': c = '\010'; break;
  case 't': c = '\011'; break;
  case 'n': c = '\012'; break;
  case 'f': c = '\014'; break;
  case 'r': c = '\015'; break;
  case 'u':
      if (reader->js_fill != ((void *)0)
         && (int)(reader->js_end - p) < 65)
      {
   reader->js_used = (int)(p - reader->js_buf);
   if (reader->js_fill(reader))
   {
       p = reader->js_buf + reader->js_used;
       reader->js_end = reader->js_buf
           + strlen((char *)(reader->js_buf));
   }
      }
      nr = 0;
      len = 0;
      vim_str2nr(p + 2, ((void *)0), &len,
         4 + 8, &nr, ((void *)0), 4);
      p += len + 2;
      if (0xd800 <= nr && nr <= 0xdfff
       && (int)(reader->js_end - p) >= 6
       && *p == '\\' && *(p+1) == 'u')
      {
   varnumber_T nr2 = 0;
   len = 0;
   vim_str2nr(p + 2, ((void *)0), &len,
         4 + 8, &nr2, ((void *)0), 4);
   if (0xdc00 <= nr2 && nr2 <= 0xdfff)
   {
       p += len + 2;
       nr = (((nr - 0xd800) << 10) |
    ((nr2 - 0xdc00) & 0x3ff)) + 0x10000;
   }
      }
      if (res != ((void *)0))
      {
   char_u buf[65];
   buf[utf_char2bytes((int)nr, buf)] = '\000';
   ga_concat(&ga, buf);
      }
      break;
  default:
      ++p;
      continue;
     }
     if (c > 0)
     {
  p += 2;
  if (res != ((void *)0))
      ga_append(&ga, c);
     }
 }
 else
 {
     len = utf_ptr2len(p);
     if (res != ((void *)0))
     {
  if (ga_grow(&ga, len) == 0)
  {
      ga_clear(&ga);
      return 0;
  }
  memmove((char *)((char *)ga.ga_data + ga.ga_len), (char *)(p), (size_t)len);
  ga.ga_len += len;
     }
     p += len;
 }
    }
    reader->js_used = (int)(p - reader->js_buf);
    if (*p == quote)
    {
 ++reader->js_used;
 if (res != ((void *)0))
 {
     ga_append(&ga, '\000');
     res->v_type = VAR_STRING;
     if (!enc_utf8)
     {
  vimconv_T conv;
  conv.vc_type = 0;
  convert_setup(&conv, (char_u*)"utf-8", p_enc);
  if (conv.vc_type != 0)
  {
      res->vval.v_string =
          string_convert(&conv, ga.ga_data, ((void *)0));
      vim_free(ga.ga_data);
  }
  convert_setup(&conv, ((void *)0), ((void *)0));
     }
     else
  res->vval.v_string = ga.ga_data;
 }
 return 1;
    }
    if (res != ((void *)0))
    {
 res->v_type = VAR_SPECIAL;
 res->vval.v_number = 2L;
 ga_clear(&ga);
    }
    return 2;
}
typedef enum {
    JSON_ARRAY,
    JSON_OBJECT_KEY,
    JSON_OBJECT
} json_decode_T;
typedef struct {
    json_decode_T jd_type;
    typval_T jd_tv;
    typval_T jd_key_tv;
    char_u *jd_key;
} json_dec_item_T;
    static int
json_decode_item(js_read_T *reader, typval_T *res, int options)
{
    char_u *p;
    int len;
    int retval;
    garray_T stack;
    typval_T item;
    typval_T *cur_item;
    json_dec_item_T *top_item;
    char_u key_buf[65];
    ga_init2(&stack, sizeof(json_dec_item_T), 100);
    cur_item = res;
    init_tv(&item);
    if (res != ((void *)0))
    init_tv(res);
    fill_numbuflen(reader);
    p = reader->js_buf + reader->js_used;
    for (;;)
    {
 top_item = ((void *)0);
 if (stack.ga_len > 0)
 {
     top_item = ((json_dec_item_T *)stack.ga_data) + stack.ga_len - 1;
     json_skip_white(reader);
     p = reader->js_buf + reader->js_used;
     if (*p == '\000')
     {
  retval = 2;
  if (top_item->jd_type == JSON_OBJECT)
      clear_tv(&top_item->jd_key_tv);
  goto theend;
     }
     if (top_item->jd_type == JSON_OBJECT_KEY
         || top_item->jd_type == JSON_ARRAY)
     {
  if (*p == (top_item->jd_type == JSON_ARRAY ? ']' : '}'))
  {
      ++reader->js_used;
      --stack.ga_len;
      if (stack.ga_len == 0)
      {
   retval = 1;
   goto theend;
      }
      if (cur_item != ((void *)0))
   cur_item = &top_item->jd_tv;
      goto item_end;
  }
     }
 }
 if (top_item != ((void *)0) && top_item->jd_type == JSON_OBJECT_KEY
  && (options & 1)
  && reader->js_buf[reader->js_used] != '"'
  && reader->js_buf[reader->js_used] != '\'')
 {
     char_u *key;
     key = p = reader->js_buf + reader->js_used;
     while (*p != '\000' && *p != ':' && *p > ' ')
  ++p;
     if (cur_item != ((void *)0))
     {
  cur_item->v_type = VAR_STRING;
  cur_item->vval.v_string = vim_strnsave(key, (int)(p - key));
  top_item->jd_key = cur_item->vval.v_string;
     }
     reader->js_used += (int)(p - key);
 }
 else
 {
     switch (*p)
     {
  case '[':
      if (ga_grow(&stack, 1) == 0)
      {
   retval = 0;
   break;
      }
      if (cur_item != ((void *)0) && rettv_list_alloc(cur_item) == 0)
      {
   cur_item->v_type = VAR_SPECIAL;
   cur_item->vval.v_number = 2L;
   retval = 0;
   break;
      }
      ++reader->js_used;
      top_item = ((json_dec_item_T *)stack.ga_data)
        + stack.ga_len;
      top_item->jd_type = JSON_ARRAY;
      ++stack.ga_len;
      if (cur_item != ((void *)0))
      {
   top_item->jd_tv = *cur_item;
   cur_item = &item;
      }
      continue;
  case '{':
      if (ga_grow(&stack, 1) == 0)
      {
   retval = 0;
   break;
      }
      if (cur_item != ((void *)0) && rettv_dict_alloc(cur_item) == 0)
      {
   cur_item->v_type = VAR_SPECIAL;
   cur_item->vval.v_number = 2L;
   retval = 0;
   break;
      }
      ++reader->js_used;
      top_item = ((json_dec_item_T *)stack.ga_data)
        + stack.ga_len;
      top_item->jd_type = JSON_OBJECT_KEY;
      ++stack.ga_len;
      if (cur_item != ((void *)0))
      {
   top_item->jd_tv = *cur_item;
   cur_item = &top_item->jd_key_tv;
      }
      continue;
  case '"':
      retval = json_decode_string(reader, cur_item, *p);
      break;
  case '\'':
      if (options & 1)
   retval = json_decode_string(reader, cur_item, *p);
      else
      {
   emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
   retval = 0;
      }
      break;
  case ',':
      if ((options & 1) == 0)
      {
   emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
   retval = 0;
   break;
      }
  case '\000':
      if (cur_item != ((void *)0))
      {
   cur_item->v_type = VAR_SPECIAL;
   cur_item->vval.v_number = 2L;
      }
      retval = 1;
      break;
  default:
      if (((unsigned)(*p) - '0' < 10) || *p == '-')
      {
   char_u *sp = p;
   if (*sp == '-')
   {
       ++sp;
       if (*sp == '\000')
       {
    retval = 2;
    break;
       }
       if (!((unsigned)(*sp) - '0' < 10))
       {
    emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
    retval = 0;
    break;
       }
   }
   sp = skipdigits(sp);
   if (*sp == '.' || *sp == 'e' || *sp == 'E')
   {
       if (cur_item == ((void *)0))
       {
    float_T f;
    len = string2float(p, &f);
       }
       else
       {
    cur_item->v_type = VAR_FLOAT;
    len = string2float(p, &cur_item->vval.v_float);
       }
   }
   else
   {
       varnumber_T nr;
       vim_str2nr(reader->js_buf + reader->js_used,
        ((void *)0), &len, 0,
        &nr, ((void *)0), 0);
       if (cur_item != ((void *)0))
       {
    cur_item->v_type = VAR_NUMBER;
    cur_item->vval.v_number = nr;
       }
   }
   reader->js_used += len;
   retval = 1;
   break;
      }
      if (strncasecmp((char *)((char *)p), (char *)("false"), (size_t)(5)) == 0)
      {
   reader->js_used += 5;
   if (cur_item != ((void *)0))
   {
       cur_item->v_type = VAR_SPECIAL;
       cur_item->vval.v_number = 0L;
   }
   retval = 1;
   break;
      }
      if (strncasecmp((char *)((char *)p), (char *)("true"), (size_t)(4)) == 0)
      {
   reader->js_used += 4;
   if (cur_item != ((void *)0))
   {
       cur_item->v_type = VAR_SPECIAL;
       cur_item->vval.v_number = 1L;
   }
   retval = 1;
   break;
      }
      if (strncasecmp((char *)((char *)p), (char *)("null"), (size_t)(4)) == 0)
      {
   reader->js_used += 4;
   if (cur_item != ((void *)0))
   {
       cur_item->v_type = VAR_SPECIAL;
       cur_item->vval.v_number = 3L;
   }
   retval = 1;
   break;
      }
      if (strncasecmp((char *)((char *)p), (char *)("NaN"), (size_t)(3)) == 0)
      {
   reader->js_used += 3;
   if (cur_item != ((void *)0))
   {
       cur_item->v_type = VAR_FLOAT;
       cur_item->vval.v_float = (__builtin_nanf (""));
   }
   retval = 1;
   break;
      }
      if (strncasecmp((char *)((char *)p), (char *)("Infinity"), (size_t)(8)) == 0)
      {
   reader->js_used += 8;
   if (cur_item != ((void *)0))
   {
       cur_item->v_type = VAR_FLOAT;
       cur_item->vval.v_float = (__builtin_inff());
   }
   retval = 1;
   break;
      }
      len = (int)(reader->js_end - (reader->js_buf + reader->js_used));
      if (
       (len < 5 && strncasecmp((char *)((char *)p), (char *)("false"), (size_t)(len)) == 0)
       || (len < 8 && strncasecmp((char *)((char *)p), (char *)("Infinity"), (size_t)(len)) == 0)
       || (len < 3 && strncasecmp((char *)((char *)p), (char *)("NaN"), (size_t)(len)) == 0)
       || (len < 4 && (strncasecmp((char *)((char *)p), (char *)("true"), (size_t)(len)) == 0
           || strncasecmp((char *)((char *)p), (char *)("null"), (size_t)(len)) == 0)))
   retval = 2;
      else
   retval = 0;
      break;
     }
     if (retval == 0)
  break;
     if (retval == 2 || stack.ga_len == 0)
  goto theend;
     if (top_item != ((void *)0) && top_item->jd_type == JSON_OBJECT_KEY
      && cur_item != ((void *)0))
     {
  top_item->jd_key = get_tv_string_buf_chk(cur_item, key_buf);
  if (top_item->jd_key == ((void *)0))
  {
      clear_tv(cur_item);
      emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
      retval = 0;
      goto theend;
  }
     }
 }
item_end:
 top_item = ((json_dec_item_T *)stack.ga_data) + stack.ga_len - 1;
 switch (top_item->jd_type)
 {
     case JSON_ARRAY:
  if (res != ((void *)0))
  {
      listitem_T *li = listitem_alloc();
      if (li == ((void *)0))
      {
   clear_tv(cur_item);
   retval = 0;
   goto theend;
      }
      li->li_tv = *cur_item;
      list_append(top_item->jd_tv.vval.v_list, li);
  }
  if (cur_item != ((void *)0))
      cur_item = &item;
  json_skip_white(reader);
  p = reader->js_buf + reader->js_used;
  if (*p == ',')
      ++reader->js_used;
  else if (*p != ']')
  {
      if (*p == '\000')
   retval = 2;
      else
      {
   emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
   retval = 0;
      }
      goto theend;
  }
  break;
     case JSON_OBJECT_KEY:
  json_skip_white(reader);
  p = reader->js_buf + reader->js_used;
  if (*p != ':')
  {
      if (cur_item != ((void *)0))
   clear_tv(cur_item);
      if (*p == '\000')
   retval = 2;
      else
      {
   emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
   retval = 0;
      }
      goto theend;
  }
  ++reader->js_used;
  json_skip_white(reader);
  top_item->jd_type = JSON_OBJECT;
  if (cur_item != ((void *)0))
      cur_item = &item;
  break;
     case JSON_OBJECT:
  if (cur_item != ((void *)0)
   && dict_find(top_item->jd_tv.vval.v_dict,
       top_item->jd_key, -1) != ((void *)0))
  {
      emsg2((char_u *)(dcgettext (((void *)0), (char *)("E938: Duplicate key in JSON: \"%s\""), 5)), (char_u *)(top_item->jd_key));
      clear_tv(&top_item->jd_key_tv);
      clear_tv(cur_item);
      retval = 0;
      goto theend;
  }
  if (cur_item != ((void *)0))
  {
      dictitem_T *di = dictitem_alloc(top_item->jd_key);
      clear_tv(&top_item->jd_key_tv);
      if (di == ((void *)0))
      {
   clear_tv(cur_item);
   retval = 0;
   goto theend;
      }
      di->di_tv = *cur_item;
      di->di_tv.v_lock = 0;
      if (dict_add(top_item->jd_tv.vval.v_dict, di) == 0)
      {
   dictitem_free(di);
   retval = 0;
   goto theend;
      }
  }
  json_skip_white(reader);
  p = reader->js_buf + reader->js_used;
  if (*p == ',')
      ++reader->js_used;
  else if (*p != '}')
  {
      if (*p == '\000')
   retval = 2;
      else
      {
   emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
   retval = 0;
      }
      goto theend;
  }
  top_item->jd_type = JSON_OBJECT_KEY;
  if (cur_item != ((void *)0))
      cur_item = &top_item->jd_key_tv;
  break;
 }
    }
    if (res != ((void *)0))
    {
 clear_tv(res);
 res->v_type = VAR_SPECIAL;
 res->vval.v_number = 2L;
    }
    emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
theend:
    ga_clear(&stack);
    return retval;
}
    int
json_decode_all(js_read_T *reader, typval_T *res, int options)
{
    int ret;
    reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
    json_skip_white(reader);
    ret = json_decode_item(reader, res, options);
    if (ret != 1)
    {
 if (ret == 2)
     emsg((char_u *)(dcgettext (((void *)0), (char *)(e_invarg), 5)));
 return 0;
    }
    json_skip_white(reader);
    if (reader->js_buf[reader->js_used] != '\000')
    {
 emsg((char_u *)(dcgettext (((void *)0), (char *)(e_trailing), 5)));
 return 0;
    }
    return 1;
}
    int
json_decode(js_read_T *reader, typval_T *res, int options)
{
    int ret;
    reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
    json_skip_white(reader);
    ret = json_decode_item(reader, res, options);
    json_skip_white(reader);
    return ret;
}
    int
json_find_end(js_read_T *reader, int options)
{
    int used_save = reader->js_used;
    int ret;
    reader->js_end = reader->js_buf + strlen((char *)(reader->js_buf));
    json_skip_white(reader);
    ret = json_decode_item(reader, ((void *)0), options);
    reader->js_used = used_save;
    return ret;
}
