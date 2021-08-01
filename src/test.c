#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
#include "cstr.h"
#include "lexer.h"
#include "strvec.h"
#include "tokens.h"


void print_section(char *name);



int main(void) {
	// test stuff in here
	cstr *op_token = get_op_token('+');
	cstr *fnum = get_cstr("35.754");
	cstr *inum = get_cstr("142");
	cstr *int_token = get_int_token(inum);
	cstr *float_token = get_float_token(fnum);

	if (is_int_token(int_token)) printf("int token is an int token\n");
	if (is_op_token(op_token)) printf("op token is an op token\n");
	if (is_float_token(float_token)) printf("float token is a float token\n");


 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}