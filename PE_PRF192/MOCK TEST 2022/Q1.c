/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao 2 số float a va b
neu a nho hon b in ra :a<b  
neu a lon hon hoac bang b in:a>=b
****************************************************************/

#include <stdio.h>
 
int main()
{
    system("cls");
    //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    double a,b;
    scanf("%f %f",&a,&b);
    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    if(a<b) printf("a<b");
    else printf("a>=b");
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}