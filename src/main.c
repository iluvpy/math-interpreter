#include <stdio.h>
#include <ctype.h>

#include "cstr.h"
#include "console.h"
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"
#include "debug.h"

//defines
#define COMMAND_EXECUTED 0
#define NO_COMMAND 1
#define QUIT_COMMAND -1


#define CLR_CMD "cls"
#define CLR2_CMD "clear"
#define H_CMD "h"
#define H2_CMD "help"
#define Q_CMD "q"
#define Q2_CMD "quit"


// forward declarations

// prints help menu
void print_help_menu();
// this function does nothing
int commands(cstr *input);
bool is_command(cstr *input);

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
        int res = commands(input); 
        if (res < 0) { // quit command
            del_cstr(input);
            break;
        }
		else if (res == COMMAND_EXECUTED) {
			del_cstr(input);
			continue;
		}

		svector *tokens = generate_tokens(input);
        DEBUG_MESSAGE("tokenizing...\n");
		for (int i = 0; i < svec_len(tokens); i++) {
			printf("%s\n", cstr_str(svec_get(tokens, i)));
		}
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
			printcolor(FgRed, "parsing error occured! please check your writing!\n");
		}

		del_svec(tokens);
        // free memory for input
        del_cstr(input);
    }
    return 0;
}


// prints out the help menu
void print_help_menu() {
    printcolor(FgMagenta, "\nmathc debug version \n");
    printcolor(FgGreen ,"------- Comannds -------\n");
    printcolor(FgBlue, "'%s' or '%s' to show this menu again\n", H_CMD, H2_CMD);
    printcolor(FgBlue, "'%s' or '%s' to clear the console\n", CLR_CMD, CLR2_CMD);
    printcolor(FgBlue, "'%s' or '%s' to exit\n\n", Q_CMD, Q2_CMD);
	
}

// checks for commands
int commands(cstr *input) {

    char *str = cstr_str(input);

	if (str_eq_str(str, Q_CMD) || str_eq_str(str, Q2_CMD)) {
		return QUIT_COMMAND;
	}
	else if (str_eq_str(str, H_CMD) || str_eq_str(str, H2_CMD)) {
		print_help_menu();
		return COMMAND_EXECUTED;
	}
	else if (str_eq_str(str, CLR_CMD) || str_eq_str(str, CLR2_CMD)) {
		clear_console();
		return COMMAND_EXECUTED;
	}
    else if (!isdigit(str[0])) { // if the first letter of the input isnt a number 
		printcolor(FgRed, "Uknown command '%s', please type '%s' or '%s' for help.\n", str, H_CMD, H2_CMD);
		return COMMAND_EXECUTED;
	}

	return NO_COMMAND;
}

