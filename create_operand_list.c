#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

Status create_operand_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;

    /* create operand list by converting string's characters to integers */
    while(str[i] != '\0')
    {
        insert_last(head, tail, str[i] - '0');
        i++;
    }

    return SUCCESS;
}

