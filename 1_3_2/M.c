int MAXIMUM(const int* X, int n)
{
  int k, j, m;

  k = n-1;          // INIT
  goto CHANGEM;
  do {              // LOOP
    if (m < X[k]) {
CHANGEM:
      j = k;
      m = X[k];
    }
    k--;
  } while (k >= 0);
  return j;         // EXIT
}
