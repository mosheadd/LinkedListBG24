#include "listc.h"
#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "listd.h"


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
    
    iNodeInit(&(*list)->tail, data);

    (*list)->size = 1;
    (*list)->tail->next = (*list)->tail;

}


void iListCFree(iListC **list)
{

    iNode* buf = NULL;

    for(int i=0;i<(*list)->size;i++)
    {

        if(i == (*list)->size - 1)
        {
            (*list)->tail->next = NULL;
            free((*list)->tail);
            (*list)->tail = NULL;
            break;
        }

        buf = (*list)->tail;
        (*list)->tail = (*list)->tail->next;
        free(buf);
        buf = NULL;

    }

}


void iListCPrint(iListC *list)
{

    iNode* buf = list->tail->next;

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

    iNode* curr = list->tail->next;

    for(int j = 0;j < i;j++, curr = curr->next);

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

    buf->next = (*list)->tail->next;

    (*list)->tail->next = buf;

    (*list)->size++;
    
}


void iListCPushBack(iListC **list, int data)
{

    if((*list) == NULL)
    {
        iListCCreate(list, data);
        return;
    }

    iNode* buf = NULL;

    iNodeInit(&buf, data);

    buf->next = (*list)->tail->next;

    (*list)->tail->next = buf;
    (*list)->tail = buf;

    (*list)->size++;

}


void iListCInsert(iListC **list, int data, int i)
{

    if(i == 0)
    {
        iListCPushFront(list, data);
        return;
    }

    iNode* beforei = iListCGetElem(*list, i - 1);

    iNode* buf = NULL;
    iNodeInit(&buf, data);

    buf->next = beforei->next;
    beforei->next = buf;

    if(i == (*list)->size)
        (*list)->tail = buf;

    (*list)->size++;


}


void iListCPopFront(iListC **list)
{

    if((*list)->size == 1)
    {
        (*list)->tail->next = NULL;
        free((*list)->tail);
        (*list)->tail = NULL;
        return;
    }

    iNode* head = (*list)->tail->next;

    (*list)->tail->next = head->next;

    free(head);
    head = NULL;

    (*list)->size--;

}


void iListCPopBack(iListC **list)
{
    
    if((*list)->size == 1)
    {
        (*list)->tail->next = NULL;
        free((*list)->tail);
        (*list)->tail = NULL;
        return;
    }

    iNode* lastbutone = iListCGetElem(*list, (*list)->size - 2);
    iNode* last = (*list)->tail;

    lastbutone->next = (*list)->tail->next;

    (*list)->tail = lastbutone;

    free(last);
    last = NULL;

    (*list)->size--;

}


void iListCPop(iListC **list, int i)
{

    if(i < 0 || i >= (*list)->size)
        return;

    iNode* beforei = NULL;

    if(i == 0)
        beforei = (*list)->tail;
    else
        beforei = iListCGetElem(*list, i - 1);
    
    iNode* deleteto = beforei->next;


    beforei->next = deleteto->next;

    if(i == (*list)->size - 1)
        (*list)->tail = beforei;


    free(deleteto);
    deleteto = NULL;

    (*list)->size--;

}
