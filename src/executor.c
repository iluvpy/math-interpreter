#include "executor.h"

cstr *execute_ast(AstNode *node) {
    cstr *node_value = node_get_value(node);
    if (is_op_token(node_value)) {
        cstr *left_node = NULL;
        cstr *right_node = NULL;
        if (node_get_left(node)) left_node = node_get_value(node_get_left(node));
        if (node_get_right(node)) right_node = node_get_value(node_get_right(node));
        // convert to actual numbers
        switch (get_op_char(node_value))
        {
            case '*':
                
                break;
            case '/':
                
                break;
			case '+':
                
        		break;
			case '-':
                
            	break;
				
            default:
                break;
        }
    }
    else { // probably a number token
        // if the right node is null then its the end if the AST
        if (!node_get_right(node)) return node_get_value(node);
 
    }

    return NULL;
}