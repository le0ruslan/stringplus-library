#include "s21_string_test.h"

START_TEST(test_strncat_1) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str3[] = "Hello, world!";
  size_t num = 1;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_2) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str3[] = "\0";
  size_t num = 1;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_3) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str3[] = "\n\0\\d\f\\g\7";
  size_t num = 3;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_4) {
  char str1[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str3[] = "";
  size_t num = 0;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_5) {
  char str1[30] = "";
  char str2[30] = "";
  char str3[] = "Hello, world!";
  size_t num = 13;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_6) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  size_t num = 6;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_7) {
  char str1[30] = "";
  char str2[30] = "";
  char str3[] = "Hello, world!";
  size_t num = 3;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_8) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] = "My name is Polina.";
  size_t num = 2;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_9) {
  char str1[100] = "";
  char str2[100] = "";
  char str3[] = "";
  size_t num = 10;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_10) {
  char str1[100] = "Hello\0, world!";
  char str2[100] = "Hello\0, world!";
  char str3[] = "My name is\0 Polina.";
  size_t num = 15;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_11) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] = "\0";
  size_t num = 1;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_12) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] = "\0";
  size_t num = 0;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_13) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] = "\0\0\0\0";
  size_t num = 4;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_14) {
  char str1[100] = "Hello, world!";
  char str2[100] = "Hello, world!";
  char str3[] = "";
  size_t num = 2;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

START_TEST(test_strncat_15) {
  char str1[100] = "Hello, world!\0\0\0";
  char str2[100] = "Hello, world!\0\0\0";
  char str3[] = "My name is Polina.";
  size_t num = 0;
  ck_assert_pstr_eq(strncat(str1, str3, num), s21_strncat(str2, str3, num));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("test_strncat_tc");

  tcase_add_test(tc, test_strncat_1);
  tcase_add_test(tc, test_strncat_2);
  tcase_add_test(tc, test_strncat_3);
  tcase_add_test(tc, test_strncat_4);
  tcase_add_test(tc, test_strncat_5);
  tcase_add_test(tc, test_strncat_6);
  tcase_add_test(tc, test_strncat_7);
  tcase_add_test(tc, test_strncat_8);
  tcase_add_test(tc, test_strncat_9);
  tcase_add_test(tc, test_strncat_10);
  tcase_add_test(tc, test_strncat_11);
  tcase_add_test(tc, test_strncat_12);
  tcase_add_test(tc, test_strncat_13);
  tcase_add_test(tc, test_strncat_14);
  tcase_add_test(tc, test_strncat_15);

  suite_add_tcase(s, tc);

  return s;
}