#pragma once

/**
 * @brief  abstract syntax treee library
 */

#include <stdio.h>
#include "cstr.h"
#include "debug.h"

#define AST_SIZE sizeof(Ast)
#define ASTNODE_SIZE sizeof(AstNode)

struct AstNode {
    cstr *value;
    struct AstNode *left;
    struct AstNode *right;
};
typedef struct AstNode AstNode;

typedef struct Ast {
    AstNode *first_node;
} Ast;


// ast
Ast *alloc_ast();
void ast_set_node(Ast* ast, AstNode *node);
AstNode *ast_get_node(Ast *ast);

// to print an ast you need to set node to NULL
void print_ast(Ast *ast, AstNode *node);
// frees all the memory in the ast
void del_ast(Ast *ast);

// ast node
AstNode *alloc_astNode();
AstNode *get_node(cstr *value);
// copies value into node->value
void node_set_value(AstNode *node, cstr *value); 
cstr *node_get_value(AstNode *node);
void node_set_left(AstNode *node, AstNode *left);
void node_set_right(AstNode *node, AstNode *right);
AstNode *node_get_left(AstNode *node);
AstNode *node_get_right(AstNode *node);
// frees itself and all the nodes below it
void del_node(AstNode *node);
