#include "s21_string_test.h"
START_TEST(strerror_1) {
  for (int i = 1; i < 40; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);

  suite_add_tcase(s, tc);
  return s;
}
