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

long long even_sqr(long long a)
{
    if(a%2==0)
    {
        return a*a;
    }
    else return 0;
}


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  int n;
  scanf("%d", &n);
  long long b=0,a[10];
  for(int i=0; i<n; i++)
  {
      scanf("%ld",&a[i]);
  }
  for(int i=0; i<n; i++)
  {
      b+=even_sqr(a[i]);
  }





   // OUTPUT for marking:
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:


  printf("%ld",b);


   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
/*----------------------------------------------------------------
5
1
2
4
1
3

----------------------------------------------------------------*/
