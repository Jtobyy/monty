#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pp(int fd);
void push(stack_t **stack_head, int n);
void pall(stack_t *stack_head);
void free_stack_t(stack_t *head);
int print_stack_t(stack_t *h);
int get_op_int(char *semi_buf);
char *get_opcode(char *semi_buf);
void pint(stack_t *stack_head);
stack_t *pop(stack_t *stack_head);
stack_t *swap(stack_t *head);
stack_t *add(stack_t *head);
void nop(void);
stack_t *sub(stack_t *head);
stack_t *div_(stack_t *head);
stack_t *mul_(stack_t *head);
stack_t *mod_(stack_t *head);
void pchar_(stack_t *head);
void pstr(stack_t *head);
stack_t *rotl(stack_t *head);
stack_t *rotr(stack_t *head);

extern int line_no;
extern stack_t *stack_head;
extern int queueorstack;
#endif
