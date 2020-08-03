/* even.c */
#include <stdio.h>

int even(int a);

int main() {
  int eingabe;

  printf("Bitte geben Sie eine Zahl ein: ");
  scanf("%i", &eingabe);

  if (even(eingabe) == 1) {
    printf("%i ist gerade.\n", eingabe);
  } else if (even(eingabe) == 0) {
    printf("%i ist ungerade.\n", eingabe);
  }
  return 0;
}

int even(int a) {
  if (a%2 == 0) {
    return 1;
  } else {
    return 0;
  }
}
