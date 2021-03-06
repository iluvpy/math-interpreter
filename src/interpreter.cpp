#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "interpreter.h"

#include "defines.h"


/*
    contructor
*/
Interpreter::Interpreter() 
: mode(INTERPRET_MODE), 
  expression(""),
  running(true)
{

}

Interpreter::~Interpreter() { 

}

void Interpreter::run() {
    while (running) {
        loop();    
    }
    
}

void Interpreter::loop() {

    // gets input 
    // and formats the input
    input();

    errorCheck(); // checks for syntax errors in the math expression
    throwErrors(); // throws errors if errorCheck found errors
    if (mode == INTERPRET_MODE)
        std::cout << expression << std::endl;
        calculate();


    throwErrors(); 
    clear(); // clears all vectors, e.g the error vector
}


void Interpreter::input() {
    std::cout << "input> ";
    getline(std::cin, expression);

    // remove spaces, e.g from "1 + 1" to "1+1"
    _remove(' ');

    // updates length 
    length = expression.length();
}


void Interpreter::calculate() {
    if (getParentethisCount() == 0) {
        for (int i = 0; i < length; i++) {
            
        }
    }
}

// gets the numbers x, y in x + y
// or in x*y
// and so on
std::vector<float> Interpreter::getNumbers(int position /*position of arithmetic sign ie: +, *, -, /  */) {

    if (position-1 < length || position+1 > length) {
        errors.push_back(ARITHMETIC_ERROR);
        return std::vector<float>{NULL};
    }

    // update length 
    length = expression.length();
}

/*
    throws errors that where added to the
    Interpreter::errors vector

    param error: default value is NULL
    when not NULL then it will add the 
    error code to the Interpreter::errors vector 
*/
void Interpreter::throwErrors(int error) {
    if (error != NULL) {
        errors.push_back(error);
    }
    
}


/*
    removes chars from the math expression string

    e.g: expression string = " ( 1 + 1 ) " and param ch = ' '
         expression string now = to "(1+1)"
*/
void Interpreter::_remove(char ch) {
    auto position = std::remove(expression.begin(), expression.end(), ch);
    expression.erase(position, expression.end());
} 

/* 
    clear all vectors in this class
    e.g the errors vector
*/
void Interpreter::clear() {
    errors.clear();
}

int Interpreter::getParentethisCount() {
    int count = 0;
    for (char ch : expression) {
        if (ch == '(' | ')') {count++;}
    }
    return count;
}