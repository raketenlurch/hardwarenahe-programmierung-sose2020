#include <stdio.h>
#include <string.h>
#include "caesar_minus2_gross.h"

void caesar(char *klartext) {
  char ch, c;
  int i = 0, key = 2;

  for (i = 0; klartext[i] != '\0'; i++) {
    ch = klartext[i];

    if (ch >= 'C' && ch <= 'Z') {
      ch = ch - key;
      klartext[i] = ch;
    } else if (ch == 'A' || ch == 'B') {
      c = ch - 'A';
      c = c + 24;
      c = c % 26;
      klartext[i] = c + 'A';
    }
  }
}

int encode_and_compare(char *clearstring, char *string_to_encode) {
  if (strcmp(clearstring, string_to_encode)) {
    return 1;
  } else {
    return 0;
  }
}
