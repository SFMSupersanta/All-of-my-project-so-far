//v2.0
//made by suprersanta 
#include <stdio.h>
#include <stdlib.h>

void console_dump(long long num) //code để in số product code, company code ra console.
{
    num /= 10;
    long temp_num = num / 100000;              //bỏ 5 số cuối
    long another_temp_num = num % 100000;      //lấy 5 số cuối
    printf("The company code is %06d",temp_num);
    printf("\nThe product code is %05d\n" ,another_temp_num);

    /****************************************************************
    int temp_array[5];                //làm 1 cái array rồi cho cả dãy 11 số vào array là xong. đừng làm theo tui.
    printf("The company code is ");
    for (int i = 0; i <= 5; i++)
    {
        int digit = temp_num % 10;
        temp_num /= 10;
        temp_array[i] = digit;
    }
    for (int i = 5; i >= 0; i--)
        printf("%d",temp_array[i]);
    printf("\nThe product code is ");
    for (int i = 0; i <= 4; i++)
    {
        int digit = num % 10;
        num /= 10;
        temp_array[i] = digit;
    }
    for (int i = 4; i >=0; i--)
        printf("%d",temp_array[i]);
    printf("\n"); ****************/
}

int check_num(long long num)                  //function để check xem có hợp lệ không 
{
    int check_digit = num % 10;
    num /= 10;
    int odd_sum, even_sum, weighted_sum;
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
    weighted_sum = odd_sum*3 + even_sum + check_digit;
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
        scanf("%lld", &num);
        if(num == 0)
        { 
            break;                           //thoát khỏi vòng do-for
            printf("Have a Nice Day!");
        }
        if(check_num(num)==1)
        { 
            printf("This is a valid UPC.\n");
            console_dump(num);
        }
        else printf("This is not a valid UPC.\n");
    } while (num != 0);                           //để vòng không lặp lại
    
}