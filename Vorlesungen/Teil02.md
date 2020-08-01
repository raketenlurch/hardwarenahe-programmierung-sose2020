# Hardwarenahe Programmierung - 2. Teil

## Inhalt
1. Sprünge
2. Der Stack
3. Pointer
4. Dynamische Speicherverwaltung

## 1. Sprünge
- Unbedingte Sprünge
- Bedingte Sprünge

### Unbedingte Sprünge
- bisher: lineare Ausführung von Instruktionen
- nun: Sprünge zu Adressen/Label
@import "Bilder/Teil02/UnbedingteSprünge01.png"
- oft am Ende von if/else-Zweigen

### Sprünge über Flags (direkt)
- Realisierung von Verzweigungen, Schleifen
- bedingt durch Flags (EFLAGS-Register)

### Frage
Bedingte Sprünge abhängig von jeweils einem Flag:
- jz/jnz: Springe wenn Z-Flag (nicht) gesetzt ist
- jo/jno: Springe wenn O-Flag (nicht) gesetzt ist
- jc/jnc: Springe wenn C-Flag (nicht) gesetzt ist

**Sie sind gefrage!**
Wie können Sie mit den genannten Sprüngen (jz, jo, jc, jnz, jno, jnc) und den
bekannten arithmetischen Operationen die Vergleiche =, < und > realisieren?
Betrachten Sie nur vorzeichenlose Zahlen.

### If
**Live**
```C
// read two numbers a and b
// store a in eax and b in ebx
if (a == b) {
  printf("a ist gleich b\n");
} else {
  printf("a ist ungleich b\n");
}
```

### Vergleiche
- *cmp op1, op2*
- berechnet *op1 - op2*, speichert nur EFALGS
- vorzeichenlose Zahlen:
    - $=$ *je*, *jne*
    - $<$ *jb*, *jnae*
    - $\leq$ *jbe*, *jna*
    - $>$ *ja*, *jnbe*
    - $\geq$ *jae*, *jnb*
- beim Vergleich vorzeichenbehafteter Zahlen
    - **equal** $\rightarrow$ **equal**
    - **above** $\rightarrow$ **greater**
    - **below** $\rightarrow$ **less**
    - *je*, *jne*, *jl*, *jnge*, *jle*, *jng*, *jg*, *jnle*, *jge*, *jnl*

### While Schleife
**Neue Hausaufgabe**
Implementieren Sie (mit den bis hierher genannten Befehlen):
```C
int i = 10;
int sum = 0;
while (i > 0) {
  sum += i;
  i--;
}
```

### Schleifen - eleganter
- *loop label*
@import "Bilder/Teil02/SchleifenEleganter01.png"
- *loope label/loopz label*
@import "Bilder/Teil02/SchleifenEleganter02.png"
- *loopne label/loopnz label*
@import "Bilder/Teil02/SchleifenEleganter03.png"

### Beispiel: Schleifen
**C**
```C
int sum = 0;
for (int i = 10; i > 0; i--) {
  sum += i;
}
```

**Assembler**
@import "Bilder/Teil02/Assembler01.png"

## 2. Der Stack

### Der Stack 1
- Bisher:
    - alle Daten entweder in einem Register
    - ... oder in einem festen Speicherplatz
    - Problem: Funktionen (insb. rekursive)
- der Stack
    - spezieller Speicherbereich
    - Zugriff mittels *push* und *pop*
    - wächst nach unten (Addressierung!)
    - Nutzung spezieller Register: ESP und EBP

### Exkurs: Speicher
@import "Bilder/Teil02/ExkursSpeicher01.png"

### Der Stack 2
- ab 80386: 4 Byte Breite
- kürzere Daten möglich
- üblicherweise Ausrichtung an 4 Byte Grenzen
- ESP zeigt auf aktuellen (untersten) Stackeintrag

### Beispiel: elementare Stack-Instruktionen
@import "Bilder/Teil02/ElementareStackInstruktionen01.png"
@import "Bilder/Teil02/ElementareStackInstruktionen02.png"
@import "Bilder/Teil02/ElementareStackInstruktionen03.png"
@import "Bilder/Teil02/ElementareStackInstruktionen04.png"
@import "Bilder/Teil02/ElementareStackInstruktionen05.png"

## 3. Pointer
- Pointer: englisch für Zeiger
- Pointer speichert also eine Speicheradresse
- in C:
    - Angabe, auf welchen Datentyp der Pointer zeigt
    - z.B. *int * p;*
    - Dereferenzierungsoperator: * (Zugriff auf referenziertes Objekt)
    - Adressoperator: & (Zugriff auf Adresse eines Objekts)

### Beispiel: Pointer
@import "Bilder/Teil02/BeispielPointer01.png"
@import "Bilder/Teil02/BeispielPointer02.png"
@import "Bilder/Teil02/BeispielPointer03.png"
@import "Bilder/Teil02/BeispielPointer04.png"
@import "Bilder/Teil02/BeispielPointer05.png"

### Exkurs: gdb
**Neue Hausaufgabe**
Betrachten Sie das Pointerbeispiel im Debugger (gdb).

### Zeigerarithmetik
- "rechnen" mit Zeigern prinzipiell möglich
- aber gefährlich (!)
- zusammenhängende Speicherbereiche können so durchlaufen werden
```C
int a[10];
int *p = a;
for (int i = 0; i < 10; i++) {
  * (p+i) = i;
  printf("%i\n", * (p+i));
}
```

### Zeiger auf Zeiger
- Mehr als ein \* ?
    - \*\*: Zeiger auf Zeiger
    - \*\*\*: Zeiger auf Zeiger auf Zeiger
    - \*\*\*\*: ...
- z.B. für Realisierung mehrdimensionaler Arrays

**Sie sind gefragt!**
 Name    | Datentyp
---------|----------
 *i*     | *int \*\*i*
 *\*i*   |
 *i[2]*  |
 *\*\*i* |

### Typischer Fehler
**Sie sind gefragt!**
```C
#include <stdio.h>

int main() {
  int * p;
  * p = 5;
  printf("%i\n", * p);
  return 0;
}
```

### Lösung #1
Wir verwenden nur Pointer zu Variablen, die bereits angelegt wurden.
Aber:
- unnötig: Zugriff auf Adresse auch über Adressoperator möglich
- blöd, wenn wir Speicher innerhalb von Funktionen dauerhaft reservieren möchten

## 4. Dynamische Speicherverwaltung
- *malloc* und *free*
- Mögliche Implementierungen
- Beispiel: Mehrdimensionale Arrays

### Lösung #2
- Speicherreservierung zur Laufzeit
- Speicher wird im Heap reserviert, d.h. nicht im Stackframe einer Funktion (!)
@import "Bilder/Teil02/Lösung01.png"
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int * p = malloc(sizeof(int));
  * p = 5;
  printf("%i\n", * p);
  free(p);
  return 0;
}
```

### Manpage
**Neue Hausaufgabe**
War betrachten die manpage zu *malloc*.

### malloc und free zusammengefasst
malloc ...
- kann fehlschlagen (Rückgabe dann i.Allg. NULL)
- sollte in Kombination mit *sizeof()*-Operator verwendet werden
- Speicher wird nicht automatisch wieder freigegeben

free ...
- Aufruf mit Speicherbereichen, die vorab reserviert wurden
- Aufruf mit ungültigen Pointern führt zu Fehlern
- darf nicht mehrfach auf dem gleichen Pointer ausgeführt werden

### Der sizeof()-Operator
- liefert die Größe einer Variablen
- Verwendung typischerweise mit Datentypen
```C
int main() {
  printf("%li\n", sizeof(int));
  int a[10];
  printf("%li\n", sizeof(a));
  printf("%li\n", sizeof(a)/sizeof(int));
  int * b;
  printf("%li\n", sizeof(b));
  b = malloc(sizeof(int) * 10)
  printf("%li\n", sizeof(b));
  example_function(a);
}

void example_function(int a[]) {
  printf("%li\n", sizeof(a));
}
```

### Warum?
**Sie sind gefragt!**
Warum schreiben wir *malloc(sizeof(int))* und nicht *malloc(4)*?

### Typische Fehler
- Zeiger werden verschoben, der Speicher nicht freigegeben (Speicherleck!)
- Speicher wird mehrfach freigegeben (valgrind: double free)
- Freigabe von Speicher, der nicht über *malloc* reserviert wurde (valgrind:
  invalid free)
- Rückgabe von *malloc* wird nicht überprüft

### Ein bisschen Theorie
- Ziel: besseres Verständnis der Fehlerquellen
- Implementierung angelehnt an Kernighan & Ritchie: The C Programming Language,
  2nd Edition, Abschnitt 8.7
- zentrale Fragen:
    - Wie findet *malloc* einen freien Speicherbereich passender Größe?
    - Woher weiß *free*, wie groß der freizugebende Speicherblock ist?

### Die Free-Liste
- Idee: freien Speicher in zyklisch verketteter Liste verwalten
- Jeder freie/belegte Speicherblock bekommt einen Header:
    - Größe des Blocks
    - in Free-Liste: next-Zeiger
@import "Bilder/Teil02/FreeListe01.png"

### malloc - prinzipielles Vorgehen
1. Durchsuche die Free-Liste nach einem ausreichend großen Speicherblock.
    - **Fall 1: Es gibt einen Block genügender Größe**
        - Verwende der ersten gefundenen Block!
    - **Fall 2: Es gibt keinen Block, der groß genug ist**
        - Bitte das Betriebssystem um mehr Speicher!
2. Belege darin geforderte Menge Speicher und Platz für den Header
    - **Fall 1: Größe passt genau**
        - Passe Zeiger der Free-Liste an
    - **Fall 2: freier Block ist zu groß**
      Speicher hinten abschneiden $\rightarrow$ keine Änderung in der Free-Liste
        1. Größe im alten Header anpassen (alte Größe - Headergröße - Größe neuer
           Speicherblock)
        2. Neuen Header am Beginn des neuen Speicherblocks schreiben
3. Gebe einen Zeiger auf das erste Byte nach dem Header zurück
    - Aufrufer sieht den Header nicht!

### free
1. Durchsuche Free-Liste und finde die benachbarten freien Blöcke.
2. Prüpfe ob (min.) einer benachbart ist.
3. Fasse gegebenenfalls Blöcke zusammen.
    - Zusammengefasst wird rekursiv von hinten nach vorne.
    - Speichergrößen und Headergrößen dabei addieren.
4. Füge neuen freien Block in free-Liste ein.

### malloc/free-Beispiel 1
- 32 Byte großer Speicher, 1 Byte lange Adressen (0 - 31):
@import "Bilder/Teil02/MallocFreeBeispiel01.png"
- *p = malloc(6); \*p = FF 89 28 8D 42 E2;*
@import "Bilder/Teil02/MallocFreeBeispiel02.png"

### malloc/free-Beispiel 2
@import "Bilder/Teil02/MallocFreeBeispiel03.png"
- *q = malloc(7); \*q = 3E 7A 7C FF 9A B3 C0;*
@import "Bilder/Teil02/MallocFreeBeispiel04.png"

### malloc/free-Beispiel 3
@import "Bilder/Teil02/MallocFreeBeispiel05.png"
- *free(p);*
@import "Bilder/Teil02/MallocFreeBeispiel06.png"

### malloc/free-Beispiel 4
@import "Bilder/Teil02/MallocFreeBeispiel07.png"
- *r = malloc(2); \*r = BE EF*
@import "Bilder/Teil02/MallocFreeBeispiel08.png"

### malloc/free-Beispiel 5
@import "Bilder/Teil02/MallocFreeBeispiel09.png"
- *free(q);*
@import "Bilder/Teil02/MallocFreeBeispiel10.png"
- *free(q);*
@import "Bilder/Teil02/MallocFreeBeispiel11.png"

### malloc/free-Beispiel 6
@import "Bilder/Teil02/MallocFreeBeispiel12.png"
- *s = malloc(s); \*s = A7 AF C4 7F 03 90 CD 13 A0 F5 49 00*
@import "Bilder/Teil02/MallocFreeBeispiel13.png"

### malloc/free-Beispiel 7
@import "Bilder/Teil02/MallocFreeBeispiel14.png"
- *free(p)*
@import "Bilder/Teil02/MallocFreeBeispiel15.png"

### malloc/free-Beispiel 8
@import "Bilder/Teil02/MallocFreeBeispiel16.png"
- *\*s 8A C3 DF 56 15 5 FF 10 6E B7 C4 00*
@import "Bilder/Teil02/MallocFreeBeispiel17.png"

### malloc/free-Beispiel 9
@import "Bilder/Teil02/MallocFreeBeispiel17.png"
- *t = malloc(15); \* = 4B 61 74 61 73 74 72 6F 70 68 65 21 21 21 00*
@import "Bilder/Teil02/MallocFreeBeispiel18.png"

### Speicher reservieren
@import "Bilder/Teil02/SpeicherReservieren01.png"
@import "Bilder/Teil02/SpeicherReservieren02.png"
@import "Bilder/Teil02/SpeicherReservieren03.png"
@import "Bilder/Teil02/SpeicherReservieren04.png"

### Speicher freigeben - Häufigster Fehler
@import "Bilder/Teil02/SpeicherFreigebenHäufigsterFehler01.png"

### Speicher richtig freigeben
@import "Bilder/Teil02/SpeicherRichtigFreigeben01.png"
@import "Bilder/Teil02/SpeicherRichtigFreigeben02.png"
@import "Bilder/Teil02/SpeicherRichtigFreigeben03.png"

### Hausaufgaben
**Neue Hausaufgabe**
Verschaffen Sie sich einen Überblick über die Funktionen, die über die Bibliothek
string.h bereitgestellt werden.

**Neue Hausaufgabe**
Beschäftigen Sie sich damit, wir Strings in C gespeichert werden.
