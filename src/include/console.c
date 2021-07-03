#include <stdio.h>
#include <stdlib.h>

#include "cstr.h"
#include "console.h"


cstr *minput(size_t max) {
    char *str = malloc(max);
    str = fgets(str, max, stdin);
    if (str == NULL) {return NULL;}
    return get_cstr(str);
}

 // gets input dynamically
char *dinput() {

}

