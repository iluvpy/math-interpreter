#pragma once

/**
 *  @brief functions to do math with cstr
 */
#include "cstr.h"
#define CSTR_FLOATING_POINT_PRECISION 55

cstr *math_cstr_add(cstr *n1, cstr *n2);
cstr *math_cstr_sub(cstr *n1, cstr *n2);
cstr *math_cstr_mlt(cstr *n1, cstr *n2);
cstr *math_cstr_div(cstr *n1, cstr *n2);
cstr *math_cstr_pow(cstr *n1, cstr *n2);