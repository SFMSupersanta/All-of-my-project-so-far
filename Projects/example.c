
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long dev_f(long long  numerator,long long  denominator)             //a better version of dev_f function
{
    numerator = abs(numerator);
    denominator = abs(denominator);
    while(numerator!=denominator)
    {
        if(numerator>denominator)
        {
            numerator-=denominator;
        }
        else
        {
            denominator-=numerator;
        }
    }
    return numerator;
}

int main()
{
    printf("result: %lld\n", dev_f(135,15));
    return 0;

    //game(suit,rank);
    
    //main code
}