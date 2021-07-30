#include "tokens.h"



cstr *get_int_token(cstr *sn) {
	cstr *token = get_cstr(INTEGER_TOKEN);
	cstr_appendcs(token, sn);
	return token;  
}

cstr *get_float_token(cstr *sf) {
	cstr *token = get_cstr(FLOAT_TOKEN);
	cstr_appendcs(token, sf);
	return token;  
}

cstr *get_op_token(char operator) {
	cstr *op_token = get_cstr(OPERATOR_TOKEN);
	cstr_appendc(op_token, operator);
	return op_token;
}

cstr *get_bracket_token(char bracket) {
	cstr *token = get_cstr(BRACKET_TOKEN);
	cstr_appendc(token, bracket);
	return token;
}

cstr *token_typeof(cstr *_token) {
	cstr *type_ = get_cstr("");
	for(int i = 0;;i++) {
		char current_c = cstr_getc(_token, i);
		if (current_c == TOKEN_SEPERATOR) {
			cstr_appendc(type_, current_c);
			break;
		}
		cstr_appendc(type_, current_c);
	}
	return type_;
}	

bool is_op_token(cstr *_token) {
	cstr *type = token_typeof(_token);
	bool b = cstr_eq_str(type, OPERATOR_TOKEN);
	del_cstr(type);
	return b;
}

char get_op_char(cstr *op_token) {
	return cstr_getc(op_token, cstr_len(op_token)-1);
}
