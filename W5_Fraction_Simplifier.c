/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>

void simplify(long long numerator, long long denominator)
{
    long long temp_denominator = denominator ;
    long long temp_numerator = numerator ;

    if(numerator > denominator && numerator % denominator ==0)
    {
    
        numerator = numerator / denominator;
        denominator = 1;
    }
    else if (numerator < denominator && denominator % numerator ==0)
    {
        denominator = denominator / numerator;
        numerator = 1;
    }
    else
    {
        long long devider;
        if(numerator > denominator)
        {
            devider = denominator/2;
        }
        else 
        {
            devider = numerator/2;
        }
        for(long long i = devider; i >1 ; i--)
        {
            //printf("%lld ", i);
            if(numerator % i ==0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
            }
        }
    }

    printf("\n%lld / %lld = %lld / %lld",temp_numerator,temp_denominator,numerator,denominator);
}

int main()
{
    printf("Fraction Simplifier\n");
    printf("-------------------\n"); 

    printf("Numerator:    ");
    long long numerator ;
    scanf("%lld", &numerator);

    printf("Denominator:  ");
    long long denominator ;
    scanf("%lld", &denominator);
    
    simplify(numerator,denominator);

    return 0;

}