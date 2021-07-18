#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"

char *bool_str(bool b) {
    return b ? "True" : "False";
}

// returns length of integer
size_t get_intlen(int n) {
	size_t length = 0;
	int n2 = 1;
	while (n2 < n) {n2 *= 10; length++;}
	return length;
}

// returns length of float
// note this returns the int len of f plus 7 because we use 7 decimal points
size_t get_floatlen(float f) {
	int int_f = (int)f;
	return get_intlen(int_f)+7; 
}
