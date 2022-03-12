/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>

//Function to caculate future value
double future(double principal,double rate,double year)
{

    double total = 1 + rate;     
    double temp = total;

    for(int i = 1; i < year; i ++) total *= temp;

    double value = total * principal;

    return value;

}

//function to calculate present value?
double present(double principal,double rate,double year)
{

    printf("\nprincipal: %f, rate: %f, year: %f\n",principal,rate,year);
    double total = 1 + rate;
    double temp = total;

    for (int i = 1; i < year; i++) total *= temp;
    
    double value = (1/total) * principal;

    return value;

}
int main() 
{ 
  double p, r, y;

  printf ("Investment Caculator\n====================\n");
  printf ("Principal  : ");
  scanf ("%lf", &p);

  printf ("Annual Rate: ");
  scanf ("%lf", &r);

  printf ("No of Years: ");
  scanf ("%lf", &y);

  printf ("Future value (f) ot present value (p): ");
  char choice;
  
  getchar();
  scanf ("%c", &choice);

  if (choice == 'f')
  {

      double money;
      money=future(p, r, y);
      printf("\nThe present amounnt : $ %.2f\n", p);
      printf("The future value    : $ %.2f", money);
      
  }else if (choice == 'p')
  {

      double money;
      money = present (p, r, y);
      printf("\nThe future amounnt : $ %.2f\n",p);
      printf("The present value  : $ %.2f", money);

  }

  
  return 0;
}
/***************************************************************
////////////////////////////////////////////////////////////////
Design and code a program that performs two financial calculations: future value and present value.  Your program prompts for and accepts a principal amount, an interest rate, the number of periods and the type of calculation requested: future or present value. 

Design your program according to structured design principles and include a function that can be used in both calculations as well as in other applications.  Do not use any library functions apart from <stdio.h> functions. 

Preface your function header with a comprehensive description of the function purpose, the function parameters and the function return value.

The formula for future value is

 future value = principal * ( 1 + rate ) (number of periods)
The formula for present value is
 present value = principal * ( 1 + rate ) -(number of periods)
The output from your program should look something like:

 Investment Calculator
 =====================
 Principal  :  1000
 Annual Rate:  0.06
 No of Years:  5
 Future value (f) or present value (p): f

 The present amount : $  1000.00
 The future value   : $  1338.23

 Investment Calculator
 =====================
 Principal  :  1000
 Annual Rate:  0.06
 No of Years:  5
 Future value (f) or present value (p): p 

 The future amount  : $  1000.00
 The present value  : $   747.26 
****************************************************************/