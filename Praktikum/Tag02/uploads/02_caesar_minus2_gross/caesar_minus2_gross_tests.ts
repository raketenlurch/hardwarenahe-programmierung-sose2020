#include "caesar_minus2_gross.h"

// checkmk caesar_minus2_gross_tests.ts > caesar_minus2_gross_tests.c
// gcc caesar_minus2_gross.c caesar_minus2_gross_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage

#test caesar_E_to_C
    char to_test[] = "E";
    caesar(to_test);

    char res[] = "C";
    ck_assert_str_eq(to_test, res);


#test caesar_A_to_Y
    char to_test[] = "A";
    caesar(to_test);

    char res[] = "Y";
    ck_assert_str_eq(to_test, res);


#test caesar_B_to_Z
    char to_test[] = "B";
    caesar(to_test);

    char res[] = "Z";
    ck_assert_str_eq(to_test, res);


#test caesar_longer_string
    char to_test[] ="DIESISTEINLANGERSTRING";
    caesar(to_test);
    
    char res[] = "BGCQGQRCGLJYLECPQRPGLE";
    ck_assert_str_eq(to_test, res);


#test caesar_really_long_string
    char to_test[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    caesar(to_test);
    
    char res[] = "YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX";
    ck_assert_str_eq(to_test, res);


#test encode_and_compare_true_short
    char string_to_encode[] = "A";
    char clearstring[] = "Y";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 1);


#test encode_and_compare_true_long
    char string_to_encode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char clearstring[] = "YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 1);


#test encode_and_compare_false
    char string_to_encode[] = "A";
    char clearstring[] = "A";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 0);
