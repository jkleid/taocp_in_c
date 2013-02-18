#ifndef _MIX_H_
#define _MIX_H_

#include <stdint.h>

// Number of bits in a mix byte:
#define BYTE_BITS 6

typedef struct Word {
  unsigned int sign : 1;
  unsigned int      : 1;
  unsigned int f1   : BYTE_BITS;
  unsigned int f2   : BYTE_BITS;
  unsigned int f3   : BYTE_BITS;
  unsigned int f4   : BYTE_BITS;
  unsigned int f5   : BYTE_BITS;
} Word;

typedef struct Instruction {
  int A;
  unsigned char I;
  unsigned char F;
  unsigned char C;
} Instruction;

enum Instruction_Opcodes {
  NOP,  ADD,  SUB,  MUL,  DIV,  NUM,  SLA,  MOVE,
  LDA,  LD1,  LD2,  LD3,  LD4,  LD5,  LD6,  LDX,
  LDAN, LD1N, LD2N, LD3N, LD4N, LD5N, LD6N, LDXN,
  STA,  ST1,  ST2,  ST3,  ST4,  ST5,  ST6,  STX,
  STJ,  STZ,  JBUS, IOC,  IN,   OUT,  JRED, JMP,
  JA,   J1,   J2,   J3,   J4,   J5,   J6,   JX,
  INCA, INC1, INC2, INC3, INC4, INC5, INC6, INCX,
  CMPA, CMP1, CMP2, CMP3, CMP4, CMP5, CMP6, CMPX,
// Variants:
  CHAR = NUM, HLT = NUM,
  SRA = SLA, SLAX = SLA, SRAX = SLA, SLC = SLA, SRC = SLA,
  JSJ = JMP, JOV = JMP, JNOV = JMP, JL = JMP, JE = JMP,
  JG = JMP, JGE = JMP, JNE = JMP, JLE = JMP,
  DECA = INCA, ENTA = INCA, ENNA = INCA,
  DEC1 = INC1, ENT1 = INC1, ENN1 = INC1,
  DEC2 = INC2, ENT2 = INC2, ENN2 = INC2,
  DEC3 = INC3, ENT3 = INC3, ENN3 = INC3,
  DEC4 = INC4, ENT4 = INC4, ENN4 = INC4,
  DEC5 = INC5, ENT5 = INC5, ENN5 = INC5,
  DEC6 = INC6, ENT6 = INC6, ENN6 = INC6,
  DECX = INCX, ENTX = INCX, ENNX = INCX,
};

#define AS_INT(w) (*((uint32_t*)&(w)))
#define RANGE(left, right) (8*(left) + (right))

Word PackInstruction(Instruction inst);
Instruction UnpackInstruction(Word word);
void PrintWord(const char* description, Word word);

#endif
