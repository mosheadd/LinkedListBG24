#include "list.h"



void iListAdd(iList* node, int data)
{

    while(node->next == NULL)
    {
        node = node->next;
    }

    node->next = (iList*)malloc(sizeof(iList));

    node = node->next;
    node->data = data;

}

void iListfree(iList* node)
{

    free(node->next);

}

void iListprint(iList* node)
{

    while(node->next != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    
}
