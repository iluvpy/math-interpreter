#ifndef DEFINES_H
#define DEFINES_H
#include <string>

#define ERROR__ -1
#define NO_NUMBER_ER -0x012f
#define to_string(x) std::to_string(x)

typedef double float64;
typedef long long int64;

typedef struct  
{
    std::string math_expression;
    bool running;

} Args;



#endif // DEFINES_H