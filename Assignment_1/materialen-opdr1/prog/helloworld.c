#include <stdio.h>

int main(void)
{
    const char *msg = "hello, world\n";
    int i;

    for (i = 0; msg[i] != '\0'; ++i)
        putchar(msg[i]);

    return 0;
}
