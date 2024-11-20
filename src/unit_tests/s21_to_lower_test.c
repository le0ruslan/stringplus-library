#include "s21_string_test.h"

START_TEST(test_to_lower_1) {
  char str1[30] = "hello, world!";
  char str3[] = "hELLO, WORLD!";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str1[30] = "\nh\t\\g123123";
  char str3[] = "\nH\t\\G123123";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str1[30] = "already lower";
  char str3[] = "already lower";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str1[30] = "";
  char str3[] = "";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str1[30] = "abcdefghijklmnopqrstuvwxyz";
  char str3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str1[30] = "_?};!234";
  char str3[] = "_?};!234";
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *str1 = NULL;
  char *str3 = NULL;
  char *str2 = s21_to_lower(str3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("test_to_lower_tc");

  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  suite_add_tcase(s, tc);
  return s;
}