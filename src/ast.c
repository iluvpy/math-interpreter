#include "ast.h"

// ast
Ast *alloc_ast() {
    Ast *ast = malloc(AST_SIZE);
    ast->first_node = NULL;
    return ast;
}

void ast_setNode(Ast* ast, AstNode *node) {
    ast->first_node = node;
}

AstNode *ast_getNode(Ast *ast) {
    return ast->first_node;
}

void del_ast(Ast *ast) {
    del_node(ast->first_node);
}


// ast node
AstNode *alloc_astNode() {
    AstNode *node = malloc(ASTNODE_SIZE);
    node->value = NULL;
    node->left = NULL;
    node->right = NULL; 
    return node;
}

AstNode *get_node(cstr *value) {
    AstNode *node = alloc_astNode();
    node->value = value;
    return node;
}


// copies value into node->value
void node_setValue(AstNode *node, cstr *value) {
    node->value = cstr_cpy(value);
}

void node_setLeft(AstNode *node, AstNode *left) {
    node->left = left;
}

void node_setRight(AstNode *node, AstNode *right) {
    node->right = right;
}

void del_node(AstNode *node) {
    if (node != NULL) {
        del_cstr(node->value);
        if (node->left != NULL) {
            del_node(node->left);
            node->left = NULL;
        }
        if (node->right != NULL) {
            del_node(node->right);
            node->right = NULL; 
        }
        free(node);
        node = NULL;
    }
} 