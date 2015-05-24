#include <stdio.h>
#include "mix.h"

Word PackInstruction(Instruction inst) {
  const unsigned int BYTE_MASK = (1 << (BYTE_BITS + 1)) - 1;
  Word word;
  AS_INT(word) = 0;
  word.sign = inst.A >= 0 ? 1 : 0;
  word.f1 = (inst.A & (BYTE_MASK << BYTE_BITS)) >> BYTE_BITS;
  word.f2 = inst.A & BYTE_MASK;
  word.f3 = inst.I;
  word.f4 = inst.F;
  word.f5 = inst.C;
  return word;
}

Instruction UnpackInstruction(Word word) {
  Instruction inst;
  inst.A = (word.f1 << BYTE_BITS) | word.f2;
  inst.A = word.sign ? inst.A : -inst.A;
  inst.I = word.f3;
  inst.F = word.f4;
  inst.C = word.f5;
  return inst;
}

void PrintWord(const char* description, Word word) {
  printf("%s: [%d] %d, %d, %d, %d, %d\n", description, word.sign, word.f1,
         word.f2, word.f3, word.f4, word.f5);
}
