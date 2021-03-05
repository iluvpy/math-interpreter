#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "interpreter.h"


Interpreter::Interpreter() 
: mode(INTERPRET_MODE), 
  expression("")
{

}

Interpreter::~Interpreter() { 

}

void Interpreter::run() {
    while (1) {
        loop();    
    }
    
}

void Interpreter::loop() {
    // gets input / updates input
    // and formats the input
    input(); 
    errorCheck();
    throwErrors(); 
    if (mode == INTERPRET_MODE)
        std::cout << expression << std::endl;
        calculate();


    throwErrors(); 
    clear(); // clears all vectors
}


void Interpreter::input() {
    std::cout << "input> ";
    getline(std::cin, expression);

    // remove spaces
    std::string::iterator pos = std::remove(expression.begin(), expression.end(), ' ');
    expression.erase(pos, expression.end());

    length = expression.length();
}


void Interpreter::calculate() {
    if (getParentethisCount() == 0) {
        for (int i = 0; i < length; i++) {
            if (i > 0 && i < length) {
                
            }
        }
    }
}

// gets the numbers x, y in x + y
// or in x*y
// and so on
std::vector<float> Interpreter::getNumbers(int position /*position of arithmetic sign ie: +, *, -, /  */) {
    // this would mean that the arithmetic sign ie + - * etc
    // is at the start or at the end of the math expression
    if (position-1 < length || position+1 > length) {
        errors.push_back(ARITHMETIC_ERROR);
        return std::vector<float>{NULL};
    }

    // update length 
    length = expression.length();
}

void Interpreter::throwErrors(int error) {
    if (error == NULL) {

    }
}

void Interpreter::clear() {
    multiplication_positions.clear();
    errors.clear();
}

int Interpreter::getParentethisCount() {
    int count = 0;
    for (char ch : expression) {
        if (ch == '(' | ')') {count++;}
    }
    return count;
}