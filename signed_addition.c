#include "apc.h"
#include <stdlib.h>

Status signed_addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, char sign1, char sign2, Dlist **headR, Dlist **tailR, char *result_sign)
{
    /* Operator is '+' and signs are equal perform addition*/
    if(sign1 == sign2) 
    {
        addition(tail1, tail2, headR, tailR); //function call for addition operation

        /* print the sign if its '-' otherwise just print headR as it is */
        if(sign1 == '-')
        {
            *result_sign = '-'; 
        }
    }
    else
    {
        /* operator is '+' and signs are not equal then compare both the operands */
        int cmp = compare_list(head1, head2);

        /* if both are equal directly insert zero to result */
        if(cmp == 0)
        {
            insert_first(headR, tailR, 0);
        }
        /* operand 1 is greater then do subtraction and assign the sign of first operand to result_sign */
        else if(cmp > 0)
        {
            subtraction(tail1, tail2, headR, tailR);

            *result_sign = sign1;
        }
        /* operand2 is greater */
        else
        {
            subtraction(tail2, tail1, headR, tailR);

            *result_sign = sign2;
        }
    }

    return SUCCESS;
}
