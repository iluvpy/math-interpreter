#include "parser.h"

bool error_occured = false;

// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	ast_set_node(ast, start_node);

	parse_(tokens, start_node);

	if (error_occured) {
		error_occured = false; // reset error
		printf("error occured while parsing...\n");
		del_ast(ast);
		return NULL;
	}
	return ast;
}

bool tokens_are_valid(svector *tokens) {
	int op_tokens = 0;
	int number_tokens = 0;
	for (int i = 0; i < svec_len(tokens); i++) {
		cstr *token = svec_get(tokens, i);
		if (is_number_token(token)) 
			number_tokens++;
		else if (is_op_token(token))
			op_tokens++;
	}

	return (number_tokens > op_tokens) || (number_tokens == 1 && op_tokens == 0); 
}

void parse_(svector *tokens, AstNode *_node) {
	printf("parser!\n");

	if (!tokens_are_valid(tokens)) {
		error_occured = true;
		return;
	}

	int len = svec_len(tokens);
	if (len > 0) { // if len > 0
		int pos1 = svec_findc(tokens, '+');
		int pos2 = pos1 != SVEC_NOT_FOUND ? pos1 : svec_findc(tokens, '-');
		// a number can also be INT:-1 so i need to see if it contains an 'O' for 'OP:-' 
		pos2 = pos2 == svec_findc(tokens, 'O') ? pos2 : SVEC_NOT_FOUND;
		if (pos2 != SVEC_NOT_FOUND) {
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
			if (len > 1) {
				error_occured = true;
				return;
			}
			node_set_value(_node, svec_get(tokens, len-1));
			return;
		}
		// as pos1 was shifted and now equals to the right node so pos1-- equals to the left node (the value of the left node)
		pos1--;
		if (pos1 != -1 && pos1 < len) { // if pos1 exists (in our cirucmstances)
			AstNode *left = get_node(svec_get(tokens, pos1)); // the left number
			printf("left number: %s\n", cstr_str(svec_get(tokens, pos1)));
			svec_pop(tokens, pos1);
			AstNode *right = alloc_astNode();
			node_set_left(_node, left);
			node_set_right(_node, right);
			parse_(tokens, right);
		}
		else {
			error_occured = true;
			return;
		}

	}
	
}