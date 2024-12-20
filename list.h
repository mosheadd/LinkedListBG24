#ifndef LIST_H
#define LIST_H


typedef struct iList
{

    int data;

    struct iList* next;

}iList;


void iListCreate(iList** list, int data);

void iListFree(iList** list);

void iListPrint(iList* list);

int iListGetSize(iList* list);

iList* iListGetElem(iList* list, int i);

void iListPushFront(iList** list, int data);

void iListPushBack(iList** list, int data);

void iListInsert(iList** list, int data, int i);

void iListPopFront(iList** list);

void iListPopBack(iList** list);

void iListPop(iList** list, int i);


#endif
