#pragma once

/**
 * @brief functions for stdin, stdout, stderr
 */

#include <stdarg.h>
#include <ctype.h>
#include "cstr.h"

#define UPPERCASE_A_ASCII 65
#define UPPERCASE_Z_ASCII 90
#define LOWERCASE_A_ASCII 97
#define LOWERCASE_Z_ASCII 122
#define SPACE_ASCII 32
#define ENDLINE_ASCII 10
#define IS_UPPERCASE_CHAR(char_) (char_ >= UPPERCASE_A_ASCII && char_ <= UPPERCASE_Z_ASCII)
#define IS_LOWERCASE_CHAR(char_) (char_ >= LOWERCASE_A_ASCII && char_ <= LOWERCASE_Z_ASCII)

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

// commands
#define CLR_CMD "cls"
#define CLR2_CMD "clear"
#define H_CMD "h"
#define H2_CMD "help"
#define Q_CMD "q"
#define Q2_CMD "quit"

#define COMMAND_EXECUTED 0
#define NO_COMMAND 1
#define QUIT_COMMAND -1


// input

// max input
// set max bytes
cstr *dynamic_input(); // gets input dynamically

// output

// prints text in color 
void print_color(char *color, char *format, ...);
void print_help_menu();
// other
void clear_console();
bool valid_math_expression(cstr *input);
int check_commands(cstr *input);
int handle_input(cstr *input);