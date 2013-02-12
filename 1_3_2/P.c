#include <stdio.h>

void PRIMES(int l, int prime[])
{
  int j, n, k, r, q;

  j = 0;                         // P1
  n = 3;
  prime[0] = 2;
  while(1) {
    prime[++j] = n;              // P2
    if (j == l) return;          // P3
P4: n += 2;                      // P4
    for(k=1;;k++) {              // P5;;P8
      q = n / prime[k];          // P6
      r = n % prime[k];
      if (r == 0) goto P4;       // n is not prime
      if (q <= prime[k]) break;  // P7; n is prime
    }
  }
}


/* Separate print function, to make it easier to test primes generation.
 *
 * Note the use of two buffers is completely unnecessary in modern C code,
 * and results in some confusing code, but it was present in the original MIXAL
 * program.
 *
 * Also, the C code would be more straight-forward if the primes on each line
 * were populated in normal order, instead of reverse order.
 */
void PRINTPRIMES()
{
  const char * title = "FIRST FIVE HUNDRED PRIMES";
  int primes[500];
  char buffer[2][50 + sizeof(char*)];
  int m;
  char* b;

  *(char**)&buffer[0][50] = &buffer[1][45];
  *(char**)&buffer[1][50] = &buffer[0][45];
  PRIMES(500, primes);
  printf("%s\n", title);   // P9
  b = &buffer[0][45]; 
  m = -50;
  do {
    m += 501;              // P10
    do {
      sprintf(b, "%04d", primes[m-1]);
      b[4] = ' ';          // Replace null terminator with a space
      b -= 5;
      m -= 50;
    } while(m > 0);
    b[54] = '\0';          // Put null terminator back at end of string
    printf("%s\n", b + 5); // P11
    b = *(char**)&b[55];   // Buffer swap
  } while(m < 0);
}
