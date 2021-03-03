#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include <unistd.h>
#include "interpreter.h"


Interpreter::Interpreter() {

}

Interpreter::~Interpreter() { 

}

void Interpreter::run() {
    loop();
}

void Interpreter::loop() {
    std::cout << expression << std::endl;
    std::cout << "input> ";
    getline(std::cin, expression);

    // remove spaces
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            expression.erase(i, i+1);
        }
    }
   
    calculate();
}

void Interpreter::calculate() {

}

int Interpreter::getParentethisCount() {
    int count = 0;
    for (char ch : expression) {count++;}
    return count;
}