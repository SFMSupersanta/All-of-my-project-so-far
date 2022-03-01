/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: Cyclelic right sift of an array
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cyclicRightShift ( char s[ ], int n );

int main()
{ 
    char s[ ] = "abcdef";
    cyclicRightShift( s, 1 );
    printf("%s\n", s );
    cyclicRightShift( s, 2 );
    printf("%s\n", s );
    cyclicRightShift( s, 3 );
    printf("%s\n", s );
    return 0;
}

void cyclicRightShift ( char s[ ], int n )
{
    char buffer[255];
    //printf("%s\n",s);
    int count = 0;
    while (s[count] != '\0') count++;
    //printf("count: %d\n",count);
    for(int i=0; i<count; i++)
    {
        if((i+n)>=count) 
        {
            //printf("i: %d,n: %d\n",i,n);
            buffer[(i+n)-count] = s[i];
            //printf("%c %d\n", buffer[(i+n)-count], (i+n)-count);
        }
        else 
        {
            //printf("i: %d,n: %d\n",i,n);
            buffer[i+n]=s[i];
            //printf("%c %d\n",buffer[i+n]),i+n;
        }
    }
    //buffer[count+1]='\0';
    strcpy(s,buffer);
}
