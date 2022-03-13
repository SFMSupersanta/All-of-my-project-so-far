/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string_val  1000

int compare_arr(char arr1[], char arr2[], int size)  //compairing strings
{
    for(int i = 0; i <size; i++)
    {
        if (arr1[i] != arr2[i]) return 1;
    } return 0;
}

int mygrep(char filename[],char searchstring[])      //find and print lines that contain search string
{
    FILE *fileP = NULL;
    fileP = fopen(filename, "r");
    int status = 1;
    if (fileP != NULL)
    {
        int searchsize = 0;
        while (searchstring[searchsize]!='\0') searchsize++; //since array decays into pointer, this is the only way
        int i =0;

        char data[max_string_val];
        do
        {
            data[i] = fgetc(fileP);
            i++;
        }while(!feof(fileP));           //while the program did not encounter the EOF value

        for(int j = 0; j < i-1; j++)    //i-1 because data[i]='EOF'
        {

            if (data[j] == searchstring[0])
            {
                //printf("data[j] = '%c'\n", data[j]);
                char foundarr[searchsize];
                for (int k = 0;k<searchsize;k++)
                {
                    foundarr[k] = data[j + k];
                }
                if (compare_arr(foundarr, searchstring,searchsize)==0)
                {
                    status=0;
                    int foundj = j;
                    while (data[foundj] != '\n'&& foundj != 0)
                    {
                        foundj--;
                    }
                    if (foundj == 0) printf ("%c",data[foundj]); //in the case of foundj =0 the first character will not be printed of not for this codeline
                    foundj++;//to skip the \n or the '0' value
                    while (data[foundj] != '\n' && data[foundj] != EOF) //while one of the two condition does not meat, the code will stop executing
                    {
                        printf("%c",data[foundj]);
                        foundj++;
                    }printf ("\n");
                }
            }
        }
    }
    else printf ("Error opening file %s\n", filename);
    return status;
}

int main()
{
    printf (" BTP100 grep\n ===========\n File name : ");
    char filename[max_string_val];
    scanf (" %[^\n]s",filename);            //scaning a ling will never be this hard
    printf (" Search string : ");
    char string[max_string_val];
    scanf (" %[^\n]s",string);              //this mean scaning a string until the \n value is found and then discard it  
    printf (" Lines that contain '%s'\n",string);
    if (mygrep (filename,string) == 1) printf(" Found no line that contains '%s'",string);
    return 0;
}

/*#######################
////////////////////////////////////////////////////////////////
Design and code a function that searches for the presence of a 
particular string within a file and displays each record that 
contains the search string.  It should also return a value of 
0 if the search string was found in one or more lines, and 1 of 
the search string was not found in the file at all.  This is 
similar to a simplified version of the "grep" command, working 
with a search string instead of a regular expression. 

The function prototype should look like this:

 int mygrep(char filename[], char searchstring[]);

Write a main program to test your function. 

For example, if a file named problems.txt contains

 Design and code a function that searches
 for the presence of a particular string
 within a file and displays each record
 that contains the search string.

then a function call mygrep("problems.txt", "string") 
would return the value 0 and display:

 BTP100 grep
 ===========
 File name : problems.txt
 Search string : string
 Lines that contain 'string'
 for the presence of a particular string
 that contains the search string.
****************************************************************/