#include <string.h>
#include "simpleString.h"

// Tests bauen und ausführen:
// checkmk simpleString_tests.ts > simpleString_tests.c
// gcc simpleString.c simpleString_tests.c -o tests -Wall $(pkg-config --cflags --libs check) -std=c99 -g
// ./tests

#test length_of_empty_string
    char * string = "";
    int result = my_strlen(string);
    ck_assert_int_eq(0, result);

#test length_of_string
    char * string = "Hallo Welt";
    int result = my_strlen(string);
    ck_assert_int_eq(10, result);

#test array_is_no_string
    char array[] ={'a', 'b', 'c'};
    int len = 3;
    int result = is_string(array, len);
    ck_assert_int_eq(0, result);

#test empty_string_is_string
    char *empty = "";
    int len = 1;
    int result = is_string(empty, len);
    ck_assert_int_eq(1, result);

#test string_is_string
    char *string = "hallo";
    int len = 6;
    int result = is_string(string, len);
    ck_assert_int_eq(1, result);
