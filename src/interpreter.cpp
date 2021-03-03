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

    if (mode == INTERPRET_MODE)
        std::cout << expression << std::endl;
        calculate();
}


void Interpreter::input() {
    std::cout << "input> ";
    getline(std::cin, expression);

    // remove spaces
    std::string::iterator pos = std::remove(expression.begin(), expression.end(), ' ');
    expression.erase(pos, expression.end());
}


void Interpreter::calculate() {
    if (getParentethisCount() == 0) {

    }
}

int Interpreter::getOperators() {
    
}

int Interpreter::getParentethisCount() {
    int count = 0;
    for (char ch : expression) {count++;}
    return count;
}