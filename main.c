/*
Name        : Preethi T M 
Batch       : 26001B
Date        : 18/06/2026
Project     : **Arbitrary Precision Calculator (APC) using Doubly Linked Lists**
Description : Developed an Arbitrary Precision Calculator in C capable of performing addition, subtraction, multiplication, and division on extremely large integers
              beyond the range of standard data types. Implemented custom arithmetic operations using doubly linked lists, where each node stores a single digit of the number. 
              Designed algorithms for carry handling, borrowing, sign management, leading zero removal, and large-number comparison. Optimized memory management through dynamic allocation 
              and validated correctness using extensive test cases.
              My APC project consists of multiple source files. The Makefile automates compilation and linking, manages dependencies, recompiles only modified files, reduces build time, and 
              makes the project easier to maintain
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "apc.h"

int main(int argc, char *argv[])
{
    /* validates arguments passed */
    if(validate_args(argc, argv) == FAILURE)
    {
        return FAILURE;
    }

    // printf("Operand1 : %s\n", argv[1]);
    // printf("Operator : %s\n", argv[2]);
    // printf("Operand2 : %s\n", argv[3]);

    /* initializing signs */
    char sign1 = '+';
    char sign2 = '+';
    char result_sign = '+';

    /* if the sign doesn't match with initialized sign update the sign */
    if(argv[1][0] == '-')
    {
        sign1 = '-';
    }

    if(argv[3][0] == '-')
    {
        sign2 = '-';
    }

    /*taking a temporary pointer to store operand 1 and 2*/
    char *op1 = argv[1];
    char *op2 = argv[3];

    /* moving the pointer to next position if the sign is found */
    if(op1[0] == '+' || op1[0] == '-')
    {
        op1++;
    }

    if(op2[0] == '+' || op2[0] == '-')
    {
        op2++;
    }

    /* creating pointers */
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    /* creating lists for both the operands */
    create_operand_list(op1, &head1, &tail1);
    create_operand_list(op2, &head2, &tail2);

    /* removing unnecessary zeroes */
    remove_leading_zeroes(&head1, &tail1);
    remove_leading_zeroes(&head2, &tail2);

    // print_list(head1);
    // print_list(head2);

    // insert_first(&headR, &tailR, 6);
    // insert_first(&headR, &tailR, 4);
    // insert_first(&headR, &tailR, 2);

    /* Addition */
    if(argv[2][0] == '+') 
    {
        if(signed_addition(head1, tail1, head2, tail2, sign1, sign2, &headR, &tailR, &result_sign) == FAILURE)
        {
            return FAILURE;
        }
    }
    /* subtraction */
    else if(argv[2][0] == '-')
    {
        /* if operand2 is detected with + or - sign update the sign accordingly */
        if(sign2 == '+')
        {
            sign2 = '-';
        }
        else
        {
            sign2 = '+';
        }
        if(signed_addition(head1, tail1, head2, tail2, sign1, sign2, &headR, &tailR, &result_sign) == FAILURE)
        {
            return FAILURE;
        }
    }
    /* dividsion */
    else if(argv[2][0] == '/')
    {
        /* anything by zero is not valid */
        if(head2->data == 0 && head2 == tail2)
        {
            printf("Error : Division by zero is not possible\n");
            return FAILURE;
        }
        division(&head1, &tail1, head2, tail2, &headR, &tailR);

        /* if opereands with opposite signs update the result_sign with '-' */
        if(sign1 != sign2)
        {
            result_sign = '-';
        }
    }
    /* multiplication */
    else if(argv[2][0] == 'X' || argv[2][0] == 'x')
    {
        /* if any operand is zero update the result list as zero directly */
        if((head1 == tail1 && head1->data == 0) || (head2 == tail2 && head2->data == 0))
        {
            insert_first(&headR, &tailR, 0);
        }
        else
        {
            multiplication(tail1, tail2, &headR, &tailR);

            /* if opereands with opposite signs update the result_sign with '-' */
            if(sign1 != sign2)
            {
                result_sign = '-';
            }
        }
    }
    /* remove unnecessary zeroes from result list */
    remove_leading_zeroes(&headR, &tailR);

    /* if result sign is '-' print '-' before printing result value */
    if(result_sign == '-' && !(headR->data == 0 && headR == tailR))
    {
        printf("-");
    }

    /* print result list */
    print_list(headR);

    /* freeing memory */
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}