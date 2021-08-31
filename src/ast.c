#include "ast.h"

// allocates memory for ast and initializes values
Ast *alloc_ast() {
    Ast *ast = malloc(AST_SIZE);
    ast->first_node = NULL;
    return ast;
}
// sets first node to node
void ast_set_node(Ast* ast, AstNode *node) {
    ast->first_node = node;
}

// returns first node of ast
AstNode *ast_get_node(Ast *ast) {
    return ast->first_node;
}

// frees the memory of the underlying nodes of the ast and the ast itself
void del_ast(Ast *ast) {
    del_node(ast->first_node);
    free(ast);
}

// allocates the memory for the astnode and initalized the values
AstNode *alloc_astNode() {
    AstNode *node = malloc(ASTNODE_SIZE);
    node->value = NULL;
    node->left = NULL;
    node->right = NULL; 
    return node;
}
// creates an astnode from a cstr
AstNode *get_node(cstr *value) {
    AstNode *node = alloc_astNode();
    node->value = value;
    return node;
}


// copies value into node->value
void node_set_value(AstNode *node, cstr *value) {
    if (node->value != NULL) del_cstr(node->value);
    node->value = cstr_cpy(value);
}
// returns value of node if node not NULL, NULL if otherwise
cstr *node_get_value(AstNode *node) {
    if (node) return node->value;
    return NULL;
}

void node_set_left(AstNode *node, AstNode *left) {
    node->left = left;
}

void node_set_right(AstNode *node, AstNode *right) {
    node->right = right;
}

// returns the left node of node if node not NULL, NULL if otherwise 
AstNode *node_get_left(AstNode *node) {
    if (node) return node->left;
    return NULL;
}

// returns the right node of node if node not NULL, NULL if otherwise 
AstNode *node_get_right(AstNode *node) {
    if (node) return node->right;
    return NULL;
}

// deletes node and all the underlying nodes
void del_node(AstNode *node) {
    if (node) {
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