#include <stdio.h>

#include "cstr.h"
#include "console.h"
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"
#include "debug.h"


int main(int argc, char **argv) 
{
    cstr *input;
    print_help_menu();
    while (true) {
        printf("mathc# ");
		input = dynamic_input();
		if (!input) {// no input was given
			continue;
		} 
        int res = handle_input(input);
		if (res == QUIT_COMMAND) {
			del_cstr(input);
			break; // go back to start
		}
		else if (res == COMMAND_EXECUTED) {
			del_cstr(input);
			continue; // go back to start
		}
		
        DEBUG_MESSAGE("tokenizing...\n");
		svector *tokens = generate_tokens(input);
		DEBUG_MESSAGE("all tokens:\n");
		ON_DEBUG(
			for (int i = 0; i < svec_len(tokens); i++) {
				printf("\t%s\n", cstr_str(svec_get(tokens, i)));
			}
		)
        DEBUG_MESSAGE("parsing...\n");
		Ast *ast = parser(tokens);
		if (ast) {
			DEBUG_MESSAGE("interpreting...\n");
			print_ast(ast, NULL);
			cstr *result = cstr_cpy(interpret_ast(ast_get_node(ast)));
			cstr *number_result = get_token_value(result);
			del_cstr(result);
			printf("result: %s\n", cstr_str(number_result));
			del_cstr(number_result);
        	del_ast(ast);
		}
		else {
			print_color(FgRed, "parsing error occured! please check your writing!\n");
		}

		del_svec(tokens);
        // free memory for input
        del_cstr(input);
    }
    return 0;
}
