#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Sap xep cac ki tu trong 1 chuoi

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  char a[105];
  scanf("%s",a); // Nhap 1 chuoi
  int i,j,n=strlen(a);
  for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] < a[j+1]) // Dieu kien de sap xep
			{
				char tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp; 
			}
		}
	} 
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  printf("%s",a); // In ra chuoi sau khi sap xep
  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
