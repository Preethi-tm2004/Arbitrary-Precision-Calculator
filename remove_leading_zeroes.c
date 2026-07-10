#include "apc.h"
#include <stdlib.h>

void remove_leading_zeroes(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    /* Remove zeroes until first non-zero digit */
    while(*head != NULL && (*head)->data == 0 && *head != *tail)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    } 
}