#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	// i need to make a new variable as it copies 'none' into it and wont free the original variable but only the copy 
	// when del_ast is called i.e none is not deleted so i need to delete it myself
	cstr *none = get_cstr("None");
	node_setValue(start_node, none); 
	del_cstr(none);
	ast_setNode(ast, start_node);

	// find first operator
	for (int i = 0; i < svec_len(tokens); i++) {
		if (is_op_token(svec_get(tokens, i))) {

			node_setValue(start_node, svec_get(tokens, i));
			cstr *num_token = svec_get(tokens, i-1);
			if (is_number_token(num_token)) {
				AstNode *node = alloc_astNode();
				node_setValue(node, num_token);
				start_node->right = node;
			}
			break;
		}
	}


	return ast;
}
