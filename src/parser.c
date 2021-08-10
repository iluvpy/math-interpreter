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

	parse_(0, tokens, start_node);

	return ast;
}

void parse_(int _i, svector *tokens, AstNode *_node) {

	// find first operator
	for (int i = _i; i < svec_len(tokens); i++) {
		if (is_op_token(svec_get(tokens, i)) && i) {

			node_setValue(_node, svec_get(tokens, i));
			cstr *num_token = svec_get(tokens, i-1); // get the number (n1) in n1<some operator>n2

			if (is_number_token(num_token)) {
				AstNode *node = alloc_astNode();
				node_setValue(node, num_token);
				_node->left = node;
			}

			AstNode *right = alloc_astNode();
			parse_(i+1, tokens, right);
			// that means that we reached the end ie ...+<some number> and now we add that 'some number' to the right node
			if (node_getValue(right) == NULL) {
				cstr *num_token = svec_get(tokens, i+1); // get the number (n1) in n1<some operator>n2
				node_setValue(right, num_token);
				_node->right = right;
			}
			_node->right = right;

			break;
		}
	}
}