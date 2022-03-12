/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>

long long prime_validator (long long num)
{
  if (num==1||num==2) return 0;
  else
  {
    for (int i=2; i <= num/2; i++)
    {
      if (num % i ==0) return 0;
    }
    return 1;
  }
}

void print_prime (long long low, long long high, long long col)
{
  printf ("\n");
  long long col_track=1;
  for (int i = low; i <= high; i++)
  {
    if (prime_validator(i) == 1)
    {
      printf("%7d", i);
      col_track++;
      if (col_track % (col+1) == 0) 
      {
        printf("\n");
        col_track = 1;
      }   
    }
  }
}

int main( void )
{
  printf ("Table of Primes\n===============\n");

  printf ("Lower limit:   ");
  long long low;
  scanf("%lld", &low);

  printf ("Upper limit:   ");
  long long high;
  scanf("%lld", &high);

  printf ("# of columns:  ");
  long long int col;
  scanf ("%lld", &col);

  print_prime (low,high,col);
  
  return 0;
}
/***************************************************************
////////////////////////////////////////////////////////////////
Design and code a program that displays a table of prime numbers within a specified range and in columnar form.  Your program prompts for and accepts the number of primes to be displayed, the low and high value of the range of integers to be considered and the number of primes to be displayed in any single row. 

Design your program according to structured design principles and include a function that can readily be used in other applications.  Do not use any library functions apart from <stdio.h> functions. 

Preface your function header with a comprehensive description of the function purpose, the function parameters and the function return value.

A prime number is a whole number that is divisible by 1 and itself only.  1 is not considered a prime number. 

The output from your program should look something like: 

 Table of Primes
 ===============
 Lower limit:  0
 Upper limit:  175
 # of columns: 5

      2      3      5      7     11
     13     17     19     23     29
     31     37     41     43     47
     53     59     61     67     71
     73     79     83     89     97
    101    103    107    109    113
    127    131    137    139    149
    151    157    163    167    173 

Search the Internet for a list of prime numbers to confirm the results of your program. 
****************************************************************/