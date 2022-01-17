#include <stdio.h>

double future(double principal,double rate,double year)
{
  //printf("\nprincipal: %f, rate: %f, year: %f\n",principal,rate,year); 
  double total = 1+rate;
  double temp = total;
   for(int i = 1; i < year; i ++)
   {
     total *= temp;
   }
   printf("total is %f\n",total);
  double value = total * principal;
   return value;
}

double present(double principal,double rate,double year)
{
  printf("\nprincipal: %f, rate: %f, year: %f\n",principal,rate,year);
  double total = 1+rate;
  double temp = total;
   for(int i = 1; i < year; i++)
   {
     total *= -temp;
   }
   //printf("total is %f\n",total);
  double value = (1/total) * principal;
   return value;
}
int main() 
{ 
  double p, r, y;


  printf("Investment Caculator\n=====================\n");
  printf("Principal : ");
  scanf("%lf", &p);

  printf("Annual Rate : ");
  scanf("%lf", &r);

  printf("No of Years : ");
  scanf("%lf", &y);

  printf("Future value (f) ot present value (p): ");
  char choice;
  
  getchar();
  scanf("%c", &choice);

  if (choice == 'f')
  {
      double money;
      money=future(p, r, y);
      printf("The present amounnt : $ %.2f\n", p);
      printf("The future value    : $ %.2f", money);
  }else if (choice == 'p')
  {
      double money;
      money = present(p, r, y);
      printf("The future amounnt : $ %.2f\n",p);
      printf("The present value  : $ %.2f", money);
  }

  
  return 0;
}
