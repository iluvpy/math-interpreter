
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
#include "debug.h"

void print_section(char *name);



int main(void) {
	print_section("test");
	// write testing code here
	svector *vec = generate_svec(); 	
	svec_append_str(vec, "INT:2");
	svec_append_str(vec, "OP:*");
	svec_append_str(vec, "INT:2");
	svec_append_str(vec, "OP:+");
	svec_append_str(vec, "INT:1");

	int index = svec_findc(vec, '+');
	DEBUG_MESSAGE_VAR("str at 0: '%s', before removal index: %d, len: %d\n", cstr_str(svec_get(vec, 1)), index, svec_len(vec));
	svec_pop(vec, 1);
	DEBUG_MESSAGE_VAR("str at 0: '%s', after removal index: %d, len: %d\n", cstr_str(svec_get(vec, 1)), index, svec_len(vec));
	del_svec(vec);
	print_section("finished test");
	return 0;
}

// prints ------- name -------
void print_section(char *name) {
	print_color(FgGreen, "------- ");
	print_color(FgGreen, "%s", name);
	print_color(FgGreen, " -------\n");
}