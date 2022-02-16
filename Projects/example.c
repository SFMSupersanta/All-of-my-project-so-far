#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

bool checkdif(int arr[], int a, int b)
{
    for(int i = 0; i <b; i++) 
    {
        if(arr[i] == a)
        return false;
        break;
    }
    return true;
}

int main()
{
	int arr[] = {3,4,5,6};
	printf( "%d\n",checkdif(arr,6,4) );
	return 0;
}