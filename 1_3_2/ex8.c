#include <stdio.h>

void print_line(int array[], int length)
{
  for(int i=0; i<length; i++) {
    if (array[i]) printf("%05X", array[i]);
    else printf("     ");
  }
  printf("\n");
}

void mystery()
{
  int buffer[3000];
  int r1, r2, r3, rX;

  r1 = 1;               // 1H
  r2 = 0;
  rX = 0xAAAAA;

  do {
    r3 = r1;            // 2H
    do {
      buffer[r2++] = 0; // 3H
    } while (--r3 > 0);
    buffer[r2++] = rX;
  } while (++r1 < 75);
  r2 = -2400;
  do {
    print_line(buffer + 2400 + r2, 24);
    r2 += 24;
  } while (r2 < 0);
}

int main()
{
  mystery();
}
