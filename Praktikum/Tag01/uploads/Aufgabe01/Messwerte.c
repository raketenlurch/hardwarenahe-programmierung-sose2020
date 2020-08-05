/* Messwerte.c */
#include <stdio.h>
#define LENGTH 12

int main() {
  int i;
  double messwerte[LENGTH];

  // Eingabe
  printf("Bitte geben Sie 12 Messwerte an: ");
  for (i=0; i<LENGTH; i++) {
    printf("%d. Zahl: ", i+1);
    scanf("%le", &messwerte[i]);
  }

  // Ausgabe
  printf("Sie haben eingegeben: ");
  for (i=0; i<LENGTH; i++) {
    printf("%d. Zahl: %f\n", i, *(messwerte + i));
  }
  return 0;
}
