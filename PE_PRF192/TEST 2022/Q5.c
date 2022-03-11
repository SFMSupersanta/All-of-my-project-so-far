/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
****************************************************************/
#include <stdio.h>


int main()
{
    system("cls");
    //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    int n;
    scanf("%d", &n);
    int status = 1;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if(n>1) 
    {
        for (int i = 1; i <= n/2; i++)
        { 
            if(arr[i-1]!=arr[(n-i)]) status = 0;
        }
    }
    

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    printf("%d",status);



    
    

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}

/*
5
2
2
3
2
2

5
2
2
3
4
2

4
1
2
2
1

4
2
2
1
2


*/
