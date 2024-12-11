typedef struct iList
{

    int data;

    struct iList* next;

}iList;


void iListCreate(iList** list, int data);

void iListPrint(iList* list);

void iListPushFront(iList** list, int data);

void iListPushBack(iList* list, int data);

