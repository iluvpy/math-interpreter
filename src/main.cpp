#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include <unistd.h>
#include "defines.h"
#include "functions.h"

/*
    DISCLAIMER:
    TO BUILD YOU NEED TO ADD --DDebug
*/


int main(void) {
    Args args;
    args.running = true;

    while (args.running) {
        args.math_expression = input();
        calculate(args);
    }

    return 0;
}
