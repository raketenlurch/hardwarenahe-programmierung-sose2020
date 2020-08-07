/* main.c */
#include <stdio.h>
#include "strings_verbinden.h"

int main() {
  char ganzerString[20];
  char hello[] = "Hello";
  char world[] = "World";

  strings_verbinden(ganzerString, hello, world);
  return 0;
}
