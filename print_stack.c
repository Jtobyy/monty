#include "monty.h"

/**
 *print_stack_t - prints the element of the stack
 *@h: list
 *Return: no of elements in list
 */
int print_stack_t(stack_t *h)
{
int i;
stack_t *p;
i = 0;
if (h == NULL)
return (0);
p = h;
while (p != NULL)
{
printf("%d\n", p->n);
i++;
p = p->next;
}
return (i);
}
