#include "monty.h"

int line_no = 1;
stack_t *stack_head = NULL;

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
char *buf = NULL;
char *semi_buf = NULL;
char *opcode = NULL;
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

if (semi_buf[0] == '#')
{
free(semi_buf);
continue;
}
/* get opcode for each line from file */
opcode = get_opcode(semi_buf);

if (strcmp(opcode, "pall") == 0)
{
pall(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "pint") == 0)
{
pint(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "pop") == 0)
{
stack_head = pop(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "push") == 0)
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
free(semi_buf);
free(opcode);
}
else if (strcmp(opcode, "swap") == 0)
{
stack_head = swap(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "add") == 0)
{
stack_head = add(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "nop") == 0)
{
nop();
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "sub") == 0)
{
stack_head = sub(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "div") == 0)
{
stack_head = div_(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "mul") == 0)
{
stack_head = mul_(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "mod") == 0)
{
stack_head = mod_(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "pchar") == 0)
{
pchar_(stack_head);
free(semi_buf);
free(opcode);
continue;
}
else if (strcmp(opcode, "pstr") == 0)
{
pstr(stack_head);
free(semi_buf);
free(opcode);
continue;
}

else
{
fprintf(stderr, "L%d: unknown instruction%s\n", line_no, opcode);
free(buf);
free(semi_buf);
free(opcode);
free_stack_t(stack_head);
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
 *Return: pointer to opcode
 */
char *get_opcode(char *semi_buf)
{
int k;
int t;
int tmp;
char *opcode;
for (k = 0; semi_buf[k] != '\n'; k++)
{
while (semi_buf[k] == ' ' || semi_buf[k] == '\t')
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
opcode[t] = '\0';
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
n = -1;
for (k = 0; semi_buf[k] != '\n';)
{
while (!isdigit(semi_buf[k]) && semi_buf[k] != '-')
k++;
t = 1;
tmp = k;
if (semi_buf[tmp] == '-' && isdigit(semi_buf[tmp + 1]))
{
t++;
tmp++;
}
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
if (semi_buf[k] == '-')
{
op_int[t] = semi_buf[k];
t++;
k++;
}
while (isdigit(semi_buf[k]))
{
op_int[t] = semi_buf[k];
t++;
k++;
}
if (semi_buf[k] != ' ' && semi_buf[k] != '\n' && semi_buf[k] == '\t')
{
fprintf(stderr, "L%d: usage: push integer\n", line_no);
exit(EXIT_FAILURE);
}
op_int[t] = '\0';
n = atoi(op_int);
free(op_int);
push(&stack_head, n);
break;
}
return (n);
}
