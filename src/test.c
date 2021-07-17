#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
#include "utils.h"
#include "cstr.h"
#include "lexer.h"
#include "strvec.h"


// prints ------- name -------
void print_section(char *name) {
	printcolor(FgGreen, "------- ");
	printcolor(FgGreen, "%s", name);
	printcolor(FgGreen, " -------\n");
}

int main(void) {

	print_section("string vector test");

	svector *vec = generate_svec();
	svec_appendc_str(vec, "hello");
	svec_appendc_str(vec, "world");
	svec_appendc_str(vec, "i like cheese");
	svec_appendc_str(vec, "h4");
	svec_appendc_str(vec, "hi");

	printf("last %s\n", getstr(svec_get(vec, vec->length-1)));
	return 0;
}