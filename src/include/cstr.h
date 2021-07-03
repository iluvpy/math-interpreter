#ifndef CSTR_H
#define CSTR_H

#include <stdlib.h>
#include <stdbool.h>

#define CSTR_SIZE_ sizeof(cstr)

typedef struct cstr 

{
    size_t size; // characters
    char *str;
    bool free_str; // if string needs to be freed on deletion of cstr
} cstr;

// manipulators


// appends src to dest
void append_str(cstr *dest, char *src);
// appends src to dest
void append_cstr(cstr *dest, cstr *src);

// removes char at index
void cstr_remove(cstr *str, size_t index);
// delets all occurencies of c in str
void cstr_delc(cstr *str, char c);

// frees s
void del_cstr(cstr *s); 
// frees the underlying char * of s
// when free_str is true
void free_cstr_str(cstr *s);

// getters

// returns the char * of s
char *getcstr(cstr *s);

cstr *get_cstr(char *src);
cstr *allocate_cstr(char *src);
// adds 2 cstrings together creating a new one
cstr *add_cstr(cstr *x, cstr *y);

// other
void stdout_cstr(cstr *s);


#endif /* CSTR_H */
