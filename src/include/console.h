#ifndef CONSOLE_C
#define CONSOLE_C

#include "cstr.h"

#define DINP_LEN 512

// input

// max input
// set max bytes
cstr *minput(size_t max);


// gets input dynamically
char *dinput();
// works like dinput but returns cstr instead


cstr *cstrdinput(); 


// output

void print_color();


// other


void clear_console();

#endif // CONSOEL_H


