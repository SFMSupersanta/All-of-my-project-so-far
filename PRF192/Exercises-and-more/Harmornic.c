/****************************************************************
╰（‵□′）╯ I CAN'T BELIVE HOW THE TEACHER MADE US DO THIS
Referring code made by SFMSupersanta.
Program: practice
version #
////////////////////////////////////////////////////////////////
Write a program that calculates the harmonic value for a given
number of terms.

The harmonic value is calculated using the series formula

  h = 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + ...

Your program prompts for and accepts the number of terms to be
used in calculating the value.  Your program displays the value
to 6 decimal places.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer(void);

long long getInt(char msg[], long long min, long long max);

int main()
{
    int term = getInt("Enter the number of terms: ", 1, 100000);
    double h = 1;
    {
        for (int i = 1; i <= term; i++)
        {
            h += (double)1 / i;
        }
    }
    printf("The caculated value is: %.6lf", h);
    return 0;
}

/* clear empties input buffer */
void clear_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

long long getInt(char msg[], long long min, long long max)
{
    long long value, rc;
    int keeptrying = 1;
    char excess;

    do
    {
        printf("%s ", msg);
        rc = scanf("%lld%c", &value, &excess);
        if (rc == 0)
        {
            printf("**No input accepted!**\n\n");
            clear_buffer();
        }
        else if (excess != '\n')
        {
            printf("**Trailing characters!**\n\n");
            clear_buffer();
        }
        else if (value < min || value > max)
        {
            printf("**Out of range!**\n\n");
        }
        else
            keeptrying = 0;
    } while (keeptrying == 1);

    return value;
}