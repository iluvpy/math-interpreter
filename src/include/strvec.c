
#include "strvec.h"

// initializes svec
svector *generate_svec() {
	svector *vec = malloc(SVEC_SIZE);
	vec->length = 0;
	vec->vector = NULL;
	return vec;
}

// creates svector and initalizes index 0 with str
svector *svec_from_cstr(cstr *str) {
	svector *vec = generate_svec();
	vec->length = 0;
	vec->vector = malloc(CSTR_PTR_SIZE);
	vec->vector[vec->length] = cstr_cpy(str);
	return vec;
}

void svec_append(svector *vec, cstr *str) {
	if (vec != NULL && str != NULL) {
		vec->length++;
		if (vec->vector == NULL) { vec->vector = malloc(vec->length*CSTR_PTR_SIZE); }
		else { vec->vector = realloc(vec->vector, vec->length*CSTR_PTR_SIZE); }
		vec->vector[vec->length-1] = cstr_cpy(str);
	}
}

void svec_appendc_str(svector *vec, char *str) {
	if (vec != NULL && str != NULL) {
		vec->length++;
		if (vec->vector == NULL) { vec->vector = malloc(vec->length*CSTR_PTR_SIZE); }
		else { vec->vector = realloc(vec->vector, vec->length*CSTR_PTR_SIZE); }
		char *str_cpy_ = malloc(strlen(str)+1);
		strcpy(str_cpy_, str);
		vec->vector[vec->length-1] = cstr_from_allocstr(str_cpy_);
	}
}



// returns element if exists
cstr *svec_get(svector *vec, size_t index) {
	if (index >= 0 && index < vec->length) {
		return vec->vector[index];
	}
	return NULL;
}

// frees memory of vec
void del_svec(svector *vec) {
	if (vec != NULL) {
		for (int i = 0; i < vec->length; i++) {
			del_cstr(vec->vector[i]);
		}
		free(vec->vector);
		free(vec);
	}
}