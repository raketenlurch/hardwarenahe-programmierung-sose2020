/* Schleifen02.c */
#include <stdio.h>

int main() {
  int sum;

  for (int i=0; i<=1000; i++) {
    if (i%4 == 0) {
      sum = sum + i;
    }
  }

  printf("Die Summe aller durch 4 teilbaren Zahlen zwischen 1 und 1000 ist %d.\n", sum);
  return 0;
}
