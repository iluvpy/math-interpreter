#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"

void clear_console() {
    system("clear"); // XXX this only works for linux the command for windows is 'cls'
}
 

void printColor(char *text, char *ansi) {
    printf("%s%s%s", ansi, text, KNRM);
}

void printlnColor(char *text, char *ansi) {
    printColor(text, ansi);
    printf("%c", ENDL);
} 

void printRed(char *text) {
    printf("%s%s%s", KRED, text, KNRM);
}

void printlnRed(char *text) {
    printRed(text);
    printf("%c", ENDL);
}

void printGreen(char *text) {
    printColor(text, KGRN);
}

void printlnGreen(char *text) {
    printGreen(text);
    printf("%c", ENDL);
}

void secureInp(char *input, size_t max_bytes) {
    fgets(input, max_bytes, stdin);
}

char* dynInput() {
    printf("dyn Input was called!\n");
    int length = MIN_INP_SIZE;
    char *inp_ = (char*)malloc(MIN_INP_SIZE);
    char c;
    int i = 0;
    while ((c = getchar()) && c != EOF) {
        if (c == ENDL) {
            break;
        }
        inp_[i] = c;
        printf("got new char %c\n", c);
        i++;
        if (i >= length) {
            length += MIN_INP_SIZE;
            inp_ = realloc(inp_, length);
        }
    }

    size_t size = strlen(inp_);
    char *text = (char*)malloc(size);
    strcpy(text, inp_);
    free(inp_);
    if (i == 0) {
        free(text);
        return NULL;
    }
    return text;
}

// free dynamic input
void free_dinput(char *t) {
    free(t);
}

