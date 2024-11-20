#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// string.h Types
typedef unsigned long s21_size_t;

// string.h Macro
#define S21_NULL (void *)0

// int sprintf(char *str, const char *format, ...)
#define LENGTH_DEFAULT 0
#define LENGTH_SHORT 1
#define LENGTH_LONG 2
#define LENGTH_LONG_DOUBLE 3

#define SIGN_NONE 0
#define SIGN_MINUS 1
#define SIGN_PLUS 2
#define SIGN_SPACE 3

#define SIDE_LEFT 2
#define SIDE_RIGHT 1

#define PARAM_NONE -1
#define DEFAULT_PRECISION 6

#define SPACE_DEFAULT ' '
#define SPACE_ZERO '0'

#define PARAM_ARG '*'

#define FORMAT_OCTAL 8
#define FORMAT_DECIMAL 10
#define FORMAT_HEX 16

#define BUFFER 1000

typedef struct {
  bool addChar;
  bool nextIsFormat;
  int signMode;
  int width;
  int precision;
  int side;
  int length;
  char space_symbol;
  bool sharp;
  bool bigChar;
  bool is_ptr;
} sprintf_struct;

sprintf_struct def_sprintf_struct();
void precision_to_width(sprintf_struct *parameters);
void clear_sprintf_struct(sprintf_struct *parameters);
void flags(sprintf_struct *parameters, char fc);
int convert_int(const char **sptr);
void specifiers(sprintf_struct *parameters, char sign, char **sptr, va_list ap,
                int *count);

int s21_sprintf(char *str, const char *format, ...);

char *add_char(char *string, long symbol, sprintf_struct *parameters);
char *add_int(char *string, long long number, int format,
              sprintf_struct *parameters);
char *add_str(char *result, const char *string, sprintf_struct *parameters);
char *add_float(char *string, long double number, sprintf_struct *parameters);
char *add_e(char *string, long double number, sprintf_struct *parameters);
char *add_g(char *string, long double number, sprintf_struct *parameters);

int s21_strcmp(const char *s1, const char *s2);
int calc_expo(long double *nump);
void string_reverse(char *string, int n);
int num_len(long long number, int format);
char *print_format(char *string, int format, bool bigChar);
int float_left_length(long double number);
int end_zeros_count(long double number, int precision);
// end of sprintf function

// roostaha - start
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strerror(int errnum);
void *s21_trim(const char *src, const char *trim_chars);

#ifdef __APPLE__

#define ERR_MSGS_COUNT 106
#define ERR_MSGS                                                               \
  {                                                                            \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"                                       \
  }

#else

#define ERR_MSGS_COUNT 134
#define ERR_MSGS                                                               \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error"                                       \
  }

#endif
// roostaha - end

// suzyheim - start


void *s21_memchr(const void *, int, s21_size_t);
int s21_memcmp(const void *, const void *, s21_size_t);
void *s21_memcpy(void *, const void *, s21_size_t);
void *s21_memset(void *, int, s21_size_t);
char *s21_strncat(char *, const char *, s21_size_t);
void *s21_to_upper(const char *);
void *s21_to_lower(const char *);

// suzyheim - end

// lavonekr - start
s21_size_t s21_strspn(const char *str, const char *chars);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
// lavonekr - end

#endif  // S21_STRING_H_
