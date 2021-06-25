#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"


// console
void printlnColor(char *text, char *ansi) {
    printf("%s%s%s", ansi, text, KNRM);
} 

void printRed(char *text) {
    printf("%s%s%s", KRED, text, KNRM);
}

void secureInp(char **input, size_t max_bytes) {
    fgets(*input, max_bytes, stdin);
}

char* dynInput() {
    int length = 0;
    char *inp_ = (char*)malloc(MIN_INP_SIZE);
    char c;
    int i = 0;
    while ((c = getchar()) && c != EOF && c != '\n') {
        inp_[i] = c;
        i++;
        if (i >= length) {
            length += MIN_INP_SIZE;
            inp_ = realloc(inp_, length);
        }
    }

    size_t size = strlen(inp_);
    char *text = (char*)malloc(size);
    for (int i = 0; i < size; i++) {
        text[i] = inp_[i];
    }
    free(inp_);

    return text;
}

void free_dinput(char *t) {
    free(t);
}

