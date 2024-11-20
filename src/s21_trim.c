#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *p;
  if (src == S21_NULL) {
    return S21_NULL;
  } else {
    static char buff[BUFFER];
    int left_index = 0;
    int right_index = 0;
    int flag_end = 0;
    s21_sprintf(buff, "%s", src);
    p = buff;
    if (trim_chars != S21_NULL) {
      for (int i = 0; i < (int)s21_strlen(src); i++) {
        if (s21_strchr(trim_chars, src[i]) != S21_NULL && !flag_end) {
          left_index++;
        } else {
          flag_end = 1;
        }
      }
      flag_end = 0;
      for (int j = (int)s21_strlen(src) - 1; j > 0; j--) {
        if (s21_strchr(trim_chars, src[j]) != S21_NULL && !flag_end) {
          right_index++;
        } else {
          flag_end = 1;
        }
      }
      for (int left = 0; left < left_index; left++) {
        p++;
      }
      for (int right = (int)s21_strlen(p) - 1; right_index > 0; right_index--) {
        p[right] = '\0';
        right--;
      }
    }
  }

  return p;
}