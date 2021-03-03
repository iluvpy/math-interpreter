#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "interpreter.h"


Interpreter::Interpreter() 
: mode(INTERPRET_MODE)
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
    std::cout << expression << std::endl;
    std::cout << "input> ";
    getline(std::cin, expression);

    // remove spaces
    std::string::iterator pos = std::remove(expression.begin(), expression.end(), ' ');
    expression.erase(pos, expression.end());
    calculate();
}

void Interpreter::calculate() {

}

int Interpreter::getParentethisCount() {
    int count = 0;
    for (char ch : expression) {count++;}
    return count;
}