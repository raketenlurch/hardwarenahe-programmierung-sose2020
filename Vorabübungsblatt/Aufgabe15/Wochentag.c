/* Wochentag.c */
#include <stdio.h>

int main(void) {
  int day, i;

  printf("Bitte geben Sie eine Zahl zwischen 1 und 365 ein: ");
  scanf("%i", &day);

  i = day % 7;
  switch(i) {
    case 1:  printf("Der %i. Tag im Jahr ist ein Donnerstag.\n", day);
             break;
    case 2:  printf("Der %i. Tag im Jahr ist ein Freitag.\n", day);
             break;
    case 3:  printf("Der %i. Tag im Jahr ist ein Samstag.\n", day);
             break;
    case 4:  printf("Der %i. Tag im Jahr ist ein Sonntag.\n", day);
             break;
    case 5:  printf("Der %i. Tag im Jahr ist ein Montag.\n", day);
             break;
    case 6:  printf("Der %i. Tag im Jahr ist ein Dienstag.\n", day);
             break;
    default: printf("Der %i. Tag im Jahr ist ein Mittwoch.\n", day);
             break;
  }
  return 0;
}
