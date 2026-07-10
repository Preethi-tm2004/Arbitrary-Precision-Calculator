#ifndef APC_H
#define APC_H

typedef int data_t;

typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
}Dlist;

typedef enum
{
    SUCCESS,
    FAILURE
}Status;

/* Validation function */
Status validate_args(int argc, char *argv[]);

/* DLL functions */
Status insert_first(Dlist **head, Dlist **tail, data_t data);
Status insert_last(Dlist **head, Dlist **tail, data_t data);
void create_count_list(int count, Dlist **headR, Dlist **tailR);
void remove_leading_zeroes(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
void delete_list(Dlist **head, Dlist **tail);
Status compare_list(Dlist *head1, Dlist *head2);

/* Create number list */
Status create_operand_list(char *str, Dlist **head, Dlist **tail);

/* Arithmatic operations */
Status signed_addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, char sign1, char sign2, Dlist **headR, Dlist **tailR, char *result_sign);
Status addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
Status subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
Status division(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);
Status multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);









#endif