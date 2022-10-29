/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao so int n
in ra tong ba so chan cuoi cung tu 0 den n
****************************************************************/
#include <stdio.h>
int tong_chan_cuoi(int n)
{
    if (n % 2 == 1)
        n--;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += n;
        n -= 2;
        if (n <= 0)
            i = 3;
    }
    return sum;
}
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    int n;
    scanf("%d", &n);

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    printf("%d", tong_chan_cuoi(n));

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return 0;
}