#include "list.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"


void iListCreate(iList** list, int data)
{

    *list = (iList*)malloc(sizeof(iList));

    if(!*list)
        exit(-1);

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

    iList* buf = NULL;
    
    iListCreate(&buf, data);

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
        last = last->next;

    iList* buf = NULL;

    iListCreate(&buf, data);

    buf->next = NULL;

    last->next = buf;

}


void iListInsert(iList **list, int data, int i)
{

    if(i == 0)
    {
        iListPushFront(list, data);
        return;
    }

    iList* curr = (*list);

    for(int j=0;j<i-1;j++, curr = curr->next);

    iList* buf = NULL;

    iListCreate(&buf, data);

    if(curr->next)
        buf->next = curr->next;
    else
        buf->next = NULL;

    curr->next = buf;

}


void iListPopFront(iList **list)
{

    if(!(*list))
        return;

    iList* buf = *list;

    *list = (*list)->next;

    free(buf);
    buf = NULL;

}


void iListPopBack(iList **list)
{

    if(!(*list))
        return;

    if((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
        return;
    }

    int size = iListGetSize(*list);

    iList* last = iListGetElem(*list, size - 1);
    iList* lastButOne = iListGetElem(*list, size - 2);

    lastButOne->next = NULL;

    free(last);
    last = NULL;

}

void iListPop(iList **list, int i)
{

    int size = iListGetSize(*list);

    if(i >= size || i < 0)
    {
        printf("pop(): Error: wrong index\n\n");
        return;
    }

    if(i == 0)
    {
        iListPopFront(list);
        return;
    }

    iList* curr = (*list);

    for(int j = 0;j<i-1;j++, curr = curr->next);

    iList* deleteto = curr->next;

    if(curr->next->next)
        curr->next = curr->next->next;
    else
        curr->next = NULL;

    free(deleteto);
    deleteto = NULL;

}
