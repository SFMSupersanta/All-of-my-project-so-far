// This is an comisson distribution. Use for reference purpose only

#include <stdio.h>

int main()
{
    int number;
    printf("Type in the number :");
    scanf("%d", &number);
    int lastdigit = number % 10, count = 1;
    number /= 10;
    while (number != 0)
    {
        if (number % 10 == lastdigit)
        {
            count++;
        }
        number /= 10;
    }
    printf("Occorence of last digit : %d\n", count);
    return 0;
}