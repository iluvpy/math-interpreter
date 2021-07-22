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

}

cstr *compiler_output(compiler *cmplr) {
	return cmplr->result;
}
