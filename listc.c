#include "listc.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "listd.h"
#include "listc.h"

void iNodeInit(iNode **node, int data)
{

    *node = (iNode*)malloc(sizeof(iNode));

    if(!*node)
        exit(-1);

    (*node)->data = data;
    (*node)->next = NULL;

}

void iListCCreate(iListC **list, int data)
{

    *list = (iListC*)malloc(sizeof(iListC));

    if(!*list)
        exit(-1);
    
    iNodeInit(&(*list)->head, data);

    (*list)->size = 1;
    (*list)->head->next = (*list)->head;

}


void iListCFree(iListC **list)
{

    iNode* buf = NULL;

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


void iListCPrint(iListC *list)
{

    iNode* buf = list->head;

    for(int i=0;i<list->size;i++)
    {

        printf("%d ", buf->data);
        buf = buf->next;

    }

    printf("\n\n");

}


iNode *iListCGetElem(iListC *list, int i)
{

    if(i < 0 || i > list->size)
    {
        printf("getElem(): Error\n");
        return NULL;
    }

    iNode* curr = list->head;

    for(int j = 0;j < i;j++, curr = curr->next);

    printf("getElem(): Error\n");
    return curr;
}

void iListCPushFront(iListC **list, int data)
{

    if((*list) == NULL)
    {
        iListCCreate(list, data);
        return;
    }

    iNode* buf = NULL;
    
    iNodeInit(&buf, data);

    buf->next = (*list)->head;

    iNode* last = (*list)->head;

    while(last->next != (*list)->head)
        last = last->next;

    last->next = buf;

    (*list)->head = buf;

    (*list)->size++;
    
}


void iListCPushBack(iListC **list, int data)
{

    if((*list) == NULL)
    {
        iListCCreate(list, data);
        return;
    }

    iNode* last = (*list)->head;

    while(last->next != (*list)->head)
        last = last->next;

    iNode* buf = NULL;

    iNodeInit(&buf, data);

    buf->next = (*list)->head;

    last->next = buf;

    (*list)->size++;

}


void iListCPopFront(iListC **list)
{

    iNode* last = (*list)->head;

    while(last->next != (*list)->head)
        last = last->next;

    if(last == (*list)->head)
    {
        (*list)->head->next = NULL;
        free((*list)->head);
        (*list)->head = NULL;
        return;
    }

    iNode* buf = (*list)->head;

    last->next = (*list)->head->next;
    (*list)->head = (*list)->head->next;

    free(buf);
    buf = NULL;

    (*list)->size--;

}


void iListCPopBack(iListC **list)
{

    iNode* lastbutone = (*list)->head;

    while(lastbutone->next->next != (*list)->head)
        lastbutone = lastbutone->next;

    if((*list)->size == 1)
    {
        (*list)->head->next = NULL;
        free((*list)->head);
        (*list)->head = NULL;
        return;
    }

    iNode* last = lastbutone->next;

    lastbutone->next = (*list)->head;

    free(last);
    last = NULL;

    (*list)->size--;

}

