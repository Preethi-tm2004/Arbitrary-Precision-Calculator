#include "apc.h"
#include <stdlib.h>

Status insert_first(Dlist **head, Dlist **tail, int data)
{
    /* create new node */
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    /* update new node */
    new->data = data;
    new->prev = NULL;
    new->next = *head;

    /* if list is empty */
    if(*head == NULL)
    {
        *head = *tail = new;
    }
    /* List is not empty */
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}