#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(Dlist *head)
{
    /* running loop until reaching NULL*/
    printf("\nResult = ");
    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}