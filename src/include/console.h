#pragma once

#include <stdarg.h>
#include "cstr.h"


#define CLR_CMD "cls"
#define H_CMD "h"
#define Q_CMD "q"
#define INPUT_LENGTH 128

// colors

// other
#define Reset "\x1b[0m"
// fg colors
#define FgBlack "\x1b[30m"
#define FgRed "\x1b[31m"
#define FgGreen "\x1b[32m"
#define FgYellow "\x1b[33m"
#define FgBlue "\x1b[34m"
#define FgMagenta "\x1b[35m"
#define FgCyan "\x1b[36m"
#define FgWhite "\x1b[37m"


// input

// max input
// set max bytes
cstr *minput(size_t max);
cstr *dynamic_input(); // gets input dynamically

// output

// prints text in color 
void printcolor(char *color, char *format, ...);

// other
void clear_console();



