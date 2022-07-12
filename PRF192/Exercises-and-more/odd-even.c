// This is an comisson distribution. Use for reference purpose only

#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    printf("Type in the number :");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        number -= 1;
    }
    else
    {
        int position = 0;
        int temp = number;
        while (number != 0)
        {
            position++;
            number /= 10;
        }
        number = temp + (pow(10, position - 1));
    }

    printf("Modified number is : %d\n", number);

    return 0;
}