#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

Status multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = tail2;

    /* temporary variable to store the count of zeroes */
    int count = 0;

    /* Outer loop for operand 2*/
    while(temp2)
    {
        int carry = 0;

        /* temporary pointer to store partial product */
        Dlist *headr1 = NULL;
        Dlist *tailr1 = NULL;

        Dlist *temp1 = tail1;

        /* Inner loop for operand 2*/
        while(temp1)
        {
            int product = temp1->data * temp2->data + carry;

            int digit = product % 10;
            carry = product / 10;

            insert_first(&headr1, &tailr1, digit);

            temp1 = temp1->prev; //traversing
        }

        if(carry)
        {
            insert_first(&headr1, &tailr1, carry);
        }

        /* append zeroes after every iteration of multiplication depending on the shift count */
        for(int i = 0 ; i < count; i++)
        {
            insert_last(&headr1, &tailr1, 0);
        }
        /* initializing headR pointer with temporary partial product if headR is empty */
        if(*headR == NULL)
        {
            *headR = headr1;
            *tailR = tailr1;
        }
        else
        {
            /* Temporary result pointer */
            Dlist *sumHead = NULL;
            Dlist *sumTail = NULL;

            /* Add current accumulated result with newly generated partial product */
            addition(*tailR, tailr1, &sumHead, &sumTail);

            /* freeing old pointers */
            delete_list(headR, tailR);
            delete_list(&headr1, &tailr1);

            /* Assingning the final result to headR pointer */
            *headR = sumHead;
            *tailR = sumTail;
        }

        count++; //incrementing zeroes count for every iteration

        temp2 = temp2->prev; //traversing
    }

    return SUCCESS;
}