/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
////////////////////////////////////////////////////////////////
From the c learning website: 
You have received a file named text.dat containing a set of client records.  Each client record is delimited by a newline character and consists of two initials in its first 2 character positions and the full client name in the remaining positions.

Write a complete program that

reads all records on the file and
displays the client names in alphabetic order based on the initials in the first 2 character positions of a record: use the 2nd initial for your primary sort and the 1st initial for your secondary sort.
You may assume that
there are no more than 500 records on the file,
each record contains no more than 80 characters excluding the newline delimiter,
there are no errors in reading the file records, and
all initials are in uppercase.
For example, if the file records look like

 AB	Albert Bumble
 FG	Fred Goofoff
 GF	Gary Flintstone
 DD	Donald Duck

the output of your program looks something like

 AB	Albert Bumble
 DD	Donald Duck
 GF	Gary Flintstone
 FG	Fred Goofoff

****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swaparr(char arr1[], char arr2[])
{ 
    char arr3[255];
    strcpy(arr3,arr1);
    strcpy(arr1,arr2);
    strcpy(arr2,arr3);
}

void sortinitial(char input[][255], int size)
{
    int index;
    for(int i=0; i<size; i++)
    { 
        index = i;
        for(int j=i+1; j<size; j++)
        { 
            if(strcmp(input[index], input[j])>0)
            { 
                index = j;
            }
        }
    swaparr(input[index],input[i]);
    }
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
        char str[500][255];
        int count = 0;

        do
        {
            fgets(str[count],80,fi);
            str[count][strcspn(str[count],"\n")] = '\0';
            count++;
        }while(!feof(fi));

        
        sortinitial(str,count+1);

        for(int i = 0; i<=count; i++)
        {
            printf("%s\n",str[i]);
        }


        fclose(fi);
    }else printf("FAILED TO OPEN FILE!!!\n");
    
    return 0;
}