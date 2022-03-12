/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void clear_buffer (void)
 {
     char c;
     while ( (c=getchar ()) != '\n'&&c!=EOF);
 }

 void getString (char msg[], char arr[],int size)
 {
     while (1)
     {
        printf ("%s",msg);
        fgets( arr, size, stdin);
        int rc = 1;
        for(int i = 0;i < size;i++)
        {
            if(arr[i]=='\n') 
            {
                rc = 0;

                arr[i]= '\0';
                i = size;
            }
        }
        if (rc!=0) 
        {
            printf ("**Trailing Characters!**\n");
            clear_buffer ();
        }
        else
        { 
            if (arr[0]=='\n') printf ("**No input detected!!**\n");
            else break;
        }
     }
 }


void cl_text(char str[], int size)
{
    char substr[255];
    int count = 0;
    for(int i = 0; i < size; i++)
    { 
        if(str[i] == ' ' && i == 0)
        {
            i++;
        }
        else if(str[i] == ' '&&i!=0)
        {
            substr[count++] = ' ';
            while(str[i+1] == ' ') i++;
        }
        else
        {
            substr[count++] = str[i];
        }
    }
    strcpy (str, substr);
}


int main()
{
    printf("String Cleaner");
    printf("\n==============\nString to be cleaned : ");
    char str[101];
    getString ("String to be cleaned :", str, sizeof(str) / sizeof(str[0]));

    cl_text (str,/*return length value*/strlen(str));
    printf ("Cleaned string       : %s", str);
}
/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
   BTP100   is not    that  hard!
###################
////////////////////////////////////////////////////////////////
Design and code a function named cleanText that receives a null terminated string and cleans that string so that it contains only one space character between words and no leading or trailing whitespace characters.  Your function should reduce all multiple occurences of whitespace characters to a single space character and return the total number of characters in the cleaned version of the string, excluding the null byte terminator.

The whitespace characters include newline, horizontal tab, form feed, vertical tab and space characters. 

Your function also converts any non-printable character to an underscore character.  The printable characters are those between ' ' and '~' inclusive as in the ASCII table.

Finally, write a program that accepts a string to be cleaned and displays the cleaned version of the string.  You may assume that the user will not input a string that contains more than 100 characters, but may input an empty string.

The output from your program looks something like like:

 String Cleaner
 ==============
 String to be cleaned :   BTP100   is not    that  hard!
 Cleaned string       : BTP100 is not that hard!

****************************************************************/