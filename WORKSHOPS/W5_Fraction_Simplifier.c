/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>

long long dev_f (long long  numerator,long long  denominator)             //a better version of dev_f function
{
    numerator = abs (numerator);
    denominator = abs (denominator);
    while(numerator != denominator)
    {
        if(numerator > denominator)
        {
            numerator -= denominator;
        }
        else
        {
            denominator -= numerator;
        }
    }
    return numerator;
}
void simplify(long long numerator, long long denominator, long long *simp_numer, long long  *simp_deno)      //sometimes, things need to become a simp
{
    if(numerator==0||denominator==0) 
    {
        *simp_numer = numerator;
        *simp_deno = denominator;
    }
    else
    {
        *simp_numer = numerator / dev_f(numerator,denominator);
        *simp_deno = denominator / dev_f(numerator,denominator);
    }
}

int main()
{
    printf ("Fraction Simplifier\n");
    printf ("-------------------\n"); 

    printf ("Numerator:    ");
    long long numerator ;
    scanf ("%lld", &numerator);

    printf ("Denominator:  ");
    long long denominator ;
    scanf ("%lld", &denominator);

    long long simp_deno,simp_numer;
    
    simplify (numerator,denominator,&simp_numer,&simp_deno);
    printf ("\n%lld / %lld = %lld / %lld",numerator,denominator,simp_numer,simp_deno);
    return 0;
}
/*#######################
###################
#TEST CASE(file)  #
###################
4,16
16,4
-4,16
4,-16
////////////////////////////////////////////////////////////////
Your company has been asked to write a fraction calculator.  Your group has been assigned the task of simplifying fractions.

Design and code a program that simplifies fractions.  Your program prompts for and accepts the numerator and denominator of a fraction and displays the fraction in simplified form.  To calculate the simplified numerator and denominator, design the simplify function described below. 

The output from your program looks something like

 Fraction Simplifier
 ===================
 Numerator:   4
 Denominator: 16

 4 / 16 = 1 / 4

Design and code a function named simplify that simplifies the numerator and denominator of a fraction.  The function receives the addresses of two int variables holding the numerator and denominator respectively and returns to those addresses the simplified numerator and denominator values, if simplification was possible.  The function does not return any value itself.  The header of your function looks something like:

 void simplify(int *numerator, int *denominator)

Include negative as well as zero values in your test cases.
****************************************************************/