#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	AstNode *start_node = alloc_astNode();
	// i need to make a new variable as it copies 'none' into it and wont free the original variable but only the copy 
	// when del_ast is called i.e none is not deleted so i need to delete it myself
	cstr *none = get_cstr("null");
	node_set_value(start_node, none); 
	del_cstr(none);
	ast_set_node(ast, start_node);

	parse_(0, tokens, start_node);

	if (cstr_eq_str(start_node->value, "null")) {
		del_ast(ast);
		return NULL;
	}
	return ast;
}

void parse_(int _i, svector *tokens, AstNode *_node) {
	printf("parse_ was called\n");
	for (int i = _i; i < svec_len(tokens); i++) {
		if (is_op_token(svec_get(tokens, i)) && i) {

			node_set_value(_node, svec_get(tokens, i));
			// here im getting the number (n1) in n1<some operator>n2 
			// example: n1 is 5 and n2 is 6 and the operator is +
			// result: 5+6
			cstr *n1 = svec_get(tokens, i-1); 

			if (is_number_token(n1)) {
				AstNode *node = alloc_astNode();
				node_set_value(node, n1);
				_node->left = node;
			}

			AstNode *right = alloc_astNode();
			parse_(i+1, tokens, right);
			// that means that we reached the end ie ...+<some number> and now we add that 'some number' to the right node
			if (node_get_value(right) == NULL) {
				cstr *num_token = svec_get(tokens, i+1); // get the number (n1) in n1<some operator>n2
				node_set_value(right, num_token);
				_node->right = right;
			}
			_node->right = right;

			break;
		}
	}
}