#include "compiler.h"


void compiler_compile(compiler *cmplr, cstr *input) {
	compiler_input(cmplr, input);
	compiler_lex(cmplr);
	compiler_parse(cmplr);
}

void compiler_input(compiler *cmplr, cstr *input) {
	cmplr->input = input;
}

void compiler_lex(compiler *cmplr) {
	cmplr->tokens = gen_tokens(cmplr->input);
}

void compiler_parse(compiler *cmplr) {
	// XXX add parsing
}

// frees everything
void compiler_clean(compiler *cmplr) {
	del_cstr(cmplr->input);
	del_svec(cmplr->tokens);
	del_cstr(cmplr->result);
}

cstr *compiler_result(compiler *cmplr) {
	return cmplr->result;
}
