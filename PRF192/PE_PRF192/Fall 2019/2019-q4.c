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

  long long n;
  scanf("%ld",&n);







   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:
  

  for (int i = 0; i < n; i++)
  {
      for(int j = 0; j <i; j++)
      {
          printf(" ");
      }
      for(int j = i; j <n; j++)
      {
          printf("*");
      }
      printf("\n");
  }



   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}