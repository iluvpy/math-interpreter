#pragma once

/**
 *  @brief functions to manipulate and create tokens
 */


#include "lexer.h"

#define TOKEN_SEPERATOR ':'
// operators in order 
#define USED_OPERATORS "^*/+-" 
#define OPERATOR_TOKEN "OP:"
#define OP_PLUS "OP:+"
#define OP_MINUS "OP:-"
#define OP_DIVIDE "OP:/"
#define OP_MULTIPLY "OP:*"
#define OP_POW "OP:^"

// types 
#define INTEGER_TOKEN "INT:"
#define FLOAT_TOKEN "FLOAT:"
#define BRACKET_TOKEN "BRACKET:"
#define NAN_TOKEN "NAN:"
#define INTEGER_T_LEN strlen(INTEGER_TOKEN)
#define FLOAT_T_LEN strlen(FLOAT_TOKEN)

cstr *get_int_token(cstr *sn);
cstr *get_float_token(cstr *sf);
cstr *get_op_token(char operator);
cstr *get_bracket_token(char bracket);
cstr *token_typeof(cstr *_token);
cstr *get_token_value(cstr *token);
bool token_istype(cstr *_token, char *type);
bool is_op_token(cstr *_token);
bool is_int_token(cstr *token);
bool is_float_token(cstr *token);
bool is_number_token(cstr *token);
char get_op_char(cstr *op_token);
