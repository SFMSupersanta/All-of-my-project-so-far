/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

long long  numcheck(long long num)
{
    long long  check_digit = num % 10;
    num /= 10;
    long long weighted_sum = 0;
    long long total_sum;
    for(long long i = 2; i <= 10; i++) 
    {
        long long product = i * (num % 10);
        num /= 10;
        weighted_sum += product;
        //printf("%d\n", product);   for debugging only
    }
    total_sum = weighted_sum + check_digit;
    if(total_sum % 11 == 0) 
        return 1;
    else
        return 0;
}

int main()
{
    long long num;
    printf ("ISBN Validator\n=============\n");
    do
    {
        printf ("ISBN (0 to quit): ");
        scanf ("%d", &num);
        if (num == 0)
        { 
            printf("Have a Nice Day!");
            break;                           //thoát khỏi vòng do-for         
        }
        if (numcheck (num)==1)
        { 
            printf ("This is a valid ISBN.\n");
        }
        else printf ("This is not a valid ISBN.\n");
    }
    while (num != 0);
}
/***************************************************************
////////////////////////////////////////////////////////////////
This problem is slightly more difficult than the above problem.  This one requires a data type that stores 10 digits.

Background

Publishers and bookstores use a number system called the International Standard Book Number (ISBN) system to identify books.  At the start of publication, each book is assigned a unique ISBN.  An ISBN, once assigned, can never be re-used.  Click here for detailed information on this numbering system. 

An ISBN consists of exactly 10 digits.  The rightmost digit is the check digit.  The check digit is validated modulo 11. 

multiply each digit from the first to the ninth by a weight from 10 to 2 respectively (the first digit by 10, the second by 9,..., the ninth by 2). 
the sum of the products plus the check digit should be divisible without remainder by 11. 
if there is a remainder, the whole number is not a valid ISBN. 
Consider the following example:

 ISBN  0003194876
                |
 check digit is 6
 add first set of alternates to themselves 
   0  0  0  3  1  9  4  8  7
  10  9  8  7  6  5  4  3  2
   0  0  0 21  6 45 16 24 14 = 126
 add check digit                 6
 total                         132
 divide by 11                   12
 remainder                       0
 Therefore this ISBN is valid

Specifications

Design a program that validates an ISBN.  Your program keeps accepting a whole number and determining if that whole number is a valid ISBN.  Your program terminates when the user enters 0 as the whole number. 

The output from your program looks something like:

 ISBN Validator
 ==============
 ISBN (0 to quit): 0003194876 
 This is a valid ISBN.
 ISBN (0 to quit): 0003194875
 This is not a valid ISBN.
 ISBN (0 to quit): 0
 Have a Nice Day!

The data type long only guarantees room for 9 digits.  The data type long long guarantees room for an integer with well over 12 digits (at least 64 bits of precision).  The conversion specifier for a long long integer is %lld.  The Borland 5.5 compiler does not include the long long data type, but instead provides __int64 and %I64d instead of %lld as the conversion specifier. 
****************************************************************/