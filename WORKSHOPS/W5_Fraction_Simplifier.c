/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>
/*
long long dev_f(long long  numerator,long long  denominator)                //devider finder
{
    if(abs(numerator)>abs(denominator))
    {
        for(long long i=abs(denominator); i>0; i--)
        {
            if(numerator%i==0&&denominator%i==0)
            {
                return i;
                break;
            }
        }
    }
    else if(abs(numerator)<abs(denominator))
    {
        for(long long i=abs(numerator); i > 0; i--)
        {
            if(numerator%i==0&&denominator%i==0)
            {
                return i;
                break;
            }
        }
    }
}
*/
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
int simplify(long long numerator, long long denominator,long long  *simp_deno, long long *simp_numer)      //sometimes, things need to become a simp
{
    if(denominator==0)                                                         //if you can do this I'll personally give you a nobel prize
    {
        printf("Devide to 0 error");
        return 1;
    } 
    if(numerator==0)                                                           //simple as eating a cake
    {
        *simp_numer = 0;
        *simp_deno = abs(denominator)/denominator;
    }
    else
    {
        if(numerator<0&&denominator<0)                                         //if they both negative, the result should be positive
        {
            *simp_numer = abs(numerator)/dev_f(numerator,denominator);
            *simp_deno = abs(denominator)/dev_f(numerator,denominator);
        }
        else
        {
            *simp_numer = numerator/dev_f(numerator,denominator);
            *simp_deno = denominator/dev_f(numerator,denominator);
        }
    }
    return 0;
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

    long long simp_deno,simp_numer;
    
    if(simplify(numerator,denominator,&simp_deno,&simp_numer)==0)                          //things should not be printed if the math is not correct
    {
        printf("\n%lld / %lld = %lld / %lld",numerator,denominator,simp_numer,simp_deno);
    }
    return 0;
}
/*#######################
###################
#TEST CASE(file)  #
###################
4,16
16,4
0,any number 
any number,0
-4,46
4,-16
-16,4
16,-4
###################
#   EXAMPLE:      #
###################
 Fraction Simplifier
 ===================
 Numerator:   4
 Denominator: 16

 4 / 16 = 1 / 4
#########################*/