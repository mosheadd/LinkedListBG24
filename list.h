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

int iListGetElem(iList* list, int i);

iList* getElem(iList* list, int i);

void iListPushFront(iList** list, int data);

void iListPushBack(iList** list, int data);


#endif
