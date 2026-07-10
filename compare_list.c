#include "apc.h"
#include <stdlib.h>

Status compare_list(Dlist *head1, Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    int len1 = 0, len2 = 0;

    /* Calculate length of the first operand*/
    while(temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    /* Calculate length of the second operand*/
    while(temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    //operand1 is greater
    if(len1 > len2)
        return 1;

    //operand2 is greater
    if(len2 > len1)
        return -1;

    //compare digit by digit when lengths are equal
    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return 1;

        if(head2->data > head1->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    //both operand are equal 
    return 0;
}