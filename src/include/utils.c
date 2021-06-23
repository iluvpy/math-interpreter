#include <stdio.h>
#include "utils.h"


void printRed(char *text) {
    printf("%s%s%s", KRED, text, KNRM);
}
