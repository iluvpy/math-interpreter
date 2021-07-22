#pragma once 
#include <stdlib.h>

typedef struct point {
	int x, y;
} point;

point *alloc_point();
point *get_point(int x, int y);
void free_point(point *p);