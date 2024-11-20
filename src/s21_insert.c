#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL || start_index > s21_strlen(src)) {
    return S21_NULL;
  }
  static char result[BUFFER];
  s21_size_t i = 0, j;
  for (; i < start_index; i++) result[i] = src[i];
  for (j = 0; j < s21_strlen(str); j++) {
    result[i] = str[j];
    i++;
  }
  for (j = start_index; src[j]; j++) {
    result[i] = src[j];
    i++;
  }
  result[i] = '\0';

  return result;
}
