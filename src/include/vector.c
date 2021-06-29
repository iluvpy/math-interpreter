#include "vector.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

#include "defines.h"


void initV(Vector *v) {
    v->length = 0; 
    v->ptr = NULL;
}
void initsV(sVector *v) {
    v->length = 0;
    v->ptr = NULL;
}


void appendV(Vector *v, int n) {
    v->length++;
    int *numbers = (int*)malloc(v->length*sizeof(int));
    for (int i = 0; i < v->length-1; i++) {
        numbers[i] = v->ptr[i];
    }
    numbers[v->length-1] = n;
    deleteVec(v);
    v->ptr = numbers;
}

void appendsV(sVector *v, char *s) {
    v->length++;
    char **strings = (char**)malloc(sizeof(char*)*v->length);
    for (int i = 0; i < v->length-1; i++) {
        strings[i] = (char*)malloc(sizeof(char)*strlen(v->ptr[i]));
    }
    strings[v->length] = (char*)malloc(sizeof(char)*strlen(s));
    strings[v->length] = s;
    deletesVec(v);
    v->ptr = strings;
}


int Vget(Vector *v, int i) {
    if (i >= 0 && i < v->length) {
        return v->ptr[i];
    }
    else {
        debug("tried to access non existent index");
    }
    return -404;
}

char* sVget(sVector *v, int i) {
    if (i >= 0 && i < v->length) {
        return v->ptr[i];
    }
    else {
        debug("tried to access non existent index");
    }
    return NULL;
}


void deleteVec(Vector *v) {
    if (v->ptr != NULL) {
        free(v->ptr);
        v->ptr = NULL;
    }
    v->length = 0;
}

void deletesVec(sVector *v) {
    if (v->ptr != NULL) {
        for (int i = 0; i < v->length; i++) {
            free(v->ptr[i]);
        }
        free(v->ptr);
        v->ptr = NULL;
    }
    v->length = 0;
}

