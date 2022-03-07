#include <string.h>
#include <stdio.h>

void capitalize(char str[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(str[i]==' ')
        {
            while(str[i] == ' ') 
            {
                i++;
                if(i==size) break;
            }
        }
        if(str[i]>=97 && str[i]<= 122) str[i] = str[i] - 32;
        i++;
        while(str[i] != ' '&& str[i] != '\0') 
        {
            if(str[i]>=65 && str[i]<= 90) str[i] = str[i] + 32;
            i++;
        }
    }
    
}

int main()
{ 
    char string[256];
    printf("Type in the array: ");
    scanf(" %[^\n]", &string);
    capitalize(string, strlen(string));
    printf("Modified string: %s",string);
    return 0;
}