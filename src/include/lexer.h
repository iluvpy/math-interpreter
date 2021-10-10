#pragma once

/**
 * @brief functions for lexing
 */

#include <stdio.h>
#include <ctype.h>
#include "cstr.h"
#include "number.h"
#include "strvec.h"
#include "tokens.h"



// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by spaces
svector *generate_tokens(cstr *m_expression);
number *get_number(int start_pos, cstr *expression);
cstr *num_to_token(number *num);



bool is_operator(char c);
bool is_bracket(char c);
bool is_lbracket(char c);
bool is_rbracket(char c);