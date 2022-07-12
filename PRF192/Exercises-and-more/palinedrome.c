// This is an comisson distribution. Use for reference purpose only

#include <stdio.h>
#include <math.h>

int primecheck(int n)
{
    if (n == 1 || n == 2 || n == 4 || n == 0)
        return 0;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int flip(int n)
{
    int result = 0;

    while (n != 0)
    {
        result = (result * 10) + (n % 10);
        n /= 10;
    }

    return result;
}

int main()
{
    int number;
    printf("Type in the number :");
    scanf("%d", &number);

    for (int i = 3; i < number; i++)
    {
        if (primecheck(i) == 1 && flip(i) == i)
        {
            printf("%d\t", i);
        }
    }

    return 0;
}