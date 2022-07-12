/****************************************************************
(╯▔皿▔)╯)
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
Generate 20 case of 2 diffirent bi color
****************************************************************/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

char bigen(void)
{
    return "xdtv"[rand() % 4];
}

bool checkbuf(char buf1[], char buf2[], char bi1, char bi2, int count)
{

    for (int i = 0; i < count; i++)
    {
        int check1 = 1;
        int check2 = 1;
        if (buf1[i] == bi1)
            check1 = 0;
        if (buf2[i] == bi2)
            check2 = 0;
        if (check1 == 0 && check2 == 0)
            return false;
    }
    buf1[count] = bi1;
    buf2[count] = bi2;
    // printf("bi1=%c bi2=%c\n", bi1, bi2);
    return true;
}

void printbi(char bi1, char bi2)
{
    if (bi1 == 'x')
        printf("xanh\t");
    else if (bi1 == 'd')
        printf("do\t");
    else if (bi1 == 't')
        printf("tim\t");
    else if (bi1 == 'v')
        printf("vang\t");
    if (bi2 == 'x')
        printf("xanh\t");
    else if (bi2 == 'd')
        printf("do\t");
    else if (bi2 == 't')
        printf("tim\t");
    else if (bi2 == 'v')
        printf("vang\t");
    printf("\n");
}

int main()
{
    srand(time(NULL));
    char buf1[20], buf2[20];
    int count = 0;
    while (count < 16)
    {
        char bi1 = bigen(), bi2 = bigen();
        if (checkbuf(buf1, buf2, bi1, bi2, count) == true)
        {
            printbi(bi1, bi2);
            count++;
            // printf("%d\n",count);
        }
    }
    return 0;
}