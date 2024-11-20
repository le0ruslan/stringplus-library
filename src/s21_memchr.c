#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 0;
  const unsigned char *copy_str = str;
  s21_size_t i = 0;
  for (; i < n; ++i) {
    if (copy_str[i] == c) {
      flag = 1;
      break;
    }
  }
  return flag == 1 ? (void *)copy_str + i : NULL;
}