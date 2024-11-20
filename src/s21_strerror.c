#include "s21_string.h"

char *s21_strerror(int errnum) {
  int errnum_max;
  char *res;
  static char buff[BUFFER];
  static const char *strerr[] = ERR_MSGS;

#ifdef __APPLE__
  errnum_max = ERR_MSGS_COUNT;
#else
  errnum_max = ERR_MSGS_COUNT - 1;
#endif

  if (errnum < 0 || errnum > errnum_max) {
#ifdef __APPLE__
    s21_sprintf(buff, "Unknown error: %d", errnum);
    res = buff;
#else
    s21_sprintf(buff, "Unknown error %d", errnum);
    res = buff;
#endif
  } else {
    res = (char *)(strerr[errnum]);
  }
  return res;
}