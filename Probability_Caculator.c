
#include <stdio.h>

long long int factorial(long long int num)
{
  for(long long int i = num - 1; i > 1; i--)
  {
    num*=i;
  }
  return num;
}

long long int combination(long long set, long long quantity)
{
    long long lg_diff ;
    if (set - quantity > quantity) lg_diff = set - quantity;
    else if (set - quantity < quantity) lg_diff = quantity;
    long long upper=set;
    for (long long i = set-1; i > lg_diff; i--)
    {
        upper = upper*i;
    }//printf("%ld\n", upper);
    if (set - quantity > quantity) return upper/factorial(quantity);
    else return upper/factorial(set-quantity);
}

long long int permutation(long long set, long long quantity)
{
  long long answer=set;
  for(int i = set-1; i > set - quantity; i--)
  {
    answer*=i;
  }
  return answer;
}

int main( void )
{
  printf("Probability Caculator\n=====================\n");

  printf("Quantity form wich to select:  ");
  long long set;
  scanf("%lld", &set);

  printf("Qantity to be selected:        ");
  long long quantity;
  scanf("%lld", &quantity);

  printf("Does order metter (y or n) ? : ");
  
  char order;
  getchar();
  scanf("%c", &order);

  if(order == 'y')
  {
      printf("Number of possible outcome is %lld",permutation(set, quantity)) ;
  }else if(order == 'n')
  {
      printf("Number of possible outcome is %lld",combination(set, quantity)) ;
  }
  
  return 0;
}
