#include "vector.h"

Vector* vectorCreate(size_t capacity)
{
    int flag=0;
    size_t tmp;
    Vector *newvector = malloc(sizeof(newvector));
    tmp = capacity;


    /*check power of two*/
    while(tmp!=1)
    {
        if(tmp%2!=0){
            flag=1;
            break;
        }
        tmp=tmp/2;
    }

    if(flag==1) {
        tmp = 2;
        while (tmp<capacity)
            tmp=tmp*2;
        capacity=tmp;
    }

    newvector->m_values = malloc(sizeof(void*)*capacity);
    newvector->m_capacity = capacity;
    newvector->m_size = 0;
    return newvector;
}

void vectorDestroy(Vector** vec) //param : Vector ** pvec
{
    free((*vec)->m_values);
    free(*vec);
}
ErrorCode vectorPush(Vector* vec,void* val)
{
    if(vec->m_size == vec->m_capacity) {
        vec->m_values = (void* *) realloc(vec->m_values, vec->m_capacity * 2 * sizeof(void*));
        if(vec->m_values==NULL)
            return E_ALLOCATION_ERROR;
    }

    vec->m_values[vec->m_size]=val;
    ++vec->m_size;
    return E_OK;
}
ErrorCode vectorInsert(Vector* vec,void* value, size_t index) ///should check the index
{
    if(index < 0){
        return E_UNDERFLOW;
    }
    if(vec->m_values[index]!=value)
        if(shiftRight(vec,index)==(E_BAD_INDEX || E_ALLOCATION_ERROR))
            return     ++vec->m_size;
    ;
    vec->m_values[index]=value;
    ++vec->m_size;
    return E_OK;
}
static ErrorCode shiftRight(Vector* vec,size_t index)
{
    int length=vec->m_size;
    int i=0;
    if(index>length)
        return E_BAD_INDEX;
    if(vec->m_capacity==length) {
        vec->m_values = (void**) realloc(vec->m_values, vec->m_capacity * 2 * sizeof(void*)); ////should check the realloc
        if (vec->m_values == NULL)
            return E_ALLOCATION_ERROR;
    }
    --length;
    for (i = length; i >=index; i--)
        vec->m_values[i+1]=vec->m_values[i];
    return E_OK;
}
static void shiftLeft(Vector* vec,size_t index)            /////done
{
    int i ;
    for(i = index;i<vec->m_size-1;i++)
        vec->m_values[i]=vec->m_values[i+1];
    --vec->m_size;
}

ErrorCode vectorPop(Vector *vec ,void* *val) ////if(vectorPop(...) !=Err_t)
{
    if(vec->m_size==0)
        return E_NULL_PTR;
    *val=vec->m_values[vec->m_size-1];
    vec->m_values[vec->m_size-1]=0;
    --vec->m_size;
    return E_OK;
}
ErrorCode vectorRemove(Vector *vec ,size_t index,void**val) ////if(vectorPop(...) !=Err_t)
{
    if (index < 0){
        return E_UNDERFLOW;
    }
    if (index > vec->m_size-1)
        return E_BAD_INDEX;
    *val = vec->m_values[index];
    vec->m_values[index] = 0;
    shiftLeft(vec, index);

    return E_OK;
}

ErrorCode vectorGetElement(const Vector* vec,size_t index, void **val){
    if(index > vec->m_size)
        return E_BAD_INDEX;
    *val = vec->m_values[index];
    return E_OK;
}
ErrorCode vectorSetElement(Vector* vec ,size_t index, void* value)
{
    if(index < 0){
        return E_UNDERFLOW;
    }
    if(vec->m_size<index)
        return E_BAD_INDEX;

    vec->m_values[index]=value;
    return E_OK;
}

size_t vectorGetSize(const Vector * vec)
{
    return vec->m_size;
}

size_t vectorGetCapacity(const Vector * vec)
{
    return vec->m_capacity;
}
size_t vectorCount(const Vector * vec,void* val)
{
    int i;
    size_t count=0;
    for(i=0;i<vec->m_size;++i)
        if(vec->m_values[i]==val)
            count++;

    return count;
}
void vectorPrint(const Vector * vec)
{
    int i;
    for(i=0;i<(vec->m_size);++i) {
        printf("%d , ", vec->m_values[i]);
    }
    printf("\n");
}
