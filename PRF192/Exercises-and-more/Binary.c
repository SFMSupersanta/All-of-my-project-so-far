/****************************************************************
[]~(￣▽￣)~*]
Referring code made by SFMSupersanta.
Program: Binary converter
version #
////////////////////////////////////////////////////////////////
convert demical to binary
****************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void clear();

long long GetInt(char msg[], long long min, long long max);

void caculate(bool result[], long long num);

int main()
{
    long long cvn = GetInt("Type in the number: ", 1, 10000000);
    bool result[16];
    for (int i = 0; i < 16; i++)
        result[i] = false;

    caculate(result, cvn);

    printf("The binary equivelent binary is: ");
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", result[i]);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
    // system("pause");
    return 0;
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

void caculate(bool result[], long long num)
{
    int cnt = 0;
    while (num != 0)
    {
        result[cnt++] = num % 2;

        num /= 2;
    }
}