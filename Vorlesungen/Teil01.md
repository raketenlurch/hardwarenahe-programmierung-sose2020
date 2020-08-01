# Hardwarenahe Programmierung - 1. Teil

## Inhalt
1. Organisatorisches & Motivation
2. Einstieg
3. Grundlagen
4. Einfache Instruktionen
5. C-Einstieg
6. Codestil

## 1. Organisatorisches & Motivation

### Kurze Wiederholung: Lernziele
Aus den Modulhandbuch:
- einfache Assemblerprogramme in x86 Assembler entwickeln
- sich selbstständig Kenntnisse in einer neuen Programmiersprache aneignen
- Programme in der Programmiersprache C unter Berücksichtigung dynamischer
  Speicherverwaltung entwickeln
- Werkzeuge für typische Aufgaben bei der Programmierung (Speicherverwaltung,
  Build-Prozesse, Tests) verwenden

**Sie sind gefragt?**
Wofür brauchen Sie das, was Sie hier lernen?
- Im Studium?
- Im Berufsleben?
@import "Bilder/Teil01/Motivation01.png"

## 2. Einstieg
- Was ist Assemblerprogrammierung?
- Erstes Assembler-Beispiel

### Der Instruktionssatz
- Prozessoren stellen einen Instruktionssatz
- unabhängig vom Betriebssystem
- binär kodiert
- Beispiel:
    - $0000001111000011_{2}$ bzw. $03 C3_{16}$
    - IA-32 bzw. x86 (= 80x86 und Nachfolger) Befehl
    - addiert und speichert zwei Zahlen

### Problem
@import "Bilder/Teil01/Problem01.png"
@import "Bilder/Teil01/Problem02.png"

### Lösung: Symbolische Schreibweise
- Beispiel:
    - *add eax*, *ebx*
- allgemein: *<mnemonic> <operanden>*
- Der Assembler übersetzt dann Symbole in binäre Instruktionen

### Assembler
- eine Instruktion in symbolischer Schreibweise
    - eine Instruktion in binärer Schreibweise
- Ergebnis: Objektdatei (*.o*)
- die Objektdatei enthält Objektcode (bzw. Maschienencode)
    - Format ist architekturspezifisch

### Das ist...
- unübersichtlich
- mühsam und
- fehleranfällig

**Sie sind gefragt!**
Also warum tun wir uns das eigentlich an?

### Warum Assemblerprogrammierung?
1. Zur Optimierung von besonders kritischen und wichtigen Stellen eines Programms:
    - genaue Kontrolle über die verwendeten Instruktionen
    - Aber: Compiler werden immer besser!
2. Direkter Hardwarezugriff
    - Beispiele: MMX, 3DNow!, SSE, RdRand
    - Aber: Zunehmende Compilerunterstützung
3. Der wichtigste Grund hier: Verstehen, wie ein Computer arbeitet!

### Vergleich Hochsprachen/Assembler
- Kompilieren von Hochsprachen erzeugt auch Maschienencode:
    - Besonderheiten des Betriebssystems werden berücksichtigt
    - daher abhängig von Prozessor und Betriebssystem
- eine Anweisung in einer Hochsprache
    - viele Anweisungen in Maschienencode
- Parameter steuern
    - Optimierungsgrad
    - Berücksichtigung von Prozessorbesonderheiten
    - aber: keine vollständige Kontrolle
- Bei der Assemblerprogrammierung
    - genaue Kontrolle darüber, welche Instruktion erzeugt wird
    - sehr viel direktere und einfachere Übersetztung als beim Kompilieren

### "Der" Assembler
- viele verschiedene (z.B. NASM, MASM, gas)
- unterschiedliche doch häufig ähnliche Syntax
- teilweise Unterstützung eines Präprozessors (z.B. Makros)
- wir verwenden: NASM (Netwide Assembler)

### Einbetten in C
- Schreiben ganzer Programme in Assembler ist
    - sehr aufwändig
    - sehr fehleranfällig
- daher
    - einzelne Funktionen werden in Assembler geschrieben
    - Aufruf aus einer höheren Programmiersprache
- Vorgehen bei C (und in dieser Veranstaltung):
    - C-Programm mit Funktionsaufruf schreiben und kompilieren
        - *driver.c*
    - Assembler-Programm für diese Funktion schreiben und assemblieren
    - Linken der Objektdateien

### Regeln Assembler
- Einhaltung der Coderichtlinien (insb. das Kommentieren des Codes)
- Aufruf über *driver.c* von Paul A. Carter
- funktionsfähig unter Linux, 32 Bit

**Nutzer(innen) von Windoes/MacOS**
Lesen Sie selbstständig nach, welche Unteschiede dann, z.B. für das Kompilieren
und für Funktionsnamen, existieren! Die Unterschiede sind (bei dem was wir
machen) gering.

### driver.c
@import "Bilder/Teil01/driver01.png"
- Was passiert hier?

### Erstes Assembler-Beispiel
@import "Bilder/Teil01/ErstesAssemblerBeispiel01.png"
@import "Bilder/Teil01/ErstesAssemblerBeispiel02.png"
@import "Bilder/Teil01/ErstesAssemblerBeispiel03.png"
@import "Bilder/Teil01/ErstesAssemblerBeispiel04.png"
@import "Bilder/Teil01/ErstesAssemblerBeispiel05.png"
@import "Bilder/Teil01/ErstesAssemblerBeispiel06.png"

**Live**
1. assemblieren
2. kompilieren
3. linken
4. ausführen

## 3. Grundlagen
- Programmaufbau in NASM
- Instruktionen

### Register
- Prozessoren stellen **Register** bereit
    - Speicherzellen, besonders schneller Zugriff
    - teilweise bestimmte Aufgaben
- Quelle/Ziel von Operationen
- Beispiel:
@import "Bilder/Teil01/Register01.png"

### Register der IA-32-Architektur 1
- Allgemeine 32-Bit Register: EAX, EBX, ECX, EDX
    - EAX: Berechnungen
    - EBX: Zeiger (Pointer)
    - ECX: Schleifen
    - EDX: Mult/Div, 64 Bit mit EAX
- historisch: 16- und 8-Bit-Aufteilung (286, 8088)
- EBP, ESP: Base/Stack-Pointer
- EFLAGS: Prozessorstatuswort
- Außerdem:
    - ESI, EDI: String-Operationen
    - CS-GS: Speicher-Segement-Zugriff
    - EIP: Instruction Counter
- inzwischen meist 64-Bit Register
- uns reichen 32-Bit
@import "Bilder/Teil01/Register02.png"

### EFLAGS-Register
- Informationen über letzte Berechnungen
- über sogenannte **Flags**
- jedes Bit/Flag hat eine eigene Bedeutung
- Beispiele:
    - Sign Flag (S)
    - Zero Flag (Z)
    - Carry Flag (C)
    - Overflow Flag (o)
- Abfrage über spezielle Instruktionen

### Überblick
- Ein Programm kann aus mehreren Übersetzungseinheiten bestehen
- Eine Übersetzungseinheit wird Modul genannt
- Ein Modul kann die folgenden Elemente beinhalten:
    - Segmentidentifikation
    - Assembler-Instruktionen
    - Pseudo-Instruktionen
    - Präprozessor-Anweisungen
    - Direktiven an den Assembler (beinhaltet Segmentidentifikation)
- Dies ist assemblerspezifisch (also hier für NASM), von den
  Grundzügen her aber typisch für x86-Assembler

### Typischer Aufbau
@import "Bilder/Teil01/TypischerAufbau01.png"
@import "Bilder/Teil01/TypischerAufbau02.png"
@import "Bilder/Teil01/TypischerAufbau03.png"
@import "Bilder/Teil01/TypischerAufbau04.png"
@import "Bilder/Teil01/TypischerAufbau05.png"
@import "Bilder/Teil01/TypischerAufbau06.png"

### Assembler-Instruktion
- Aufbau allgemein (i.Allg. genau eine Zeile):
    - *<label>: <instruction> <operands>; <comment>*
- *label*
    - optional
    - Identifizierung einer Zeile ohne Kenntnis der Speicheradresse
    - Label ersetzt Adresse
- *comment*
    - Kommentarzeichen: *;*
    - Hinweis: Beachten Sie die Coderichtlinien!
- *instruction*
    - die eigentliche Assembler-Instruktion
- *operands*
    - Je nach Instruktion können Operanden folgen
        - register (R, R8, R16, R32, SR)
        - memory (M, M8, M16, M32)
        - immediate (I)

### Einschub: Speicheradressierung
- Zugriff auf eine Adresse: *[Adresse]*
- Beispiele ohne Speicherzugriff
    - *mov eax, dword 1*
    - *mov eax, ebx*
- Beispiele mit Speicherzugriff
    - *mov [eax], 1*
    - *mov eax, [buffer]*
    - *mov eax, [ecx + ebx * 4 + 0x800]*

### Spezifikation von Instruktionen
@import "Bilder/Teil01/SpezifikationVonInstruktionen01.png"
- viele Befehle im Carter, sonst NASM Dokumentation
- O2: (R,R), (R,M), (R,I), (M,R), (M,I)

### Typische Adressierungsfehler
**Sie sind gefragt!**
@import "Bilder/Teil01/TypischeAdressierungsfehler01.png"
Welche Fehler werden hier gemacht?
- *mov 17, 1*
- *mov 17, bx*
- *mov cx, dh*
- *mov [ax], [bx]*

### Datentypen
- Datentyp = Länge in Bytes
- i.d.R. muss Länge mehrerer Operanden identisch sein
    - richtig:
        - *mov eax, ebx*
    - falsch:
        - *mov eax, bx*
- Länge implizit bekannt:
    - *mov eax, 0x10*
- oder explizite Angabe notwendig:
    - *neg byte [wert]*
    - erlaubte Typangaben: *byte* (für 8 Bit), *word* (für 16 Bit),
      *dword* (für 32 Bit)

### Direktiven
- Anweisung an den Assembler/Präprozessor
- keine direkte Übersetzung in Instruktionen
- aber ähnliches Format
- häufig um Speicherplatz zu reservieren
    - initialisierte Speicherplätze ($\rightarrow$ .*data*): *dx*
    - uninitialisierte Speicherplätze ($\rightarrow$ .*bss*): *resX*
    - X aus {B,W,D,Q,T}
- *include*
- *equ*
- *define*
- *macro/endmacro*

### Ein-/Ausgaben 1
- Abkürzung: Funktionen aus Carter
- diese verwenden z.B. printf/scanf
- in *asm_io.asm*
    - *%include "asm_io.inc"*
- *asm_io.o* mit kompilieren
- allgemein: Interrupts

### Ein-/Ausgaben 2
@import "Bilder/Teil01/EinAusgaben01.png"

**Neue Hausaufgabe**
Finden Sie heraus, was die Debugging-Hilfen *dump_mem* und *dump_stack* machen!

## 4. Einfache Instruktionen

### Übersicht
- Kopieren von Daten
- arithmetische Integerinstruktionen
- logische Instruktionen
- Verschiebe-Instruktionen
- Rotationsinstruktionen

### Arithmetische Integer-Instruktionen
- Addieren von ganzen Zahlen:
    - *add op1, op2*
    - *adc op1, op2* (mit Carry)
- Subtrahieren von ganzen Zahlen:
    - *sub op1, op2*
    - *sbb op1, op2* (mit Carry)

### Hands On
**Live**
Beispielprogramm Addieren zweier Zahlen.

**Neue Hausaufgabe**
Schreiben Sie ein Programm, dass das Addieren mit Carry demonstriert!

### Multiplikation
- vorzeichenlos: *mul source*
    - ax = al * source (bei 8 Bit source)
    - dx : ax = ax * source (bei 16 Bit source)
    - edx : eax = eax * source (bei 32 Bit source)
- vorzeichenbehaftet: *imul*
    - *imul source; analog zu mul*
    - *imul dest, source; dest *= source*
    - *imul dest, source1, source2; dest = source1 * source2; source2 immer immediate (!)*
- typischer Fehler: ein Wert im höherwertigen Ergebnisregister (z.B. edx bei 32 Bit) wird
  vorher nicht gesichert und dann überschrieben!

### Division
- vorzeichenlos: *div source*
    - al = ax div source
    - ax = dx : ax div source
    - eax = edx : eax div source
    - ah = ax mod source
    - dx = dx : ax mod source
    - edx = edx : eax mod source
- vorzeichenbehaftet: *idiv source*
    - analog zu *div*
- typischer Fehler: dx oder edx nicht initialisiert (wenn Wert bereits in ax oder
  eax passt, müssen dx bzw. edx immer auf 0 gesetzt werden)

### Logische Instruktionen
arbeiten i.d.R. bitweise:
- *and op1, op2*
    - op1 = op1 AND op2
- *or op1, op2*
    - op1 = op1 OR op2
- *xor op1, op2*
    - op1 = op1 XOR op2
- *not op1*
    - op1 = Einerkomplement von op1
- *neg op1*
    - op1 = Zweierkomplement von op1 (= (NOT op1) + 1)

### Beispiel: Subnetze
- Gegeben eine IP-Adresse und die Größe des Netzwerks, finde die Netzwerkadresse
  und die Broadcastadresse
- Netzwerk-Adresse: erste X Bit der IP-Adresse übernehmen, andere Bits sind 0
- Broadcast-Adresse: erste X Bit der IP-Adresse übernehmen, andere Bits sind 1
**Beispiel**:
- IP-Adresse: 137.77.20.57
- Netzwerkteil: 16 Bit
- Netzwerkadresse: 131.77.0.0
- Broadcastadresse: 137.77.255.255
- Gegeben:
    - IP-Adresse, X
- Gesucht:
    - Netzwerkadresse, Broadcastadresse

### Verschiebe-Instruktionen
- *shr op1, op2* (Shift Right)
    - *op1* wird um *op2* (Binär-)Stellen nach rechts verschoben
    - von links werden 0en nachgeschoben
- *shl op1, op2* (Shift Left)
    - *op1* wird um *op2* Stellen nach links verschoben
    - von rechts werden 0en nachgeschoben
- *sar op1, op2* (Shift Arithmetic Right)
    - *op1* wird um *op2* Stellen nach rechts verschoben
    - von links wird die Ziffer nachgeschoben, die vorher im höchstwertigen Bit
      stand
    - Sign Extension!
- *sal op1, op2* (Shift Arithmetic Left) Synonym für *shl*

### Rotationsinstruktionen
- *ror op1, op2* (Rotate Right)
    - *op1* wird um *op2* Stellen nach rechts rotiert
    - von links wird das Bit übernommen, welches rechts herausrotiert wurde
- *rol op1, op2* (Rotate Left)
    - *op1* wird um *op2* Stellen nach links rotiert (analog zu *ror*)
- *rcr op1, op2* (Rotate Carry Right)
    - *C*:*op1* wird um *op2* Stellen nach rechts rotiert
    - von links wird das Bit übernommen, welches im Carry-Flag stand
    - rechts wird in das Carry-Bit hineinrotiert
- *rcl op1, op2* (Rotate Carry Left)
    - *C*:*op1* wird um *op2* Stellen nach links rotiert (analog zu *rcr*)

### Wieder Subnetze 1
@import "Bilder/Teil01/WiederSubnetze01.png"

**Neues Hausaufgabe**
Setzen Sie das Programm in NASM um.

## 5. C-Einstieg

### Geschichte
@import "Bilder/Teil01/Geschichte01.png"

### Hallo Welt
**Live**
```C
#include <stdio.h>

int main(void) {
  printf("Hallo Welt\n");
  return 0;
}
```

### Was Sie schon kennen - oder selbstständig lernen müssen
- elementare Datentypen (int, char, ...) und Variablen
- Schlüsselwörter
- Kontrollstrukturen
- Kommentare
- Formatierte Ein- und Ausgabe
- Operatoren

### Was wir uns anschauen werden
- Guter Codestil
- typische Fehler
- Pointer
- Strings
- dynamische Speicherverwaltung

### Was wir auslassen
- Präprozessor
    - mächtig
    - oft für betriebssystemabhängige Programmierung
- Funktionspointer
- genauere Betrachtung

## 6. Codestil

### Warum guten Code?
@import "Bilder/Teil01/Codestil01.png"

### Coderichtlinien C
Der Code muss gut lesbar sein. Dafür:
- sinnvolle und konsistente Einrückung
- maximale Zeilenlänge: 100 Zeichen
- Funktionen müssen auf den Bildschirm passen
- aussagekräftige Benennung
- sinnvolle Kommentierung
- keine globalen Variablen, kein goto
- keine Warnings (*-WALL*)

### Subnetze - noch einmal 1
@import "Bilder/Teil01/WiederSubnetze02.png"

### Subnetze - noch einmal 2
**Neue Hausaufgabe**
Verbessern Sie dieses Programm!

### Hausaufgaben in C
**Neue Hausaufgabe**
Machen Sie sich schon einmal grundlegend mit der Syntax zu Pointern in C bekannt.
Details und Fallen besprechen wir dann im nächsten Vorlesungsteil.
