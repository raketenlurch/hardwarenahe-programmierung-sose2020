#include <stdio.h>
#include "simpleString.h"

int main() {
  char hello[] = {"hallo"};
  int length = 5;

  printf("%d\n", my_strlen(hello));
  printf("%d\n", is_string(hello, length));
  return 0;
}
