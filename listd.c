#include "list.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "listd.h"

void iListDCreate(iListD **list)
{

    *list = (iListD*)malloc(sizeof(iListD));

    (*list)->head = NULL;
    (*list)->tail = NULL;

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

void iListDGetSize(iListD *list)
{

    int i = 0;

    iNodeD* curr = list->head;

    for(;curr!=NULL;curr = curr->next, i++);

    return i;

}



