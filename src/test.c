
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
	printf("say something: ");
	cstr *str = dynamic_input();
	printf("ok i understood; you said \n'%s'\n", cstr_str(str));
	printf("now im gonna remove everying from the middle and after! \n");
	cstr_strip(str, 3);
	printf("much better!; \n'%s'\n", cstr_str(str));

	del_cstr(str);
 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}