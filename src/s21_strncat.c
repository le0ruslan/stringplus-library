#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *copy_dest = dest;
  s21_size_t size_dest = s21_strlen(dest);
  s21_size_t i = 0;
  for (; i < n; ++i) {
    *(copy_dest + size_dest + i) = *(src + i);
  }
  *(copy_dest + size_dest + i) = '\0';
  return dest;
}