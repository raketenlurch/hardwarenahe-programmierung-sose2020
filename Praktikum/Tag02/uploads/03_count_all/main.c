#include <stdio.h>
#include <string.h>
#include "count_all.h"

int main(){
    int count[80];
    char input[81];

    printf("Bitte einen Text eingeben (max. 80 Zeichen): \n");
    fgets(input, 81, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline

    int number_of_tokens = extract_and_count(input, count);
    
    print(number_of_tokens, count);

    return 0;
}
