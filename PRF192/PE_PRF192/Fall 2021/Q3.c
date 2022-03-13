#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Nhap vao n so, sap xep day vua nhap

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int n;
  scanf("%d",&n);
  int a[n],i,j;
  for(i=0; i<n; i++)
  	scanf("%d",&a[i]); // Nhap n so

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1]) // Dieu kien de thay doi vi tri (Sap xep)
			{
				int tmp = a[j]; 
				a[j] = a[j+1];
				a[j+1] = tmp; 
			}
		}
	}  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  

  for(i=0; i<n; i++)
  {
  	if(a[i]%2 == 0)
  		printf("%d ",a[i]); // In ra day sau khi sap xep
  }





  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
