#include <stdio.h>
#include "strings_verbinden.h"

void strings_verbinden(char *zusammen, char *string1, char *string2) {
  int i = 0, j = 0;

  // Insert the first string in the new string
  while (string1[i] != '\0') {
    zusammen[j] = string1[i];
    i++;
    j++;
  }

  // Insert the second string in the new string
  i = 0;
  while (string2[i] != '\0') {
    zusammen[j] = string2[i];
    i++;
    j++;
  }
  zusammen[j] = '\0';
  // Print concateneted String
  printf("Der zusammengesetzte String lautet: %s\n", zusammen);
}
