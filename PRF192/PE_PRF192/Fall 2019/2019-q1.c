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
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n;
    scanf("%d", &n);
    int product = 1;
    for (int i = 2; i <= n / 2; i++)
        if (i % 2 == 0)
            product = i * product;
    if (n < 4)
        product = 0;
    // OUTPUT for marking:;
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    printf("%d", product);
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return 0;
}