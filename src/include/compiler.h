#pragma once

#include "lexer.h"

// its not a compiler but an interpreter 
// i know that but who cares?
typedef struct compiler {
	cstr *input;
	svector *tokens;
	cstr *result;
} compiler;

void compiler_compile(compiler *cmplr, cstr *input);
void compiler_input(compiler *cmplr, cstr *input);
void compiler_lex(compiler *cmplr);
void compiler_parse(compiler *cmplr);
void compiler_clean(compiler *cmplr); // frees everything
cstr *compiler_result(compiler *cmplr);  // returns result