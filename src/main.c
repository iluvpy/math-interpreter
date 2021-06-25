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
}

// executes the command if typed in
int executes(char *input) {
    debug("input was: ");
    printf("%s\n", input);
    if (input == "q") {
        return -1;
    }
    else if (input == "c") {
        clear_console();
    }
    else if (!string_digit(input) && input != NULL) {
        printlnColor("ERROR: not a command ", KRED);
    }
}

int main(int argc, char **argv) {
    
    bool running = true;
    char *input;

    Vector v;
    initV(&v);
    appendV(&v, 100);
    printf("set first element of v to %d\n", Vget(&v, 0));

    while (running) { 
        input = start();
        int res = executes(input);
        if (res < 0) {running = false;}


        end(input);
    }

    deleteVec(&v);
    return 0;
}