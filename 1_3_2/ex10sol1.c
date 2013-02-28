int* Saddle(int matrix[9*8])
{
  int list[8];
  int idx; // r1
  int col; // r2
  int pos; // r3
  int elem; // rX
  int* a10 = matrix - 1;
  idx = 9*8;     // START
  do {           // ROWMIN
    col = 8;
    do {
      elem = a10[idx];     // 2H
      pos = 0;
      do {
        list[pos++] = col; // 4H
        do {
          idx--;           // 1H
          if (--col == 0)
            goto COLMAX;
        } while(elem < a10[idx]); // 3H
      } while(elem == a10[idx]);
    } while(elem > a10[idx]);
COLMAX: // elem is now the minimum value of the row just considered.
    do {
      col = list[pos-1];
      col += 9*8-8;
      do {
        if (elem < a10[col])  // 1H
          goto NO;
      } while((col-=8) > 0);
      return &a10[col+8];     // YES
NO:   --pos;
    } while (pos > 0);
  } while (idx > 0);
  return 0;
}
