#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double mean(double *data, int size)
{
    double sum;
    while (data)
    {
        sum+= *data;
        data++;
    }
    return sum/size;
}

double dev(double *data, int size, double m)
{
    double Ssum=0;                        //squared sum variable
    while (data)
    {
        Ssum += *data* *data;
        data++;
    }
    double deviation = (Ssum / size) - (m*m);
    return sqrt(deviation);
}



int main()
{

    double arr[] = {3,4,5,3,6,2,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    double *arrP = &arr[0];
    *arrP++;
    printf("arr: %.2lf", *arr);
    //double i=mean(arr,size);
    //printf("Result: %.2lf\n", i);
    return 0;
}