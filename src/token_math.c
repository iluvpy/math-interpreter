#include "token_math.h"
#include "numbers.h"
#include <stdio.h>
#include <math.h>
#define ASCII_0 48
#define ASCII_9 57

cstr *token_add(cstr *s1, cstr *s2) {
	double s1_f = cstr_tof(get_token_value(s1));
	double s2_f = cstr_tof(get_token_value(s2));
	return cstr_from_float(s1_f +  s2_f, CSTR_FLOATING_POINT_PRECISION);
}

cstr *token_sub(cstr *s1, cstr *s2) {
	double s1_f = cstr_tof(get_token_value(s1));
	double s2_f = cstr_tof(get_token_value(s2));
	return cstr_from_float(s1_f - s2_f, CSTR_FLOATING_POINT_PRECISION);
}

cstr *token_mlt(cstr *s1, cstr *s2) {
	double s1_f = cstr_tof(get_token_value(s1));
	double s2_f = cstr_tof(get_token_value(s2));
	return cstr_from_float(s1_f * s2_f, CSTR_FLOATING_POINT_PRECISION);
}

cstr *token_div(cstr *s1, cstr *s2) {
	double s1_f = cstr_tof(get_token_value(s1));
	double s2_f = cstr_tof(get_token_value(s2));
	return cstr_from_float(s1_f / s2_f, CSTR_FLOATING_POINT_PRECISION);
}

cstr *token_pow(cstr *s1, cstr *s2) {
	double s1_f = cstr_tof(get_token_value(s1));
	double s2_f = cstr_tof(get_token_value(s2));
	return cstr_from_float(pow(s1_f, s2_f), CSTR_FLOATING_POINT_PRECISION);
}
