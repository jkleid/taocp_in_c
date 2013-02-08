int MAXIMUM(const int* X, int n)
{
  int k, j, m;

// INIT:
  k = n-1;
  goto CHANGEM;
  do {
// LOOP:
    if (m < X[k]) {
CHANGEM:
      j = k;
      m = X[k];
    }
    k--;
  } while (k >= 0);
// EXIT:
  return j;
}
