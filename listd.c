#include "list.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "listd.h"

iNodeD *iListDGetElem(iListD *list, int i)
{

    if(i < 0 || i > list->size)
    {
        printf("iListDGetElem: Error\n\n");
        return NULL;
    }

    if(i <= list->size / 2)
    {

        iNodeD* curr = list->head;

        for(int j=0;j<i;j++, curr = curr->next);

        return curr;

    }

    iNodeD* curr = list->tail;

    for(int j=list->size;j>i;j--, curr = curr->prev);

    return curr;
}


void iListDCreate(iListD **list)
{

    *list = (iListD*)malloc(sizeof(iListD));

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;

}


void iListDFree(iListD **list)
{

    iNodeD* buf = (*list)->head;

    while(buf != NULL)
    {
        free(buf->prev);
        buf->prev = NULL;
        buf = buf->next;
    }

    free((*list)->tail);
    (*list)->tail = NULL;

}


void iListDPrint(iListD *list)
{

    iNodeD* curr = list->head;

    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n\n");

}


void iListDPrintReverse(iListD *list)
{

    iNodeD* curr = list->tail;

    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }

    printf("\n\n");

}


void iListDPushFront(iListD **list, int data)
{

    iNodeD* buf = (iNodeD*)malloc(sizeof(iNodeD));

    buf->data = data;
    buf->prev = NULL;

    if((*list)->head == NULL)
    {

        buf->next = NULL;

        (*list)->head = buf;
        (*list)->tail = buf;

        return;

    }

    buf->next = (*list)->head;
    (*list)->head->prev = buf;

    (*list)->head = buf;

    (*list)->size++;


}


void iListDPushBack(iListD **list, int data)
{

    iNodeD* buf = (iNodeD*)malloc(sizeof(iNodeD));

    buf->data = data;
    buf->next = NULL;

    if((*list)->tail == NULL)
    {

        buf->prev = NULL;

        (*list)->head = buf;
        (*list)->tail = buf;

        return;

    }

    buf->prev = (*list)->tail;
    (*list)->tail->next = buf;
    (*list)->tail = buf;

    (*list)->size++;

}

void iListDInsert(iListD **list, int data, int i)
{

    if(i == 0)
    {
        iListDPushFront(list, data);
        return;
    }

    if((*list)->size + 1 == i)
    {
        iListDPushBack(list, data);
        return;
    }

    if((*list)->head == NULL || i < 0 || i > (*list)->size)
    {
        printf("iListDInsert(): Error\n\n");
        return;
    }

    iNodeD* iElem = iListDGetElem(*list, i);

    iNodeD* buf = (iNodeD*)malloc(sizeof(iNodeD));

    buf->data = data;
    buf->next = iElem;
    buf->prev = iElem->prev;

    if(iElem->prev)
        buf->prev->next = buf;

    iElem->prev = buf;

    (*list)->size++;


}
