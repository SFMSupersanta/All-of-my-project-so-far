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
    long long a;
    long long b=1;
    scanf("%ld", &a);
    for(long long i = 2; i <= a/2 ; i+=2)
    {
        b=b*i;
        //printf("b: %ld\n", b);
    }
    // OUTPUT for marking:
    printf("\nOUTPUT:\n");

    printf("%ld", b);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}