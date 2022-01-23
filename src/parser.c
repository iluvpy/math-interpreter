#include "parser.h"

bool error_occured = false;

// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	ast_set_node(ast, start_node);

	if (!svec_len(tokens)) {
		printf("parser: no input was given...\n");
		del_ast(ast);
		return NULL;
	}

	parse_(tokens, start_node);

	if (error_occured) {
		error_occured = false; // reset error
		printf("error occured while parsing...\n");
		del_ast(ast);
		return NULL;
	}
	return ast;
}


void parse_(svector *tokens, AstNode *_node) {

	int len = svec_len(tokens);
	if (len > 0) { // if len > 0
		int pos1 = svec_findc(tokens, '+');
		DEBUG_MESSAGE_VAR("value of pos1: %d\n", pos1);
		// int pos2 = pos1 != SVEC_NOT_FOUND ? pos1 : svec_findc(tokens, '-');
		// the minus token doesnt exist so theres no need to look for it
		int pos2 = pos1; 
		// a number can also be INT:-1 so i need to see if it contains an 'O' for 'OP:-' 
		bool contains = false;
		if (pos2 != SVEC_NOT_FOUND) { contains = cstr_contains(svec_get(tokens, pos2), 'O'); }
		if (pos2 != SVEC_NOT_FOUND && contains) {
			node_set_value(_node, svec_get(tokens, pos2));
			svec_pop(tokens, pos2);
			pos1 = pos2;
		}
		else if ((pos1 = svec_findc(tokens, '*')) != SVEC_NOT_FOUND) {
			node_set_value(_node, svec_get(tokens, pos1));
			svec_pop(tokens, pos1);
		}
		else if ((pos1 = svec_findc(tokens, '/')) != SVEC_NOT_FOUND) {
			node_set_value(_node, svec_get(tokens, pos1));
			svec_pop(tokens, pos1);
		} 
		else if ((pos1 = svec_findc(tokens, '^')) != SVEC_NOT_FOUND) {
			node_set_value(_node, svec_get(tokens, pos1));
			svec_pop(tokens, pos1);
		}
		else {
			// the token array should now only contain the token, if not, that means one token wasnt used and some error occured
			if (len > 1) {
				error_occured = true;
				return;
			}
			DEBUG_MESSAGE("parser finished\n")
			node_set_value(_node, svec_get(tokens, len-1));
			return;
		}
		// get direction analyzes the order of operation and chooses if 
		// pos1 needs to index the left or right number 
		// NOTE: pos1 IS currently indexing the right number as the operator that it was indexing before was deleted
		pos1 += get_direction(tokens, pos1);

		if (pos1 >= 0 && pos1 < len) { // if pos1 exists (in our cirucmstances)
			AstNode *left = get_node(svec_get(tokens, pos1)); // the left number
			if (!node_get_value(left)) {
				error_occured = true;
				return;
			}
			DEBUG_MESSAGE_VAR("left number: %s\n", cstr_str(svec_get(tokens, pos1)));
			svec_pop(tokens, pos1);
			AstNode *right = alloc_astNode();
			node_set_left(_node, left);
			node_set_right(_node, right);
			parse_(tokens, right);

			if (!node_get_value(right)) {
				error_occured = true;
				return;
			}

			DEBUG_MESSAGE_VAR("right val: %s, left-val: %s, right-val: %s\n", cstr_str(node_get_value(right)),
				cstr_str(node_get_value(node_get_left(right))), cstr_str(node_get_value(node_get_right(right))));
		}
		else { 
			DEBUG_MESSAGE_VAR("Error inside parser caused by the token index being outside range, pos1: %d\n", pos1);
			error_occured = true;
			return;
		}

	}
	
}



/*  returns the char of the operator before the pointer, ie: in case the input was '1*2+1' and the pointer
    was at '+' it would return '*' as the operator used before the pointer is '*'
*/
char get_before_operator(svector *tokens, int index) {
	return cstr_get_last(svec_get(tokens, index-2));
}
/*  returns the char of the operator after the pointer, ie: in case the input was '1+1*2' and the pointer
    was at '+' it would return '*' as the operator used after the pointer is '*'
*/
char get_after_operator(svector *tokens, int index) {
	return cstr_get_last(svec_get(tokens, index+1));
}


/*
	get direction return -1 or 0.
	it returns -1 if the order of operation needs me to use the left number and
	0 for the right number, as the index is already pointing to the right number 0 wouldnt change
	it and thus we would point at the right number, while index-1 would be pointing at the left number
*/
int get_direction(svector *tokens, int index) {
	char before = get_before_operator(tokens, index);
	char after = get_after_operator(tokens, index);
	int before_index = string_find(USED_OPERATORS, before);
	int after_index = string_find(USED_OPERATORS, after);
	
	if (before_index == STRING_NOT_FOUND) { return -1; }
	if (after_index == STRING_NOT_FOUND) { return 0; }
	
	if (before_index == after_index) { return -1; }
 	if (before_index < after_index) { return -1; }
	else { return 0; }
}