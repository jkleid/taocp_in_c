#include <stdlib.h>
#include <check.h>
#include <P.h>


START_TEST (test_primes)
{
  int primes[500];
  PRIMES(500, primes);
  fail_unless(primes[0] == 2);
  fail_unless(primes[1] == 3);
  fail_unless(primes[2] == 5);
  fail_unless(primes[3] == 7);
  fail_unless(primes[4] == 11);
  fail_unless(primes[99] == 541);
  fail_unless(primes[220] == 1381);
  fail_unless(primes[498] == 3559);
  fail_unless(primes[499] == 3571);
}
END_TEST

Suite *test_suite()
{
  Suite *s = suite_create("P");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_primes);
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

