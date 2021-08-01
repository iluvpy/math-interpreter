#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	node_setValue(start_node, get_cstr("None"));
	ast_setNode(ast, start_node);

	// int mlt_pos = svec_find(tokens, '*');
	// int divide_pos = svec_find(tokens, '/');
	// int plus_pos = svec_find(tokens, '+');
	// int minus_pos = svec_find(tokens, '-');

	return ast;
}
