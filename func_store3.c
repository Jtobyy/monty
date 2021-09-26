#include "monty.h"

/**
 * mod - computest the rest of the division of the second
 * top element of the stack by the top element of the stack
 * and stores the result in the second top element
 * @head: address of the head of the stack
 * Return: the new header of the stack
 */
stack_t *mod_(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
int mod;
tmp1 = head;
tmp2 = head->next;
if (tmp1 == NULL || tmp2 == NULL)
{
fprintf(stderr, "L%d: can't mod, stack to short\n", line_no);
exit(EXIT_FAILURE);
}
else if (tmp1->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_no);
exit(EXIT_FAILURE);
}
mod = tmp2->n % tmp1->n;
tmp2->n = mod;
head = pop(head);
return (head);
}
