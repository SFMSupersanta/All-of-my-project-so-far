/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>

long long int factorial (long long int num)
{
  for(long long int i = num - 1; i > 1; i--)
  {
    num *= i;
  }
  return num;
}

long long int combination (long long set, long long quantity)
{
    long long lg_diff ;                 //larger difference

    if (set - quantity > quantity) lg_diff = set - quantity;     
    else if (set - quantity < quantity) lg_diff = quantity;

    long long upper=set;

    for (long long i = set-1; i > lg_diff; i--)
    {
        upper = upper * i;
    }

    if (set - quantity > quantity) return (upper / factorial(quantity));
    else return upper / factorial(set-quantity);
}

long long int permutation(long long set, long long quantity)
{
  long long answer=set;
  for(int i = set - 1; i > set - quantity; i--)
  {
    answer *= i;
  }
  return answer;
}

int main()
{
  printf ("Probability Caculator\n=====================\n");

  printf ("Quantity form wich to select:  ");
  long long set;
  scanf ("%lld", &set);

  printf ("Qantity to be selected:        ");
  long long quantity;
  scanf ("%lld", &quantity);

  printf ("Does order metter (y or n) ? : ");
  
  char order;
  getchar ();
  scanf ("%c", &order);

  if(order == 'y')

  {
      printf ("Number of possible outcome is %lld",permutation(set, quantity)) ;
  }
  
  else if(order == 'n')

  {
      printf ("Number of possible outcome is %lld",combination(set, quantity)) ;
  }
  
  return 0;
}
/***************************************************************
////////////////////////////////////////////////////////////////
Design and code a program that calculates the number of permutations or combinations of a set of items.  Your program prompts for and accepts the total number of items, the number of items in each group and whether the order of the items in a group matters. 

Design your program according to structured design principles and write a function that can readily be used in both calculations, as well as in other applications.  Do not use any library functions apart from <stdio.h> functions. 

Preface your function header with a comprehensive description of the function purpose, the function parameters and the function return value.

With permutations, the order of items within each group matters.  A group with the same items as another group but arranged in a different order is distinct from the other group.  With combinations, the order of the items within each group does not matter.  A group with the same items as another group but arranged in a different order is the same as the other group.

Consider a set of n items.  The number of permutations of the three digits 0,1 and 2 in two-digit groups is 6:

 01 02 12 20 21 10

The general formula for a permutation of n items in groups of k items is given by

 nPk = n! / ( n - k )!
where ! denotes factorial.  The formula for the factorial of n is given by
 n! = n * ( n - 1 ) * ( n - 2 ) * ... * 2 * 1
The number of combinations of the three digits 0,1 and 2 in two-digit groups is 3:

 01 02 12

The general formula for a combination of n items in groups of k items is given by

 nCk = n! / ( k! * ( n - k )! )
where ! denotes factorial. 
The output from your program should look something like: 

 Probability Calculator
 ======================
 Quantity from which to select:   49
 Quantity to be selected:         6
 Does order matter (y or n) ? :   n

 Number of possible outcomes is 13983816


****************************************************************/