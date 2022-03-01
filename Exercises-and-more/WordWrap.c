/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: wordwrap. same as workshop 10
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int wordWrap(char wrapstring[], int fieldwidth);

int main()
{
    char s[ ] = "My home is in Toronto    Ontario";
    int i;
    
    i =  wordWrap(s, 7);
    printf("%d\n%s\n", s);
    return 0;
}

int wordWrap(char wrapstring[], int fieldwidth)                        //This function returns a required lines value AND modify the string
{
    int count = 0;
}