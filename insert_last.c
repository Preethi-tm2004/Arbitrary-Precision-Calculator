#include "apc.h"
#include <stdlib.h>

Status insert_last(Dlist **head, Dlist **tail, int data)
{
    /* create new list */
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    /* Update new list */
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    /* If the list is empty */
    if(*head == NULL)
    {
        *head = *tail = new;
    }
    /* list is not empty */
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}