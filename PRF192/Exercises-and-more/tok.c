#include <stdio.h>
#include <string.h>

int main(void)
{
    char abc[] = "Hello        world";
    char *tok = abc;

    while ((tok = strtok(tok, " ")) != NULL)
    {
        printf("<<%s>>\n", tok);
        tok = NULL;
    }
    return 0;
}