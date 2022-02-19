
#include<stdio.h>
#include "validator.h"



int main()
{   
    while(1)
    {
        char c;
        printf("Input char accepted: %c\n", c=getChar("Input char : ", "abcdefgABCDEFG"));
    }
    return 0;
}