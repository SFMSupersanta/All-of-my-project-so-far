/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>

long long prime_validator(long long num)
{
  if(num==1||num==2) return 0;
  else
  {
    for(int i=2; i <= num/2; i++)
    {
      if (num % i ==0) return 0;
    }
    return 1;
  }
}

void print_prime(long long low, long long high, long long col)
{
  printf("\n");
  long long col_track=1;
  for(int i = low; i <= high; i++)
  {
    if (prime_validator(i) == 1)
    {
      printf("%7d", i);
      col_track++;
      if (col_track%(col+1)==0) 
      {
        printf("\n");
        col_track=1;
      }   
    }
  }
}

int main( void )
{
  printf("Table of Primes\n===============\n");

  printf("Lower limit:   ");
  long long low;
  scanf("%lld", &low);

  printf("Upper limit:   ");
  long long high;
  scanf("%lld", &high);

  printf("# of columns:  ");
  long long int col;
  scanf("%lld", &col);

  print_prime(low,high,col);
  
  return 0;
}
