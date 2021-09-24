#include "monty.h"

/**
 * pp - extracts instructions from file
 *@fd: file descriptor of file
 *return: void
 */
void pp(int fd)
{
int i;
int j;
int k;
int n;
int fd_count;
ssize_t r;
int line_no = 1;
char *buf = NULL;
char *semi_buf = NULL;
char *opcode = NULL;
stack_t *stack_head = NULL;
fd_count = 0;
buf = malloc(sizeof(*buf) * 500);
if (buf == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
do {
r = read(fd, buf, 500);
if (r == -1)
{
fprintf(stderr, "Error: read failed\n");
exit(EXIT_FAILURE);
}
fd_count += r;
} while (r != 0);
if (fd_count > 500)
{
buf = realloc(buf, fd_count);
lseek(fd, 0, SEEK_SET);
r = read(fd, buf, fd_count);
if (r == -1)
{
fprintf(stderr, "Error: read failed\n");
exit(EXIT_FAILURE);
}
}
for (i = 0, j = 0; i < fd_count; i = j + 1, line_no++)
{
for (j = i, k = 1; buf[j] != '\n'; j++, k++)
continue;
semi_buf = malloc(sizeof(*semi_buf) * k);
if (semi_buf == NULL)
{
fprintf(stderr, "Error: malloc failed");
exit(96);
}

for (j = i, k = 0; buf[j] != '\n'; j++, k++)
semi_buf[k] = buf[j];
semi_buf[k] = '\n';

/* get opcode for each line from file */
opcode = get_opcode(semi_buf);
 
if (strncmp(opcode, "pall", 4) == 0)
{
pall(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strncmp(opcode, "push", 4) == 0)
{
/* get int(if any) for each line from file */
n = get_op_int(semi_buf);
if (n == -1)
{
free(buf);
free(semi_buf);
free(opcode);
free_stack_t(stack_head);
fprintf(stderr, "L%d: usage: push integer\n", line_no);
exit(EXIT_FAILURE); 
}
push(&stack_head, n);
free(semi_buf);
free(opcode);
}
else
{
free(buf);
free(semi_buf);
free(opcode);
free_stack_t(stack_head);
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
exit(EXIT_FAILURE);
}
}
free(buf);
free_stack_t(stack_head);
return;
}

/**
 *get_opcode - gets opcode for each line
 *@semi_buf: current line string
 *return: pointer to opcode
 */
char *get_opcode(char *semi_buf)
{
int k;
int t;
int tmp;
char *opcode;
for (k = 0; semi_buf[k] != '\n'; k++)
{
while (semi_buf[k] == ' ')
k++;
t = 1;
tmp = k;
while (isalpha(semi_buf[tmp]))
{
t++;
tmp++;
}
opcode = malloc(sizeof(*opcode) * t);
if (opcode == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
t = 0;
while (isalpha(semi_buf[k]))
{
opcode[t] = semi_buf[k];
t++;
k++;
}
break;
}
return (opcode);
}

/**
 *get_op_int - gets the integer for a push instruction
 *@semi_buf: current line string
 *Return: integer
 */
int get_op_int(char *semi_buf)
{
int n;
int k;
int t;
int tmp;
char *op_int;
for (k = 0; semi_buf[k] != '\n'; k++)
{
if (!isdigit(semi_buf[k]) && semi_buf[k] != '-')
continue;
else
{
t = 1;
tmp = k;
while (isdigit(semi_buf[tmp]))
{
t++;
tmp++;
}

op_int = malloc(sizeof(*op_int) * t);
if (op_int == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
t = 0;
while (isdigit(semi_buf[k]))
{
op_int[t] = semi_buf[k];
t++;
k++;
}
op_int[t] = '\0';
n = atoi(op_int);
free(op_int);
return (n);
}
}
return (-1);
}


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


