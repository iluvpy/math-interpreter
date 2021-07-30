#pragma once 

#include "cstr.h"
#include "strvec.h"
#include "lexer.h"
#include "ast.h"

Ast *parser(svector *tokens);