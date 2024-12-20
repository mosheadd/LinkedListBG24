#ifndef LISTСD_H
#define LISTСD_H


typedef struct iNodeCD
{

    int data;

    struct iNodeCD* next;
    struct iNodeCD* prev;

}iNodeCD;

typedef struct iListCD
{

    size_t size;

    struct iNodeCD* head;

} iListCD;


iNodeCD* iListCDGetElem(iListCD* list, int i);

void iNodeCDInit(iNodeCD** node, int data);

void iListCDCreate(iListCD** list);

void iListCDFree(iListCD** list);

void iListCDPrint(iListCD* list);

void iListCDPrintReverse(iListCD* list);

void iListCDPushFront(iListCD** list, int data);

void iListCDPushBack(iListCD** list, int data);

void iListCDInsert(iListCD** list, int data, int i);

void iListCDPopFront(iListCD** list);

void iListCDPopBack(iListCD** list);

void iListCDErase(iListCD** list, int i);


#endif