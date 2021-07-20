#pragma once

#include "cstr.h"
#include "point.h"
#include "num_type.h"


typedef struct number {
	cstr *num;
	point pos; // start-finish index of number in a cstr "+start....finish-" 
	num_type type; // type of number, float, int, etc
} number;

inline number *alloc_number();
inline void free_number(number *num);