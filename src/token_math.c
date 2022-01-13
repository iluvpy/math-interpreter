#include "token_math.h"
#include "numbers.h"
#include <stdio.h>
#include <math.h>
#define ASCII_0 48
#define ASCII_9 57

double get_token_number(cstr *string) {
	cstr *value = get_token_value(string);
	double string_f = cstr_tof(value);
	del_cstr(value);
	return string_f;
}

cstr *token_add(cstr *s1, cstr *s2) {
	double s1_f = get_token_number(s1);
	double s2_f = get_token_number(s2);
	return to_token(cstr_from_float(s1_f +  s2_f, CSTR_FLOATING_POINT_PRECISION), true);
}

cstr *token_sub(cstr *s1, cstr *s2) {
	double s1_f = get_token_number(s1);
	double s2_f = get_token_number(s2);
	return to_token(cstr_from_float(s1_f - s2_f, CSTR_FLOATING_POINT_PRECISION), true);
}

cstr *token_mlt(cstr *s1, cstr *s2) {
	double s1_f = get_token_number(s1);
	double s2_f = get_token_number(s2);
	return to_token(cstr_from_float(s1_f * s2_f, CSTR_FLOATING_POINT_PRECISION), true);
}

cstr *token_div(cstr *s1, cstr *s2) {
	double s1_f = get_token_number(s1);
	double s2_f = get_token_number(s2);
	return to_token(cstr_from_float(s1_f / s2_f, CSTR_FLOATING_POINT_PRECISION), true);
}

cstr *token_pow(cstr *s1, cstr *s2) {
	double s1_f = get_token_number(s1);
	double s2_f = get_token_number(s2);
	return to_token(cstr_from_float(pow(s1_f, s2_f), CSTR_FLOATING_POINT_PRECISION), true);
}
