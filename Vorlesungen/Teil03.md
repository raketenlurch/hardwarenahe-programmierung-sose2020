# Hardwarenahe Programmierung - 3. Teil

## Motivation
@import "Bilder/Teil03/Motivation01.png"

## Inhalt
1. Funktionen
2. Ausblick
3. Strings in C

## 1. Funktionen
- Rücksprungadesse
- Parameterübergabe
- Lokale Variablen
- Register und Funktionen
- Aufruf einer C-Funktion

### Funktionen - Motivation
Aus höheren Programmiersprachen kennen wir:
- Variablen
- Verzweigungen
- Schleifen
- Funktionen
- Bibliotheken

**Sie sind gefragt!**
Welche dieser Teile können Sie in Assembler bereits verwenden?

### Fahrplan Funktionen
- drei Hauptprobleme
    - Rücksprungadresse merken
    - Parameterübergabe regeln
    - Übergabe des Rückgabewertes regeln
- Wir betrachten die C-Aufrufkonvention (C Calling Convention)

### Erste Idee
- Funktionsaufruf?
    - *jmp label*
- Problem?
    - Rücksprungadresse
- Idee?
    - Adresse im Register speichern
- Aber?
    - umständlich
    - unintuitiv
    - fehleranfällig
    - **Rekursion???**

### Rücksprungadresse: Lösung
- Rücksprungadresse auf den Stack
- Also:
@import "Bilder/Teil03/RücksprungadresseLösung01.png"

### Rücksprungadresse: call und ret
- Funktionsaufruf: *call*
- Rückkehr: *ret*
- Wichtig: ESP muss korrekt sein
    - daher besondere Vorsicht bei Stackverwendung

### Beispiel: Funktionsaufrufe
**Sie sind gefragt!**
Wie wollen eine Funktion *int max()* schreiben, die zwei Parameter (Integer-Zahl)
als Eingabe erwartet und die größere Zahl anschließend als Ergebnis zurückgibt.
Worauf müssen wir achten?

### Parameterübergabe
- Übergabe der Parameter über den Stack
- Ablauf:
    1. Parameter auf den Stack legen
    2. Funktion aufrufen
    3. in der Funktion mit den Parameteren arbeiten
    4. Rückgabe bei Integern über eax
    5. Funktion kehrt zurück
    6. Aufrufer räumt auf.

### Beispiel: Parameterübergabe
**Neue Hausaufgabe**
Wir schreiben *int max(int a, int b)* nach C-Aufrufkonventionen.

### Lokale Variablen
- Erinnerung: lokale Variablen liegen auch auf dem Stack
- Problem?
    - ESP kann sich verschieben
    - Wo liegen dann die lokalen Variablen?
- Lösung?
    - Extended Base Pointer (EBP)
    - markiert Beginn Stackframe
    - muss gesichert werden

### Beispiel: lokale Variablen
@import "Bilder/Teil03/BeispielLokaleVariablen01.png"
@import "Bilder/Teil03/BeispielLokaleVariablen02.png"
@import "Bilder/Teil03/BeispielLokaleVariablen03.png"
@import "Bilder/Teil03/BeispielLokaleVariablen04.png"
@import "Bilder/Teil03/BeispielLokaleVariablen05.png"
@import "Bilder/Teil03/BeispielLokaleVariablen06.png"
@import "Bilder/Teil03/BeispielLokaleVariablen07.png"

### Vereinfachung: enter/leave
- *enter op1, op2* entspricht Prolog:
@import "Bilder/Teil03/VereinfachungEnterLeave01.png"
- *leave* entspricht Epilog:
@import "Bilder/Teil03/VereinfachungEnterLeave02.png"
- Achtung, manchmal langsamer!

### Ein letzter wichtiger Punkt
**Sie sind gefragt!**
Was passiert, wenn wir Register in einer Funktion verwenden und anschließend
zurückspringen?

### Retten von Registern
- viele Register müssen ihren Wert nach Funktionsrückkehr noch haben
- Unterstützt durch *pusha* und *popa*:
    - *pusha* schreibt die entsprechenden Register
    - *popa* holt die Register vom Stack

### Zusammenfassung Stack Frame
- Stackbereich, der zu einer Funktion gehört
- kurz: EBP bis ESP
@import "Bilder/Teil03/ZusammenfassungStackFrame01.png"

### Aufruf einer C-Funktion
- Aufruf direkt von Assembler möglich
- Parameter in **umgekehrter** Reihenfolge auf den Stack
    - Warum?
    - Hinweis: *printf("x = %d\n",100);*
- Rückgabe: erfolgt bei Integer-Werten über eax
- Achtung Windows: Unterstrich (\_) nicht vergessen

### Beispiel C-Funktionen
**Sie sind gefragt!**
Haben Sie eine Idee, wo Sie (implizit) bereits C-Funktionen verwenden?

### Hands On
```C
my_mult(int a, int b) {
  int result = 0;
  for (int i = 0; i < a; i++) {
    result += b;
  }
  return result;
}
```

**Neue Hausaufgabe**
Setzen Sie diese Funktion in Assembler um und beachten Sie alles, was Sie zu
C-Calling Conventions gelernt haben.

## 2. Ausblick
- Von C zu Assembler
- Buffer Overflow Exploits

### Einmal anders herum:
@import "Bilder/Teil03/EinmalAndersHerum01.png"

### Beispiel: Von C zu Assembler
```C
#include <stdio.h>

int main() {
  printf("Hello World!\n");
  return 0;
}
```
- Übersetzen mit *gcc hello.c -S*
- Ergebnis: *hello.s*

### Assembler-Code
@import "Code/hello.s"

### Handoptimierte Version
@import "Bilder/Teil03/HandoptimierteVersion01.png"
Unfair! Optimierung automatisch mit *gcc -O<Grad> hello.c*
Beispiel: *gcc -O3 hello.c*

### Disassembler
- Maschineninstruktionen $\rightarrow$ Assemblercode
- Aber: Labels und Kommentare sind im Maschinencode (i.d.R.) nicht mehr enthalten
- Disassemblieren mit gdb:
    - Kompilieren mit *-ggdb*
    - gdb starten: *gdb programmname*
    - disassemblieren: *disas funktionsname*
    - Beenden: *quit*

### Disassemblieren mit gdb
@import "Bilder/Teil03/DisassemblierenMitGdb01.png"

### Buffer Overflow Exploits - Hacken auf dem Stack
- Ausnutzung von Pufferüberläufen um (illegitim) Privilegien zu erlangen (oder
  die Funktion zu stören).
- Idee:
    - Programm nimmt Eingaben entgegen
    - Eingabe wird in Variable fester Größe gespeichert
    - Länge der Eingabe wird nicht überprüft (Programmierfehler!)
    - Eingabe zu lang: reservierter Speicherbereich wird verlassen
        - Überschreiben von Daten auf dem Stack

**Sie sind gefragt!**
Was kann jetzt passieren?

## 3. Strings in C

### Strings
**Sie sind gefragt!**
Was wissen Sie über Strings (in C)?

### Typische Fallen
- nur bis zum ersten Whitespace eingelesen
- 0-Bytes überschrieben
- keine Nullterminierung

### Aufgabe
**Neue Hausaufgabe**
Schreiben Sie Ihre eigene Funktion um zwei Strings zu konkatenieren. Verwenden
Sie keine Bibliotheksfunktionen.
