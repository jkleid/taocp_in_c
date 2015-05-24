#include <stdlib.h>
#include <check.h>
#include <M.h>

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

#define MAX_TEST(array, max_index) \
  fail_unless(MAXIMUM(array, ARRAY_LEN(array)) == max_index)

START_TEST(test_max) {
  const int a[] = {1, 3, 7, 5, 3};
  MAX_TEST(a, 2);
  const int b[] = {10, 1, 3, 7, 5, 3};
  MAX_TEST(b, 0);
  const int c[] = {10, 1, 3, 7, 5, 3, 11};
  MAX_TEST(c, 6);
  const int d[] = {0};
  MAX_TEST(d, 0);
}
END_TEST

Suite *test_suite() {
  Suite *s = suite_create("M");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_max);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
