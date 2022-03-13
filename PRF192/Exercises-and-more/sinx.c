/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: sin
version #
////////////////////////////////////////////////////////////////
The trigonometric function sin(x) may be calculated using the 
infinite series formula

 sin(x) = x - x3/3! + x5/5! - x7/7! + ...

where x is in radians.  1 radian is 180 degrees/p.

Write a function with the header

 double sin ( double x, int nterms )

that receives as parameters the value of x in radians and the 
number of terms to be used in calculating the approximation and 
returns the approximate value.

Finally, write a main program to test your function.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer (void);

long long getInt(char msg[], long long min, long long max);

double xsin ( double x, int nterms );

long long power(int x,int pw);

long long factorial(int x);

int main()
{
    int rad = getInt("Type in the x value: ",1,1000000);
    int terms = getInt("Type the terms: ",1,10000000);
    printf("The sin of x is : %lf\n",xsin(rad,terms));
    return 0;
}

double xsin ( double x, int nterms )
{
    double  sinx=0;
    int denominator = 1;
    
    for(int i = 0; i<nterms; i++)
    {
        //printf("denominator: %d\n",denominator);
        //printf("%lld,%lld\n",power(x,denominator),factorial(denominator));
        if(i%2==0)
        {
            //printf("%lld,%lld\n",power(x,denominator),factorial(denominator));
            sinx+=((double)power(x,denominator)/factorial(denominator));
            //printf("sinx timex: %lf %d\n",sinx,i);
            denominator+=2;
        }else 
        {
            sinx-=((double)power(x,denominator)/factorial(denominator));
            //printf("sinx timex: %lf %d\n",sinx,i);
            denominator+=2;
        }
        
    }
    return sinx;
}

long long factorial(int x)
{
    long long result = 1;
    for(int i=2;i<=x;i++)
    {
        result *= i;
    }
    return result;
}

long long power(int x,int pw)
{
    long long powered=1;
    for(int i = 0; i < pw; i++)
    {
        powered*=x;
    }
    return powered;
}

 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

 long long getInt(char msg[], long long min, long long max)
{
     char val[20];           //input value
     int intval,count,rc;      //int value and count value
     while(1)
     {
         printf("%s", msg);
         count = 0;
         rc =0;
         fgets(val,20,stdin);
         if(val[0]!='\n')
         {
             if(0<max&&0>min) if(val[0]=='0' && val[1] == '\n') return 0;
             for(int i=0; i< 20; i++) 
             {
                 if(val[i]=='\n') rc = 1;
             } 
             if(rc==0) clear_buffer();
             intval = atoi(val);
 
             //printf("%d\n", intval);
 
             if(intval<=0) count++;
 
             while(intval!=0)
             {
                 intval/=10;
                 count++;
             }
 
             //printf("%d\n", count);
 
             intval = atoi(val);

             if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
             else if(min<intval&&intval<max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }