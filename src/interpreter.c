#include "interpreter.h"

cstr *interpret_ast(AstNode *node) {
	if (!node) {
		return NULL_TOKEN;
	}
    cstr *node_value = node_get_value(node);
    if (is_op_token(node_value)) {
        cstr *left_node_value = node_get_value(node_get_left(node));
        AstNode *right_node = node_get_right(node);
        // convert to actual numbers
        switch (get_op_char(node_value))
        {
            case '*':
				return token_mlt(left_node_value, interpret_ast(right_node));
                break;
            case '/':
                return token_div(left_node_value, interpret_ast(right_node));
                break;
			case '+':
                return token_add(left_node_value, interpret_ast(right_node));
        		break;
			case '-':
                return token_sub(left_node_value, interpret_ast(right_node));
            	break;
            case '^':
                return token_pow(left_node_value, interpret_ast(right_node));
                break;
            default:
                break;
        }
    }
    else { // probably a number token
        // if the right node is null then its the end if the AST
        if (!node_get_right(node)) { return node_get_value(node); }
    }

    return NULL;
}