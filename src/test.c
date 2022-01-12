
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
	print_section("test");
	// write testing code here
	svector *vec = generate_svec(); 	
	svec_append_str(vec, "INT:2");
	svec_append_str(vec, "OP:*");
	svec_append_str(vec, "INT:2");
	svec_append_str(vec, "OP:+");
	svec_append_str(vec, "INT:1");

	DEBUG_MESSAGE_VAR("%d\n", svec_findc(vec, '+'));
	del_svec(vec);
	print_section("finished test");
	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}