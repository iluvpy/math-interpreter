
#include "strvec.h"
#include <stdio.h>

// initializes svec
svector *generate_svec() {
	svector *vec = malloc(SVEC_SIZE);
	vec->length = 0; // contains 0 elements
	vec->vector = NULL;
	return vec;
}

// creates svector and initalizes index 0 with str
svector *svec_from_cstr(cstr *str) {
	svector *vec = generate_svec();
	vec->length = 1;
	vec->vector = malloc(CSTR_PTR_SIZE);
	vec->vector[vec->length-1] = cstr_cpy(str);
	return vec;
}

void svec_resize(svector *vec, size_t size) {
	if (!vec->vector) { vec->vector = malloc(size * CSTR_PTR_SIZE);}
	else { vec->vector = realloc(vec->vector, size * CSTR_PTR_SIZE);}
}

// copies str and appends it to vec
void svec_append(svector *vec, cstr *str) {
	if (vec && str) {
		vec->length++;
		svec_resize(vec, vec->length);
		vec->vector[vec->length-1] = cstr_cpy(str);
	}
}

void svec_appendc_str(svector *vec, char *str) {
	if (vec && str) {
		vec->length++;
		svec_resize(vec, vec->length);
		char *str_cpy_ = malloc(strlen(str)+1);
		strcpy(str_cpy_, str);
		vec->vector[vec->length-1] = cstr_from_allocstr(str_cpy_);
	}
}

// returns vector length 
int svec_len(svector *vec) {
	return vec->length;
}


// returns element if it exists
cstr *svec_get(svector *vec, int index) {
	if (vec) {
		if (index >= 0 && index < vec->length) {
			return vec->vector[index];
		}
	}
	return NULL;
}

void svec_set(svector *vec, int index, cstr *str) {
	if (vec) {
		if (svec_get(vec, index)) { // if element exists
			vec->vector[index] = str;
		}
	}
}

// returns index of c in vec or -1 if c is not in vec
int svec_findc(svector *vec, char c) {
	for (int i = 0; i < svec_len(vec); i++) {
		if (cstr_contains(svec_get(vec, i), c)) return i;
	}
	return -1;
}

int svec_countc(svector *vec, char c) {
	int count = 0;
	for (int i = 0; i < svec_len(vec); i++) {
		if (cstr_contains(svec_get(vec, i), c))
			count++;
	}
	return count;
}

// deletes the index if its valid
void svec_pop(svector *vec, int index) {
	if (svec_get(vec, index)) {
		for (int i = index; i < svec_len(vec); i++) {
			svec_set(vec, i, svec_get(vec, i+1));
		}
		vec->length--;
		svec_resize(vec, vec->length);
	}
}	

svector *svec_cpy(svector *vec) {
	if (vec) {
		svector *new = generate_svec();
		for (int i = 0; i < svec_len(vec); i++) {
			svec_append(new, svec_get(vec, i));
		}
		return new;
	}
	return NULL;
}

// frees memory of vec
void del_svec(svector *vec) {
	if (vec) {
		for (int i = 0; i < vec->length; i++) {
			del_cstr(vec->vector[i]);
		}
		free(vec->vector);
		free(vec);
	}
}
