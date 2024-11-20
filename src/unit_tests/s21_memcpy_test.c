#include "s21_string_test.h"

START_TEST(test_memcpy_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Good";
  size_t num = 4;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "\0";
  size_t num = 1;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_3) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "f";
  size_t num = 0;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_4) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Hi";
  size_t num = 3;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_5) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Hi";
  size_t num = 2;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_6) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "love";
  size_t num = 0;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_7) {
  char str1[] = "new_strnew_string";
  char str2[] = "new_strnew_string";
  char str3[] = "new_string";
  size_t num = strlen(str3);
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_8) {
  char str1[] = "699\017020";
  char str2[] = "699\017020";
  char str3[] = "com";
  size_t num = 3;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_9) {
  char str1[] = "69917020";
  char str2[] = "69917020";
  char str3[] = "c";
  size_t num = 1;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

START_TEST(test_memcpy_10) {
  char str1[] = "69917020";
  char str2[] = "69917020";
  char str3[] = "com";
  size_t num = 3;
  ck_assert_str_eq(memcpy(str1, str3, num), s21_memcpy(str2, str3, num));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, test_memcpy_1);
  tcase_add_test(tc, test_memcpy_2);
  tcase_add_test(tc, test_memcpy_3);
  tcase_add_test(tc, test_memcpy_4);
  tcase_add_test(tc, test_memcpy_5);
  tcase_add_test(tc, test_memcpy_6);
  tcase_add_test(tc, test_memcpy_7);
  tcase_add_test(tc, test_memcpy_8);
  tcase_add_test(tc, test_memcpy_9);
  tcase_add_test(tc, test_memcpy_10);

  suite_add_tcase(s, tc);
  return s;
}