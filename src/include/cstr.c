#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cstr.h"


void init_cstr(cstr *cs, char *s) {
    cs->size = strlen(s);
    cs->str = s;
}

// manipulators

// appends src to dest
void append_cstr(cstr *dest, char *src) {
    if (dest != NULL && src != NULL) {
        dest->size += strlen(src);
        char *cpy = dest->str;
        dest->str = malloc(dest->size);
        strcat(dest->str, cpy);
        strcat(dest->str, src);
        
    }
}

// deletes whole cstring and not only the string pointer
void del_cstr(cstr *s) {
    if (s != NULL) {
        free_cstr(s);
        free(s);
        s = NULL;
    }
}

// frees the char * of the cstring
void free_cstr(cstr *s) {
    if (s != NULL) {
        free(s->str);
        s->str = NULL;
    }
}

// getters

// returns the char * of s
char *getcstr(cstr *s) {
    if (s != NULL) {
        return (s->str != NULL) ? s->str : CSTR_NULL;
    }
}


// generates a new cstr and allocates memory
cstr *get_cstr(char *src) {
    cstr *s = malloc(sizeof(cstr));
    s->size = strlen(src);
    s->str = malloc(s->size);
    s->str = src;
    return s;
}

// other
void stdout_cstr(cstr *s) {
    printf("%s", getcstr(s));
}
