#include <stdio.h>
#include <stdbool.h>

#include "console.h"
#include "utils.h"


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
    if (input[0] == 'q') {
        return -1;
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