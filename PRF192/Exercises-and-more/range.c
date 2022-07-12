/****************************************************************
[]~(￣▽￣)~*]
Referring code made by SFMSupersanta.
Program: range
version #
////////////////////////////////////////////////////////////////
this does cool stuff, just run the program
****************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void clear();

long long GetInt(char msg[], long long min, long long max);

int main()
{
    long long min, max;
    min = GetInt("Nhap So Nho: ", 2, 20);
    max = GetInt("Nhap So Lon: ", min + 1, 20);
    int row, col;
    for (int i = min - 1; i <= max; i++)
    {
        if (i == min - 1)
            printf("       ");
        else
        {
            printf("%6d ", i);
        }
        if (i == max)
            printf("\n\n");
    }
    for (int i = min; i <= max; i++)
    {
        printf("%6d ", i);
        for (int j = min; j <= max; j++)
        {
            printf("%6d ", j * i);
        }
        printf("\n\n");
    }
}

long long GetInt(char msg[], long long min, long long max)
{
    long long value;
    int rc;

    while (true)
    {
        printf("%s", msg);
        printf("in the range [%lld,%lld] : ", min, max);
        rc = scanf("%lld", &value);
        if (rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if (getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if (value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else
            break;
    }
    return value;
}

//\input stream clear function\*
void clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}