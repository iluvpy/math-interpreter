#pragma once

#include <stdlib.h>
#include "cstr.h"

#define SVEC_SIZE sizeof(svector)

typedef struct svector {
	cstr **vector;
	int length;
} svector;


svector *svec_from_cstr(cstr *str); // creates svector and initalizes index 0 with str
svector *generate_svec(); // generates an svector initialized with length 0
void svec_append(svector *vec, cstr *str);
void svec_appendc_str(svector *vec, char *str);
// returns position of c in vec or -1 if c is not in vec
int svec_find(svector *vec, char c);
cstr *svec_get(svector *vec, int index); // returns element if exists
int svec_len(svector *vec);
// frees memory of vec
void del_svec(svector *vec);