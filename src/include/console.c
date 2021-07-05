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

// returns input from stdin in form of a char *
// input is handled dynamically so thers no maximum size
// input needs to be freed from memory after usage
// call free on the used pointer after wards
char *dinput() {
    size_t len = DINP_LEN;
    char *inp = malloc(len);
    int i = 0;
    char c;
    while ((c = getchar()) && c != EOF && c != '\n') {
        inp[i] = c;
        i++;
        if (i >= len) {
            len += DINP_LEN;
            inp = realloc(inp, len);
        }
    }
    
    // return null if enter was pressed immediately
    if (i == 0) {
        free(inp);
        return NULL;
    }

    // resize to correct size
    size_t size = strlen(inp);
    inp = realloc(inp, size);
    return inp;
}

// returns input from stdin in form of a cstr *
// input is handled dynamically so thers no maximum size
// input needs to be freed from memory after usage
// call del_cstr to delete ptr afterwards
cstr *cstrdinput() {
    return cstr_from_allocstr(dinput());
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

