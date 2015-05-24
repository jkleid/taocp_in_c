#include <stdio.h>

int* Saddle(int matrix[9 * 8]) {
  int CMAX[8];
  int* a10 = matrix - 1;
  int col;        // r1
  int pos;        // r2
  int max;        // rX; maximum value in current column
  int min_max;    // rA; minimum of the maximums
  int* saddle;    // r1
  int row_start;  // r3

  // Phase 1:
  col = 8;
  do {
    pos = 9 * 8 - 8 + col;
    goto INIT_MAX;
    do {
      if (max < a10[pos]) {
      INIT_MAX:
        max = a10[pos];
      }
      pos -= 8;
    } while (pos > 0);
    CMAX[pos + 7] = max;
    if (pos == 0) goto INIT_MIN_MAX;
    if (min_max > CMAX[pos + 7]) {
    INIT_MIN_MAX:
      min_max = CMAX[pos + 7];
    }
  } while (--col > 0);

  printf("min_max=%d\n", min_max);
  for (int i = 0; i < 8; i++) printf("CMAX[%d] = %d\n", i, CMAX[i]);

  // Phase 2:
  row_start = 9 * 8 - 8;
  do {
    pos = row_start + 8;
    col = 8;
    do {
      printf("a[%d] = %d\n", pos, a10[pos]);
      if (min_max > a10[pos]) goto NO;
      if ((min_max == a10[pos]) && (min_max == CMAX[col - 1]))
        saddle = &a10[pos];
      pos--;
    } while (--col > 0);
    printf("Saddle: %ld\n", saddle - a10);
    return saddle;
  NO:
    row_start -= 8;
    printf("NO. row_start=%d\n", row_start);
  } while (row_start >= 0);
  printf("No Saddle.\n");
  return 0;
}
