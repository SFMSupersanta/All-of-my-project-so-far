/****************************************************************
OwO
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

void console_dump(long long num) //code để in số product code, company code ra console.
{
    num /= 10;
    long temp_num = num / 100000;              // bỏ 5 số cuối
    long another_temp_num = num % 100000;      // lấy 5 số cuối
    printf("The company code is %06d",temp_num);
    printf("\nThe product code is %05d\n" ,another_temp_num);
}

int check_num(long long num)                  // function để check xem có hợp lệ không 
{
    int check_digit = num % 10;
    num /= 10;
    int odd_sum = 0, even_sum = 0, weighted_sum;
    for(int i = 1; i <= 11; i++)
    {
        int digit = num % 10;
        num /= 10;
        if(i%2==1)
        {
            odd_sum += digit;
        }
        if(i%2==0)
        {
            even_sum += digit;
        }
    }
    weighted_sum = odd_sum * 3 + even_sum + check_digit;

    if(weighted_sum % 10 == 0) 
        return 1; 
    return 0;
}

int main()
{
    long long num;
    printf("UPC Validator\n=============\n");
    do
    {
        printf("UPC (0 to quit): ");
        scanf ("%lld", &num);
        if (num == 0)
        { 
            break;                           // thoát khỏi vòng do-for
            printf("Have a Nice Day!");
        }
        if(check_num (num)==1)
        { 
            printf("This is a valid UPC.\n");
            console_dump (num);
        }
        else printf("This is not a valid UPC.\n");
    } while (num != 0);                           // để vòng không lặp lại
    
}
/***************************************************************
////////////////////////////////////////////////////////////////
This problem is moderately more difficult than the above 
problems.  This one requires a data type that stores 12 digits 
and involves a further decomposition.

Background

A Universal Product Code (UPC) bar code consists of 12-digits.  
The first 6 digits represent the company that produces the 
product, the next 5 digits represent a unique item number that 
that company has assigned to the product and the last digit is a 
check digit.  The check digit is used to determine if the code 
has been properly interpreted by the scanning device. 

To determine the expected value of the check digit, use the 
weighted sum of the other digits:

multiply the sum of the 1st, 3rd, etc. digits in the code by 3
add the sum of the 2nd, 4th, etc digits (excluding the check digit)
add the two sums together to obtain the weighted total
the expected check digit is the digit that when added to the 
weighted total results in a number that is divisible by 10
Consider the following example:

 UPC  067800001019
                 |
 check digit is  9
 add 1st, 3rd, ..., 11th digits 
      0 7 0 0 1 1    =  9
 multiply by 3       = 27
 add 2nd, 4th, ..., 10th digits
       6 8 0 0 0     = 14
 add weighted sum    = 41
 add check digit        9
 total                 50
 divide by 10           5
 remainder              0
 Therefore this is a valid UPC

Specifications

Design a program that validates a UPC and displays the company
and product numbers separately.  Your program keeps accepting a 
whole number and determining if that whole number is a valid UPC.  
Your program terminates when the user enters 0 as the whole number. 

The output from your program looks something like:

 UPC Validator
 =============
 UPC (0 to quit): 067800001019 
 This is a valid UPC.
 The company code is 067800.
 The prduct code is   00101.
 UPC (0 to quit): 067800001018
 This is not a valid UPC.
 UPC (0 to quit): 0
 Have a Nice Day!

The data type long only guarantees room for 9 digits.  The data 
type long long guarantees room for an integer with well over 12 
digits (at least 64 bits of precision).  The conversion specifier 
for a long long integer is %lld.  The Borland 5.5 compiler does 
not include the long long data type, but instead provides __int64 
and %I64d instead of %lld as the conversion specifier. 
****************************************************************/