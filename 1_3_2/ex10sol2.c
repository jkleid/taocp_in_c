int* Saddle(int matrix[9*8])
{
  int CMAX[8];
  int* a10 = matrix - 1;
  int col; // r1
  int pos; // r2
  int max; // rX; maximum value in current column
  int min_max; // rA; minimum of the maximums
  int* saddle; // r1
  int row_start; // r3

// Phase 1:
  col = 8;
  do {
    pos = 9*8-8 + col;
    goto INIT_MAX;
    do {
      if (max < a10[pos]) {
INIT_MAX:
        max = a10[pos];
      }
      pos -= 8;
    } while (pos > 0);
    CMAX[pos+7] = max;
    if (pos == 0)
      goto INIT_MIN_MAX;
    if (min_max > CMAX[pos+7]) {
INIT_MIN_MAX:
      min_max = CMAX[pos+7];
    }
  } while(--col > 0);

// Phase 2:
  row_start = 9*8-8;
  do {
    pos = row_start+8;
    col = 8;
    do {
      if (min_max > a10[pos])
        goto NO;
      if ((min_max == a10[pos]) && (min_max == CMAX[col-1]))
        saddle = &a10[pos];
      pos--;
    } while (--col > 0);
    return saddle;
NO:
    row_start -= 8;
  } while (row_start > 0);
  return 0;
}
