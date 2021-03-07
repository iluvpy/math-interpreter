#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <sstream>
#include "defines.h"

#include <string>

class Interpreter {

public:
    
    Interpreter();
    ~Interpreter();

    // voids
    void run(); 
    void input();
    void loop(); 
    void calculate(); 
    void output(); 
    void throwErrors(int error=NULL);
    void clear();
    void removeChar(char ch);
    void addStep(std::string step);
    void add();
    void subtract(std::vector<double>);
    void divide();
    void multipy();
    void pow();

    // ints
    int errorCheck();
    int getOperators();
    int getParentethisCount();
    
    // other
    std::vector<double> getNumbers(int position);


private:
    std::string expression;
    std::ostringstream solution;
    bool running;
    int mode; // mode
    int length; // length of the input string
    std::vector<int> errors; // error codes

};



#endif // INTERPRETER_H