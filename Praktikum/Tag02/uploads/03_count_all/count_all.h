/*
 * In diesem Array sollen Sie jedes im Text enthaltene Token einmal speichern
 * Wir gehen davon aus, dass der Text maximal 80 Token mit je maximal 80 Zeichen
 * enthaelt. Ausnahmsweise verwenden wir eine globale Variable.
 */
char tokens[80][81];

/*
 * extract_and_count soll die Token aus dem Eingabestring "source" im globalen
 * Array "tokens" speichern, die Anzahl der verschiedenen Token zurueckgeben
 * und im übergebenen Array "count" speichern, wie oft jedes Token im
 * Eingabestring enthalten ist, wobei die Indizes der beiden Arrays "count"
 * und "tokens" korrespondieren, d.h. count[i] und tokens[i] beschreiben das
 * gleiche Token.
 */
int extract_and_count(char *source,  int *count);

/*
 * Die Funktion print soll jedes Token des Textes genau einmal mit der 
 * zugehoerigen Häufigkeit ausgeben und wird nicht mittels Unittests getestet.
 */
void print(int diff_tokens, int *count);

/*
 * Es ist wahrscheinlich hilfreich, weitere Funktionen zu schreiben!
 */
