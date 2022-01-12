#include "number.h"


number *alloc_number() { return malloc(sizeof(number));}
cstr *number_str(number *num) {
	return num->str_num;
}
void del_number(number *num) { 
	del_point(num->pos);
	del_cstr(num->str_num);
	if (num) { free(num); } 
}