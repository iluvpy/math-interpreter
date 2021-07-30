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

bool token_istype(cstr *token, char *type) {
	cstr *str_type = token_typeof(token);
	bool b = cstr_eq_str(str_type, type);
	del_cstr(str_type);
	return b;
}

bool is_op_token(cstr *token) {
	return token_istype(token, OPERATOR_TOKEN);
}

bool is_int_token(cstr *token) {
	return token_istype(token, INTEGER_TOKEN);
}

bool is_float_token(cstr *token) {
	return token_istype(token, FLOAT_TOKEN);
}

char get_op_char(cstr *op_token) {
	return cstr_getc(op_token, cstr_len(op_token)-1);
}
