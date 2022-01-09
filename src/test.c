
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

	print_section("TEST");
	cstr *input = dynamic_input();
	FILE *test_file = fopen("./test.out.txt", "w+");
	fprintf(test_file, "%s", cstr_str(input));
	fclose(test_file);
	del_cstr(input);

 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}