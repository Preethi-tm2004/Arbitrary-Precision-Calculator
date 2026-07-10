#include "apc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

Status validate_args(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Invalid arguments\nUsage : ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Handles sign*/
    int start = 0; 

    if(argv[1][0] == '-' || argv[1][0] == '+')
    {
        start = 1;
    }

    if(argv[1][start] == '\0')
    {
        printf("Invalid operand1\n");
        return FAILURE;
    }
    /* Validate operand1 */
    for(int i = start; argv[1][i] != '\0'; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Invalid operand1\n");
            return FAILURE;
        }
    }

    /* Validate operator */
    if(strlen(argv[2]) != 1)
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    char op = argv[2][0];

    if(op != '+' && op != '-' && op != 'X' && op != 'x' && op != '/')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    /* Handles sign*/
    int first = 0; 

    if(argv[3][0] == '-' || argv[3][0] == '+')
    {
        first = 1;
    }

    if(argv[3][first] == '\0')
    {
        printf("Invalid operand2\n");
        return FAILURE;
    }

    /* Validate operand2 */
    for(int i = first; argv[3][i] != '\0'; i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf("Invalid operand2\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}