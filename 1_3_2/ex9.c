#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "mix.h"
#include "ex9.h"

enum ValidCheckKind { FLOAT, FIELD, MEMORY, GOOD };

bool ValidateInstruction(Word inst) {
  const unsigned char B = 1 << BYTE_BITS;
  const unsigned char BMAX = B - 1;
  const unsigned char UMAX = 20;
  Instruction instructions[] = {
      // 0 - 7:
      {GOOD, 0, BMAX, NOP},
      {FLOAT, 0, RANGE(5, 5), ADD},
      {FLOAT, 0, RANGE(5, 5), SUB},
      {FLOAT, 0, RANGE(5, 5), MUL},
      {FLOAT, 0, RANGE(5, 5), DIV},
      {GOOD, 0, 2, HLT},
      {GOOD, 0, 5, SRC},
      {MEMORY, 0, BMAX, MOVE},
      // 8 - 15:
      {FIELD, 0, RANGE(5, 5), LDA},
      {FIELD, 0, RANGE(5, 5), LD1},
      {FIELD, 0, RANGE(5, 5), LD2},
      {FIELD, 0, RANGE(5, 5), LD3},
      {FIELD, 0, RANGE(5, 5), LD4},
      {FIELD, 0, RANGE(5, 5), LD5},
      {FIELD, 0, RANGE(5, 5), LD6},
      {FIELD, 0, RANGE(5, 5), LDX},
      // 16 - 23:
      {FIELD, 0, RANGE(5, 5), LDAN},
      {FIELD, 0, RANGE(5, 5), LD1N},
      {FIELD, 0, RANGE(5, 5), LD2N},
      {FIELD, 0, RANGE(5, 5), LD3N},
      {FIELD, 0, RANGE(5, 5), LD4N},
      {FIELD, 0, RANGE(5, 5), LD5N},
      {FIELD, 0, RANGE(5, 5), LD6N},
      {FIELD, 0, RANGE(5, 5), LDXN},
      // 24 - 31:
      {FIELD, 0, RANGE(5, 5), STA},
      {FIELD, 0, RANGE(5, 5), ST1},
      {FIELD, 0, RANGE(5, 5), ST2},
      {FIELD, 0, RANGE(5, 5), ST3},
      {FIELD, 0, RANGE(5, 5), ST4},
      {FIELD, 0, RANGE(5, 5), ST5},
      {FIELD, 0, RANGE(5, 5), ST6},
      {FIELD, 0, RANGE(5, 5), STX},
      // 32 - 39:
      {FIELD, 0, RANGE(5, 5), STJ},
      {FIELD, 0, RANGE(5, 5), STZ},
      {MEMORY, 0, UMAX, JBUS},
      {GOOD, 0, UMAX, IOC},
      {MEMORY, 0, UMAX, IN},
      {MEMORY, 0, UMAX, OUT},
      {MEMORY, 0, BMAX, JRED},
      {MEMORY, 0, 9, JMP},
      // 40 - 47:
      {MEMORY, 0, 5, JA},
      {MEMORY, 0, 5, J1},
      {MEMORY, 0, 5, J2},
      {MEMORY, 0, 5, J3},
      {MEMORY, 0, 5, J4},
      {MEMORY, 0, 5, J5},
      {MEMORY, 0, 5, J6},
      {MEMORY, 0, 5, JX},
      // 48 - 55:
      {GOOD, 0, 3, INCA},
      {GOOD, 0, 3, INC1},
      {GOOD, 0, 3, INC2},
      {GOOD, 0, 3, INC3},
      {GOOD, 0, 3, INC4},
      {GOOD, 0, 3, INC5},
      {GOOD, 0, 3, INC6},
      {GOOD, 0, 3, INCX},
      // 56 - 63:
      {FLOAT, 0, RANGE(5, 5), CMPA},
      {FIELD, 0, RANGE(5, 5), CMP1},
      {FIELD, 0, RANGE(5, 5), CMP2},
      {FIELD, 0, RANGE(5, 5), CMP3},
      {FIELD, 0, RANGE(5, 5), CMP4},
      {FIELD, 0, RANGE(5, 5), CMP5},
      {FIELD, 0, RANGE(5, 5), CMP6},
      {FIELD, 0, RANGE(5, 5), CMPX},
  };
  const Instruction VALID_INST = {3999, 6, 6, CMPX};
  const Word VALID = PackInstruction(VALID_INST);
  Word table[64];
  // Assemble the table of instructions:
  for (int i = 0; i < 64; i++) table[i] = PackInstruction(instructions[i]);
  if (inst.f3 > VALID.f3)  // BEGIN
    return false;
  int c = inst.f5 - 64;
  if (c >= 0) return false;
  if (inst.f4 > table[c + 64].f4) return false;
  switch (table[c + 64].f2) {
    case FLOAT:
      if (inst.f4 == VALID.f4) return true;
    case FIELD:
      if ((inst.f4 / 9 + inst.f4 % 9) > 5) return false;
    case MEMORY:
      if (inst.f3 != 0) return true;
      if (inst.sign < 0) return false;
      if ((inst.f1 << BYTE_BITS | inst.f2) <= 3999)
        return true;
      else
        return false;
    case GOOD:
      return true;
    default:
      return false;
  }
}
