#pragma once

#include <stdio.h>
#include "cstr.h"
#include "utils.h"
// operators 
#define OP_PLUS "OP::+"
#define OP_MINUS "OP::-"
#define OP_DIVIDE "OP::/"
#define OP_MULTIPLY "OP::*"
#define OP_POW "OP::^"


// parse info

// tells the parser to execute everything that came before first
// e.g INT::1 * INT::76 INFO::FIRST
#define TEXEC_FIRST "INFO::FIRST"

// types 
#define TOKEN_INTEGER "INT::"
#define TOKEN_FLOAT "FLOAT::"

// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by spaces
cstr *get_tokens(cstr *m_expression);
cstr *get_int_token(int n);
cstr *get_float_token(float d);
