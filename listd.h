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


#endif