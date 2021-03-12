#ifndef FUNCTIONS_H
#define FUNCITONS_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "defines.h"


// tools
bool isArithmeticOperator(char ch) {
    return (
        ch == '+' ||
        ch == '-' ||
        ch == '/' ||
        ch == ':' ||
        ch == '*' 
    );
}



bool isBracket(char ch) {
    return (
        ch == '(' ||
        ch == ')'
    ); // TODO: maybe add [] or {}
}

bool isFloatAsString(std::string str) {
    for (char ch : str) {
        if (ch == '.' || ch == ',') {
            return true;
        }
    }
    return false;
}

bool isDot(char ch) {
    return (
        ch == '.' ||
        ch == ','
    );
}

void removeChar(std::string& str, char ch)  {
    auto positions = std::remove(str.begin(), str.end(), ch);
    str.erase(positions, str.end());
}

/*
    

    :param: pos the position of the arithmetic sign in the math expression 
    :return: the numbers in x+y, x-y, etc
*/

std::vector<float64> getNumbersWithArithmeticOp(Args& args, int64 pos) {
    std::vector<float64> numbers;
    int64 math_expression_length = args.math_expression.length();

    // checks if the arithmetic operator is 
    // in front or at the end of the math expression
    // e.g  +1+1 or 32-5-
    auto _npos = args.math_expression.npos;
    if (pos+1 == _npos || pos-1 == _npos) {
        return std::vector<float64>{ERROR__};
    }

    std::string number1;
    for (int i = pos; i < math_expression_length; i++) {
        if (isdigit(args.math_expression[i] || args.math_expression[i] == '.')) {
            number1.append(to_string(args.math_expression[i]));
            continue; // jump to the start of loop
        }
        break;
    }

    std::string number2;
    std::string temporary_string; // holds the inverted number
    for (int i = pos; i > -1; i--) {
        if (isdigit(args.math_expression[i])) {
            temporary_string.append(to_string(args.math_expression[i]));
        }
    }

    for (int i = temporary_string.length(); i > -1; i--) {
        number2.append(to_string(temporary_string[i]));
    }
    
    return std::vector<float64> {
        std::stod(number2),
        std::stod(number1)
    };
    
}



// gets the math expression as string and 
// formats it
std::string input() {
    std::string _in;
    getline(std::cin, _in);

    // remove spaces, e.g:  x + y to x+y
    removeChar(_in, ' ');

    return _in;
}

// active functions 
// that actually change stuff
std::string calculate(Args& args) {


    // find an arithmetic sign
    for (char ch : args.math_expression)  {
        if (isArithmeticOperator(ch)) {

        }
    }

}



#endif // FUNCTIONS_H