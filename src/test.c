
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
	for (int i = 0; i < 10; i++) {
		char hello[7];
		sprintf(hello, "hello%d", i);
		svec_appendc_str(strings, hello);
	}
	printf("last value: %s\n", cstr_str(svec_get(strings, svec_len(strings)-1)));
	printf("length before: %d\n", svec_len(strings));
	svec_pop(strings, 0);
	printf("length after: %d\n", svec_len(strings));
	for (int i = 0; i < svec_len(strings); i++) {
		printf("value: %s\n", cstr_str(svec_get(strings, i)));
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