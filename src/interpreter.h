#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

#define INTERPRET_MODE 1 
#define FILE_MODE 2 
#define COMPILE_MODE 3
#define LIBRARY 4


typedef signed char int8;

class Interpreter {

public:
    
    Interpreter();
    ~Interpreter();

    void run(); 
    void input();
    void loop(); 
    void calculate(); 
    void output(); 

    int getOperators();
    int getParentethisCount();
    


private:
    std::string expression;
    bool running = true;
    int mode;

};



#endif // INTERPRETER_H