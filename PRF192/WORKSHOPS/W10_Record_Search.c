/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version 2d array
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string_val  400


int compare_arr(char arr1[], char arr2[], int index)  //compairing strings
{
    for(int i = 0; i < strlen (arr2); i++)
    {
        if (arr1[index+i] != arr2[i]) return 1;
    } return 0;
}

int mygrep(char filename[],char searchstring[])     // find and print lines that contain search string
{
    FILE *fileP = NULL;                             // filer pointer
    fileP = fopen(filename, "r");                   // read the file
    int status = 1;                                 // return status
    if (fileP != NULL)
    {              
        int count = 0;                              // number of strings in the file
        char tempnuffer [max_string_val];           // temporary buffer
        char data[max_string_val][max_string_val];  // 2d data array
        // get string untill reach end of file and put it into data
        do
        {
            //get the string
            fgets (tempnuffer, sizeof (tempnuffer) / sizeof (tempnuffer[0]), fileP);
            tempnuffer[strcspn (tempnuffer, "\n")] = '\0';
            strcpy (data[count++], tempnuffer);      // cpy the string into data array
        } while (! feof (fileP));                    //stop if reached the end of file
        // for each string in data, find the searchstring in it and print the string in data if found
        for(int i = 0; i < count; i++)
        { 
            for(int j = 0; j < strlen(data[i]); j++)
            { 
                int Sstatus = 1;                     //break status
                if (data[i][j] == searchstring[0])   //found the shared first element of both string
                {    
                    if (compare_arr (data[i], searchstring, j) == 0) //check if that the string we need
                    {
                        printf ("%s\n", data[i]);
                        status = 0;                 // Set the return status
                        Sstatus = 0;                // Status to break the inner for loop
                    }
                }
                if (Sstatus == 0) j = strlen(data[i]); // break the inner for loop
            }
        }
    }      
    else printf ("Error opening file %s\n", filename);           // can't open the file for some reason
    return status;
}

int main()
{
    printf (" BTP100 grep\n ===========\n File name : ");
    char filename[max_string_val];
    scanf (" %[^\n]s",filename);            // scaning a ling will never be this hard
    printf (" Search string : ");
    char string[max_string_val];
    scanf (" %[^\n]s",string);      // scaning a string until the \n value is found and then discard it  
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