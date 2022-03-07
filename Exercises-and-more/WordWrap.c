/****************************************************************
( ˘︹˘ ))
Referring code made by SFMSupersanta.
Program: wordwrap. same as workshop 10
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordWrap(char arr[], int wrapline)
{
   int i = 0;
   int count = 0;
   while(i < (strlen(arr)))
   { 
      if(count == wrapline)
      {
         count=0;
         if(arr[i]==' ')
         { 
            while(arr[i+1]==' ') 
            {
               i++;
               if(arr[i]=='\0')break;
            }
            if(arr[i]!='\0') arr[i] = '\n';
            i++;
         }
         else if (arr[i]!=' ')
         {
            while(arr[i]!=' ') i--;
            if(arr[i]!='\0') arr[i] = '\n';
         }
      }
      printf("count:%d\ni:%d\n", count, i);
      count++;
      i++;
   }
   

}

int main()
{
    char s[ ] = "My home is in Toronto    Ontario";
    
    wordWrap(s, 7);
    
    for(int i = 0; i <strlen(s); i++) printf("%c", s[i]);


    return 0;
}

