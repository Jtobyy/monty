#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int i;
char s[2];
s[0] = '$';
s[1] = '3';
i = atoi(s);
printf("%d\n", i);
return (0);
}
