#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "console.h"

// returns true if string is a digit 
// supports floating point numbers
bool string_digit(char *s) {
    int digits = -strlen(s);
    for (int i = 0; i < strlen(s); i++) {
        digits += (isdigit(s[i]) || s[i] == '.' || s[i] == ',') ? 1 : 0;
    }
    return digits == 0;
}


char* boolstr(bool b) {
    return b ? "True" : "False";
}

char* getColorText(char *text, char *ansi) {    
    size_t d_len = strlen(text)+strlen(ansi);
    size_t dd_len = d_len+strlen(KNRM);
    char d[d_len];
    char dd[dd_len];
    strcat(d, ansi);
    strcat(d, text);
    strcat(dd, d);
    strcat(dd, KNRM);
    text = dd;
    return text;
}

// reverses text
void rev_str(char *text) {
    size_t len = strlen(text);
    char rev[len];
    strcpy(rev, text);   
    for (int i = len-1; i >= 0; i--) {
        rev[i] = text[len-i];
    }
    text = rev;
}

