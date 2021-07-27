#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CSTR_SIZE_ sizeof(cstr)
#define CSTR_PTR_SIZE sizeof(cstr*)

typedef struct cstr 
{
    size_t size; // characters
    char *str;
    bool free_str; // if string needs to be freed on deletion of cstr
} cstr;

// manipulators


// appends src to dest
void cstr_append(cstr *dest, char *src);
// appends src to dest
void cstr_appendcs(cstr *dest, cstr *src);
void cstr_appendc(cstr *dest, char c);
// removes char at index
void cstr_remove(cstr *str, size_t index);
// delets all occurencies of c in str
cstr *cstr_delc(cstr *s, char c);
// frees s
void del_cstr(cstr *s); 

// frees the underlying char * of s
// when free_str is true
void free_cstr_str(cstr *s);

// getters

// creates a cstr from an allocated char *
// deallocates the used char * when needed instead of just overwriting it
cstr *cstr_from_allocstr(char *src);

// returns the char * of s
char *cstr_str(cstr *s);
char cstr_getc(cstr *s, size_t index); // return char at index or null if index is invalid
size_t cstr_len(cstr *s); // returns number of chars in cstr (without including null termination)
size_t cstr_size(cstr *s); // return number of chars including null termination
// change cstr value to new value
// generates a new cstr from a char *
cstr *getnew_cstr(cstr *cs, char *src);
cstr *get_cstr(char *src);
// returns copy of src
cstr *cstr_cpy(cstr *src);
// adds 2 cstrings together creating a new one
cstr *add_cstr(cstr *x, cstr *y);
// returns the sum of ascii values 


int str_sum(char *s);
// returns the sum of ascii values 
int cstr_sum(cstr *s);
size_t cstr_last(cstr *s);

// returns true when cs == s
bool cstr_eq_str(cstr *cs, char *s);
bool cstr_is_in(cstr *cs, char c);
int cstr_toi(cstr *str); // to int 
float cstr_tof(cstr *str); // to float
char *bool_str(bool b);
cstr *bool_cstr(bool b);

