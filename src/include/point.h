#pragma once 

/**
 * 	@brief point struct with helper functions
 */

#include <stdlib.h>

typedef struct point {
	int x, y;
} point;

point *alloc_point();
point *get_point(int x, int y);
void del_point(point *p);