/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: String compress
version #
////////////////////////////////////////////////////////////////
Write a function with the header

 int compress ( char str[ ] )

that receives a null-terminated string str[], removes any leading 
blanks in str[], any extra blanks between the words in str[] and 
any trailing blanks in str[] and returns the number of characters
in the compressed string (excluding the null byte).  A word is 
any set of consecutive non-whitespace characters.  Any two 
consecutive words are separated from one another by whitespace 
characters. 

For example, the statements

 int i;
 char str[ ] = "   This is    a     test.      ";

 i = compress(str);
 printf ("'%s' contains %d characters.\n", str, i);

display

 'This is a test.' contains 15 characters.

****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer (void);

void getString(char mgs[],char arr[],int size);

int compress ( char str[ ] );

int main()
{ 
    char buffer[1024];
    getString ("Type in the string needed to be compressed: ",buffer,1024);
    int numc = compress(buffer);
    printf ("'%s' contains %d characters.\n", buffer, numc);
    return 0;
}

int compress ( char str[ ] )
{
    int count = 0,charCount = 0, rc;
    char buffer[1024];
    while(str[count] != '\0')
    {
        if(str[count] == ' ')
        {
            rc = count;
            if (count == 0)
            {
                str[count++] = '\n';
                while (str[count] == ' ')
                {
                    str[count] = '\n';
                    count++;
                }
            }
            else if (str[count + 1] == '\0') str[count++] = '\n';
            else if ( str[++count] == ' ')
            {
                str[count++] = '\n';
                while (str[count] == ' ')
                {
                    str[count] = '\n';
                    count++;
                }
                if (str[count] == '\0') str[rc] = '\n';
            }
        }
        count++;
    }
    for(int i = 0;i < count;i++)
    {
        if(str[i] != '\n') 
        {
            buffer[charCount++] = str[i];
            //printf("charcount=%d\n",charCount);
        }
    }
    buffer[++charCount] = '\0';
    //printf("buffer: %s\n",buffer);
    strcpy(str,buffer);
    charCount = 0;
    while(str[charCount] != '\0') charCount++;
    return charCount;
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ( (c  =getchar()) != '\n' && c != EOF);
 }

 void getString(char msg[], char arr[], int size)
 {
     while (1)
     {
        printf("%s",msg);
        fgets (arr, size, stdin);
        int rc = 1;
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == '\n') 
            {
                rc = 0;
                arr[i] = '\0';
                i = size;
            }
        }
        if(rc != 0) 
        {
            printf("**Trailing Characters!**\n");
            clear_buffer();
        }
        else
        { 
            if (arr[0] == '\n')printf("**No input detected!!**\n");
            else break;
        }
     }
 }