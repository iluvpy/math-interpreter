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
    free(ast);
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
    if (node->value != NULL) del_cstr(node->value);
    node->value = cstr_cpy(value);
}

cstr *node_getValue(AstNode *node) {
    return node->value;
}

void node_setLeft(AstNode *node, AstNode *left) {
    node->left = left;
}

void node_setRight(AstNode *node, AstNode *right) {
    node->right = right;
}

AstNode *node_getLeft(AstNode *node) {
    return node->left;
}

AstNode *node_getRight(AstNode *node) {
    return node->right;
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
    }
} 