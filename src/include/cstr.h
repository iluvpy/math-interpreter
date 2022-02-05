#pragma once


/*
    a string struct with helper functions
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CSTR_SIZE_ sizeof(cstr)
#define CSTR_PTR_SIZE sizeof(cstr*)
#define CSTR_FLOATING_POINT_PRECISION 8
#define STRING_NOT_FOUND -1

typedef struct cstr 
{
    size_t size; // number of characters including null termination
    char *str;
} cstr;

// manipulators
// appends src to dest
void cstr_appendstr(cstr *dest, char *src);
// appends src to dest
void cstr_appendcstr(cstr *dest, cstr *src);
void cstr_appendc(cstr *dest, char c);
void cstr_insert(cstr *dest, cstr *other, int index);
// removes char at index
void cstr_remove(cstr *str, int index);
// removes everything that would come after end index
void cstr_strip(cstr *str, int end);
// delets all occurencies of c in str
cstr *cstr_delc(cstr *s, char c);
// rezises memory occupied by the inner char *
void cstr_resize(cstr *s, size_t size);
// frees s
void del_cstr(cstr *s); 

// frees the underlying char * of s
// when free_str is true
void del_cstr_str(cstr *s);
void cstr_set_last(cstr *string, char new_last_char);
char cstr_get_last(cstr *s);

// getters

// creates a cstr from an allocated char *
// deallocates the used char * when needed instead of just overwriting it
cstr *cstr_from_allocstr(char *src);

// returns the char * of s
char *cstr_str(cstr *s);
char cstr_getc(cstr *s, int index); // return char at index or null if index is invalid
int cstr_len(cstr *s); // returns number of chars in cstr (without including null termination)
int cstr_size(cstr *s); // return number of chars including null termination
int string_find(char *string, char c);
// change cstr value to new value
// generates a new cstr from a char *
cstr *get_newcstr(cstr *cs, char *src);
cstr *get_cstr(char *src);
cstr *cstr_from_long(long n);
cstr *cstr_from_float(double f, int precision);
// returns copy of src
cstr *cstr_cpy(cstr *src);

// returns the sum of ascii values 
int str_sum(char *s);
// returns the sum of ascii values 
int cstr_sum(cstr *s);
int cstr_last(cstr *s);
// returns index of char inside cstr or -1 if it doesnt contain it
int cstr_find(cstr *s, char c);

// returns true when cs == s
bool cstr_eq_str(cstr *cs, char *s);
bool cstr_eq_cstr(cstr *str1, cstr *str2);
bool str_eq_str(char *s1, char *s2);
bool cstr_contains(cstr *cs, char c);
bool cstr_is_float(cstr *str);
bool cstr_is_int(cstr *str);
int cstr_toi(cstr *str); // to int 
double cstr_tof(cstr *str); // to float
char *bool_str(bool b);
cstr *bool_cstr(bool b);
bool str_contains(char * str, char c);

