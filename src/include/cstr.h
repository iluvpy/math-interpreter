#ifndef CSTR_H
#define CSTR_H

#include <stdlib.h>

#define CSTR_NULL -1

typedef struct cstr 
{
    size_t size;
    char *str;
} cstr;

// manipulators

// sets cstring to s and sets size to size
void init_cstr(cstr *cs, char *s);

// appends src to dest
void append_cstr(cstr *dest, char *src);
void del_cstr(cstr *s);
void free_cstr(cstr *s);

// getters

// returns the char * of s
char *getcstr(cstr *s);
cstr *get_cstr(char *src);

// other
void stdout_cstr(cstr *s);


#endif /* CSTR_H */
