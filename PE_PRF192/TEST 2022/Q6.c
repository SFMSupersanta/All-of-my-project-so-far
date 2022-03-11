/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
nguoi dung nhap vao 5 ten
sap xep va in ra ten cua tung nguoi tren 1 dong
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    system("cls");
    //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

    char input[5][255];
    for(int i=0; i<5; i++)
    {
        fgets(input[i], 255, stdin);
        input[i][strcspn(input[i],"\n")] = '\0';
    }
    
    int index;
    char maxchar;
    char temp[255];

    for(int i=0; i<5; i++)
    { 
        maxchar = input[i][0];
        index = i;
        for(int j=i+1; j<5; j++)
        { 
            if(input[j][0] < maxchar)
            { 
                maxchar = input[j][0];
                index = j;
            }
        }
        strcpy(temp,input[index]);
        strcpy(input[index],input[i]);
        strcpy(input[i],temp);
    }

    // OUTPUT for marking:
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    for(int i=0; i<5; i++)
    {
        printf("%s ",input[i]);
    }



    
    

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system ("pause");
    return 0;
}

/*
John
Joe
Due
Long
Ming

*/
