#pragma once

#include "lexer.h"

typedef struct compiler {
	cstr *input;
	svector *tokens;
	cstr *parsed;
	cstr *result;
} compiler;

void compiler_compile(compiler *cmplr, cstr *input);
void compiler_input(compiler *cmplr, cstr *input);
void compiler_lex(compiler *cmplr);
void compiler_parse(compiler *cmplr);
cstr *compiler_output(compiler *cmplr);