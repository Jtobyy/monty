#include "monty.h"

/**
 *push - adds a node to the beginning of the stack
 *@stack_head: address of stack's head
 *@n: value at node
 *Return: void
 */
void push(stack_t **stack_head, int n)
{
int r __attribute__((unused));
stack_t *lp;
lp = malloc(sizeof(*lp));
if (lp == NULL)
{
fprintf(stderr, "Error: malloc failed");
exit(96);
}
lp->n = n;
lp->next = *stack_head;
lp->prev = NULL;
if (*stack_head == NULL)
*stack_head = lp;
else
{
(*stack_head)->prev = lp;
*stack_head = lp;
}
return;
}

/**
 *pall - prints out all elements in the stack
 *@stack_head: address of the head of the stack
 *Return: void
 */
void pall(stack_t *stack_head)
{
stack_t *lp;
if (stack_head == NULL)
return;
lp = stack_head;
while (stack_head != NULL)
{
stack_head = lp->next;
printf("%d\n", lp->n);
lp = stack_head;
}
return;
}

/**
 *pint - prints the value at the top of the stack
 *@stack_head: address of the head of the stack
 *Return: void
 *
 */
void pint(stack_t *stack_head)
{
if (stack_head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
exit(EXIT_FAILURE);
}
printf("%d\n", stack_head->n);
return;
}

/**
 *pop - removes the value at the top of the stack
 *@stack_head: address of the head of the stack
 *Return: The new header of the stacks
 *
 */
stack_t *pop(stack_t *head)
{
stack_t *lp;
if (stack_head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
exit(EXIT_FAILURE);
}
lp = head;
head = lp->next;
free(lp);
return (head);
}

/**
 *swap - swaps the top two elements of a stack
 *@stack_head: address of the head of the stack
 *Return: the new header of the stack
 *It is always a good idea to return the current header
 *after making any changes to a linked list. This avoids errors
 *
 */
stack_t *swap(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
if (stack_head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
(tmp2->next)->prev = tmp1;
tmp1->next = tmp2->next;
tmp1->prev = tmp2;
tmp2->next = tmp1;
tmp2->prev = NULL;
head = tmp2;
return (head);
}
