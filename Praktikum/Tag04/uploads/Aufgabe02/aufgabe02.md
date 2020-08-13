# Aufgabe 2: Der Compiler
Recherchieren Sie die Antworten auf folgende Fragen:

- Aus welchen 4 Stufen besteht der C-Kompiliervorgang? Beschreiben Sie für jede
  der 4 Stufen kurz, was der Compiler dort macht.
    - **1. Stufe: Präprozessor: Die Quelle reparieren**. Zunächst muss der Compiler
      die Quellen aufbereiten. Er muss alle Header-Dateien reinmischen, die mit
      *#include*-**Direktiven** angegeben wurden. Außerdem muss er eventuell
      Bereiche des Programms expandieren oder überspringen. Ist das geschenen,
      ist der Code für die eigentliche Kompilierung bereit.
    - **2. Stufe: Kompilierung: In Assembler übersetzen.** Wahrscheinlich
      erscheint Ihnen C als Programmiersprache schon recht primitiv, trotzdem ist
      es *immer noch nicht so einfach*, dass der Computer es verstehen kann. Der
      Computer versteht nur völlig "primitive" Instruktionen in **Maschienensprache,**
      **und der erste Schritt** zur Generierung von Maschienensprache ist es, den
      C-Quellcode in **Assembler-Symbole** folgender Art zu verwandeln:

      ```asm
      movq -24(%rbp), %rax
      movzbl (%rax), %eax
      movl %eax, %edx
      ```

      Und? Sieht das primitiv und obskur aus? Assembler beschreibt die einzelnen
      Instruktionen, die die CPU befolgen muss, wenn sie das Programm ausführt.
      Der C-Compiler beherrscht einen ganzen Berg an Rezepten für die verschiedenen
      Teile der Programmiersprache C. Diese Rezepte sagen ihm, wie er eine
      *if*-Anweisung oder einen Funktionsaufruf in eine Folge von Assembler-Instruktionen
      übersetzt. Aber für die Maschiene ist selbst Assembler nicht einfach genug.
      Deswegen muss...
    - **3. Stufe: Assembler: Objektcode generieren.** Der Compiler muss die
      Symbolcodes *assemblieren*, um **Maschienen-,** oder **Objektcode** zu
      erzeugen. Das ist der eigentliche Binärcode, der von den Schaltkreisen in
      der CPU ausgeführt wird. Und ist damit alles erledigt? Schließlich wurde
      der ursprüngliche C-Quellcode in die Nullen und Einsen umgewandelt, die die
      Schaltkreise des Computers benötigen. Doch nein, es steht immer noch ein
      Schritt aus. Wenn Sie dem Computer für ein Programm mehrere Dateien zur
      Kompilierung geben, generiert der Compiler jeweils Objektcode für jede
      dieser Quelldateien. Aber wenn diese Objektdateien ein ausführbares Programm
      bilden sollen, muss noch ein Schritt folgen...
    - **4. Stufe: Linken: Die Teile verbinden.** Wenn Sie alle Teile des Objektcodes
      haben, müssen diese wie die Teile eines Puzzels zusammengesetzt werden, bis
      sie das vollständige **ausführbare Programm** bilden. Der Compiler verbindet
      Code in einem Teil des Objektcodes mit Code in einem anderen Teil des
      Objektcodes, wenn er eine Funktion in jenem Teil aufruft. Das Linken sorgt
      auch dafür, dass das Programm Bibliothekscode richtig aufrufen kann. Schließlich
      wird das Programm in eine Programmdatei geschrieben - in einem Format, das
      vom Betriebssystem unterstüzt wird. Das Dateiformat ist wichtig, weil es
      dem Betriebssystem ermöglicht, das Programm in den Speicher zu laden und
      auszuführen.

- Sie haben bereits die Compilierdirektive *#include* kennengelernt. Auf welcher
  der 4 Stufen wird sie verarbeitet? Begründen Sie, warum diese Direktive nicht
  in den anderen Stufen sinnvoll verarbeitet werden kann.
    - In Stufe 1, da ansonsten die Kompilierung abbrechen würde, wenn das Programm
      Funktionen aus Bibliotheken benötigt.
