#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Doi tu he co so 2 sang he co so 10

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char s[1005];
	scanf("%s",s); // Nhap vao chuoi la he co so 2
	int i,l=strlen(s),res = 0,cnt=0;
	for(i=l-1; i>=0; i--)
	{
		if(s[i]!='0')
		{
			res += pow(2,cnt); // Luu 1 bien khi chuyen ve co so 10
			cnt++;
		}
	}
  
  
  
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d",res); // In ra so o he co so 10










  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
