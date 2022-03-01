#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
//note: int &n means that the variable n is passed to the function, not it's copy.
void input(int a[], int &n) { 
    printf("Enter number of elements n = ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++)
      {printf("a[%d] = ",i);
        scanf("%d",&a[i]);
      }
   }

void display(int a[], int n) { 
    for(int i=0;i<n;i++) printf("%d ",a[i]);
     printf("\n"); 
   }
double firstNume(int num)
{
  double value;
  if (num%2==0) value =1; else value =-1;
  return value;
}


long long firstDeno(int num)
{
  long long value=1;
  int factor=2*num+1;
  for (int i=2; i <=factor; i++)
  {
    value *= i;
  }
  return value;
}
//----------------------------------------------------------------------
double fen(double x, int n) { // You should complete this function
  // Write your statements here
  double value=x;
  double Nume1,Nume2,tempVal;
  long long Deno1;
  for (int i=1; i<=n; i++)
  {
    Nume1= firstNume(i);
    Nume2= pow(x,(i*2)+1);
    Deno1= firstDeno(i);
    printf("num2: %lf, deno: %lld\n",Nume2,Deno1);
    tempVal= Nume1*(Nume2/Deno1);
    printf("temp: %lf\n",tempVal);
    if(abs(tempVal)<0.000000000001)
    {
      i=n+1;
    }
    value +=tempVal;
  } 
  //return bt(x, 0, c);
  // return(-1); //This statement must be changed 

  return value;
 }

int fun(int a[], int n) { // You should complete this function
  // Write your statements here
int i,j,value;
  if (n%2 != 0)
  {
    for (i = 0; i < n-1; i++)        
        for (j = 0; j < n-i-1; j++) 
        if (a[j] > a[j+1])
          {
            int temp = a[j];
            a[j]= a[j+1];
            a[j+1] = temp;
          }
    value = a[n-1];    
  }
  else 
  {
     for (i = 0; i < n-1; i++)        
        for (j = 0; j < n-i-1; j++) 
        if (a[j] < a[j+1])
          {
            int temp = a[j];
            a[j]= a[j+1];
            a[j+1] = temp;
          }
    value = a[n-1];
  }
  return value;
 }


int main() {  // Do not edit this function
  system("cls");
  printf("\nTEST QUESTION (4 marks):\n");
  printf("1. Run TC 1 (fen) \n");
  printf("2. Run TC 2 (fun) \n");
  //tc holds the test case number of test
  int tc;
  printf("Enter TC (0 to exit): "); scanf("%d",&tc);
  if(tc==0) return(0);
  //============================================================
  switch(tc) {
    case 1: { // Start of TC 1
         double x, s;
         int n;
         printf("Enter x = "); scanf("%lf",&x);
         printf("Enter n = "); scanf("%d",&n);
         s = fen(x,n);
         printf("\n\nsin(%lf) = %.4lf\n\n", x, s);
         printf("\nOUTPUT:\n");
         printf("%.4f\n",s); 

        }  break; // end of TC 1       

    case 2: { // Start of TC 2
         int a[100]; int n;
         input(a,n);
         n = fun(a, n);
         printf("\nOUTPUT:\n");
         printf("%d",n);
         printf("\n");
        
        };  break; // The end of TC2     
    }
  printf("\n\n");
  system ("pause");
  return(0);
}
