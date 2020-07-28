/* prime-number.c */
#include <stdio.h>

int eingabe();
int is_Prime(int a);

int main() {
  int input = eingabe();

  if (is_Prime(input)) {
    printf("%i ist eine Primzahl.\n", input);
  } else {
    printf("%i ist keine Primzahl.\n", input);
  }
  return 0;
}

int eingabe() {
  int x;

  printf("Bitte geben Sie eine Zahl ein: ");
  scanf("%i", &x);
  return x;
}

int is_Prime(int a) {
  if (a == 1) {
    return 0;
  }
  int i = 2;
  while (i < a) {
    if (a%i == 0) {
      return 0;
    }
    i++;
  }
}
