#include "s21_string.h"

s21_size_t s21_strspn(const char *str, const char *chars) {
  s21_size_t i;
  char ch[256] = {0};
  for (i = 0; i < s21_strlen(chars); i++) {
    ch[(unsigned char)chars[i]] = 1;
  }
  for (i = 0; i < s21_strlen(str); i++) {
    if (ch[(unsigned char)str[i]] == 0) {
      break;
    }
  }
  return i;
}

static char *last;
char *s21_strtok(char *str, const char *delim) {
  char *token_string = S21_NULL;
  int flag = 1;
  if (!str) {
    str = last;
  }
  str = str + s21_strspn(str, delim);
  if (!*str) {
    last = str;
    flag = 0;
  }
  if (flag) {
    token_string = str;
    str = s21_strpbrk(str, delim);
    if (str) {
      *str = '\0';
      last = str + 1;
    } else {
      last = token_string + s21_strlen(token_string);
    }
  }
  return token_string;
}
