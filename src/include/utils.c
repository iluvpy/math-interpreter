#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"

char *bool_str(bool b) {
    return b ? "True" : "False";
}