#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cstr.h"
#include "numbers.h"

// manipulators

// appends src to dest
void cstr_appendstr(cstr *dest, char *src) {
    if (dest && src ) {
        dest->size += strlen(src);
        if (dest->free_str) {dest->str = realloc(dest->str, dest->size);}
		else {dest->str = malloc(dest->size);}
        strcat(dest->str, src);
        dest->free_str = true;
    }
}

// appends src to dest
void cstr_appendcstr(cstr *dest, cstr *src) {
    if (dest && src ) {
        cstr_appendstr(dest, src->str);
    }
}

void cstr_appendc(cstr *dest, char c) {
	dest->size++;
	if (dest->free_str) {
		dest->str = realloc(dest->str, dest->size);
	}
	else {
		dest->str = malloc(dest->size);
	}
	strncat(dest->str, &c, 1);
}

void cstr_insert(cstr *dest, cstr *other, int index) {
	char new_str[dest->size+cstr_len(other)]; 
	char str_rest[dest->size-index]; // the rest of the dest string
	for (int i = 0; i < index+1; i++) {
		new_str[i] = cstr_getc(dest, i);
	}
	for (int i = index; i < cstr_len(dest); i++) str_rest[i] = cstr_getc(dest, i);
	strcat(new_str, other->str);
	strcat(new_str, str_rest);
	dest->size += cstr_len(other);
	if (dest->free_str) dest->str = realloc(dest->str, dest->size);
	else dest->str = malloc(dest->size);
	strcpy(dest->str, new_str);
}

// removes char at index
void cstr_remove(cstr *s, size_t index) {
    if (s ) {
		memmove(&(s->str[index]), &(s->str[index+1]), s->size - index);
		s->size--;
    }
}

// delets all occurencies of c in str
cstr *cstr_delc(cstr *s, char c) {
	size_t found = 0;
	for (int i = 0; i < s->size; i++) {
		if (cstr_getc(s, i) == c) found++;
	}
	if (found > 0) {

		cstr *new_str = get_cstr("");
		for (int i = 0; i < s->size; i++) {
			char cc = cstr_getc(s, i);
			if (cc != c) cstr_appendc(new_str, cc);
		}
		del_cstr(s);
		return new_str;
	}
	return s;
}

// deletes whole cstring and not only the string pointer
void del_cstr(cstr *s) {
    if (s) {
        del_cstr_str(s);
        free(s); 
    }
}

// frees the underlying char * of s
// when free_str is true
void del_cstr_str(cstr *s) {
    if (s) {
       if (s->free_str && s->str) {
            free(s->str);
            s->free_str = false;
        }
    }
}

// returns the char * of s
char *cstr_str(cstr *s) {
    if (s) {
        return (s->str) ? s->str : NULL;
    }
	return NULL;
}

// returns char at index or null if index is invalid 
char cstr_getc(cstr *s, size_t index) {
	if (index >= 0 && index < s->size && s) {
		return s->str[index];
	}
	return '\0';
}

// returns number of chars in cstr (without including null termination)
size_t cstr_len(cstr *s) {
	return s->size-1;
}
// return number of chars including null termination
size_t cstr_size(cstr *s) {
	return s->size;
}

// creates a cstr from an allocated char *
// deallocates the used char * when needed instead of just overwriting it
cstr *cstr_from_allocstr(char *src) {
    if (src == NULL) {return NULL;}
    cstr *cs = malloc(CSTR_SIZE_);
	cs->size = strlen(src)+1;
	cs->str = src;
	cs->free_str = true;
    return cs;
}   


// generates a new cstr from a char * 
cstr *get_cstr(char *src) {
    cstr *s = malloc(CSTR_SIZE_);
    s->size = strlen(src)+1;
    s->str = malloc(s->size);
    strcpy(s->str, src);
    s->free_str = true;
    return s;  
}

cstr *get_newcstr(cstr *old, char *new) {
	del_cstr(old);
	return get_cstr(new);
} 


cstr *cstr_from_long(long n) {
	char str[geti_digits(n)];
	sprintf(str, "%ld", n);
	return get_cstr(str);
}

cstr *cstr_from_float(double f, int precision) {
	char str[geti_digits((int)f)+precision];
	cstr *fmt = get_cstr("");
	cstr *precision_str = cstr_from_long(precision);
	cstr_appendstr(fmt, "%.");
	cstr_appendcstr(fmt, precision_str);
	cstr_appendc(fmt, 'f');
	sprintf(str, cstr_str(fmt), f);

	del_cstr(fmt);
	del_cstr(precision_str);
	return get_cstr(str);
}

// returns copy of src
cstr *cstr_cpy(cstr *src) {
	if (src) {
		char *cpy = malloc(src->size+1);
		strcpy(cpy, src->str);
		return cstr_from_allocstr(cpy);
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

size_t cstr_last(cstr *s) {
	return s->size-1;
}



bool cstr_eq_str(cstr *cs, char *s) {
    return (cstr_sum(cs) - str_sum(s) == 0);
}

bool cstr_eq_cstr(cstr *str1, cstr *str2) {
	return cstr_eq_str(str1, str2->str);
}

bool str_eq_str(char *s1, char *s2) {
	return (str_sum(s1)-str_sum(s2) == 0);
}

bool cstr_is_in(cstr *cs, char c) {
	for (int i = 0; i < cs->size; i++) {
		if (cstr_getc(cs, i) == c) {return true;}
	}
	return false;
}

bool cstr_is_float(cstr *str) {
	return (cstr_is_int(str) && (cstr_is_in(str, '.') || cstr_is_in(str, ',')));
}

bool cstr_is_int(cstr *str) {
	for (int i = 0; i < cstr_len(str); i++) {
		if (isdigit(cstr_getc(str, i))) return true;
	}
	return false;
}


// returns int of cstr if is int and 0 if not int
int cstr_toi(cstr *str) {
	return atoi(str->str);
}

double cstr_tof(cstr *str) {
	return atof(str->str);
}

char *bool_str(bool b) {
    return b ? "True" : "False";
}

cstr *bool_cstr(bool b) {
	return get_cstr(bool_str(b));
}