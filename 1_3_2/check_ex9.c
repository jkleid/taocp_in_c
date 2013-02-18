#include <stdlib.h>
#include <check.h>
#include "ex9.h"
#include "mix.h"


START_TEST (test_validity)
{
  Instruction nop = { 0, 0, 0, NOP };
  fail_unless(ValidateInstruction(PackInstruction(nop)));
  Instruction add0 = { 0, 0, 0, ADD };
  fail_unless(ValidateInstruction(PackInstruction(add0)));
  Instruction add1 = { 0, 0, RANGE(5, 5), ADD };
  fail_unless(ValidateInstruction(PackInstruction(add1)));
  Instruction add2 = { 0, 0, 46, ADD };
  fail_if(ValidateInstruction(PackInstruction(add2)));
  Instruction add3 = { -1, 0, 6, ADD };
  fail_unless(ValidateInstruction(PackInstruction(add3)));
  Instruction add4 = { -1, 0, 5, ADD };
  fail_if(ValidateInstruction(PackInstruction(add4)));


}
END_TEST

Suite *test_suite()
{
  Suite *s = suite_create("P");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_validity);
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

