#include <conio.h>
#include <float.h>
#include <stdio.h>

int main( void )
{

  double principal=1000;              //
  double rate=0.06, year=5;
  double total = 1+rate;
  double temp = total;
   for(int i = 1; i < year; i++)
   {
     total *= temp;
   }
  printf("total is %.2f\n",total);
  double value = (1/total) * principal;
  printf("value is %.2f\n",value);
  return 0;
}
