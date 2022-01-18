/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>

void time_cal(double velocity, double height)
{
    double g = 9.8;
    double height_that_never_can_be_reached = height;
    velocity *= 2;
    velocity = -velocity;
    height *= 2;

    double delta = velocity*velocity - 4*(g*height);
    //printf("\ndelta: %f\n", delta);

    if (delta > 0)
    {
        printf("\nYour firework will reach the desired height at times:\n");
        printf("%.2lf sec\n", (- velocity + sqrt(delta)) / (2 * g));
        printf("%.2lf sec\n", (- velocity - sqrt(delta)) / (2 * g));
    }
    else if (delta == 0)
    {
        printf("\nYour firework will reach the desired height at times:\n");
        printf("%.2lf sec\n", (- velocity + sqrt(delta)) / (2 * g));
    }
    else if (delta < 0)
    {
        printf("\nYour firework will never reach %2.lf m\n",height_that_never_can_be_reached);
    }
    printf("\n");
}

int main()
{
    printf("Fireworks\n=========\n");

    double velocity;
    double height;
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
            printf("Desired height (m):                             ");
            scanf("%lf", &height);
            time_cal(velocity, height);
        }

    }while(velocity != 0);

    
    return 0;
}