# Aufgabe 2: Fehlersuche

- Bestimmen und korrigieren Sie vier Fehler im folgenden Programm:

```C
#include <stdio.h>
int main() {
  /* local variable definition */
  int a == 10;
  int b = 15
  while( a < 20) {
    if ((a + b) = 15) {
      printf("the sum of a and b: %d\n", a + b);
      break;
    }
    printf("value of a: %d\n", a)
    a++;
    /* decrement b by 2 */
    b = -2;
  }
  return 0;  
}
```

- Nach wie vielen Iterationen gibt das Programm folgende Meldung aus?

```C
the sum of a and b: 15
```
