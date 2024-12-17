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

}iListD;


void iListDCreate(iListD** list);

void iListDFree(iListD** list);

void iListDPrint(iListD* list);

void iListDPrintReverse(iListD* list);

void iListDGetSize(iListD* list);


#endif