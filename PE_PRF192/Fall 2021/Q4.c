#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Ve hinh tam giac can rong co n canh

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int n,i,j;
  scanf("%d",&n);
  

  
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(j == n || i == n || i + j == n + 1) // Dieu kien de ve tam giac rong
			{
				printf("*");
			}
			else
				printf(" ");
		}
//		if(i < n)
			printf("\n");
	}
  
  
  
  
  
  






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
