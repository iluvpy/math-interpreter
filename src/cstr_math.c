#include "cstr_math.h"
#include "numbers.h"

#define ASCII_0 48

cstr *math_cstr_add(cstr *s1, cstr *s2) {
    long int n1 = 0;
    long int n2 = 0;
    if (s1 && s2) {
        for (int i = 0; i < cstr_len(s1); i++) {
            char current_c = cstr_getc(s1, i);
            n1 += current_c;
        }
        for (int i = 0; i < cstr_len(s2); i++) {
            char current_c = cstr_getc(s2, i);
            n2 += current_c;
        }
        return cstr_from_long(n1+n2);
    }
    return NULL;
}

cstr *math_cstr_sub(cstr *s1, cstr *s2) {
    
    return NULL;
}

cstr *math_cstr_mlt(cstr *s1, cstr *s2) {

    return NULL;
}

cstr *math_cstr_div(cstr *s1, cstr *s2) {

    return NULL;
}

cstr *math_cstr_pow(cstr *s1, cstr *s2) {

    return NULL;
}
