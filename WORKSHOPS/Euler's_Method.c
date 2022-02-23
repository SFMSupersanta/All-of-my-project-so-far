/****************************************************************
╰（‵□′）╯ I CAN'T BELIVE HOW THE TEACHER MADE US DO THIS
Referring code made by SFMSupersanta.
Program: practice
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer (void);

double getDouble(char msg[], double min, double max);

int main()
{
    double num = getDouble("Find the square root of : ",0,100000)
          ,err = getDouble("Acceptable Error : ",0,100000);
        
    double iestimate = num/2;
    int i=1;
    printf(" Iteration            Estimate");
    printf("%10d,%.20lf",i++,iestimate);
    if((iestimate-2)>err)
    {
        while(err<=euclid(num,&iestimate))
        printf("%10d,%7.12lf",i++,iestimate);
    }
    printf("The approximate square root after %d iterations is %.6lf",i,iestimate);
    return 0;
}

double euclid(double num, double *estimate)
{
    double quotient = *estimate;
    *estimate = num / quotient;
    return quotient - *estimate;
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
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
     } 
     while (keeptrying == 1);
     
     return value;
 }