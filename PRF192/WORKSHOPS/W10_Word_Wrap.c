/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version #
////////////////////////////////////////////////////////////////
We use word-wrapping in text-editing programs and text-presentation programs such as web browsers.

Design and code a function that converts a null-terminated string into word-wrapped format of specified width.  The converted string, when displayed, fits into a field of the specified width.  Your word-wrap function receives a null-terminated string and the field width and returns the number of lines needed to display the wrapped string.  Your function also returns the wrapped string through the same parameter as the original string.  You may assume that

a word is a set of consecutive non-whitespace characters,
no word in the string is longer than the field width, and
any two consecutive words are separated by whitespace characters.
The function prototype should look like this:

 int wordwrap(char wrapstring[], int fieldwidth);

Write a main program to test your function.  Include strings with leading, trailing, multiple embedded whitespace and multiple-whitespace only in your set of test cases.

For example, consider the following string and a field width of 10

 This is week 13 of BTP100 

For this, your program should display:

 This is
 week 13 of
 BTP100

****************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordWrap(char arr[], int wrapline)
{
   int i = 0;
   int count = 0;
   int linecount = 1;
   while (i < (strlen(arr)))
   { 
      if (count == wrapline)
      {
         count = 0;
         if (arr[i] == ' ')
         { 
            while (arr[i+1] == ' ') i++;
            if (arr[i] != '\0') arr[i] = '\n';
            i++;
            linecount++;
         }
         else if (arr[i] != ' ')
         {

            while (arr[i] != ' ') 
            {
               i--;
            }
            if (arr[i] != '\0') arr[i] = '\n';
            i++;
            linecount++;
         }
      }
      count++;
      i++;
   }
   return linecount;
}

int main()
{
    char string[] = {"This is week 13 of BTP100 "};
    int with = 10;
    int lines = wordWrap(string, with);
    printf ("\n%s\n",string);
    printf ("\nNumber of lines required: %d\n", lines);
    return 0;
}


/*#######################
 ////////////////////////////////////////////////////////////////
We use word-wrapping in text-editing programs and 
text-presentation programs such as web browsers.

Design and code a function that converts a null-terminated 
string into word-wrapped format of specified width.  
The converted string, when displayed, fits into a field of 
the specified width.  Your word-wrap function receives a 
null-terminated string and the field width and returns the 
number of lines needed to display the wrapped string.  Your 
function also returns the wrapped string through the same 
parameter as the original string.  You may assume that

a word is a set of consecutive non-whitespace characters,
no word in the string is longer than the field width, and
any two consecutive words are separated by whitespace characters.
The function prototype should look like this:

 int wordwrap(char wrapstring[], int fieldwidth);

Write a main program to test your function.  Include strings 
with leading, trailing, multiple embedded whitespace and 
multiple-whitespace only in your set of test cases.

For example, consider the following string and a field width of 10

 This is week 13 of BTP100 

For this, your program should display:

 This is
 week 13 of
 BTP100

****************************************************************/
