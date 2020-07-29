/* Tierkreiszeichen.c */
#include <stdio.h>

int main() {
  int year, i;

  printf("Bitte geben Sie ein Jahr ein: ");
  scanf("%i", &year);

  i = year % 12;
  switch (i) {
    case 1:  printf("Das Tierkreiszeichen für %i ist Hahn.\n", i);
             break;
    case 2:  printf("Das Tierkreiszeichen für %i ist Hund.\n", i);
             break;
    case 3:  printf("Das Tierkreiszeichen für %i ist Schwein.\n", i);
             break;
    case 4:  printf("Das Tierkreiszeichen für %i ist Ratte.\n", i);
             break;
    case 5:  printf("Das Tierkreiszeichen für %i ist Büffel.\n", i);
             break;
    case 6:  printf("Das Tierkreiszeichen für %i ist Tiger.\n", i);
             break;
    case 7:  printf("Das Tierkreiszeichen für %i ist Hase.\n", i);
             break;
    case 8:  printf("Das Tierkreiszeichen für %i ist Drache.\n", i);
             break;
    case 9:  printf("Das Tierkreiszeichen für %i ist Schlange.\n", i);
             break;
    case 10: printf("Das Tierkreiszeichen für %i ist Pferd.\n", i);
             break;
    case 11: printf("Das Tierkreiszeichen für %i ist Schaf.\n", i);
             break;
    default: printf("Das Tierkreiszeichen für %i ist Affe.\n", i);
             break;
  }
  return 0;
}
