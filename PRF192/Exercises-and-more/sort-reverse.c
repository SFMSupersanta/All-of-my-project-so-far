// This is an comisson distribution. Use for reference purpose only

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//swap function
void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

int main()
{   
    int n;
    printf("Type in n: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    { 
        printf("arr[%d] = ", i);
        scanf("%d", &array[i]);
    }

    qsort(array, n/2, sizeof(int), cmpfunc);

    int count = 0;
    for(int i=n/2; i < n-(n/4); i++)
    {
        swap(&array[i], &array[n-count-1]);
        count++;
    }

    printf("sorted array: ");

    for(int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;

}


