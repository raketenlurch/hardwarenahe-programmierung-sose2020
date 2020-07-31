/* Quersumme.c */
#include <stdio.h>

int eingabe();
int quersumme(int a);

int main() {
  int input = eingabe();
  int ergebnis = quersumme(input);

  printf("Die Quersumme von %i ist %i.\n", input, ergebnis);
  return 0;
}

int eingabe() {
  int zahl;

  printf("Bitte geben Sie eine Zahl ein: ");
  scanf("%i", &zahl);
  return zahl;  
}

int quersumme(int a) {
  int sum = 0;
  while (a != 0) {
    sum = sum + (a%10);
    a = a/10;
  }
  return sum;
}
