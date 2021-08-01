#include "number.h"


number *alloc_number() { return malloc(sizeof(number));}
cstr *number_str(number *num) {
	return num->str_num;
}
void free_number(number *num) { 
	free_point(num->pos);
	del_cstr(num->str_num);
	if (num != NULL) free(num); 
}