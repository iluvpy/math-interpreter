
#include "lexer.h"

const num_type types;

// transforms a mathematical expression into a simple start - to finish string of 
// tokens seperated by endlines
svector *gen_tokens(cstr *m_expression) {
	svector *tokens = generate_svec();

	int i = 0; 
	while (i < cstr_size(m_expression)) {
		char c = cstr_getc(m_expression, i);
		if (is_LBracket(c)) {
			printf("hit a '('\n");
		}
		else if (is_RBracket(c)) {
			printf("hit a ')'\n");
		}
		else if (isdigit(c)){
			// create number
			number *num = get_number(i, m_expression);
			printf("i is %d\n", i);
			i = num->pos->y-1;

			printf("i is now %d\n", i);
			// get token
			cstr *token = num_to_token(num);
			printf("got new token: %s\n", cstr_str(token));
			svec_append(tokens, token);
			del_cstr(token);
			free_number(num);
			if (i > cstr_len(m_expression)) {break;}
		}
		printf("i is at '%c'\n", cstr_getc(m_expression, i));
		i++;
	}
	
	return tokens;
}


cstr *get_int_token(int n) {
	char *s = malloc(get_intlen(n)+1+INTEGER_T_LEN);
	sprintf(s, "%s%d", INTEGER_TOKEN, n);
	return cstr_from_allocstr(s);   
}

cstr *get_float_token(float f) {
	char *s = malloc(get_floatlen(f)+1+FLOAT_T_LEN);
	sprintf(s, "%s%0.6f", FLOAT_TOKEN, f);
	return cstr_from_allocstr(s);  
}



cstr *num_to_token(number *num) {
	switch (num->type)
	{
		case INT_T:
			return get_int_token(cstr_toi(num->str_num));
		case FLOAT_T:
			return get_float_token(cstr_tof(num->str_num));
		case NAN_T:
			return get_cstr(NAN_TOKEN);
		default:
			return NULL;
			break;
	}
}

number *get_number(size_t start_pos, cstr *expression) {
	number *num = alloc_number();
	cstr *str_num = get_cstr("");
	num_type type_ = INT_T;
	for (int i = 0; i < cstr_size(expression); i++) {
		char c = cstr_getc(expression, i);
		if (isdigit(c) || c == '.' || c == ',') {
			if (c == '.' || c == ',') {type_ = FLOAT_T;}
			cstr_appendc(str_num, c);
		}
		else {
			break;
		}
	}
	if (cstr_len(str_num) == 0) {type_ = NAN_T;}
	num->pos = get_point(start_pos, start_pos+cstr_len(str_num));
	num->type = type_;
	num->str_num = str_num;
	return num;
}	

//XXX: add more brackets later like [] {} etc
bool is_LBracket(char c) {return c == '(';}
bool is_RBracket(char c) {return c == ')';}