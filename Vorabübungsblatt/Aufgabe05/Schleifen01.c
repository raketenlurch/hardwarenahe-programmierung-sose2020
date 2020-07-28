/* Schleife01.c */
#include <stdio.h>

int main() {
  int sum;

  for (int i=0; i<=100; i++) {
    sum = sum + i;
  }

  printf("Die Summer aller Zahlen von 1 bis 100 ist %d.\n", sum);
  return 0;
}
