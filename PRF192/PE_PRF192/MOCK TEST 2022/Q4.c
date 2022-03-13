/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao 7 so int
in ra 7 so theo thu tu sap xep tu nho den lon
****************************************************************/
#include <stdio.h>

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

int main()
{
    system("cls");
    //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    int input[7];
    for(int i = 0; i < 7; i++)
    { 
        scanf("%d",&input[i]);
    }

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    selectionsort(input,7);



/*
1
3
2
6
4
8
10

*/

    
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",input[i]);
    }

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}