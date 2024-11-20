#include "s21_string_test.h"

START_TEST(test_memchr_1) {
  char *str = "Suzy Heim";
  int ch = ' ';
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_2) {
  char *str = "Suzy Heim";
  int ch = 83;
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_3) {
  char *str = "Suzy Heim";
  int ch = 117;
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_4) {
  char *str = "Suzy Heim";
  int ch = 122;
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_5) {
  char *str = "Suzy Heim";
  int ch = 121;
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_6) {
  char *str = "Suzy Heim";
  int ch = 'i';
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_7) {
  char *str = "123456";
  int ch = '3';
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_8) {
  char *str = "123456";
  int ch = '6';
  size_t num = 3;
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_9) {
  void *str = "123456";
  int ch = 6;
  size_t num = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

START_TEST(test_memchr_10) {
  char *str = "Suzy Heim";
  int ch = '\0';
  size_t num = strlen(str) + 1;
  ck_assert_ptr_eq(s21_memchr(str, ch, num), memchr(str, ch, num));
}

Suite *test_memchr(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, test_memchr_1);
  tcase_add_test(tc, test_memchr_2);
  tcase_add_test(tc, test_memchr_3);
  tcase_add_test(tc, test_memchr_4);
  tcase_add_test(tc, test_memchr_5);
  tcase_add_test(tc, test_memchr_6);
  tcase_add_test(tc, test_memchr_7);
  tcase_add_test(tc, test_memchr_8);
  tcase_add_test(tc, test_memchr_9);
  tcase_add_test(tc, test_memchr_10);

  suite_add_tcase(s, tc);
  return s;
}
