#include "parser.h"


// returns the result of the parsed tokens
Ast *parser(svector *tokens) {
	Ast *ast = alloc_ast();
	for (int i = 0; i < svec_len(tokens); i++) {
		cstr *token = svec_get(tokens, i);

		if (is_op_token(token)) {
			printf("found operator token\n");
			switch (get_op_char(token))
			{
				case '*':
					printf("wow youre multiplying somethin'");
					break;
				case '/':
					break;
				
				default:
					break;
			}
		}

		cstr *type = token_typeof(token);
		printf("parser found token type of '%s'\n", cstr_str(type));
		del_cstr(type);
	}
	return ast;
}
