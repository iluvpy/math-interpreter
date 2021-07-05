#include <stdio.h>

#include "cstr.h"
#include "console.h"
#include "utils.h"


#define CLR_CMD "cls"
#define H_CMD "h"
#define Q_CMD "q"

#define tostr(s) getcstr(s)


// prints out the help menu
void help() {
    printf("math debug version \n");
    printf("comannds: \n");
    printf("%s to show this menu again\n", H_CMD);
    printf("%s to clear the console\n", CLR_CMD);
    printf("%s to exit\n\n", Q_CMD);
}


// checks for commands
int commands(cstr *input) {
    int n = cstr_sum(input);
    if (cstr_eq_str(input, Q_CMD)) {return -1;}
    if (cstr_eq_str(input, H_CMD)) {help();}
    else if (cstr_eq_str(input, CLR_CMD)) {clear_console();}
    return 0;
}


int main(int argc, char **argv) 
{
    bool running = true;
    cstr *input;
    help();
    while (running) {
        printf("math# ");
        input = cstrdinput();
        
        // NULL when no input is given i.e enter was pressed
        if (input == NULL) {
            continue; // return to start
        }

        int res = commands(input); 
        if (res < 0) {
            del_cstr(input);
            break;
        }
    
        // free memory for input
        del_cstr(input);
    }


    printf("exiting\n");
    return 0;
}