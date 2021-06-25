#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include "defines.h"


typedef struct
{
    int length;
    int *ptr;   
} Vector;

typedef struct
{
    int length;
    char **ptr;
} sVector;

void initV(Vector *v);
void initsV(sVector *v);
void appendV(Vector *v, int n);
void appendsV(sVector *v, char *s);
int Vget(Vector *v, int i);
char *sVget(sVector *v, int i);
void deleteVec(Vector *v);
void deletesVec(sVector *v);


Vector* reallocVec(Vector *v, size_t new_size);


#endif // VECTOR_H
