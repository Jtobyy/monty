#include "monty.h"

/**
 * rotr - rotates the stack to the buttom
 * 
 * @head: address of the head of the stack
 * Return: new head
 */
stack_t *rotr(stack_t *head)
{
stack_t *tmp;
stack_t *sp;
if (head == NULL)
return head;
tmp = head->next;
while (tmp != NULL)
{
sp = tmp;
tmp = tmp->next;
}
(sp->prev)->next = NULL;
sp->prev = NULL;
sp->next = head;
return (sp);
}
