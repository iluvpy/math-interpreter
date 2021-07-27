
#include "lexer.h"

const num_type types;

// transforms a mathematical expression into a simple start to finish array of tokens that 
// can then be executed by the parser
svector *gen_tokens(cstr *m_expression) {
	svector *tokens = generate_svec();
	int i = 0; 
	while (i < cstr_size(m_expression)) {
		char current_char = cstr_getc(m_expression, i);
		if (is_LBracket(current_char)) {
			printf("hit a '('\n");
		}
		else if (is_RBracket(current_char)) {
			printf("hit a ')'\n");
		}
		else if (is_operator(current_char)) {
			cstr *operator_token = get_op_token(current_char);
			svec_append(tokens, operator_token);
			del_cstr(operator_token);
		}
		else if (isdigit(current_char)){
			// create number
			number *num = get_number(i, m_expression);
			i = num->pos->y;
			// get token
			cstr *token = num_to_token(num);
			svec_append(tokens, token);
			del_cstr(token);
			free_number(num);
			if (i >= cstr_len(m_expression)) {break;} 
		}
		i++;
	}
	
	return tokens;
}


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

cstr *num_to_token(number *num) {
	switch (num->type)
	{
		case INT_T:
			return get_int_token(num->str_num);
		case FLOAT_T:
			return get_float_token(num->str_num);
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
	for (int i = start_pos; i < cstr_size(expression); i++) {
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
	num->pos = get_point(start_pos, start_pos+cstr_len(str_num)-1);
	num->type = type_;
	num->str_num = str_num;
	return num;
}	

bool is_operator(char c) {
	char operators[] = USED_OPERATORS;
	for (int i = 0; i < strlen(operators); i++) {
		if (operators[i] == c) return true;
	}
	return false;
}


//XXX: add more brackets later like [] {} etc
bool is_LBracket(char c) {return c == '(';}
bool is_RBracket(char c) {return c == ')';}