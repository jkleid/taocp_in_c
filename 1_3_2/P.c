void PRIMES(int l, int prime[])
{
  int j, n, k, r, q;
  j = 0;
  n = 3;
  prime[0] = 2;
  while(true) {
    prime[++j] = n;              // P2
    if (j == l) return;          // P3
P4:
    n += 2;
    for(k=1;;k++) {              // P5;;P8
      q = prime[k] / n;          // P6
      r = prime[k] % n;
      if (r == 0) goto P4;
      if (q <= prime[k]) break;  // P7
    }
}

void PRINTPRIMES(int l, int prime[])
{

}
