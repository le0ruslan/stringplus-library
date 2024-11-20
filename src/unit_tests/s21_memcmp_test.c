#include "s21_string_test.h"

START_TEST(test_memcmp_1) {
  char *str1 = "Suzy Heim";
  char *str2 = "Suzy Heimir";
  size_t num = strlen(str1);
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n2, n1);
}
END_TEST

START_TEST(test_memcmp_2) {
  char *str1 = "Suzy Heim";
  char *str2 = "Suzy Heimir";
  size_t num = 5;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n2, n1);
}
END_TEST

START_TEST(test_memcmp_3) {
  char *str1 = "Suzy Heim";
  char *str2 = "Suzy Heimir";
  size_t num = 0;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n2, n1);
}
END_TEST

START_TEST(test_memcmp_4) {
  char *str1 = "Suzy Heim";
  char *str2 = "Suzy Heimir";
  size_t num = strlen(str2);
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n2, n1);
}
END_TEST

START_TEST(test_memcmp_5) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  size_t num = 14;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_6) {
  char *str1 = "Suzy Heim";
  char *str2 = "Suzy Suzy";
  size_t num = strlen(str1);
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_7) {
  char *str1 = "605895";
  char *str2 = "603895";
  size_t num = 4;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_8) {
  char *str1 = "899432";
  char *str2 = "899432";
  size_t num = 4;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_9) {
  char *str1 = "";
  char *str2 = "";
  size_t num = 0;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_10) {
  char *str1 =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char *str2 =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  size_t num = 115;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcmp_11) {
  char *str1 =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char *str2 =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2";
  size_t num = 115;
  int n1 = memcmp(str1, str2, num);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str1, str2, num);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, test_memcmp_1);
  tcase_add_test(tc, test_memcmp_2);
  tcase_add_test(tc, test_memcmp_3);
  tcase_add_test(tc, test_memcmp_4);
  tcase_add_test(tc, test_memcmp_5);
  tcase_add_test(tc, test_memcmp_6);
  tcase_add_test(tc, test_memcmp_7);
  tcase_add_test(tc, test_memcmp_8);
  tcase_add_test(tc, test_memcmp_9);
  tcase_add_test(tc, test_memcmp_10);
  tcase_add_test(tc, test_memcmp_11);

  suite_add_tcase(s, tc);
  return s;
}