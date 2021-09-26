#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
#include "cstr.h"
#include "lexer.h"
#include "strvec.h"
#include "tokens.h"
#include "cstr_math.h"


void print_section(char *name);



int main(void) {

	cstr *s1 = get_cstr("523");
	cstr *s2 = get_cstr("52753");
	free(math_cstr_add(s1, s2));
 	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}