/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: Post code validator
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int postalCode ( char code[ ] );

int main()
{
    printf("%d\n", postalCode("M6P2T4"));
    printf("%d\n", postalCode("M6P.T4"));
    printf("%d\n", postalCode("M6P 2T4"));
    return 0;
}

int postalCode ( char code[ ] )
{
    for ( int i = 0; i <6; i++ )
    { 
        if(i%2==0)
        { 
            if(code[i]>=97&&code[i]<=122) code[i]=code[i]-32;
            if(code[i]<=65||code[i]>=90) return 0;
            //printf("code[i]: %c\n",code[i]);
        }else
        { 
            if(code[i]<=48||code[i]>=57) return 0;
        }
    }
    return 1;
}