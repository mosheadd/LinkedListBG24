#include "stdio.h"
#include "stdlib.h"

#include "list.h"


int main()
{

    iList list;
    list.data = 1;

    iListadd(&list, 2);

    iListprint(&list);

    iListfree(&list);

    return 0;
}