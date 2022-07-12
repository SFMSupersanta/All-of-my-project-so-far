#include <stdio.h>

long long int factorial(long long int num)
{
  for (long long int i = num - 1; i > 1; i--)
  {
    num *= i;
  }
  return num;
}

long long int combination(long long set, long long quantity)
{
  long long lg_diff;
  if (set - quantity > quantity)
    lg_diff = set - quantity;
  else if (set - quantity < quantity)
    lg_diff = quantity;
  long long upper = set;
  for (long long i = set - 1; i > lg_diff; i--)
  {
    upper = upper * i;
  } // printf("%ld\n", upper);
  if (set - quantity > quantity)
    return upper / factorial(quantity);
  else
    return upper / factorial(set - quantity);
}

long long int permutation(long long set, long long quantity)
{
  long long answer = set;
  for (int i = set - 1; i > set - quantity; i--)
  {
    answer *= i;
  }

  return answer;
}

int main()
{
  long long int fact = combination(49, 6);
  printf("factorial: %ld\n", fact);
  return 0;
}
