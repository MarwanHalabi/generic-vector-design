#ifndef VECTOR_OF_INTS_VECTOR_H
#define VECTOR_OF_INTS_VECTOR_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    size_t m_size;   ///cuurent capacity
    size_t m_capacity;  ////num of element in m_values
    void** m_values;
} Vector;

typedef enum
{
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

Vector* vectorCreate ( size_t size) ;
void vectorDestroy (Vector **vector) ;
/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush (Vector *vector, void* value) ;
/* Adds an item at a certain position and shifts. Grows if needed (by *
2) */
ErrorCode vectorInsert (Vector *vector, void* value, size_t index) ;
/* Clears the item at the end. */
ErrorCode vectorPop (Vector *vector, void** res) ;
/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove (Vector *vector, size_t index, void** res) ;
ErrorCode vectorGetElement ( const Vector *vector, size_t index,void** res) ;
ErrorCode vectorSetElement (Vector *vector, size_t index, void* value) ;
size_t vectorGetSize( const Vector * vector );
size_t vectorGetCapacity( const Vector * vector );
/* Counts how many instances of a given value there are. */
size_t vectorCount( const Vector * vector , void* value);

static ErrorCode shiftRight(Vector* vec,size_t index);
static void shiftLeft(Vector* vec,size_t index);
void vectorPrint(const Vector * vec);
#ifdef _DEBUG
void vectorPrint (Vector *vector) ;
#endif /* _DEBUG */
#endif
