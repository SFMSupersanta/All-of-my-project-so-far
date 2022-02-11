/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: PRF192
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  char l[100],s[100];
  gets(l);
  gets(s);
  int shorts=0;
  while(s[shorts]!='\0') {shorts++;}
  int index=0;
  while(l[index]!='\0')
  {
      if(l[index]==s[0])
      {
          int status=0;
          for(int i=0;i<shorts;i++)
          {
              if(l[index+i]!=s[i])
              status=1;
          }
          if(status==0)
          {
              for(int i=0;i<shorts;i++)
              {
                  l[index+i]=s[shorts-i-1];
              }
          }
      }
      index++;
  }
  


   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:

  printf("%s",l);




   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}