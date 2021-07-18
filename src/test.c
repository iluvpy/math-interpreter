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
	cstr *str = get_cstr("hello");
	svec_appendc_str(vec, "hello");
	svec_appendc_str(vec, "world");
	svec_appendc_str(vec, "i like cheese");
	svec_appendc_str(vec, "h4");
	svec_appendc_str(vec, "hi");
	svec_append(vec, str);

	printf("last %s\n", getstr(svec_get(vec, vec->length-1)));

	int n = 152566;
	printf("there are %zu digits in %d\n", get_intlen(n), n);

	printf("input: ");
	cstr *input = minput(6);
	printf("input was '%s'\n", getstr(input));
	del_cstr(input);
	del_svec(vec);
	del_cstr(str);
	return 0;
}