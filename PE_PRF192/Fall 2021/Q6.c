#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 1 chuoi ki tu, dem xem co bao nhieu ki tu la chu so, bao nhieu ki tu la chu, bao nhieu ki tu dac biet

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char s[1000];
	gets(s); // Nhap vao 1 chuoi
	int l = strlen(s),i;
	int dem1=0,dem2=0,dem3=0;  
	for(i=0; i<l; i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
			dem2++; // Dem so ki tu la chu so
		else
			if('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z')
				dem1++; // Dem so ki tu la chu
			else
				dem3++; // Dem so ki tu dac biet
	}
  
//UEFA Europa @2021
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  
printf("%d\n%d\n%d",dem1,dem2,dem3); // In ra so luong






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
