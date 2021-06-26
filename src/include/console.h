#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdlib.h>

#define KNRM  "\x1B[0m" // reset color (normal text color)
#define KRED  "\x1B[31m" // red
#define KGRN  "\x1B[32m" // green
#define KYEL  "\x1B[33m" // yellow
#define KBLU  "\x1B[34m" // blue
#define KMAG  "\x1B[35m" // magenta
#define KCYN  "\x1B[36m" // cyan
#define KWHT  "\x1B[37m" // white

#define MIN_INP_SIZE 128 // bytes
#define ENDL 0x0a
#define FREE_DINP_T(t) free(t)


void clear_console();
void printColor(char *text, char *ansi);
void printlnColor(char *text, char *ansi);
void printRed(char *text);
void printlnRed(char *text);
void printlnGreen(char *text);
void printGreen(char *text);

void secureInp(char *text, size_t max_bytes);
void free_dinput(char *t);

// dynamic input (size can vary)
// needs to be freed afterwards
char* dynInput();

#endif // CONSOLE_H