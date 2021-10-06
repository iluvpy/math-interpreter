#pragma once

/**
 *  @brief functions to do math with cstr
 */
#include "cstr.h"
#include "tokens.h"

cstr *token_add(cstr *n1, cstr *n2);
cstr *token_sub(cstr *n1, cstr *n2);
cstr *token_mlt(cstr *n1, cstr *n2);
cstr *token_div(cstr *n1, cstr *n2);
cstr *token_pow(cstr *n1, cstr *n2);