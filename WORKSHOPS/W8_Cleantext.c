/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
function to make the text "clean"
take a string, size of the string and a string pointer as input and assing value to the string pointer
*/
int char_to_ascii(char i)
{
    int k = i;
    return k;
}

void cl_text(char str[], int size, char *out_str)
{
    for (int i = 0; i <= size-1; i++)
    {
        if(str[i] == ' '&& i==0)
        {
            while(str[i+1] == ' ')
            {
                i++;
            }
            *out_str++ = str[i+1];
        }
        
        else if(str[i] == ' ')
        {
            while(str[i+1] == ' ')
            {
                i++;
            }
            *out_str++ = str[i];
        }
        else if (char_to_ascii(str[i]) < 32 || char_to_ascii(str[i]) == 127)
        {
           *out_str++ = '_';
        }
        else 
        {
            *out_str++ = str[i];
        }
    }
}

int main()
{
    printf("String Cleaner");
    printf("\n==============\nString to be cleaned : ");
    char str[101];
    gets(str);
    char cl_str[101];
    cl_text(str,/*return length value*/strlen(str),cl_str);
    printf("Cleaned string       : %s", cl_str);
}