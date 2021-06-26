#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "console.h"
#include "utils.h"
#include "vector.h"


void handleFlags(int argc, char **argv) {
    // XXX add handling for flags
}



char* start() {
    printf("> ");
    return dynInput();
}

void end(char *input) {
    free_dinput(input);
    input = NULL;
}

// executes the command if typed in
int executes(char *input) {
    if (input != NULL) {
        printf("input was: %s\n", input);
        size_t len = strlen(input);
        if (input[0] == 'q') {
            return -1;
        }
        else if (input[0] == 'c') {
            clear_console();
        }
        else if (!string_digit(input)) {
            printlnColor("ERROR: not a command ", KRED);
        }
    }
}

int main(int argc, char **argv) {
    
    bool running = true;
    char *input;

    while (running) { 
        input = start();
        int res = executes(input);
        if (res < 0) {running = false;}


        end(input);
    }
    
    return 0;
}