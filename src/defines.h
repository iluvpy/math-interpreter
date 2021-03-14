#ifndef DEFINES_H
#define DEFINES_H
#include <string>
#include <ctype.h>

#define ERROR__ -1 // just some error
#define NO_NUMBER_ER -0x012f

#define to_string(x) std::to_string(x)

typedef double float64;
typedef unsigned long long uint64; // could be more than 64 bits though
typedef long long int64; // could be more than 64 bits though


typedef struct  
{
    std::string math_expression;
    bool running;

} Args;



#endif // DEFINES_H