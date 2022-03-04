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
#include <stdbool.h>

bool dupecheck(int i, int dupearr[])
{
    int k=0;
    while(dupearr[k]!=NULL)
    {
        if(i==dupearr[k]) return false;
        k++;
    }
    dupearr[k]=i;
    return true;
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:


  int a[7];
  for (int i = 0; i < 7; i++)
  {
      scanf("%d", &a[i]);
  }
  int maxdig = NULL, maxdig2 = NULL, maxcnt=0, maxcnt2=0;
  int dupe[7];
  for (int i = 0; i < 7; i++)
  {
      dupe[i] = NULL;
  }
  

  for(int i = 0; i < 7; i++)
  {
      if(a[i] > 9)
      {
        if(dupecheck(a[i], dupe)==true)
        { 
            int cnt = 0;
            for (int j = i+1; j < 7; j++)
            {
                if(a[i]==a[j]) cnt++;
            }
            if(maxdig == NULL)
            {
                maxcnt = cnt;
                maxdig = a[i];
            }
            else if(maxdig2 == NULL)
            {
                if(cnt>maxcnt) 
                {
                    maxdig2=maxdig;
                    maxdig = a[i];
                    maxcnt2 = maxcnt;
                    maxcnt = cnt;
                }else
                {
                    maxdig2 = a[i];
                }
            }
            else if(cnt>maxcnt)
            {
                maxcnt2=maxcnt;
                maxcnt = cnt;
                maxdig2=maxdig;
                maxdig = a[i];
            }
            else if(cnt>maxcnt2)
            {
                maxdig2=a[i];
                maxcnt2=cnt;
            }
            else if(cnt==maxcnt)
            {
                maxdig2=maxdig;
                maxdig=a[i];
                maxcnt2=maxcnt;
            }
        }
      }
  }
  
  
   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:
   printf("%d,%d\n",maxdig,maxdig2);
  
    if(maxdig!= NULL&&maxdig2==NULL)
    {
        printf("%ld",maxdig);
    }
    else if(maxdig!= NULL&&maxdig2!=NULL)
    {
        printf("%ld  %ld", maxdig,maxdig2);
    }
    else printf("no two-digit number");



   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}