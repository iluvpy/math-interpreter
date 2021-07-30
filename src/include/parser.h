#pragma once 

#include "cstr.h"
#include "strvec.h"
#include "lexer.h"
#include "ast.h"
#include "console.h"

Ast *parser(svector *tokens);