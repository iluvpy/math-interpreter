#pragma once

#include <stdlib.h>
#include "cstr.h"

#define SVEC_SIZE sizeof(svector)

typedef struct svector {
	cstr **vector;
	size_t length;
} svector;


svector *svec_from_cstr(cstr *str); // creates svector and initalizes index 0 with str
svector *generate_svec(); // generates an svector initialized with length 0
void svec_append(svector *vec, cstr *str);
cstr *svec_get(svector *vec, size_t index); // returns element if exists

// frees memory of vec
void del_svec(svector *vec);