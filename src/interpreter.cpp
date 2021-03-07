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
    removeChar(' ');

    // updates length 
    length = expression.length();
}


void Interpreter::calculate() {
    int result;
    if (getParentethisCount() == 0) {
        for (int i = 0; i < length; i++) {
            if (expression[i] == ARITHMETIC_OPERATOR) {
                std::vector<double> numbers = getNumbers(i);
                

                switch (expression[i]) {
                    case '+':
                        result = numbers[1]+numbers[0];
                    case '-':
                        result = numbers[1]-numbers[0];
                    case '*':
                        result = numbers[1]*numbers[0];
                    case '/' | ':':
                        result = numbers[1]/numbers[0];
                    case '^':
                        result = std::pow(numbers[1], numbers[0]);
                }

                int number_length = std::to_string(result).length();
                int start_pos, end_pos = numbers[2], numbers[3];
                
            }
        }
    }
  
    
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



/* gets the numbers x, y in x + y
// or in x*y 
// and so on
// e.g:  65-77 it would return std::vector<double>{65, -77}
// 
// :return: returns a double vector that contains the 2 numbers
//          and the start position of the x+y expression and the end pos-
//          tion 
// e.g : 100+5 here 0 is the start position and 4 is the end position
*/           
std::vector<double> Interpreter::getNumbers(int position /*position of arithmetic sign ie: +, *, -, /  */) {
    std::vector<double> nums;
    int end_pos;
    if (position-1 < length || position+1 > length) {
        errors.push_back(ARITHMETIC_ERROR);
        return std::vector<double>{NULL};
    }

    int i = position;
    std::string num1;
    for (;;) {
        i++;
        if (expression[i] != ARITHMETIC_OPERATOR && expression[i] != BRACKETS) {
            num1.append(std::string{expression[i]});
            continue;
        }
        else if (expression[i] == BRACKETS) {continue;}
        break;
    }
    
    i = position;
    std::string num2;
    for (;;) {
        i--;
        if (expression[i] != ARITHMETIC_OPERATOR || expression[i] == BRACKETS) {continue;}
        break;
    }

    for (int j = i; j < position; j++) {
        num2.append(std::string{expression[j]});
    }
    
    nums = {std::stod(num1), std::stod(num2), (double)(i), (double)(end_pos)};
    return nums;
}

// adds a new string and a new line to the solution ostringstream
// :param: step is the string that is added
void Interpreter::addStep(std::string step) {
    solution << step << "\n";
}

/*
    removes chars from the math expression string

    e.g: expression string = " ( 1 + 1 ) " and param ch = ' '
         expression string now equals to "(1+1)"
*/
void Interpreter::removeChar(char ch) {
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