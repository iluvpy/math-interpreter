#ifndef CONSOLE_C
#define CONSOLE_C

#include "cstr.h"

#define DINP_LEN 128


// colors

// other
#define Reset "\x1b[0m"
#define Bright "\x1b[1m"
#define Dim "\x1b[2m"
#define Underscore "\x1b[4m"
#define Blink "\x1b[5m"
#define Reverse "\x1b[7m"
#define Hidden "\x1b[8m"
// fg colors
#define FgBlack "\x1b[30m"
#define FgRed "\x1b[31m"
#define FgGreen "\x1b[32m"
#define FgYellow "\x1b[33m"
#define FgBlue "\x1b[34m"
#define FgMagenta "\x1b[35m"
#define FgCyan "\x1b[36m"
#define FgWhite "\x1b[37m"
// bg colors
#define BgBlack "\x1b[40m"
#define BgRed "\x1b[41m"
#define BgGreen "\x1b[42m"
#define BgYellow "\x1b[43m"
#define BgBlue "\x1b[44m"
#define BgMagenta "\x1b[45m"
#define BgCyan "\x1b[46m"
#define BgWhite "\x1b[47m"


// input

// max input
// set max bytes
cstr *minput(size_t max);


// returns input from stdin in form of a char *
// input is handled dynamically so thers no maximum size
// input needs to be freed from memory after usage
// call free on the used pointer after wards
char *dinput();

// returns input from stdin in form of a cstr *
// input is handled dynamically so thers no maximum size
// input needs to be freed from memory after usage
// call del_cstr to delete ptr afterwards
cstr *cstrdinput(); 


// output

// prints text in color 
void printcolor(char *text, char *color);
// print text in color and endlines
void printlncolor(char *text, char *color);
// other


void clear_console();

#endif // CONSOEL_H


