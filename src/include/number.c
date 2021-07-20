#include "number.h"

inline number *alloc_number() { return malloc(sizeof(number));}
inline void free_number(number *num) { free(num); }