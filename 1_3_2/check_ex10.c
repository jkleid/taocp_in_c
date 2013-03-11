#include <stdlib.h>
#include <check.h>
#include <ex10.h>


START_TEST (test_saddle1)
{
  int matrix[] = {
    8, 0, 8, 1, 0, 1, 3, 9,
    6, 9, 4, 1, 2, 5, 0, 6,
    1, 1, 9, 5, 3, 7, 3, 6,
    9, 7, 1, 9, 3, 6, 1, 9,
    6, 3, 2, 9, 5, 2, 4, 7,
    8, 8, 9, 9, 6, 7, 7, 8,
    2, 4, 4, 4, 4, 7, 7, 9,
    7, 1, 4, 9, 5, 9, 6, 0,
    0, 1, 9, 5, 2, 0, 0, 1,
  };

  fail_unless(Saddle(matrix) == &matrix[44]);
}
END_TEST

START_TEST (test_saddle2)
{
  int matrix[] = {
    8, 0, 8, 1, 9, 1, 3, 9,
    6, 9, 4, 1, 2, 5, 0, 6,
    1, 1, 9, 5, 3, 7, 3, 6,
    9, 7, 1, 9, 3, 6, 1, 9,
    6, 3, 2, 9, 5, 2, 4, 7,
    8, 8, 9, 9, 6, 7, 7, 8,
    2, 4, 4, 4, 4, 7, 7, 9,
    7, 1, 4, 9, 5, 9, 6, 0,
    0, 1, 9, 5, 2, 0, 0, 1,
  };

  fail_unless(Saddle(matrix) == 0);
}
END_TEST

START_TEST (test_saddle3)
{
  int matrix[] = {
    8, 0, 8, 1, 0, 1, 3, 9,
    6, 9, 4, 1, 2, 5, 0, 6,
    1, 1, 9, 5, 3, 7, 3, 6,
    9, 7, 1, 9, 3, 6, 1, 9,
    6, 3, 2, 9, 5, 2, 4, 7,
    8, 6, 9, 9, 6, 7, 7, 8,
    2, 4, 4, 4, 4, 7, 7, 9,
    7, 1, 4, 9, 5, 9, 6, 0,
    0, 1, 9, 5, 2, 0, 0, 1,
  };

  fail_unless(Saddle(matrix) == &matrix[44]);
}
END_TEST

START_TEST (test_saddle4)
{
  int matrix[] = {
    8, 0, 8, 1, 0, 1, 3, 9,
    6, 9, 4, 1, 2, 5, 0, 6,
    1, 1, 9, 5, 3, 7, 3, 6,
    9, 7, 1, 9, 3, 6, 1, 9,
    6, 3, 2, 9, 5, 2, 4, 7,
    5, 5, 5, 5, 5, 5, 5, 5,
    2, 4, 4, 4, 4, 7, 7, 9,
    7, 1, 4, 9, 5, 9, 6, 0,
    0, 1, 9, 5, 2, 0, 0, 1,
  };
  
  fail_unless(Saddle(matrix) == &matrix[44]);
} 
END_TEST

START_TEST (test_saddle5)
{
  int matrix[] = {
    8, 0, 8, 1, 0, 1, 3, 0,
    6, 9, 4, 1, 2, 5, 0, 0,
    1, 1, 9, 5, 3, 7, 3, 0,
    9, 7, 1, 9, 3, 6, 1, 0,
    6, 3, 2, 9, 5, 2, 4, 0,
    5, 5, 5, 5, 5, 5, 5, 0,
    2, 4, 4, 4, 4, 7, 7, 0,
    7, 1, 4, 9, 5, 9, 6, 0,
    2, 2, 2, 2, 2, 2, 2, 1,
  };

  fail_unless(Saddle(matrix) == &matrix[71]);
}
END_TEST

START_TEST (test_saddle6)
{
  int matrix[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
  };

  fail_unless(Saddle(matrix) == &matrix[64]);
}
END_TEST


Suite *test_suite()
{
  Suite *s = suite_create("ex10");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_saddle1);
  tcase_add_test(tc_core, test_saddle2);
  tcase_add_test(tc_core, test_saddle3);
  tcase_add_test(tc_core, test_saddle4);
  tcase_add_test(tc_core, test_saddle5);
  tcase_add_test(tc_core, test_saddle6);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void)
{
  int number_failed;
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

