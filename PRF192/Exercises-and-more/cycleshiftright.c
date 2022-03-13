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

int main()
{ 
    char s[ ] = "abcdef";
    cyclicRightShift ( s, 1 );
    printf ("%s\n", s );
    cyclicRightShift ( s, 2 );
    printf ("%s\n", s );
    cyclicRightShift ( s, 3 );
    printf ("%s\n", s );
    return 0;
}

void cyclicRightShift ( char s[ ], int n )
{
    char buffer[strlen (s) + 1];
    int count = 0;
    while (s[count] != '\0') count++;
    for(int i = 0; i < count; i++)
    {
        if ( (i + n) >= count) 
        {
            buffer[ (i + n) - count] = s[i];
        }
        else 
        {
            buffer[i + n] =s [i];
        }
    }
    strcpy (s, buffer);
}
