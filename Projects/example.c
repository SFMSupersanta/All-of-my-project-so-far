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

double giaiThua(int n)
{    
    double tich=1;
    for (int i=1;i<=n;i++){
		tich*=i;
	}
	return tich;
}

//----------------------------------------------------------------------
double fen(double x, double c) { // You should complete this function
  // Write your statements here
  //return bt(x, 0, c);
  // return(-1); //This statement must be changed 

	double sin = x; int p = 1; double k;
	
	do{
		k = ( pow(x, (p * 2) + 1)) / giaiThua( (p * 2) + 1);
		if (p % 2 == 0) sin += k;
		else sin -= k;
		p++;
	} while (abs(k) > c);
	
	return sin;
	
 }
 
 void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void fun(int a[], int n) { // You should complete this function
  // Write your statements here
	int i, j, min_idx;
	
	if (n%2 != 0){
		// One by one move boundary of unsorted subarray
    	for (i = 0; i < n-1; i++)
    	{
        	// Find the minimum element in unsorted array
        	min_idx = i;
        	for (j = i+1; j < n; j++)
          	if (a[j] < a[min_idx])
            	min_idx = j;
  
        	// Swap the found minimum element with the first element
        	swap(&a[min_idx], &a[i]);
    	}
	}else{
		for (i = 0; i < n-1; i++)
    	{
        	// Find the minimum element in unsorted array
        	min_idx = i;
        	for (j = i+1; j < n; j++)
          	if (a[j] > a[min_idx])
            	min_idx = j;
  
        	// Swap the found minimum element with the first element
        	swap(&a[min_idx], &a[i]);
    	}
	}
 }

void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
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
         double x, epsi, s;
         printf("Enter x = "); scanf("%lf",&x);
         printf("Enter epsi = "); scanf("%lf",&epsi);
         s = fen(x,epsi);
         printf("sin(%.1f) = %.4f\n",x,s);
         printf("\nOUTPUT:\n");
         printf("%.4f\n",s); 

        }  break; // end of TC 1       

    case 2: { // Start of TC 2
         int a[100]; int n;
         input(a,n);
         printf("\nThe original array:\n"); 
         display(a,n);
         fun(a,n);
         printf("\nThe array after processing:\n"); 
         display(a,n);

         printf("\nOUTPUT:\n");
         display(a,n);
         printf("\n");
        
        };  break; // The end of TC2     
    }
  printf("\n\n");
 // while(getchar()!='\n');
//  getchar();
  system ("pause");
  return(0);
}
