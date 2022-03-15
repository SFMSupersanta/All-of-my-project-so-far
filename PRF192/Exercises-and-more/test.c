#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
    char *s = (char*)malloc(sizeof(char) * 17);
	do
    {
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';
        printf("%s\n", s);
        free(s);
    }while (s[0] != '\0');


    
    return(0);
}
