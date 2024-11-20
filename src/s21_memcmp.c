#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *copy_str1 = str1;
  const unsigned char *copy_str2 = str2;
  int tmp = 0;
  for (s21_size_t i = 0; i < n; ++i) {
    if (copy_str1[i] < copy_str2[i]) {
      tmp = -1;
      break;
    } else if (copy_str1[i] > copy_str2[i]) {
      tmp = 1;
      break;
    }
  }
  return tmp;
}