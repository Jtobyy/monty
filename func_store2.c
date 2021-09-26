#include "monty.h"

/**
 *add - adds the top two elements of a stack
 *and stores the result in the second top element
 *@stack_head: address of the head of the stack
 *Return: the new header of the stack
 *It is always a good idea to return the current header
 *after making any changes to a linked list. This avoids errors
 *as opposed to returning void.
 */
stack_t *add(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
int sum;
tmp1 = head;
tmp2 = head->next;
if (tmp1 == NULL || tmp2 == NULL)
{
fprintf(stderr, "L%d: can't add, stack to short\n", line_no);
exit(EXIT_FAILURE);
}
sum = tmp1->n + tmp2->n;
tmp2->n = sum;
head = pop(head);
return (head);
}

/**
 *nop - the opcode nop does nothing
 *Return: void
 */
void nop(void)
{
return;
}
