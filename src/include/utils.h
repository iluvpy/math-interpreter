#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdbool.h>
#include "defines.h"

// returns true if string is a digit 
// supports floating point numbers
bool string_digit(char *s);
char* getColorText(char *text, char *ansi);
char* boolstr(bool b);
// reverses text
// text needs to be freed aftwerwards
void rev_str(char *text);
#endif // UTILS_H