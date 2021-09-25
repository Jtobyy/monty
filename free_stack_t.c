#include "monty.h"

/**
*free_stack_t - frees the stack
*@head: link to the head of the list
*Return: void
*/
void free_stack_t(stack_t *head)
{
stack_t *lp;
if (head == NULL)
return;
lp = head;
while (head != NULL)
{
head = lp->next;
free(lp);
lp = head;
}
return;
}
