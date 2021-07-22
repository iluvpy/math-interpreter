#pragma once

#include "cstr.h"
#include "point.h"
#include "num_type.h"


typedef struct number {
	cstr *str_num;
	point *pos; // start-finish index of number in a cstr "+start....finish-" 
	num_type type; // type of number, float, int, etc
} number;

number *alloc_number();
cstr *number_str(number *num);

void free_number(number *num);