#include "apc.h"
#include <stdlib.h>

void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return;
}