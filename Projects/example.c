
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool pc(long long i)
{
    for (int j = 0; j < i/2; j++)
    {
        if(i%j==0)
        return false;
        break;
    } return true;
}

int main()
{
  long long n;
  printf("ENTER");
  scanf("%lld", &n);
  printf("Retulst: %d\n", pc(n));
  if(pc(n)==true) printf("Not Prime");
  else printf("Prime");
}