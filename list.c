#include "list.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"


void iListCreate(iList** list, int data)
{

    *list = (iList*)malloc(sizeof(iList));

    (*list)->data = data;
    (*list)->next = NULL;

}

void iListPrint(iList* list)
{

    while(list != NULL)
    {

        printf("%d ", list->data);
        list = list->next;

    }

    printf("\n\n");

}

void iListPushFront(iList** list, int data)
{

    iList* buf = (iList*)malloc(sizeof(iList));

    buf->data = data;
    buf->next = (*list);

    (*list) = buf;

}

void iListPushBack(iList* list, int data)
{

    iList* last = list;

    while(last->next != NULL)
    {

        last = last->next;

    }

    iList* buf = (iList*)malloc(sizeof(iList));

    buf->data = data;
    buf->next = NULL;

    last->next = buf;

}

