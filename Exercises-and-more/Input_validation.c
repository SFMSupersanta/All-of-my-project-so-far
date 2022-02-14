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
//getchar(str, min, max)
double GetDouble(char msg[], double min, double max)
{
    double value;
    int rc;
    char ovflow;
    while (true) 
    {
        printf("%s\n", msg);
        printf("in the range [%.2lf,%.2lf] : ",min, max);
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
        else if(value < min || value > max)
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
    double input = GetDouble("Enter the number",10,20);
    printf("\nProgram accepted %.2lf\n",input);
    return 0;
}