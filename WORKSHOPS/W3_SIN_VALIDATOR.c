/****************************************************************
 A valid SIN number is the number that the last number is a check number.
 Double the first, third, and so forth,...number leftwise.
 The first sum is the sum of every doubled number's digit. EX: 16=1+6.
 The second sum is the sum of every secon, fourth, and so forth.
 Add the two sum and if the total sum plus the check number is devisible to 10, that number is a valid SIN.\n
 Coder: Supersanta.
 Date:14/01/2021 DD/MM/YYYY
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
            //printf("%d\n", even_sum);
            even_sum += digit;
            //printf("%d\n", digit);
        }
    }
    total_sum = odd_sum + even_sum + check_digit;
    //printf("%d\n", total_sum);
    //printf("%d\n", odd_sum);
    //printf("%d\n", even_sum);
    if(total_sum %10==0)
        return 1;
    else return 0;

}

int main()
{
    int num;
    printf("SIN Validator\n=============\n");
    do
    {
        printf("SIN (0 to quit): ");
        scanf("%d", &num);
        if(num == 0)
        { 
            printf("Have a Nice Day!");
            break;                           //thoát khỏi vòng do-for
        }
        if(numcheck(num)==1)
        { 
            printf("This is a valid SIN.\n");
        }
        else printf("This is not a valid SIN.\n");
    }
    while(num != 0);
}