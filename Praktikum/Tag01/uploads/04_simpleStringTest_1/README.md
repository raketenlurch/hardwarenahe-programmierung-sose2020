# Aufgabe 3: Unittests
In dieser Aufgabe sollen Sie die Funktionalität von vorgegebenen C-Funktionen
mittels des Unit-Test Frameworks *check* überprüfen. Schauen Sie sich dazu
zunächst die vorgegebenen Unittests in der Datei *simpleString_tests.ts* zur
Implementierung in *simpleString.c* an, welche ihnen zeigen, wie solche Tests
aussehen können.

- Bauen Sie die Tests und führen Sie sie aus (entsprechend der Anleitung im
  ILIAS-Lernmodul). Die fehlgeschlagenen Tests helfen Ihnen, Fehler in der von
  uns bereitgestellten Implementierung zu erkennen. Sie sollten verstehen, was
  die Ausgabe der Tests bedeutet.

- Korrigieren Sie im Anschluss die Fehler in der Implementierung und demonstrieren
  Sie, dass nun alle Tests erfolgreich durchlaufen. Die Tests selbst sollten Sie
  nicht verändern!

Folgende C-Funktionen sind gestellt:

- eine Funktion *int my_strlen(char \*string)*, die die Länge des übergebenen
  Strings zurückgeben soll.
- eine Funktion *int is_string(char *string, int len)*, die 1 zurückgeben soll,
  wenn das übergebene *char* Array der Länge *len* ein String ist, und 0 sonst
