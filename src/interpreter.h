#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

#define INTERPRET_MODE 1 
#define FILE_MODE 2 
#define COMPILE_MODE 3
#define LIBRARY 4

#define ARITHMETIC_ERROR 5

typedef int8_t int8;

class Interpreter {

public:
    
    Interpreter();
    ~Interpreter();

    void run(); 
    void input();
    void loop(); 
    void calculate(); 
    void output(); 
    void throwErrors(int error=NULL);
    void clear();

    int errorCheck();
    int getOperators();
    
    int getParentethisCount();
    std::vector<float> getNumbers(int position);


private:
    std::string expression;
    bool running = true;
    int mode;
    int length; // length of the input string

    std::vector<int> multiplication_positions;
    std::vector<int> errors;

};



#endif // INTERPRETER_H