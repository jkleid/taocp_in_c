#include <stdlib.h>
#include <check.h>
#include "ex9.h"
#include "mix.h"

#define CHECK_INSTRUCTION(a, i, f, c, result)                        \
  do {                                                               \
    Instruction in = {a, i, f, c};                                   \
    fail_unless(ValidateInstruction(PackInstruction(in)) == result); \
  } while (0)

START_TEST(test_valid_instructions) {
  CHECK_INSTRUCTION(0, 0, 0, NOP, true);

  CHECK_INSTRUCTION(0, 0, 0, ADD, true);
  CHECK_INSTRUCTION(0, 0, RANGE(5, 5), ADD, true);
  CHECK_INSTRUCTION(-1, 0, 6, ADD, true);
  CHECK_INSTRUCTION(5000, 4, 6, ADD, true);
  CHECK_INSTRUCTION(-1, 1, 5, ADD, true);
  CHECK_INSTRUCTION(3999, 0, 5, ADD, true);

  CHECK_INSTRUCTION(24, 0, 2, HLT, true);
  CHECK_INSTRUCTION(0, 0, 0, HLT, true);

  CHECK_INSTRUCTION(0, 0, RANGE(0, 5), LDA, true);
  CHECK_INSTRUCTION(-100, 1, RANGE(0, 5), LDA, true);

  CHECK_INSTRUCTION(0, 0, 0, JBUS, true);
  CHECK_INSTRUCTION(0, 0, 20, JBUS, true);

  CHECK_INSTRUCTION(-5, 0, 0, ENNA, true);
  CHECK_INSTRUCTION(0, 0, 2, ENNA, true);
}
END_TEST

START_TEST(test_invalid_instructions) {
  CHECK_INSTRUCTION(0, 0, RANGE(5, 6), ADD, false);
  CHECK_INSTRUCTION(0, 0, RANGE(1, 0), ADD, false);
  CHECK_INSTRUCTION(0, 0, RANGE(5, 0), ADD, false);
  CHECK_INSTRUCTION(0, 0, RANGE(5, 4), ADD, false);
  CHECK_INSTRUCTION(0, 0, RANGE(4, 3), ADD, false);
  CHECK_INSTRUCTION(-1, 0, 5, ADD, false);
  CHECK_INSTRUCTION(4000, 0, 5, ADD, false);

  CHECK_INSTRUCTION(24, 52, 90, HLT, false);
  CHECK_INSTRUCTION(24, 0, 3, HLT, false);

  CHECK_INSTRUCTION(0, 0, RANGE(5, 4), LDA, false);
  CHECK_INSTRUCTION(0, 7, RANGE(5, 5), LDA, false);

  CHECK_INSTRUCTION(0, 0, 21, JBUS, false);
  CHECK_INSTRUCTION(-5, 0, 20, JBUS, false);

  CHECK_INSTRUCTION(-5, 0, 20, ENNA, false);
  CHECK_INSTRUCTION(0, 0, 20, ENNA, false);
}
END_TEST

Suite *test_suite() {
  Suite *s = suite_create("mix_validity");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_valid_instructions);
  tcase_add_test(tc_core, test_invalid_instructions);
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
