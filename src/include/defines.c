#include "defines.h"

void debug(char *s) {
    #ifdef DEBUG
    printf("DEBUG: %s\n", s);
    #endif
}