#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare_arr(char arr1[], char arr2[], int size)
{
    for(int i = 0; i <size; i++)
    {
        if (arr1[i] != arr2[i]) return 1;
    } return 0;
}



int main()
{

    char arr1[] = {"134aaaa"};
    char arr2[] = {"1234aaaa"};
    printf("%d\n",compare_arr(arr1, arr2,8));
    return 0;
}