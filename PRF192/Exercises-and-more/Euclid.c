/****************************************************************
╰（‵□′）╯ I CAN'T BELIVE HOW THE TEACHER MADE US DO THIS
Referring code made by SFMSupersanta.
Program: practice
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer(void);

double getDouble(char msg[], double min, double max);

double euclid(double num, double *estimate);

int main()
{
    double num = getDouble("Find the square root of : ", 0, 100000);
    double err = getDouble("Acceptable Error : ", 0, 100000);
    double iestimate = num / 2;
    int i = 1;
    printf(" Iteration            Estimate\n");
    printf("%10d%*.12lf\n", i++, 20, iestimate);
    if ((iestimate - 2) > err)
    {
        while (err <= euclid(num, &iestimate))
            printf("%10d%*.12lf\n", i++, 20, iestimate);
    }
    printf("The approximate square root after %d iterations is %.6lf\n", --i, iestimate);
    return 0;
}

double euclid(double num, double *estimate)
{

    double quotient;
    quotient = num / *estimate;
    *estimate = (quotient + *estimate) / 2;
    return *estimate - quotient;
}

/* clear empties input buffer */
void clear_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

double getDouble(char msg[], double min, double max)
{
    double value, rc;
    int keeptrying = 1;
    char excess;

    do
    {
        printf("%s ", msg);
        rc = scanf("%lf%c", &value, &excess);
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

// testcase:
/*
34567.0
0.000000001

*/