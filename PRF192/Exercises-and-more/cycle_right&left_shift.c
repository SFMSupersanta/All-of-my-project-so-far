/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: Cyclelic right sift of an array
version #
////////////////////////////////////////////////////////////////
Write a function with the header

 void cyclicRightShift ( char s[ ], int n )

that shifts each character in the null-terminated string s[ ] by 
n elements to the right and moves each character that shifts 
beyond the end of the string to the beginning of the string.  
The character immediately to the right of element i is element 
i+1.

For example, the following calls

 char s[ ] = "abcdef";
 cyclicRightShift( s, 1 );
 printf("%s\n", s );
 cyclicRightShift( s, 2 );
 printf("%s\n", s );
 cyclicRightShift( s, 3 );
 printf("%s\n", s );

display

 fabcde
 defabc
 abcdef
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cyclicRightShift ( char s[ ], int n );
void cyclicLeftShift ( char s[ ], int n );

int main()
{ 
    char s[ ] = "abcdef";
    cyclicRightShift ( s, 1 );
    printf ("%s\n", s );
    cyclicRightShift ( s, 2 );
    printf ("%s\n", s );
    cyclicRightShift ( s, 3 );
    printf ("%s\n", s );

    cyclicLeftShift ( s, 1 );
    printf ("%s\n", s );
    cyclicLeftShift ( s, 2 );
    printf ("%s\n", s );
    cyclicLeftShift ( s, 3 );
    printf ("%s\n", s );
    return 0;
}

void cyclicLeftShift ( char s[ ], int n )
{
    int len = strlen( s ), cnt = 0;
    char buffer[len];
    strncpy(buffer, s, len);
    for(int i = n; i < len; i++)
    {
        s[cnt++] = buffer[i];
    }
    for(int i = 0; i < n; i++)
    {
        s[cnt++] = buffer[i];
    }
}

void cyclicRightShift ( char s[ ], int n )
{
    int len = strlen( s ), cnt = 0;
    char buffer[len];
    strncpy(buffer, s, len);
    for(int i = len - n; i < len; i++)
    {
        s[cnt++] = buffer[i];
    }
    for(int i = 0; i < len - n; i++)
    {
        s[cnt++] = buffer[i];
    }
}
