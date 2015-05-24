#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "M.h"

void generate_array(int array[], int size) {
  for (int i = 0; i < size; i++) array[i] = rand() % 1000;
}

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) printf("%d ", array[i]);
  printf("\n");
}

void mystery() {
  int X[100], r1, r2, rA, rX;
  generate_array(X, 100);  // Generate data instead of reading from device
  r1 = 100;
  do {
    r2 = MAXIMUM(X, r1);  // 1H
    rA = X[r2];
    rX = X[r1 - 1];
    X[r1 - 1] = rA;
    X[r2] = rX;
  } while (--r1 > 0);
  print_array(X, 100);
}

int main() {
  srand(time(NULL));
  mystery();
}
