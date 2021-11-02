#include "parser.h"

bool error_occured = false;

// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	ast_set_node(ast, start_node);

	parse_(tokens, start_node);

	if (error_occured) {
		printf("error occured while parsing...\n");
		del_ast(ast);
		return NULL;
	}
	return ast;
}

void parse_(svector *tokens, AstNode *_node) {
	printf("parser!\n");
	int len = svec_len(tokens);
	if (len > 0) { // if len > 0
		int pos1 = svec_find(tokens, '+');
		int pos2 = pos1 != -1 ? pos1 : svec_find(tokens, '-');
		if (pos2 != -1) {
			node_set_value(_node, svec_get(tokens, pos2));
			svec_pop(tokens, pos2);
			pos1 = pos2;
		}
		else if ((pos1 = svec_find(tokens, '*')) != -1) {
			node_set_value(_node, svec_get(tokens, pos1));
			svec_pop(tokens, pos1);
		}
		else if ((pos1 = svec_find(tokens, '/')) != -1) {
			node_set_value(_node, svec_get(tokens, pos1));
			svec_pop(tokens, pos1);
		}
		else {
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