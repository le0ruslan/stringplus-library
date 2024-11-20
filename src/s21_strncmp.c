#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  if (n != 0) {
    for (; *str1 && *str1 == *str2 && n != 0; str1++, str2++) {
      n--;
    }
    diff = *str1 - *str2;
  }
  return diff;
}
