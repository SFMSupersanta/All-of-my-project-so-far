// Optimized implementation of Bubble sort
#include <stdio.h>
#include <stdbool.h>
#include "validator.h"
  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int items)
{
   int i, j;
   bool swapped;
   for (i = 0; i < items-1; i++)
   {
     swapped = false;
     for (j = 0; j < items-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

void selectionSort(int arr[], int items)
{
    int i, j, min_index;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < items-1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < items; j++)
          if (arr[j] < arr[min_index])
            min_index = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  
// Driver program to test above functions
int main()
{
    int size;
    printf("Number of items to sort: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &arr[i]);
        clear_buffer();
    }
    char algorithm;
    getChar("Select sort algorithm: ", "BbSs");
    if(algorithm == 'B' || algorithm == 'b')
    {
        bubbleSort(arr, size);
    }
    else
    {
        selectionSort(arr, size);
    }
    printf("\nSorted array: ");
    printArray(arr, size);
    return 0;
}