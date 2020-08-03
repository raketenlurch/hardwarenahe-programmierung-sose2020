#include <stdio.h>

/*
 * Nimmt Tastatureingabe vom Benutzer entgegen und gibt die eingegebene Zahl zurück.
 */
int warte_auf_eingabe();

/*
 * Gibt "anzahl" Äpfel aus und passt die übergebenen Geld- und Apfelbestände
 * des Automaten entsprechend an.
 */
void apfel_ausgeben(int anzahl, double *geldstand, int *apfelstand);

/*
 * Ausgabe eines Apfels.
 */
void print_apfel();



print_apfel(){
    printf("        |/\n");
    printf("   ___  | ___ \n");     
    printf("  /    \\|/    \\\n");
    printf(" /              \\\n");
    printf("|               |\n");
    printf("|               |\n");
    printf(" \\             /\n");
    printf("  \\____/|\____/\n");
}


