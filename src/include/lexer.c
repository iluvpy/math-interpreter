
#include "lexer.h"


// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by endlines
cstr *get_tokens(cstr *m_expression) {

	
	return ((cstr*)0);
}


cstr *get_int_token(int n) {
	char *s = malloc(get_intlen(n)+1+strlen(TOKEN_INTEGER));
	sprintf(s, "%s%d", TOKEN_INTEGER, n);
	return cstr_from_allocstr(s);  
	
}

cstr *get_float_token(float f) {
	char *s = malloc(get_floatlen(f)+1+strlen(TOKEN_FLOAT));
	sprintf(s, "%s%0.6f", TOKEN_FLOAT, f);
	return cstr_from_allocstr(s);  
}
