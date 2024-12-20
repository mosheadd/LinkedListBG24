#ifndef LISTС_H
#define LISTС_H


typedef struct iNode
{

    int data;

    struct iNode* next;

}iNode;

typedef struct iListC
{

    size_t size;

    struct iNode* tail;

} iListC;

void iNodeInit(iNode** node, int data);

void iListCCreate(iListC** list, int data);

void iListCFree(iListC** list);

void iListCPrint(iListC* list);

iNode* iListCGetElem(iListC* list, int i);

void iListCPushFront(iListC** list, int data);

void iListCPushBack(iListC** list, int data);

void iListCInsert(iListC** list, int data, int i);

void iListCPopFront(iListC** list);

void iListCPopBack(iListC** list);

void iListCPop(iListC** list, int i);


#endif