#include "count_all.h"
#include <string.h>

// checkmk count_all_tests.ts > count_all_tests.c
// gcc count_all.c count_all_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage

void check_token_array(int cnt_tokens, int *mycount, int *count, char mytokens[][80]){
    for(int i = 0; i < cnt_tokens; i++){
        int token_found = 0;
        for(int j = 0; j < cnt_tokens; j++){
            if(strcmp(mytokens[i], tokens[j]) == 0 ){
                token_found++;
                ck_assert_msg(count[j] == mycount[i], "Anzahl für Wort %s nicht korrekt. Ist %i, soll %i.\n", mytokens[i], count[j], mycount[i]);
            }
        }
        if(token_found == 0){
            ck_abort_msg("Wort %s in tokens nicht gefunden!\n", mytokens[i]);
        } else if (token_found > 1) {
            ck_abort_msg("Wort %s in tokens zu oft gefunden!\n", mytokens[i]);
        }
    }
}

#test extract_and_count_without_special_chars_return_value
    char string[] = "Wort1 Wort2 wort1 Wort1 Wort1 Wort4 Wort3 Wort3";
    int count[80]; 
    ck_assert_int_eq(extract_and_count(string, count), 5);

#test extract_and_count_without_special_chars_check_arrays
    char string[] = "Wort1 Wort2 wort1 Wort1 Wort1 Wort4 Wort3 Wort3";
    char mytokens[][80] = {"Wort1", "Wort2", "wort1", "Wort4", "Wort3"};
    int mycount[] = {3, 1, 1, 1, 2};
    int cnt_tokens = 5;
    int count[80]; 
    extract_and_count(string, count);
    check_token_array(cnt_tokens, mycount, count, mytokens);

