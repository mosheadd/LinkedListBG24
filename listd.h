#ifndef LISTD_H
#define LISTD_H


typedef struct iNodeD
{

    int data;

    struct iNodeD* next;
    struct iNodeD* prev;

} iNodeD;


typedef struct iListD
{

    iNodeD* head;
    iNodeD* tail;

    size_t size;

}iListD;



iNodeD* iListDGetElem(iListD* list, int i);

void iListDCreate(iListD** list);

void iListDFree(iListD** list);

void iListDPrint(iListD* list);

void iListDPrintReverse(iListD* list);

void iListDPushFront(iListD** list, int data);

void iListDPushBack(iListD** list, int data);

void iListDInsert(iListD** list, int data, int i);



#endif