/* Swap.c */
#include <stdio.h>

void swap(int* a, int* b);

int main() {
  int zahl1 = 5;
  int zahl2 = 10;

  printf("1. Zahl: %i, 2. Zahl: %i\n", zahl1, zahl2);
  swap(&zahl1, &zahl2);
  printf("1. Zahl: %i, 2. Zahl: %i\n", zahl1, zahl2);
  return 0;
}

void swap(int* a, int* b) {
  int* tmp = 0;
  tmp* = a*;
  a* = b*;
  b* = tmp*;

  //int* tmp = a*;
  //a* = b*;
  //b* = tmp*;
}
