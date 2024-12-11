#include "list.h"
#include "stddef.h"


void iListCreate(iList** list, int data)
{

    *list = (iList*)malloc(sizeof(iList));

    (*list)->data = data;
    (*list)->next = NULL;

}
