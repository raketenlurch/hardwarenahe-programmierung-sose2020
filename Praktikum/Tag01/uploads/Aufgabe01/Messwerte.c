/* Messwerte.c */
/*#include <stdio.h>
#define MAX 12

int main() {
  int i;
  double messwerte[MAX];

  printf("Bitte geben Sie 12 Zahlen ein: ");
  for (i = 0; i < MAX; i++) {
    printf("%d. Zahl: ", i+1);
    scanf("%le", &messwerte[i]);
  }

  printf("Sie haben eingegeben: ");
  for (i = 0; i < MAX; i++) {
    printf("%d", i);
  }
  printf("\n");
  return 0;
}
*/

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
    printf("%d. Zahl: %f", i, *(messwerte + i));
  }
  return 0;
}
