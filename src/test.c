#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "strvec.h"
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

	// print_section("string vector test");

	// svector *vec = generate_svec();
	// cstr *str = get_cstr("hello");
	// svec_appendc_str(vec, "hello");
	// svec_appendc_str(vec, "world");
	// svec_appendc_str(vec, "i like cheese");
	// svec_appendc_str(vec, "h4");
	// svec_appendc_str(vec, "hi");
	// svec_append(vec, str);

	// for (int i = 0; i < svec_len(vec); i++) {
	// 	printf("e%d is equal to '%s'\n", i, cstr_str(svec_get(vec, i)));
	// }
	// del_svec(vec);
	// del_cstr(str);

	cstr *text2 = get_cstr("hello");
	printf("text2 now: %s\n", cstr_str(text2));
	text2 = cstr_delc(text2, 'l');
	printf("text2 after removing 'l': %s\n", cstr_str(text2));
	del_cstr(text2);

 	return 0;
}