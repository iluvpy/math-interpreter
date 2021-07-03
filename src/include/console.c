#include <stdio.h>
#include <stdlib.h>

#include "cstr.h"
#include "console.h"


cstr *minput(size_t max) {
    char *str = malloc(max);
    fgets(str, max, stdin);
    return allocate_cstr(str);
}

 // gets input dynamically
char *dinput() {

}
