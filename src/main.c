#include <stdio.h>
#include <ctype.h>

#include "cstr.h"
#include "console.h"
#include "lexer.h"
#include "parser.h"

//defines
#define tostr(s) getcstr(s)
#define COMMAND_EXECUTED 0
#define NO_COMMAND 1
#define QUIT_COMMAND -1

// forward declarations
void help();
int commands(cstr *input);

int main(int argc, char **argv) 
{
    bool running = true;
    cstr *input;
    help();
    while (running) {
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

		svector *tokens = gen_tokens(input);
        printf("tokens: \n");
		for (int i = 0; i < svec_len(tokens); i++) {
			printf("%s\n", cstr_str(svec_get(tokens, i)));
		}
		parser(tokens);

		del_svec(tokens);
        // free memory for input
        del_cstr(input);
    }
    return 0;
}


// prints out the help menu
void help() {
    printcolor(FgMagenta, "\nmathc debug version \n");
    printcolor(FgGreen ,"------- Comannds -------\n");
    printcolor(FgBlue, "'%s' to show this menu again\n", H_CMD);
    printcolor(FgBlue, "'%s' to clear the console\n", CLR_CMD);
    printcolor(FgBlue, "'%s' to exit\n\n", Q_CMD);
	
}


// checks for commands
int commands(cstr *input) {
    if (isalpha(cstr_getc(input, 0))) {
        if (cstr_eq_str(input, Q_CMD)) {return QUIT_COMMAND;}
        if (cstr_eq_str(input, H_CMD)) {help();}
        else if (cstr_eq_str(input, CLR_CMD)) {clear_console();}
        else {
            printcolor(FgRed ,"Unknown command '%s'. type '%s' for help\n", cstr_str(input), H_CMD);
        }
		return COMMAND_EXECUTED;
    } 
	return NO_COMMAND;
}
