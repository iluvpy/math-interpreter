#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdbool.h>
#include "defines.h"

// returns true if string is a digit 
// supports floating point numbers
bool string_digit(char *s);
void getColorText(char **dest, char *src, char *ansi);
char* boolstr(bool b);
// reverses text
// text needs to be freed aftwerwards
void rev_str(char **dest, char *src);
#endif // UTILS_H