#pragma once

#include <stdio.h>
#include <ctype.h>
#include "cstr.h"
#include "number.h"
#include "strvec.h"


#define TOKEN_SEPERATOR ":"
// operators 
#define USED_OPERATORS "+-/*^"
#define OPERATOR_TOKEN "OP:"
#define OP_PLUS "OP:+"
#define OP_MINUS "OP:-"
#define OP_DIVIDE "OP:/"
#define OP_MULTIPLY "OP:*"
#define OP_POW "OP:^"

// parse info
// tells the parser to execute everything that came before first
// e.g INT::1 * INT::76 INFO::FIRST
#define T_EXEC_FIRST "INFO:FIRST"

// types 
#define INTEGER_TOKEN "INT:"
#define FLOAT_TOKEN "FLOAT:"
#define BRACKET_TOKEN "BRACKET:"
#define NAN_TOKEN "NAN:"
#define INTEGER_T_LEN strlen(INTEGER_TOKEN)
#define FLOAT_T_LEN strlen(FLOAT_TOKEN)

// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by spaces
svector *gen_tokens(cstr *m_expression);
cstr *get_int_token(cstr *sn);
cstr *get_float_token(cstr *f);
cstr *get_op_token(char operator);
cstr *get_bracket_token(char bracket);
number *get_number(size_t start_pos, cstr *expression);
cstr *num_to_token(number *num);



bool is_operator(char c);
bool is_LBracket(char c);
bool is_RBracket(char c);