/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordwrap(char wrapstring[], int fieldwidth)
{
  fieldwidth --;
  int count = 0;
  int track = 0;
  int reqline = 1;
  while(wrapstring[track]!='\0')
  {
      int status = 1;
      //printf("%c", wrapstring[track]);
      if (count==fieldwidth&&wrapstring[track]==' '&&wrapstring[track-1]!=' '&&wrapstring[track+1]!= ' ')      //1st probability                  
      {
          reqline++;
          wrapstring[track] = '\n';
          track++;
          status = 0;
      }
      else if (count==fieldwidth&&wrapstring[track]!=' '&&wrapstring[track+1]!=' ')                            //2nd probability
      {
          reqline++;
          while(wrapstring[track-1]!=' ')
          {
              track--;
          }
          while(wrapstring[track-1]==' ')
          {
              track--;
          }
          printf("\ntrack:%d\n",track);
          wrapstring[track]='\n';
          track++;
          status= 0;
      }
      else if (count==fieldwidth&&wrapstring[track]!=' '&&wrapstring[track+1]==' ')                  //3rd probability
      {
          reqline++;
          while(wrapstring[track+1]== ' ')
          {
              track++;
          }
          wrapstring[track]='\n';
          track++;
          printf("\ntrack:%d\n",track);
      }
      else if (count==fieldwidth&&wrapstring[track]==' '&&wrapstring[track+1]==' '&&wrapstring[track-1]==' ')
      {
          reqline++;
          while (wrapstring[track+1]==' ')
          {
              track++;
          }
          wrapstring[track]='\n';
          track++;
          printf("\ntrack:%d\n",track);
      }
      printf("status:%d\n",status);
      printf("track(out):%d\n",track);
      printf("count:%d\n\n",count);
      if(status == 0) count=0;
      else count++;
      track++;
  }
  printf("\n%s\n",wrapstring);
  return reqline;
}

int main()
{
    char string[] ={"This is week 13 of BTP100 "};
    int with=10;
    int lines = wordwrap(string, with);
    printf("\nNumber of lines required: %d\n", lines);
    return 0;
}


/*#######################
###################
#TEST CASE(ctrc+v)#
###################
This is week 13 of BTP100 
###################
#   EXAMPLE:      #
###################
 This is
 week 13 of
 BTP100
#########################*/