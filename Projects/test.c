/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


long long xfactorial(int x)
{
    long long result = 1;
    for(int i=2;i<=x;i++)
    {
        result *= i;
    }
    return result;
}


long long factorial(long long n) 
{

   if (n <= 1)
  
   return 1;
  
   else
  
   return (n * factorial(n-1));

}

int main()
{
  int k=1;
  while(k!=0)
  {
    printf("enter k: ");
    scanf("%d", &k);
    printf("Recurion: %d\n",factorial(k));
    printf("Normalfactorial: %d\n",xfactorial(k));
    
  }
  return 0;
}