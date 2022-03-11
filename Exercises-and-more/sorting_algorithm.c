/****************************************************************
╰（‵□′）╯
Referring code made by SFMSupersanta.
Program: Sorting algorithms
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//bublesort
void bubs(int arr[], int size);

//swap function 
void swap(int *a, int *b);

//partitioning-quick-sort
int partition(int arr[], int low,int high);

//quick sort
void quickSort(int arr[], int low, int high);

//selection sort
void selectionsort(int arr[], int size);

void print(int arr[], int size);

void StringSelectionSort(char input[][255], int size);

void swaparr(char arr1[], char arr2[]);


//main
int main()
{
    int sort[] = {3,456,323,641,472,431,165,2347,36,346,445,24,2,34,3,4,5,6,7,8,9,10,1100,65};
    int size = sizeof(sort) / sizeof(int);

    char str[4][255]={"AB      Albert Bumble"
                     ,"DD      Donald Duck"
                     ,"FG      Fred Goofoff"
                     ,"GF      Gary Flintstone"};
    StringSelectionSort(str,4);
    for (int i=0; i<4; i++)
    { 
        printf("%s\n", str[i]);
    }

    printf("\narray: ");
    print(sort, size);

    quickSort(sort,0,size-1);
    printf("\nquick sorted arr: ");
    print(sort,size);

    bubs(sort,size);
    printf("\nbuble arr sort: ");
    print(sort,size);

    quickSort(sort,0,size-1);
    printf("\nReversed array: ");
    print(sort,size);

    selectionsort(sort,size);
    printf("\nselectionsort arr sort: ");
    print(sort,size);
    printf("\n");

    return 0;           
}

void swaparr(char arr1[], char arr2[])
{ 
    char arr3[255];
    strcpy(arr3,arr1);
    strcpy(arr1,arr2);
    strcpy(arr2,arr3);
}

void StringSelectionSort(char input[][255], int size)
{
    int index;
    for(int i=0; i<size; i++)
    { 
        index = i;
        for(int j=i+1; j<size; j++)
        { 
            if(strcmp(input[index], input[j])>0)
            { 
                index = j;
            }
        }
    swaparr(input[index],input[i]);
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size;i++)
    {
        printf("%d",arr[i]);
        if(i!=size) printf(" ");
    }
    printf("\n");
}

//swap function
void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

void selectionsort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int *jmin = &arr[i];
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < *jmin) jmin = &arr[j];
        }
        swap(&arr[i], &*jmin);
    }
}

//bublesort
void bubs(int arr[], int size)
{

    for(int i = 0; i < size-1; i++)
    {

        for (int j = size-1; j>i; j--)
        {
 
            if(arr[j] < arr[j-1]) 
            {
                swap(&arr[j],&arr[j-1]);

            }
        }
    }
}

//partitioning
int partition(int arr[], int low,int high)
{
    //printf("size: %d,%d\n",low,high);
    int i=low-1, middle=arr[high];
    //printf("low,midle: %d, %d\n",i,middle);
    for(int j = low; j < high; j++)
    {
        if(arr[j] < middle)
        {
            i++;
            swap(&arr[i], &arr[j]);
            //printf("swaped: %d,%d\n",arr[j], arr[i]);
        }
    }

    //swap arr[high] in place
    swap(&arr[++i], &arr[high]);

    return i;
}

//quick sort
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        //because arr[pi] is already in it's place
        quickSort(arr,low, pi-1);
        quickSort(arr,pi+1,high);
    }
}