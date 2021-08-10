#include <stdio.h>
#include <ctype.h>

#include "cstr.h"
#include "console.h"
#include "lexer.h"
#include "parser.h"

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
		if (input == NULL) continue; // no input was given
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
        printf("tokens: \n");
		for (int i = 0; i < svec_len(tokens); i++) {
			printf("%s\n", cstr_str(svec_get(tokens, i)));
		}
        printf("parsing:\n");
		Ast *ast = parser(tokens);
        printf("ast first node value: '%s'\n", cstr_str(node_getValue(ast_getNode(ast))));
        printf("ast right node value: '%s'\n", cstr_str(node_getValue(node_getRight(ast_getNode(ast)))));
        printf("ast left node value: '%s'\n", cstr_str(node_getValue(node_getLeft(ast_getNode(ast)))));
        del_ast(ast);

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
    printcolor(FgBlue, "'%s' to show this menu again\n", H_CMD);
    printcolor(FgBlue, "'%s' to clear the console\n", CLR_CMD);
    printcolor(FgBlue, "'%s' to exit\n\n", Q_CMD);
	
}

// only used and should only be used in commands() function
#define CMD_EXEC(inp, CMD, func, _return) \
    if (inp[0] == CMD[0]) { \
        if (str_eq_str(inp, CMD)) { \
            func;\
            return _return; \
        }\
        if (strlen(inp) == strlen(CMD)) { \
            printcolor(FgRed, "'%s' does not exist, did you mean '%s'?\n", inp, CMD); \
            return COMMAND_EXECUTED;\
        } \
    } \


void void_func() { return; } 

// checks for commands
int commands(cstr *input) {

    char *str = cstr_str(input);
    CMD_EXEC(str, Q_CMD, void_func(), QUIT_COMMAND);
    CMD_EXEC(str, Q2_CMD, void_func(), QUIT_COMMAND);
    CMD_EXEC(str, H_CMD, print_help_menu(), COMMAND_EXECUTED);
    CMD_EXEC(str, H2_CMD, print_help_menu(), COMMAND_EXECUTED);
    CMD_EXEC(str, CLR_CMD, clear_console(), COMMAND_EXECUTED);
    CMD_EXEC(str, CLR2_CMD, clear_console(), COMMAND_EXECUTED);

	return NO_COMMAND;
}

