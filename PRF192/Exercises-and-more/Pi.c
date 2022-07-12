/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: exercise
version #
////////////////////////////////////////////////////////////////
The mathematical constant p may be calculated using the series
formula

 p = 4 ( 1 - 1/3 + 1/5 - 1/7 + ... )

Write a function with the header

 double pi ( int nterms )

that receives as a parameter the number of terms to be used in
calculating the approximate value of p and returns that value.

The mathematical constant p may also be calculated using the
Wallis product

 p = 2 [ (2/1) * (2/3) * (4/3) * (4/5) * (6/5) * (6/7) ... ]

Write a second function with the header

 double pi_wallis ( int nterms )

that receives as a parameter the number of terms to be used
in calculating the approximate value of p and returns that value.

Finally, write a main program that evaluates p for an increasing
number of terms and displays the results returned from both
functions so as to show the relative rate of convergence of each
method of approximation.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer(void);

long long getInt(char msg[], long long min, long long max);

double pi(int nterms);

double pi_wallis(int nterms);

int main()
{
    int terms = getInt("Type the terms used in both function: ", 1, 10000000);
    printf("Series formula result: %.6lf\nWallis product result: %.6lf\n", pi(terms), pi_wallis(terms));
    return 0;
}

double pi(int terms)
{
    double pi = 0;
    double j = 1;
    for (int i = 0; i < terms; i++)
    {
        if (i % 2 == 0)
        {
            pi += 1 / j;
            j += 2;
        }
        else
        {
            pi -= 1 / j;
            j += 2;
        }
    }
    printf("pi: %.6lf\n", pi);
    return 4 * pi;
}

double pi_wallis(int nterms)
{
    int nominator = 2, denominator = 1;
    double product = 1;
    for (int i = 1; i <= nterms; i++)
    {
        if (i % 2 == 1)
        {
            product *= (double)nominator / denominator;
            denominator += 2;
        }
        else
        {
            product *= (double)nominator / denominator;
            nominator += 2;
        }
    }
    return 2 * product;
}

void clear_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

long long getInt(char msg[], long long min, long long max)
{
    char val[20];          // input value
    int intval, count, rc; // int value and count value
    while (1)
    {
        printf("%s", msg);
        count = 0;
        rc = 0;
        fgets(val, 20, stdin);
        if (val[0] != '\n')
        {
            if (0 < max && 0 > min)
                if (val[0] == '0' && val[1] == '\n')
                    return 0;
            for (int i = 0; i < 20; i++)
            {
                if (val[i] == '\n')
                    rc = 1;
            }
            if (rc == 0)
                clear_buffer();
            intval = atoi(val);

            // printf("%d\n", intval);

            if (intval <= 0)
                count++;

            while (intval != 0)
            {
                intval /= 10;
                count++;
            }

            // printf("%d\n", count);

            intval = atoi(val);

            if (val[count] != '\n')
                printf("**Trailing Character(s)**\n");
            else if (min < intval && intval < max)
            {
                return intval;
            }
            else
                printf("**OUT OF RANGE**\n");
        }
        else
            printf("**No input**\n");
    }
}