/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao 4 chu cai
in ra cac chu cai sap xep theo alphabelt tren 1 dong va cach 
nhau bang 1 space
****************************************************************/
#include <stdio.h>

//swap function
void swap(char *a, char *b)
{
    char c=*a;
    *a=*b;
    *b=c;
}

void selectionsort(char arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        char *jmin = &arr[i];
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

    char input[4];

    for (int i = 0; i < 4; i++)
    {
        scanf("%c", &input[i]);
        getchar();
    }

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    selectionsort(input,4);



/*
a
h
b
g

*/

    
    for (int i = 0; i < 4; i++)
    {
        printf("%c ",input[i]);
    }

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}