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
    int sum=0;
    scanf("%d",&n);
    if(n%2==1) n--;

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(int i=0; i<3; i++)
    {
        sum+=n;
        n-=2;
        if(n<=0) i=3;
    }

    printf("%d", sum);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}