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


void iListFree(iList **list)
{

    iList* buf = NULL;

    while((*list) != NULL)
    {

        buf = *list;
        (*list) = (*list)->next;
        free(buf);
        buf = NULL;

    }

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


int iListGetElemVal(iList *list, int i)
{

    for(int j=0;list != NULL;j++)
    {

        if(j == i)
            return list->data;

        list = list->next;

    }

    printf("getElemVal(): Error\n");
    return -2147483646;

}


int iListGetSize(iList *list)
{
    int i=0;

    for(;list != NULL;list = list->next, i++);

    return i;
}


iList *iListGetElem(iList *list, int i)
{

    for(int j=0;list != NULL;j++)
    {

        if(j == i)
            return list;

        list = list->next;

    }

    printf("getElem(): Error\n");
    return NULL;
}


void iListPushFront(iList** list, int data)
{

    iList* buf = (iList*)malloc(sizeof(iList));

    buf->data = data;
    buf->next = (*list);

    (*list) = buf;

}


void iListPushBack(iList** list, int data)
{

    if((*list) == NULL)
    {
        iListPushFront(list, data);
        return;
    }

    iList* last = *list;

    while(last->next != NULL)
    {

        last = last->next;

    }

    iList* buf = (iList*)malloc(sizeof(iList));

    buf->data = data;
    buf->next = NULL;

    last->next = buf;

}


void iListInsert(iList **list, int data, int i)
{

    int size = iListGetSize(*list);

    if(i < 0 || i > size)
    {
        printf("iListInsert(): Error: wrong index\n\n");
        return;
    }

    if(i == 0)
    {
        iListPushFront(list, data);
        return;
    }

    if(i == size)
    {
        iListPushBack(list, data);
        return;
    }

    iList* curr = *list;
    iList* after = (*list)->next;

    for(int j=0;;j++, curr = after, after = after->next)
    {

        if(j == i)
        {

            iList* buf = (iList*)malloc(sizeof(iList));

            buf->data = data;
            buf->next = after;

            curr->next = buf;

            return;

        }

    }

}
