#pragma once

#include "cstr.h"

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
void ast_setNode(Ast* ast, AstNode *node);
AstNode *ast_getNode(Ast *ast);
// frees all the memory in the ast
void del_ast(Ast *ast);

// ast node
AstNode *alloc_astNode();
AstNode *get_node(cstr *value);
// copies value into node->value
void node_setValue(AstNode *node, cstr *value); 
cstr *node_getValue(AstNode *node);
void node_setLeft(AstNode *node, AstNode *left);
void node_setRight(AstNode *node, AstNode *right);
AstNode *node_getLeft(AstNode *node);
AstNode *node_getRight(AstNode *node);
// frees itself and all the nodes below it
void del_node(AstNode *node);
