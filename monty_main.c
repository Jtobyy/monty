#include "monty.h"

/**
 *main - intepreter for monty bytecode
 *@argc: no of command line arguments. expected to be 2.
 *@argv: array of command line arguments.
 *Return: 0 on succes
 */
int main(int argc, char *argv[])
{
char *monty_file;
int f;
int c;
if (argc != 2)
{
write(STDERR_FILENO, "USAGE: monty file\n", 19);
exit(EXIT_FAILURE);
}
monty_file = argv[1];
f = open(monty_file, O_RDONLY);
if (f == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", monty_file);
exit(EXIT_FAILURE);
}
pp(f);
c = close(f);
if (c == -1)
{
fprintf(stderr, "Error: Can't close file %s\n", monty_file);
exit(EXIT_FAILURE);
}
return (0);
}

