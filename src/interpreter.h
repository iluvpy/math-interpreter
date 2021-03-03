#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

class Interpreter {

public:
    
    Interpreter();
    ~Interpreter();

    void run(); 
    void loop(); 
    void calculate(); 
    void output(); 
    int getParentethisCount();
    


private:
    std::string expression;

};



#endif // INTERPRETER_H