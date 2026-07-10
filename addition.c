#include "apc.h"
#include <stdlib.h>

Status addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    //stores carry 
    int carry = 0;

    //stores sum and digit
    int sum, digit;

    //traverse till both lists reaches NULL
    while(tail1 != NULL || tail2 != NULL)
    {
        //storing carry of previous iteration 
        sum = carry;

        //Add digits from first number if available
        if(tail1 != NULL)
        {
            sum = sum + tail1->data;

            //Move to next digit(backward traverse)
            tail1 = tail1->prev;
        }

        //Add digits from second number if available
        if(tail2 != NULL)
        {
            sum = sum + tail2->data;

            //Move to next digit(backward traverse)
            tail2 = tail2->prev;
        }

        //digit to be stored
        digit = sum % 10;

        //carry for next iteration
        carry = sum / 10;
        
        //Insert digit from beginning of result list
        insert_first(headR, tailR, digit);
    }

    //insert carry if exist after the loop
    if(carry)
    {
        insert_first(headR, tailR, carry);
    }

    return SUCCESS;
}