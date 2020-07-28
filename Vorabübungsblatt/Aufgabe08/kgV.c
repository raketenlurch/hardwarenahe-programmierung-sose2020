/* kgV.c */
#include <stdio.h>

int ggT(int a, int b);
int kgV(int a, int b);

int main() {
  int zahl1, zahl2, ergebnis;

  printf("Bitte geben Sie zwei Zahlen an.\n");
  printf("Zahl 1: ");
  scanf("%i", &zahl1);
  printf("Zahl 2: ");
  scanf("%i", &zahl2);
  ergebnis = kgV(zahl1, zahl2);
  printf("Das kleinste gemeinsame Vielfache von %i und %i ist %i.\n", zahl1, zahl2, ergebnis);
  return 0;
}

int ggT(int a, int b) {
  if (a == 0) {
    return 0;
  }
  while (b != 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return a;
}

int kgV(int a, int b) {
  int ggt, ergebnis;

  ggt = ggT(a, b);
  ergebnis = (a / ggt) * b;
  return ergebnis;
}
