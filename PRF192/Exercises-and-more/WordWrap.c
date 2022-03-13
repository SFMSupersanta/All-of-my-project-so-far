/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: wordwrap. same as workshop 10
version #
////////////////////////////////////////////////////////////////
Text editors wrap words to fit within a prescribed width, 
sometimes represented by a number of columns.  If a word at 
the end of a line does not fit within the prescribed number of 
columns, then that the text editor word starts the word on a 
newline.  A word is defined as a set non-whitespace characters.  
A word is separated from any other word by whitespace. 

Write a function with the header

 int wordWrap( char s[ ], int width ) 

that receives a string s[ ] and a number of columns width.  
This string may contain whitespace characters adjacent to 
one another.  wordWrap

changes s[ ] to a wrapped version that fits within width,
stores the wrapped version in s[ ] and
returns the number of lines that the wrapped version occupies. 
If any word in the original string exceeds the prescribed 
width, wordWrap breaks that word into parts.
For example, the statements

 char s[ ] = "My home is in Toronto    Ontario";
 int i;

 i =  wordWrap(s, 7);
 printf("%d\n%s\n", s);

display

 4
 My home
 is in
 Toronto
 Ontario
****************************************************************/
//This thing run as long as a word's length does not excees the line length
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
    char s[] = "aaaa aaa aaa a";
    
    int n = wordWrap(s, 7);
    
    printf("line required: %d\n%s",n,s);

    return 0;
}
