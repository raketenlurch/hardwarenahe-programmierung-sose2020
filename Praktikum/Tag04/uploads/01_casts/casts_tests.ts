#include "casts.h"

#test drei_durch_twei
    float ergebnis = dividiere(3, 2);

    ck_assert_int_eq(ergebnis * 2, 3);

#test drei_durch_drei
    float ergebnis = dividiere(3, 3);

    ck_assert_int_eq(ergebnis * 3, 3);

#test zwei_durch_vier
    float ergebnis = dividiere(2, 4);

    ck_assert_int_eq(ergebnis * 4, 2);
