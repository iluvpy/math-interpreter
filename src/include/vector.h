#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>



typedef struct
{
    int length;
    int *start;   
} Vector;

typedef struct
{
    int length;
    char **start;
} sVector;

void initV(Vector *v);
void initsV(sVector *v);
void appendV(Vector *v, int n);
void appendsV(sVector *v, char *s);
void deleteVec(Vector *v);
void deletesVec(sVector *v);


Vector* reallocVec(Vector *v, size_t new_size);


#endif // VECTOR_H
