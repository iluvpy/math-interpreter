#ifndef CONSOLE_C
#define CONSOLE_C

#include "cstr.h"

#define DINP_LEN 128

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

void print_color();


// other


void clear_console();

#endif // CONSOEL_H


