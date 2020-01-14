#include "test.h"

void test1(){

    void* val1;
    Vector *v1=vectorCreate(8);
    printf("The m_size is : %d\n",vectorGetSize(v1));
    printf("The capacity is : %d\n",vectorGetCapacity(v1));

    vectorPush(v1,1);
    vectorPush(v1,2);
    vectorPush(v1,5);
    vectorPush(v1,6);

    if(vectorGetElement(v1,1,&val1)==E_OK) {
        printf("element is index 1 is  %d\n", val1);
        printf("After GetElement : ");
        vectorPrint(v1);
    }
    vectorInsert(v1,112,3);
    if(vectorGetElement(v1,1,&val1)==E_OK) {
        printf("After insert : ");
        vectorPrint(v1);
    }

    vectorPop(v1,&val1);
    if(vectorGetElement(v1,1,&val1)==E_OK) {
        printf("After pop : ");
        vectorPrint(v1);
    }

    vectorRemove(v1,2,&val1);

    if(vectorGetElement(v1,1,&val1)==E_OK) {
        printf("After remove index 2 : ");
        vectorPrint(v1);
    }
    vectorGetElement(v1,&val1,1);
    vectorDestroy(&v1);
}

/*void test(){

    int val1;
    Vector *v1=vectorCreate(8);
    printf("The m_size is : %d\n",vectorGetSize(v1));
    printf("The capacity is : %d\n",vectorGetCapacity(v1));

    if(vectorPush(v1,22)==E_OK) {
        printf("After push : ");
        vectorPrint(v1);
    }
    if(vectorPush(v1,77)==E_OK) {
        printf("After push : ");
        vectorPrint(v1);
    }
    if(vectorPush(v1,66)==E_OK) {
        printf("After push : ");
        vectorPrint(v1);
    }
    if(vectorPush(v1,33)==E_OK) {
        printf("After push : ");
        vectorPrint(v1);
    }
    if(vectorInsert(v1,44,1)==E_OK) {
        printf("After Insert : ");
        vectorPrint(v1);
    }
    if(vectorInsert(v1,55,3)==E_OK) {
        printf("After Insert : ");
        vectorPrint(v1);
    }
    if(vectorPop(v1,&val1)==E_OK) {
        printf("pop result : %d\n", val1);
        printf("After pop : ");
        vectorPrint(v1);
    }
    if(vectorRemove(v1,2,&val1)==E_OK) {
        printf("Remove result : %d\n", val1);
        printf("After Remove : ");
        vectorPrint(v1);
    }
    else
        printf("ERROR_INDEX");

    if(vectorGetElement(v1,1,&val1)==E_OK) {
        printf("element is index 1 is  %d\n", val1);
        printf("After GetElement : ");
        vectorPrint(v1);
    }
    else
        printf("ERROR_INDEX");

    vectorDestroy(&v1);

}
*/