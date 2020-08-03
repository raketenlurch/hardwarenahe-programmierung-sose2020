
/*
 * Soll die Länge des in in übergebenen Char-Arrays enthaltenen String zurückgeben
 */
int my_strlen(char *string);

/*
 * Soll 1 zurückgeben, wenn es sich bei dem übergebenen Char-Arrays um einen
 * String handelt, 0 sonst.
 * In der Variable "len" wird die Größe des Char-Arrays übergeben, damit es nicht
 * zu Segmentationfaults kommt.
 */
int is_string(char *string, int len);

