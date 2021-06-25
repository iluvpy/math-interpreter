#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct 
{
    int length;
    int *start;   
} iVector;

void initVector(iVector *v, int len);
void appendV(iVector *v, int n);
void deleteVec(iVector *v);

iVector* reallocVec(iVector *v, size_t new_size);


#endif // VECTOR_H
