#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	node_setValue(start_node, get_cstr("None"));
	ast_setNode(ast, start_node);

	for (int i = 0;  i < svec_len(tokens); i++) {
		cstr *token = svec_get(tokens, i);
		if (is_int_token(token) || is_float_token(token)) {
			node_setValue(start_node, token);
			break;
		}
	}

	return ast;
}
