#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cstr.h"

// manipulators

// appends src to dest
void append_str(cstr *dest, char *src) {
    if (dest != NULL && src != NULL) {
        dest->size += strlen(src);
        dest->str = realloc(dest->str, dest->size);
        strcat(dest->str, src);
        dest->free_str = true;
    }
}

// appends src to dest
void append_cstr(cstr *dest, cstr *src) {
    if (dest != NULL && src != NULL) {
        append_str(dest, src->str);
    }
}

// removes char at index
void cstr_remove(cstr *s, size_t index) {
    if (s != NULL) {
        s->size--;
        char cpy[s->size];
        for (int i = 0; i < s->size; i++) {
            if (i >= s->size-1) {break;}
            if (i != index) {
                cpy[i] = s->str[i];
                continue;
            }
        }
        if (s->free_str) {free_cstr_str(s);}
        s->str = malloc(s->size);
        strcpy(s->str, cpy);
        s->free_str = true;
    }
}

// delets all occurencies of c in str
void cstr_delc(cstr *s, char c) {}

// deletes whole cstring and not only the string pointer
void del_cstr(cstr *s) {
    if (s != NULL) {
        free_cstr_str(s);
        free(s); 
        s = NULL;
    }
}

// frees the underlying char * of s
// when free_str is true
void free_cstr_str(cstr *s) {
    if (s != NULL) {
       if (s->free_str && s->str != NULL) {
            free(s->str);
            s->free_str = false;
        }
    }
}



// getters


// returns the char * of s
char *getstr(cstr *s) {
    if (s != NULL) {
        return (s->str != NULL) ? s->str : NULL;
    }
	return NULL;
}

// creates a cstr from an allocated char *
// deallocates the used char * when needed
// instead of just overwriting it
cstr *cstr_from_allocstr(char *src) {
    if (src == NULL) {return NULL;}
    cstr *cs = get_cstr(src);
    cs->free_str = true;
    return cs;
}   

// change cstr value to new value
// uses get_cstr to create new cstr
cstr *getnew_cstr(cstr *cs, char *src) {
    if (cs != NULL) {
        del_cstr(cs);
        return get_cstr(src);
    }
	return NULL;
}   

// change cstr value to new value
// uses allocate_cstr to create new cstr
// i.e it allocates new memory for src
// instead of just using that char *
cstr *allocnew_cstr(cstr *cs, char *src) {
    if (cs != NULL) {
        del_cstr(cs);
        return allocate_cstr(src);
    }
	return NULL;
}

// generates a new cstr and allocates memory
// uses src as the char pointer without allocating a new one
cstr *get_cstr(char *src) {
    if (src == NULL) {return NULL;}
    cstr *s = malloc(CSTR_SIZE_);
    s->size = strlen(src);
    s->str = src;
    s->free_str = false;
    return s;    
}

// works like get_cstr but 
// allocates the memory for the 
// underlying char * and copies src into it
cstr *allocate_cstr(char *src) {
    cstr *s = malloc(CSTR_SIZE_);
    s->size = strlen(src);
    s->str = malloc(s->size);
    strcpy(s->str, src);
    s->free_str = true;
    return s;
} 


// adds 2 cstrings together creating a new one
cstr *add_cstr(cstr *x, cstr *y) {
    if (x != NULL && y != NULL) {
        char res[x->size+x->size];
        strcpy(res, getstr(x));
        strcat(res, getstr(y));
        return allocate_cstr(res); 
    }

    return NULL;
}


int str_sum(char *s) {
    size_t sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        sum += s[i];
    }
    return sum;
}

// returns the sum of ascii values 
int cstr_sum(cstr *s) {
    return str_sum(s->str);
}


// other
void stdout_cstr(cstr *s, bool endl) {
    printf("%s%c", getstr(s), (endl) ? '\n' : '\0');
}


bool cstr_eq_str(cstr *cs, char *s) {
    return (cstr_sum(cs) - str_sum(s) == 0);
}