
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

void print_section(char *name);



int main(void) {

	svector *strings = generate_svec();
	svec_appendc_str(strings, "hello world0");
	svec_appendc_str(strings, "hello world1");
	svec_appendc_str(strings, "hello world2");
	svec_appendc_str(strings, "hello world3");

	for (int i = 0; i < svec_len(strings); i++) {
		for (int j = 0; j < svec_len(strings); j++) {
			printf("i: %d, j: %d, value: %s\n", i, j, cstr_str(svec_get(strings, i)));
		}
		svec_pop(strings, svec_len(strings)-(i+1));
	}
	del_svec(strings);

 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}