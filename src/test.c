#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
#include "cstr.h"
#include "lexer.h"
#include "strvec.h"
#include "tokens.h"


// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}


int main(void) {

	// test stuff in here
	cstr *token = get_op_token('+');
	char c = get_op_char(token);
	printf("token: '%s', char: '%c'\n", cstr_str(token), c);

	del_cstr(token);
 	return 0;
}