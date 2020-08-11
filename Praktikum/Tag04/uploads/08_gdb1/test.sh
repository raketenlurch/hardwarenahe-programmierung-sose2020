#!/usr/bin/env bash

gcc gdb_1_loesung.c -o gdb_1

./gdb_1 > ausgabe.txt

if diff ausgabe.txt erwartete_ausgabe.txt ;then
    echo -e "OK: Ausgabe stimmt mit erwarteter Ausgabe überein."
else
    echo -e "FEHLER: Ausgabe stimmt nicht mit erwarteter Ausgabe überein:"
    diff -y ausgabe.txt erwartete_ausgabe.txt
    exit 1
fi

rm ausgabe.txt
