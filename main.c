#include "stdio.h"
#include "stdlib.h"

#include "list.h"
#include "list.c"

#include "listd.h"
#include "listd.c"

#include "listc.h"
#include "listc.c"

#include "listcd.h"
#include "listcd.c"


int main()
{


    printf("------------\n\n");

    iList* list = NULL;

    iListCreate(&list, 0);

    for(int i=1;i<10;i++)
        iListPushBack(&list, i);

    iListPrint(list);

    iListPopFront(&list);

    iListPrint(list);

    iListPushFront(&list, -1);
    iListInsert(&list, 10, 4);

    iListPrint(list);

    iListPopBack(&list);
    iListPushBack(&list, 10);

    iListPrint(list);

    iListFree(&list);

    iListCreate(&list, 0);

    iListPrint(list);

    for(int i=1;i<10;i++)
    {
        iListPushBack(&list, i);
        iListPushFront(&list, i);
    }

    iListPrint(list);

    iListFree(&list);

    printf("-------------\n\n");

    iListCD* listcd = NULL;

    iListCDCreate(&listcd);

    for(int i=0;i<10;i++)
        iListCDPushFront(&listcd, i);

    iListCDPrint(listcd);


    for(int i=0;i<3;i++)
        iListCDErase(&listcd, listcd->size / 2);

    iListCDPrint(listcd);

    iListCDPrintReverse(listcd);

    iListCDFree(&listcd);
    
    

    return 0;
}