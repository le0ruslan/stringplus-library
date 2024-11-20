#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  s21_size_t length_needle = s21_strlen(needle);
  if (length_needle == 0) {
    result = (char *)haystack;
  }
  while (*haystack != '\0' && result == S21_NULL) {
    if ((*haystack == *needle) &&
        s21_strncmp(haystack, needle, length_needle) == 0) {
      result = (char *)haystack;
    }
    haystack++;
  }
  return result;
}
