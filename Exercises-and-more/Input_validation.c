/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: Input validation
version #
****************************************************************/

#include <stdio.h>
#include <stdbool.h>
#define MIN 0.1
#define MAX 99.99

void clear (void) 
{
    while ( getchar() != '\n' );
}

double GetDouble()
{
    double value;
    int rc;
    char ovflow;
    while (true) 
    {
        printf("Enter a whole number\n");
        printf("in the range [%.2lf,%.2lf] : ",MIN,MAX);
        rc = scanf("%lf%c",&value,&ovflow);
        if(rc == 0)
        {
            printf("**No input accepted!**\n\n");
            printf("----Press Enter to continue----");
            clear();
        }
        else if(ovflow != '\n')
        {
            printf("**Trailing characters!**\n\n");
            clear();
            printf("----Press Enter to continue----");
            clear();
        }
        else if(value < MIN || value > MAX)
        {
            printf("**Out of range!**\n\n");
            printf("----Press Enter to continue----");
            clear();
        }
        else break;
    }
    return value;
}

int main()
{
    double input = GetDouble();
    printf("\nProgram accepted %.2lf\n",input);
    return 0;
}