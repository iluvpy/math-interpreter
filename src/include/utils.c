#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

// returns true if string is a digit 
// supports floating point numbers
bool string_digit(char *s) {
    int digits = -strlen(s);
    for (int i = 0; i < strlen(s); i++) {
        digits += (isdigit(s[i]) || s[i] == '.' || s[i] == ',') ? 1 : 0;
    }
    return digits == 0;
}