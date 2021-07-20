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

	printf("last element of string vector: %s\n", cstr_str(svec_get(vec, vec->length-1)));
	del_svec(vec);
	del_cstr(str);
	
	print_section("end of str vec test");

	int n = 152566;
	printf("there are %zu digits in %d\n", get_intlen(n), n);

	cstr *itoken = get_int_token(52342);
	printf("int token: %s\n", cstr_str(itoken));
	del_cstr(itoken);

	cstr *ftoken = get_float_token(125.6534f);
	printf("float token: %s\n", cstr_str(ftoken));
	del_cstr(ftoken);

	return 0;
}