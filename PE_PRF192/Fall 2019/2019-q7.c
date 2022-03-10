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

  int arr[7];
  for (int i = 0; i < 7; i++)
  {
  	scanf("%d", &arr[i]);
  }
  int mask[7] = {0};   

  //first mask eliminaton
  for (int i = 0; i < 7; i++)
  { 
  	if(arr[i]<10||arr[i]>99) mask [i] = -1;
  }    

  //second mask eliminaton and count
  for (int i = 0; i < 7; i++)
  { 
  	if(mask[i]==0)
  	{ 
  		mask[i] ++;
  		for (int j = i+1; j < 7; j++)
  		{ 
  			if(mask[j]==0)
  			{
  				if(arr[j]==arr[i]) 
  				{
  					mask[i] ++;
  					mask[j] = -1;
  				}
  			}
  		}
  	}
  }
	  
   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:
  
   int status=0;

   for(int i = 0; i < 7; i++)
   { 
   	 if(mask[i]>0)
        {
            printf("%d ", arr[i]);
            if(status == 0) status = 1;
        }
   }

   if(status == 0) printf("no two-digit number");
  
   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}

/*
1
3
5
7
12
12
12

1
3
5
7
9
1
2

10
10
1
2
3
12
12

*/