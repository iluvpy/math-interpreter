#ifndef INTERPRETER_H
#define INTERPRETER_H

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
    void _remove(char ch);

    // ints
    int errorCheck();
    int getOperators();
    int getParentethisCount();
    
    // other
    std::vector<float> getNumbers(int position);


private:
    std::string expression;
    bool running;
    int mode;
    int length; // length of the input string
    std::vector<int> errors;

};



#endif // INTERPRETER_H