#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 100

int main (int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    printf("Enter a message: \n");
    if (fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {

        printf("Your message is: \n%s\n", buffer);
    } else printf("No message entered.\n");
    return 0;
}