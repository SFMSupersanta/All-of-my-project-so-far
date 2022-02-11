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



  int n,d;
  scanf("%d", &n);
  while(n>0)
  {
      d+=n%10;
      n/=10;
  }




   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:



  printf("%d",d);


   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}