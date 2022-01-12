#include "point.h"

point *alloc_point() {
	return malloc(sizeof(point));
}

point *get_point(int x, int y) {
	point *p = alloc_point();
	p->x = x;
	p->y = y;
	return p;
}

void del_point(point *p) {
	if (p) { free(p); }
}