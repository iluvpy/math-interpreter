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

	for (int i = 0; i < svec_len(vec); i++) {
		printf("e%d is equal to '%s'\n", i, cstr_str(svec_get(vec, i)));
	}
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

	cstr *phrase = get_cstr("hello world.");
	char c = '.';
	printf("'%c' is in '%s': %s\n", c, cstr_str(phrase), bool_str(cstr_is_in(phrase, c)));
	del_cstr(phrase);

	cstr *text = get_cstr("");
	for (int i = 0; i < 26; i++) {
		cstr_appendc(text, i+97);
	}
	printf("result: ");
	for (int i = 0; i < 26; i++) {
		printf("%c", cstr_getc(text, i));
	}
	printf("\n");

	char char_ = 97;
	cstr_appendc(text, (int)char_);
	printf("added '%c' to text variable\n", char_);
	printf("text variable is now equal to '%s'\n", cstr_str(text));
	del_cstr(text);

 	return 0;
}