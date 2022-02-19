
#include<stdio.h>
#include "validator.h"



int main()
{   
    while(1)
    {
        double c;
        printf("Input accepted: %.3lf\n", c=getDouble("Input char : ", 1,10));
    }

    return 0;
}