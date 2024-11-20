#include "s21_string_test.h"

START_TEST(test_to_upper_1) {
  char str1[30] = "hello, world!";
  char str3[] = "HELLO, WORLD!";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str1[30] = "\nh\t\\g123123";
  char str3[] = "\nH\t\\G123123";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str1[30] = "already lower";
  char str3[] = "ALREADY LOWER";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str1[30] = "";
  char str3[] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str1[30] = "abcdefghijklmnopqrstuvwxyz";
  char str3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str1[30] = "_?};!234";
  char str3[] = "_?};!234";
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *str1 = NULL;
  char *str3 = NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_pstr_eq(str3, str2);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("test_to_upper_tc");

  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_upper_4);
  tcase_add_test(tc, test_to_upper_5);
  tcase_add_test(tc, test_to_upper_6);
  tcase_add_test(tc, test_to_upper_7);

  suite_add_tcase(s, tc);
  return s;
}