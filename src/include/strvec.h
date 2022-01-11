#pragma once

#include <stdlib.h>
#include "cstr.h"

#define SVEC_SIZE sizeof(svector)
#define SVEC_NOT_FOUND -1

typedef struct svector {
	cstr **vector; // the vector
	// corrisponds to the number of elements and not the index of the last element
	size_t length; 
} svector;


svector *svec_from_cstr(cstr *str); // creates svector and initalizes index 0 with str
svector *generate_svec(); // generates an svector initialized with length 0
void svec_resize(svector *vec, size_t size);
void svec_append(svector *vec, cstr *str);
void svec_appendc_str(svector *vec, char *str);
// returns position of c in vec or -1 if c is not in vec
int svec_findc(svector *vec, char c);
int svec_countc(svector *vec, char c);
cstr *svec_get(svector *vec, int index); // returns element if exists
void svec_set(svector *vec, int index, cstr *str); // sets element at index if it exists
void svec_pop(svector *vec, int index);  // deletes element if exists
svector *svec_cpy(svector *vec);
int svec_len(svector *vec);
// frees memory of vec
void del_svec(svector *vec);