/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version #
////////////////////////////////////////////////////////////////
This program contain a function that takes an bool array and 
use eratosthenes method to make it so that all true values are 
prime number.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void eratosthenes(bool arr[], long long size)
{ 
    for (int i = 1; i <= size; i++)
    { 
        arr[i] = true;
    }

    
    for (int i = 2; i <= size; i++) 
    {
    if (arr[i] == true) 
    {
      for (int j = 2 * i; j <= size; j += i) 
      {
        arr[j] = false;
      }
    }
  }


}

int main()
{
    long long number = 1000000 ;
    double time_spent = 0.0;
    bool arr[number+1];

    clock_t begin = clock();

    eratosthenes(arr, number);
    
    clock_t end = clock();
    
    int count = 1;
    for (int i = 1; i < number; i ++)
    {
        if(arr[i] == true)
        {
            printf("%10d", i);
            count ++;
            if (count % 10 == 0) 
            {
                printf("\n");
                count = 1;
            }
        }
    }
    
    
    time_spent += (double)(end - begin);
    printf("\nThe elapsed time is %lf seconds", time_spent);
}