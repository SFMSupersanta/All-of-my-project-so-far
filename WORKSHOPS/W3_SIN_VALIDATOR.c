/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int numcheck(int num)
{
    int check_digit = num % 10;
    num /= 10;
    int odd_sum, even_sum=0, total_sum;     //tôi không hiểu sao không cho even_sum=0 thì nó thành 34 :)
    for (int i = 1; i <= 8; i++)
    {
        int digit = num % 10;
        num /= 10;
        if(i % 2 == 1)
        {
            digit *= 2;
            int sum = digit % 10 + digit / 10;
            odd_sum += sum;
        }
        else if (i % 2 == 0)
        {

            even_sum += digit;

        }
    }
    total_sum = odd_sum + even_sum + check_digit;

    if(total_sum % 10 == 0)
        return 1;
    else return 0;

}

int main()
{
    int num;
    printf ("SIN Validator\n=============\n");
    do
    {
        printf ("SIN (0 to quit): ");
        scanf ("%d", &num);
        if(num == 0)
        { 
            printf ("Have a Nice Day!");
            break;                           //thoát khỏi vòng do-for
        }
        if (numcheck (num) == 1)
        { 
            printf("This is a valid SIN.\n");
        }
        else printf("This is not a valid SIN.\n");
    }
    while(num != 0);
}
/***************************************************************
////////////////////////////////////////////////////////////////
A Canadian SIN has nine digits.  The right-most digit is a check digit that enables validation.  For the whole number to be a valid SIN, a weighted sum of the other digits plus this check digit must be divisible by 10. 

To obtain the weighted sum, take the digit to the left of the check digit and then every second digit leftwards.  Add each of these digits to itself.  Then, add each digit of each sum to form the weighted sum of the even positioned digits.  Add each of the remaining SIN digits (except the check digit) to form the sum of the odd positioned digits.  Add the two sums and subtract the next highest number ending in zero from their total.  If this number is the check digit, the whole number is a valid SIN; otherwise, the whole number is not a valid SIN.

Consider the following example:

 SIN  193 456 787
                |
 check digit is 7
 add first set of alternates to themselves 
   9  4  6  8
   9  4  6  8
  18  8 12 16
 add the digits of each sum 1+8+8+1+2+1+6 = 27
 add the other alternates   1+3+5+7       = 16
 total                                    = 43
 Next highest integer multiple of 10      = 50
 Difference                               =  7
 Matches the check digit, therefore this SIN is valid 

Specifications

Design a program that validates a Canadian Social Insurance Number (SIN).  Your program keeps accepting a whole number and determining if that whole number is a valid SIN.  Your program terminates when the user enters 0 as the whole number.  The output from your program looks something like:

 SIN Validator
 =============
 SIN (0 to quit): 193456787
 This is a valid SIN.
 SIN (0 to quit): 193456788
 This is not a valid SIN.
 SIN (0 to quit): 0
 Have a Nice Day!


****************************************************************/