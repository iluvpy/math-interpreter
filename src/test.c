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
	srand(time(NULL));
	char chars[10][2] = {"a.", "b9", "c1", "d0", "00", "5j", "0?", "i#", "6x", "uh"};
	print_section("string vector test");

	svector *vec = generate_svec();
	size_t vector_size = 100;
	for (int i = 0; i < vector_size; i++) {
		cstr *temp_str = get_cstr(chars[ rand() % 10 ]);
		for (int j = 0; j < 10; j++) {
			append_str(temp_str, chars[ rand() % 10 ]);
		}
		printf("added %s to vector index %d", getstr(temp_str), i);
		svec_append(vec, temp_str);
		del_cstr(temp_str);
	}

	for (int i = 0; i < vector_size; i++) {
		printf("index %d is %s", i, getstr(svec_get(vec, i)));
	}

	del_svec(vec);
	return 0;
}