Für diese Aufgabe benötigen Sie folgende zwei Dateien:

- gdb_1
- gdb_1.c.gpg
- test.sh

Sie können das Programm gdb_1 in gdb ausführen. Die Datei gdb_1.c.gpg ist
verschlüsselt. Das Passwort können Sie mittels gdb herausfinden. Es steht in
der Variablen pwd.

Entschlüsseln Sie die Datei mit folgendem Befehl:

gpg -d gdb_1.c.gpg

Leiten Sie die Ausgabe in die Datei gdb_1_loesung.c um und arbeiten Sie mit der C-Datei und gdb
weiter um die beiden Fehler zu finden.
