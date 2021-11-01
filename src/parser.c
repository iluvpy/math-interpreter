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

	parse_(tokens, start_node);

	if (cstr_eq_str(start_node->value, "null")) {
		del_ast(ast);
		return NULL;
	}
	return ast;
}

void parse_(svector *tokens, AstNode *_node) {
	if (svec_len(tokens) > 0) {
		svec_pop(tokens, svec_len(tokens)-1);
		parse_(tokens, _node);
		return;
	}
	printf("parsing done!\n");
}