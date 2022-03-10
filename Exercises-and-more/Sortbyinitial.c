/****************************************************************
╰（‵□′）╯ 
Referring code made by SFMSupersanta.
Program: Dunno
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swaparr(char arr1[], char arr2[])
{ 
    char arr3[80];
    strcpy(arr3,arr1);
    strcpy(arr1,arr2);
    strcpy(arr2,arr3);
}

void sortinitial(char arr[][80], int size)
{
    int *pM;
    int tracker;
    char ctracker;
    for(int i=0; i<size; i++)
    { 
        pM = &arr[i][0];
        for(int j=i+1; j<size; j++)
        { 
            if(arr[j][0] < *pM) 
            {
                pM = &arr[j][0];
                tracker = j;
            }
        }
        swaparr(arr[tracker],arr[i]);
    }
    ctracker = arr[0][0];
    /*
    for(int i; i<size; i++)
    {
        if(ctracker!=arr[i][0])
        { 

        }
    }*/
}

int main()
{ 
    char strf[255];
    printf("Enter the file name: ");
    fgets(strf,255,stdin);
    strf[strcspn(strf,"\n")] = '\0';
    FILE* fi = NULL;
    fi = fopen(strf, "r");
    if(fi != NULL)
    {
        char str[500][80];
        int count = 0;
        do
        {
            fgets(str[count],80,fi);
            str[count][strcspn(str[count],"\n")] = '\0';
        }while()
    }else printf("FAILED TO OPEN FILE!!!\n");
    return 0;
}