/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: Post code validator
version #
////////////////////////////////////////////////////////////////
Write a function with the header

 int postalCode ( char code[ ] )

that receives the null-terminated string code[ ] and returns 1 if the code is a valid postal code for Canada and 0 otherwise.
Recall that a Canadian postal code consists of exactly 6 characters: the first, third and fifth are alphabetic, while the second,
fourth and sixth are numeric.  Your function does not change the contents of code[ ].

For example, the following calls

 printf("%d\n", postalCode("M6P2T4"));
 printf("%d\n", postalCode("M6P.T4"));
 printf("%d\n", postalCode("M6P 2T4"));

display:

 1
 0
 0

That is, the first code is valid; the second code is invalid because the fourth character is not numeric;
 the third code is invalid because of the string contains 7 characters.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int postalCode(char code[]);

int main()
{
    printf("%d\n", postalCode("M6P2T4"));
    printf("%d\n", postalCode("M6P.T4"));
    printf("%d\n", postalCode("M6P 2T4"));
    return 0;
}

int postalCode(char code[])
{
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            if (code[i] >= 97 && code[i] <= 122)
                code[i] = code[i] - 32;
            if (code[i] <= 65 || code[i] >= 90)
                return 0;
        }
        else
        {
            if (code[i] <= 48 || code[i] >= 57)
                return 0;
        }
    }
    return 1;
}