#include <stdio.h>
#include <ctype.h>

#include "cstr.h"
#include "console.h"
#include "utils.h"


#define tostr(s) getcstr(s)


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
    if (isalpha(getstr(input)[0])) {
        if (cstr_eq_str(input, Q_CMD)) {return -1;}
        if (cstr_eq_str(input, H_CMD)) {help();}
        else if (cstr_eq_str(input, CLR_CMD)) {clear_console();}
        else {
            printcolor(FgRed ,"Unknown command '%s'\n", getstr(input));
        }
    } 
    return 0;
}


int main(int argc, char **argv) 
{
    bool running = true;
    cstr *input;
    help();
    while (running) {
        printf("math# ");
		input = dynamic_input();
		if (input == NULL) continue; // no input was given

        int res = commands(input); 
        if (res < 0) { // quit command
            del_cstr(input);
            break;
        }
        
        // free memory for input
        del_cstr(input);
    }


    printcolor(FgCyan ,"exiting ):\n");
    return 0;
}