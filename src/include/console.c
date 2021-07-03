#include <stdio.h>
#include <stdlib.h>

#include "cstr.h"
#include "console.h"

// max input
// set max bytes
cstr *minput(size_t max) {
    char *str = malloc(max);
    str = fgets(str, max, stdin);
    if (str == NULL) {return NULL;}
    return cstr_fallocstr(str);
}

 // gets input dynamically
char *dinput() {

}

