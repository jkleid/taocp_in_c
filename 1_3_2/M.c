int MAXIMUM(const int* X, int n) {
  int j, k, m;

  k = n - 1;  // INIT
  goto CHANGEM;
  do {  // LOOP
    if (m < X[k]) {
    CHANGEM:
      j = k;
      m = X[k];
    }
  } while (--k >= 0);
  return j;  // EXIT
}
