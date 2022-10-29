/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao string co so cac chu so la so le tu 5 den 20
in ra 5 chu o giua
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    char input[21];
    fgets(input, 21, stdin);
    input[strcspn(input, "\n")] = '\0';

    int n = strlen(input);

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    // abcdefg
    // abcdefghikl
    for (int i = (n - 5) / 2; i < ((n - 5) / 2) + 5; i++)
    {
        printf("%c", input[i]);
    }

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return 0;
}

/*
1hello7

*/
