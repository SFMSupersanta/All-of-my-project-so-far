
#include<stdio.h>
#include<stdlib.h>
#include "validator.h"
#include "reverse.h"


int main()
{   
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverseInt(arr, size);
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    reverseInt(arr, size);

    int *newarr = PreverseInt(arr, size);
    printf("Reversed array using pointer: ");
    for (int i = 0; i < size; i++) printf("%d ", newarr[i]);
    printf("\n");
    free(newarr);

    char str[] = "abcdefghijklmnopqrstuvwxyz";

    reverseStr(str);
    printf("Reversed string: %s\n", str);
    reverseStr(str);

    char *newstr = PreverseStr(str);
    printf("Reversed string using pointer: %s\n", newstr);

    free(newstr);

    return 0;
}