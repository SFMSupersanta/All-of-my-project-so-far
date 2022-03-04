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

int pc(int i)
{
    for (int j = 2; j < i/2; j++)
    {
        if(i%j==0)
        {
        //printf("i: %d\n", i);
        return 0;
        break;
        }
    } return 1;
}




int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:



  int n;

  scanf("%d", &n);





  // OUTPUT for marking:
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:


  if(pc(n)==1) printf("Not Prime");
  else printf("Prime");



   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}