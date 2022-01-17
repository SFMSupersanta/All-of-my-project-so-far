#include<stdio.h>

int factorial(int num)
{
  for(int i = num - 1; i > 2; i--)
  {
    num*=i;
  }
  return num;
}

int permutation(long long set, long long quantity)
{
  long long answer;
  answer = factorial(set) / factorial(set - quantity);
  return answer;
}

int main()
{
	long long set = 49;
	long long quantity = 6;
	printf("%d\n", permutation(set, quantity));
}

