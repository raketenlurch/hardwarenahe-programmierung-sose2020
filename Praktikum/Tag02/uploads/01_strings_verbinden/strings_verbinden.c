#include <stdio.h>
#include "strings_verbinden.h"

void strings_verbinden(char *zusammen, char *string1, char *string2) {
  int pos_zusammen = 0;

  // Insert the first string in the new string
  for (int pos_string1 = 0; string1[pos_string1] != '\0';) {
    zusammen[pos_zusammen] = string1[pos_string1];
    pos_string1++;
    pos_zusammen++;
  }

  // Insert the second string in the new string
  for (int pos_string2 = 0; string2[pos_string2] != '\0';) {
    zusammen[pos_zusammen] = string2[pos_string2];
    pos_string2++;
    pos_zusammen++;
  }

  // Print concateneted String
  printf("Der zusammengesetzte String lautet: %s\n", zusammen);
}
