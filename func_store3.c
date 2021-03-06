#include "monty.h"

/**
 * mod_ - computest the rest of the division of the second
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
if (head == NULL || head->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
if (tmp1->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_no);
exit(EXIT_FAILURE);
}
mod = tmp2->n % tmp1->n;
tmp2->n = mod;
head = pop(head);
return (head);
}

/**
 * pchar_ - prints the character at the top of the stack
 * followed by a new line
 * 
 * @head: address of the head of the stack
 * Return: void
 */
void pchar_(stack_t *head)
{
if (head == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
exit(EXIT_FAILURE);
}
else if (head->n < 65 || head->n > 122 || (head->n >= 91 && head->n <= 96))
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
exit(EXIT_FAILURE);
}
printf("%c\n", head->n);
return;
}

/**
 * pstr - prints the string strting at the top of the stack
 * followed by a new line
 * 
 * @head: address of the head of the stack
 * Return: void
 */
void pstr(stack_t *head)
{
while (head != NULL && head->n != 0)
{
if (head->n < 65 || head->n > 122 || (head->n >= 91 && head->n <= 96))
break;
printf("%c", head->n);
head = head->next;
}
putchar('\n');
return;
}

/**
 * rotl - rotates the stack to the top
 * 
 * @head: address of the head of the stack
 * Return: new head
 */
stack_t *rotl(stack_t *head)
{
stack_t *tmp;
stack_t *sp;
if (head == NULL || head->next == NULL)
return head;
tmp = head->next;
while (tmp != NULL)
{
sp = tmp;
tmp = tmp->next;
}
tmp = head->next;
sp->next = head;
head->next = NULL;
head->prev = sp;
return (tmp);
}

/**
 * reverse - rotates the stack
 * 
 * @head: address of the head of the stack
 * Return: new head
 */
stack_t *reverse(stack_t *head)
{
stack_t *tmp;
stack_t *sp;
if (head == NULL)
return head;
tmp = head->next;
head->next = NULL;
head->prev = tmp;
tmp->prev = tmp->next;
tmp->next = head;
while (tmp->prev != NULL)
{
sp = tmp;
tmp = tmp->prev;
tmp->prev = tmp->next;
tmp->next = sp;
}
return (tmp);
}
