/* Schleifen02.c */
#include <stdio.h>

int main() {
  int sum;

  for (int i=0; i<=100; i++) {
    if (i%2 == 0) {
      sum = sum + i;
    }
  }

  printf("Die Summe aller geraden Zahlen von 1 bis 100 ist %d.\n", sum);
  return 0;
}
