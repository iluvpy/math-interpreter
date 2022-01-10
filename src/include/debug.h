#pragma once
#include "stdio.h"
#include "stdarg.h"

#ifdef DEBUG
    #define DEBUG_CALL(function, fmt, var, ...) \
        printf("function: %s, line: %d, var name: %s, msg: ", #function, __LINE__, #var);\
        printf(fmt, var, ##__VA_ARGS__);
#else
    #define DEBUG_CALL(...)
#endif

