#include "monty.h"

/**
 *add - adds the top two elements of a stack
 *and stores the result in the second top element
 *@head: address of the head of the stack
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
if (head == NULL || head->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
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

/**
 *sub - subtracts the top two elements of a stack
 *and stores the result in the second top element
 *@head: address of the head of the stack
 *Return: the new header of the stack
 *It is always a good idea to return the current header
 *after making any changes to a linked list. This avoids errors
 *as opposed to returning void.
 */
stack_t *sub(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
int diff;
if (head == NULL || head->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
diff = tmp2->n - tmp1->n;
tmp2->n = diff;
head = pop(head);
return (head);
}

/**
 *div_ - divides the second top element of a stack
 *by the top element of the stack
 *and stores the result in the second top element
 *@head: address of the head of the stack
 *Return: the new header of the stack
 *It is always a good idea to return the current header
 *after making any changes to a linked list. This avoids errors
 *as opposed to returning void.
 */
stack_t *div_(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
int quo;
if (head == NULL || head->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
if (tmp1->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_no);
exit(EXIT_FAILURE);
}
quo = tmp2->n / tmp1->n;
tmp2->n = quo;
head = pop(head);
return (head);
}

/**
 *mul_ - multiplies the second top element of a stack
 *with the top element of the stack
 *and stores the result in the second top element
 *@head: address of the head of the stack
 *Return: the new header of the stack
 */
stack_t *mul_(stack_t *head)
{
stack_t *tmp1;
stack_t *tmp2;
int prod;
if (head == NULL || head->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
tmp1 = head;
tmp2 = head->next;
prod = tmp2->n * tmp1->n;
tmp2->n = prod;
head = pop(head);
return (head);
}
