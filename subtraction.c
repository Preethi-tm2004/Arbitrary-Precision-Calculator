#include "apc.h"
#include <stdlib.h>

Status subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0; //stores borrow from previous digit
    int d1, d2;
    int diff;

    //traverse till both list reaches null
    while(tail1 != NULL || tail2 != NULL)
    {
        /* initializing operand1 and operand2 digits to zero for every iteration */
        d1 = 0;
        d2 = 0;

        //get digit from operand1 
        if(tail1)
        {
            d1 = tail1->data;
            tail1 = tail1->prev;
        }

        //get digit form operand2
        if(tail2)
        {
            d2 = tail2->data;
            tail2 = tail2->prev;
        }

        //apply previous borrow
        d1 = d1 - borrow;

        //check whether borrow is required;
        if(d1 < d2)
        {
            diff = (d1 + 10) - d2; //Borrow from next digit
            borrow = 1; //set borrow flag
        }
        else
        {
            diff = d1 - d2; //normal subtraction
            borrow = 0; //reset borrow flag
        }

        //insert result digit from the beginning
        insert_first(headR, tailR, diff);
    }

    return SUCCESS;
}