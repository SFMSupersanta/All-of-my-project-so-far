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


  double a[5],b;
  for(int i=0; i<5; i++)
  {
      scanf("%lf",&a[i]);
  }
 
  for(int j=0; j<5; j++)
  {
    for(int i=0; i<5; i++)
    {
        if(a[i]<a[i+1])
        {
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
        }
    }
  }





   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:


  for(int i=0; i<5; i++) 
  {
      printf("%f ", a[i]);
  }

   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}