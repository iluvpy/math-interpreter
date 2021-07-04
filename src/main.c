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
    printf("%s to clear the console", CLR_CMD);
    printf("%s to exit\n\n", Q_CMD);
}


// checks for commands
int commands(cstr *input) {
    printf("%s qual to q: %s\n", tostr(input), bool_str(tostr(input) == "q"));
    if (tostr(input) == "q") {return -1;}
    else if (tostr(input) == H_CMD) {help();}
    else if (tostr(input) == CLR_CMD) {clear_console();}
    return 0;
}


int main(int argc, char **argv) 
{
    bool running = true;
    cstr *input;
    help();
    while (running) {
        printf("math> ");
        input = cstrdinput();

        int res = commands(input); 
        if (res < 0) {
            del_cstr(input);
            break;
        }
    
        // free memory for input
        del_cstr(input);
    }


    printf("\nexiting\n");
    return 0;
}