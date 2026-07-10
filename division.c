#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

Status division(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR)
{

    /* creating count_list and initializing it with 0 */
    Dlist *count_list_head = NULL;
    Dlist *count_list_tail = NULL;

    insert_last(&count_list_head, &count_list_tail, 0);

    /* Creating a list containing digit 1 to increment the count after every successfull subtraction */
    Dlist *one_head = NULL;
    Dlist *one_tail = NULL;

    insert_last(&one_head, &one_tail, 1);

    /* Creating result list for storing subtraction result temporarily */
    Dlist *res_head = NULL;
    Dlist *res_tail = NULL;

    /* Repeat subtraction until dividend become smaller than divisor */
    while(1)
    {
        /* Compare current dividend with diviser */
        int cmp = compare_list(*head1, head2);

        /* break the loop when dividend become smaller than diviser */
        if(cmp < 0)
            break;

        /* perform dividend - divisor */
        subtraction(*tail1, tail2, &res_head, &res_tail);

        /* free memory taken by old dividend */
        delete_list(head1, tail1);

        /* Update dividend with subtraction result */
        *head1 = res_head;
        *tail1 = res_tail;

        remove_leading_zeroes(head1, tail1);

        /* Reset result pointer for further subtraction */
        res_head = NULL;
        res_tail = NULL;

        /* Temporary pointer to store updated count */
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;

        /* To increment count by 1 */
        addition(count_list_tail, one_tail, &temp_head, &temp_tail);

        /* Delete old count_list */
        delete_list(&count_list_head, &count_list_tail);

        /* Update the count_list with updated count value */
        count_list_head = temp_head;
        count_list_tail = temp_tail;

    }

    /* Store final count value in final result list */
    *headR = count_list_head;
    *tailR = count_list_tail;

    return SUCCESS;
}