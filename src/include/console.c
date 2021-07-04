#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstr.h"
#include "console.h"


// input 

// max input
// set max bytes
cstr *minput(size_t max) {
    char *str = malloc(max);
    str = fgets(str, max, stdin);
    if (str == NULL) {return NULL;}
    return cstr_from_allocstr(str);
}

 // gets input dynamically
char *dinput() {
    size_t len = DINP_LEN;
    char *inp = malloc(len);
    int i = 0;
    char c;
    while ((c = getchar()) && c != '\n') {
        inp[i] = c;
        i++;
        if (i >= len) {
            len += DINP_LEN;
            inp = realloc(inp, len);
        }
    }
    // resize to correct size
    size_t size = strlen(inp);
    inp = realloc(inp, size);
    return inp;
}

// works like dinput but returns cstr instead
cstr *cstrdinput() {
    cstr *inp = cstr_from_allocstr(dinput());
}


// output 



// other

void clear_console() {
#ifdef WIN32_
    system("cls");
#else
    system("clear");
#endif
}

