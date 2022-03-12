/****************************************************************
[]~(￣▽￣)~*]
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>

void time_cal(double velocity, double height, double delta, double *pt1, double *pt2)
{   
    //printf("\ndelta: %lf\nvelocity: %lf\nheight: %lf", delta,velocity,height);
    double g = 9.8;
    if (delta > 0)
    {
        *pt1 = (- velocity + sqrt(delta)) / (2 * g);
        *pt2 = (- velocity - sqrt(delta)) / (2 * g);
    }
    else if (delta == 0)
    {
        *pt1 =  (- velocity + sqrt(delta)) / (2 * g);
    }
    
}

int main()
{
    printf("Fireworks\n=========\n");

    double velocity;
    double height, t1,t2;
    do
    {
        printf("Initial vertical velocity (m/sec) (0 to quit) : ");
        scanf("%lf", &velocity);

        if (velocity == 0) 
        {
            printf("\nHave a nice day!\n");  
        }
        else
        {
            double g = 9.8;
            printf("Desired height (m):                             ");
            scanf("%lf", &height);
            double height_that_never_can_be_reached = height;
            //times 2 for how the equation works
            velocity *= 2;
            height *= 2;
            //also because of the equation
            velocity = -velocity;
            double delta = velocity * velocity - 4 * (g * height);
        
            time_cal(velocity, height, delta, &t1,&t2);
            if(delta > 0)
            {
                printf ("\nYour firework will reach the desired height at times:\n");
                printf ("  %.2lf sec\n  %.2lf sec\n", t1,t2);
            }
            else if (delta == 0)
            {
                printf ("\nYour firework will reach the desired height at times:\n");
                printf ("  %.2lf sec\n", t1);
            }
            else if (delta < 0)
            {
                printf ("\nYour firework will never reach %.2lf m\n",height_that_never_can_be_reached);
            }
            printf ("\n");
        }

    }while (velocity != 0);

    return 0;
}
/*#######################
###################
#TEST CASE(ctrc+v)#
###################
20 10
20 20.408163265306122
20 21
0

###################
////////////////////////////////////////////////////////////////
You have been asked to design a set of simultaneous fireworks for your next National holiday.  In the design, you need to ensure that each firework reaches a specified height. 

You know that the height (in m) of a projectile is given by the formula

 h = - g * t2 / 2 + b * t
where t is the time from launch, g is the acceleration due to gravity (9.8 m/sec2) and b is the initial vertical velocity component (in m/sec). 
Design and code a program that calculates the time at which a projectile will reach a certain height.  Your program prompts for and accepts the initial vertical velocity component and the desired height.  Your program handles cases where the desired height is the maximum height reached and cases where the desired height is never reached.  Your program stops asking for input and terminates if the user enters 0 for the initial vertical velocity.  To determine the solution of the above equation, design and code the roots function described below. 

Your output might look something like:

 Fireworks
 =========
 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             10

 Your firework will reach the desired height at times:
   0.58 sec
   3.50 sec

 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             20.408163265306122 

 Your firework will reach the desired height at time:
   2.04 sec

 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             21

 Your firework will never reach 21.00 m

 Initial vertical velocity (m/sec) (0 to quit) : 0

 Have a Nice Day!

Design and code a C function named roots that calculates the roots of a quadratic equation.  Your function receives three doubles that hold the coefficients of the quadratic equation and returns through two other double parameters the real roots of the equation.  The function returns the number of real roots found as the return value of the function itself.  The header for your function looks something like

 int roots(double a, double b, double c, double *r1, double *r2) 

Consider the quadratic equation:

 f(x) = a * x2 + b * x + c
               
where a, b and tc are constant coefficients.  This equation may have up to 2 real roots.  The roots are the values of x for which
 a * x2 + b * x + c = 0
               
The roots are given by the equations
 x1 = ( - b + sqrt( D ) ) / ( 2 * a )
 x2 = ( - b - sqrt( D ) ) / ( 2 * a )
where D is the discriminant
 D = b2 - 4 * a * c
If D is positive-valued, there are 2 real roots.  If D is zero-valued, there is one real root.  If D is negative-valued, there are no real roots.
If there is one real root, set x1 to its value and leave x2 unchanged.  If there are no real roots, leave x1 and x2 unchanged. 
****************************************************************/