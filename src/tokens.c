#include "tokens.h"



cstr *get_int_token(cstr *sn) {
	cstr *token = get_cstr(INTEGER_TOKEN);
	cstr_appendcstr(token, sn);
	return token;  
}

cstr *get_float_token(cstr *sf) {
	cstr *token = get_cstr(FLOAT_TOKEN);
	cstr_appendcstr(token, sf);
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
	for (int i = 0;;i++) {
		char current_c = cstr_getc(_token, i);
		if (current_c == TOKEN_SEPERATOR) {
			cstr_appendc(type_, current_c);
			break;
		}
		cstr_appendc(type_, current_c);
	}
	return type_;
}	

cstr *get_token_value(cstr *token) {
	cstr *new_str = get_cstr("");
	int start = 0;
	for (int i = 0; i < cstr_size(token); i++) {
		if (cstr_getc(token, i) == TOKEN_SEPERATOR) {
			start = i; 
			break;
		}
	}
	for (int i = start+1; i < cstr_size(token); i++) {
		cstr_appendc(new_str, cstr_getc(token, i));
	}
	return new_str;
}

cstr *to_token(cstr *number) {
	cstr *type = get_cstr("");
	if (cstr_tof(number) == cstr_toi(number)) {
		int pos1 = cstr_find(number, '.');
		int pos = pos1 > -1 ? pos1 : cstr_find(number, ',');
		if (pos > -1) {
			cstr_strip(number, pos); // gets rid of the .000000 at the end  of the number if there is
		}
		cstr_appendstr(type, INTEGER_TOKEN);
	}
	else 
		cstr_appendstr(type, FLOAT_TOKEN);
	cstr_appendcstr(type, number);
	return type;
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

bool is_number_token(cstr *token) {
	return (is_int_token(token) || is_float_token(token));
}

char get_op_char(cstr *op_token) {
	return cstr_getc(op_token, cstr_len(op_token)-1);
}
