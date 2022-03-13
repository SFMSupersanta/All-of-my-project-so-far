#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 1 day, in ra phan tu la so chan va xuat hien nhieu lan (tu 2 do len)

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  
  //scan the amounnt of numbers
  int n ;
  scanf("%d", &n);
  //number array initialize
  int numbers[n];
  for (int i = 0; i < n; i++)
  {
	  scanf("%d", &numbers[i]);
  }

  
  //mask array initialize and excute odd numbers
  int mask[n];
  
  for (int i=0;i<n;i++)
  {
	  if(numbers[i]%2==0) mask[i] = 0;
	  else mask[i] = 1;
  }
  
  

  //caculations
  for(int i = 0; i < n; i++)
  {
	  if(mask[i]==0)
	  {
		  for(int j=i; j<n; j++)
		  {
			  if(numbers[i]==numbers[j])
			  {
				mask[i] ++;
				mask[j] = 1;
			  }
		  }
	  }
  }  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

  for(int i=0;i<n;i++)
  {
	  if(mask[i]>1) printf("%d ",numbers[i]);
  }
  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
