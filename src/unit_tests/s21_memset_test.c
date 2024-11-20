#include "s21_string_test.h"

START_TEST(test_memset_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t bytes = strlen(str1);
  int ch = ' ';
  size_t num = strlen(str1);
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

START_TEST(test_memset_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t bytes = strlen(str1);
  int ch = ' ';
  size_t num = 5;
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

START_TEST(test_memset_3) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t bytes = strlen(str1);
  int ch = ' ';
  size_t num = 0;
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

START_TEST(test_memset_4) {
  char str1[] = "";
  char str2[] = "";
  size_t bytes = strlen(str1);
  int ch = '\0';
  size_t num = 0;
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

START_TEST(test_memset_5) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  size_t bytes = strlen(str1);
  int ch = '\0';
  size_t num = 4;
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

START_TEST(test_memset_6) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  size_t bytes = strlen(str1);
  int ch = 80;
  size_t num = 7;
  memset(str1, ch, num);
  s21_memset(str2, ch, num);
  ck_assert_mem_eq(str1, str2, bytes);
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, test_memset_1);
  tcase_add_test(tc, test_memset_2);
  tcase_add_test(tc, test_memset_3);
  tcase_add_test(tc, test_memset_4);
  tcase_add_test(tc, test_memset_5);
  tcase_add_test(tc, test_memset_6);

  suite_add_tcase(s, tc);
  return s;
}
