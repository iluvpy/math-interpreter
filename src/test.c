
/*
	NOTE: this file is just used for testing purposes and can be removed from the build file if needed
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
#include "cstr.h"
#include "lexer.h"
#include "strvec.h"
#include "tokens.h"
#include "numbers.h"
#include "ast.h"
#include "debug.h"

void print_section(char *name);



int main(void) {
	DEBUG_CALL(main, "%s\nnew msg: %d", "hello", 4);
 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}