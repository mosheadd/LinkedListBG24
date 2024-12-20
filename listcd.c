#include "listcd.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "listd.h"


iNodeCD *iListCDGetElem(iListCD *list, int i)
{

    if(i < 0 || i > list->size)
        return NULL;
    
    if(i < list->size / 2)
    {

        iNodeCD* curr = list->head;

        for(int j = 0; j < i ; j++, curr = curr->next);
        return curr;
    }
    iNodeCD* curr = list->head->prev;

    for(int j = list->size - 1; j > i; j--, curr = curr->prev);
    return curr;
    

}


void iNodeCDInit(iNodeCD **node, int data)
{

    *node = (iNodeCD*)malloc(sizeof(iNodeCD));

    if(!(*node))
        exit(-1);

    (*node)->data = data;

}


void iListCDCreate(iListCD **list)
{

    *list = (iListCD*)malloc(sizeof(iListCD));

    (*list)->head = NULL;
    (*list)->size = 0;

}


void iListCDFree(iListCD **list)
{

    iNodeCD* buf = NULL;

    for(int i=0;i<(*list)->size;i++)
    {

        if(i == (*list)->size - 1)
        {
            (*list)->head->next = NULL;
            free((*list)->head);
            (*list)->head = NULL;
            break;
        }

        buf = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(buf);
        buf = NULL;

    }

}


void iListCDPrint(iListCD *list)
{

    for(int i=0;i<list->size;i++)
    {
        printf("%d ", list->head->data);
        list->head = list->head->next;
    }

    printf("\n\n");

}


void iListCDPrintReverse(iListCD *list)
{

    iNodeCD* curr = list->head->prev;

    for(int i=0;i<list->size;i++)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }

    printf("\n\n");

}


void iListCDPushFront(iListCD **list, int data)
{

    iNodeCD* buf = NULL;
    iNodeCDInit(&buf, data);

    if((*list)->head == NULL)
    {
        buf->next = buf;
        buf->prev = buf;
        (*list)->head = buf;
        (*list)->size = 1;
        return;
    }

    buf->next = (*list)->head;
    buf->prev = (*list)->head->prev;

    (*list)->head->prev->next = buf;
    (*list)->head->prev = buf;

    (*list)->head = buf;

    (*list)->size++;

}


void iListCDPushBack(iListCD **list, int data)
{

    iNodeCD* buf = NULL;
    iNodeCDInit(&buf, data);

    if((*list)->head == NULL)
    {
        buf->next = buf;
        buf->prev = buf;
        (*list)->head = buf;
        (*list)->size = 1;
        return;
    }

    buf->next = (*list)->head;
    buf->prev = (*list)->head->prev;

    (*list)->head->prev->next = buf;
    (*list)->head->prev = buf;

    (*list)->size++;

}


void iListCDInsert(iListCD **list, int data, int i)
{

    if(i < 0 || i > (*list)->size)
        return;

    if(i == (*list)->size)
    {
        iListCDPushBack(list, data);
        return;
    }

    iNodeCD* curr = iListCDGetElem(*list, i);

    iNodeCD* buf = NULL;
    iNodeCDInit(&buf, data);

    buf->next = curr;
    buf->prev = curr->prev;

    curr->prev->next = buf;
    curr->prev = buf;

    if(i == 0)
        (*list)->head = buf;

    (*list)->size++;

}


void iListCDPopFront(iListCD **list)
{

    if((*list)->head == NULL)
        return;


    iNodeCD* head = (*list)->head;

    if((*list)->size == 1)
    {
        (*list)->head = NULL;
    }
    else
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        (*list)->head = head->next;
    }

    free(head);
    head = NULL;

    (*list)->size--;

}


void iListCDPopBack(iListCD **list)
{

    if((*list)->head == NULL)
        return;

    
    iNodeCD* last = (*list)->head->prev;

    if((*list)->size == 1)
    {
        (*list)->head = NULL;
    }
    else
    {
        last->prev->next = (*list)->head;
        (*list)->head->prev =  last->prev;
    }

    free(last);
    last = NULL;

    (*list)->size--;

}


void iListCDErase(iListCD **list, int i)
{

    if(i < 0 || i > (*list)->size)
        return;

    iNodeCD* deleteto = iListCDGetElem(*list, i);

    deleteto->prev->next = deleteto->next;
    deleteto->next->prev = deleteto->prev;

    if((*list)->size == 1)
        (*list)->head = NULL;
    else if(i == 0)
        (*list)->head = deleteto->next;

    free(deleteto);
    deleteto = NULL;

    (*list)->size--;

}
