#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	// i need to make a new variable as it copies 'none' into it and wont free it 
	// when del_ast is called i.e none is not deleted so i need to delete it myself
	cstr *none = get_cstr("None");
	node_setValue(start_node, none); 
	del_cstr(none);
	ast_setNode(ast, start_node);

	for (int i = 0; i < strlen(USED_OPERATORS); i++) {
		int operator_pos = svec_find(tokens, USED_OPERATORS[i]);
		if (operator_pos >= 0) {
			node_setValue(start_node, svec_get(tokens, operator_pos));
			break;
		}
	}
	// int divide_pos = svec_find(tokens, '/');
	// int plus_pos = svec_find(tokens, '+');
	// int minus_pos = svec_find(tokens, '-');

	return ast;
}
