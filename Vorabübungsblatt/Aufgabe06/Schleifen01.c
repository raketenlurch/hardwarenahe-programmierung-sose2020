/* Schleifen01.c */
#include <stdio.h>

int main() {
  int sum;

  for (int i=0; i<=1000; i++) {
    sum = sum + i;
  }

  printf("Die Summe aller Zahlen zwischen 1 und 1000 ist %d.\n", sum);
  return 0;
}
