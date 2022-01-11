#pragma once
#include "stdio.h"
#include "stdarg.h"
#include "console.h"

/*
    DEBUG should defined by the compiler flag -DDEBUG in the build file,
    remove it or run another build file if there is any that is flagged as the release build file
*/

#ifdef DEBUG
    #define DEBUG_MESSAGE_VAR(fmt, var, ...) \
        printcolor(FgGreen, "DEBUG:\n");\
        printf("\t%s line: %d,\n\tvar name: %s,\n\tmsg: ", __FILE__, __LINE__, #var);\
        printf(fmt, var, ##__VA_ARGS__);
    
    #define DEBUG_MESSAGE(string) \
        printcolor(FgGreen, "DEBUG:\n");\
        printf("%s line: %d,\n\tmessage: %s", __FILE__, __LINE__, string);
#else
    #define DEBUG_CALL(...)
#endif

