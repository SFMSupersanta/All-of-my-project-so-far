/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: Input validation
version #
****************************************************************/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void clear (void) 
{
    while ( getchar() != '\n' );
}
//getchar(str, min, max)
int GetInt(char msg[], int min, int max)
{
    int value;
    int rc;
    char ovflow;
    while (true) 
    {
        printf("%s\n", msg);
        printf("in the range [%d,%d] : ",min, max);
        rc = scanf("%d%c",&value,&ovflow);
        if(rc == 0)
        {
            printf("No input accepted");
        }
        else if(ovflow != '\n')
        {
            printf("Trailing characters");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("Out of range");
        }
        else break;
    }
    return value;
}

int main()
{
    srand(time(NULL));
    int times = GetInt("Input",0,100);
    int head=0, tail=0;
    for (int i = 0; i < times; i++)
    {
        int coin = rand() % 2;
        if (coin == 0)
        {
            head++;
        }else
        {
            tail++;
        }
    }
    printf("head result is %.2lf%%",(double)head*100/times);
    printf("tail result is %.2lf%%",(double)tail*100/times);
    return 0;
}