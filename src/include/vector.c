#include "vector.h"

#include <string.h>

void initV(Vector *v) {v->length = 0;}
void initsV(sVector *v) {v->length = 0;}


void appendV(Vector *v, int n) {
    v->length++;
    int *numbers = (int*)malloc(v->length*sizeof(int));
    for (int i = 0; i < v->length-1; i++) {
        numbers[i] = v->start[i];
    }
    numbers[v->length-1] = n;
    deleteVec(v);
    v->start = numbers;
}

void appendsV(sVector *v, char *s) {
    v->length++;
    char **strings = (char**)malloc(sizeof(char*)*v->length);
    for (int i = 0; i < v->length-1; i++) {
        strings[i] = (char*)malloc(sizeof(char)*strlen(v->start[i]));
    }
    strings[v->length] = (char*)malloc(sizeof(char)*strlen(s));
    strings[v->length] = s;
    deletesVec(v);
    v->start = strings;
}

void deleteVec(Vector *v) {
    free(v->start);
}

void deletesVec(sVector *v) {
    for (int i = 0; i < v->length; i++) {
        free(v->start[i]);
    }
    free(v->start);
}

