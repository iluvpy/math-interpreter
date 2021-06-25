#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include "defines.h"


#define IF_QUIT(t) t == "q" || t == "quit"

// returns the percentage of similarity (1 is 100% and 0 would be 0%)
f32 is_similar(char *s1, char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2); 
    int sims = 0;
}

#endif // UTILS_H