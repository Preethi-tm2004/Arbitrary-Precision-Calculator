#include "apc.h"
#include <stdlib.h>

void create_count_list(int count, Dlist **headR, Dlist **tailR)
{
    /* when divident is smaller than divisor -> result of the division is zero so inssert 0 to result list*/
    if(count == 0)
    {
        insert_last(headR, tailR, 0);
        return;
    }

    /* temporary array to store the value of the count */
    int digits[20];
    int i = 0;

    /* store the value of count digit by digit */
    while(count)
    {
        digits[i++] = count % 10;
        count = count / 10;
    }

    /* Insert the value of count digit by digit to the nodes of the list*/
    while(i--)
    {
        insert_last(headR, tailR, digits[i]); 
    }

}