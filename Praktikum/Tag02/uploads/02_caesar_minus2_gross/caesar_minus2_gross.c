#include <stdio.h>
#include <string.h>
#include "caesar_minus2_gross.h"

void caesar(char *klartext) {
  char ch;
  int i = 0, key = 2;

  // Prüfen, ob char ein Großbuchstabe ist
  // wenn nein, char in einen Großbuchstaben umwandeln
  // String encrypten
  // encrypteten String ausgeben

  for (i = 0; klartext[i] != '\0'; i++) {
    ch = klartext[i];

    if (ch >= 'C' && ch <= 'Z') {
      ch = ch - key;

      klartext[i] = ch;
    } else if (ch > 'Z') {
      ch = ch - 'Z' + 'A' - 1;
      klartext[i] = ch;
    } else if (ch == 'B') {
      ch = 'Z';
      klartext[i] = ch;
    } else if (ch == 'A') {
      ch = 'Y';
      klartext[i] = ch;
    }
  }
  printf("Encrypted message: %s\n", klartext);
}

int encode_and_compare(char *clearstring, char *string_to_encode) {

}
