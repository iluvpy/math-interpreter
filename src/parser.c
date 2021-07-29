#include "parser.h"


// returns the result of the parsed tokens
cstr *parser(svector *tokens) {
	for (int i = 0; i < svec_len(tokens); i++) {
		cstr *str = svec_get(tokens, i);
		cstr *token = get_cstr("");
		int token_len = 0;
		for (int j = 0; j < cstr_size(str); j++) {
			char current_char = cstr_getc(str, j);
			cstr_appendc(token, current_char);
			if (current_char == TOKEN_SEPERATOR) {break;}
			token_len++;
		}

		printf("parser found token type of '%s'\n", cstr_str(token));
		del_cstr(token);
	}
	return NULL;
}
