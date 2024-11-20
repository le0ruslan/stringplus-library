#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *copy_dest = dest;
  const unsigned char *copy_src = src;
  for (s21_size_t i = 0; i < n; ++i) {
    copy_dest[i] = copy_src[i];
  }
  return dest;
}