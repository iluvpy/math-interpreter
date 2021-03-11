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

    std::string number_1;
    for (int i = 0; i < math_expression_length; i++) {
        if (isdigit(args.math_expression[i])) {
            number_1.append(to_string(args.math_expression[i]));
            continue; // jump to the start of loop
        }
        break;
    }

    std::string number2;

    
    
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