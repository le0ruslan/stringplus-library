#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t length_string = '\0';
  int result = 0;
  for (; *(str + length_string); length_string++) {
    result++;
  }
  return result;
}
