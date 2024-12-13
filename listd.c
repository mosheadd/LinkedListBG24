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

}
