int MAXIMUM_LITERAL(const int* X, int n) {
  int j, k, m;

INIT:
  k = n;
  goto CHANGEM;
LOOP:
  if (m >= X[k]) goto M5;
CHANGEM:
  j = k;
  m = X[k];
M5:
  k--;
  if (k > 0) goto LOOP;
  return j;
}

/*
 * Adapater to convert the array from zero based to one based,
 * and convert the result back to zero based.
 */
int MAXIMUM(const int* X, int n) { return MAXIMUM_LITERAL(X - 1, n) - 1; }
