#include "stddef.h"


typedef struct
{

    int data;

    iList* next = NULL;

} iList;


void iListAdd(iList* node, int data);

void iListprint(iList* node);

void iListfree(iList* node);
