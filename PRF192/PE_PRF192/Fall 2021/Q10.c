#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Doi tu he co so 2 sang he co so 10

int demical(char str[])
{
	int result = 0;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		result += (str[i] - 48) * pow(2, strlen(str) - 1 - i);
	}
	return result;
}

int main()
{
	system("cls");
	// INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char s[1005];
	scanf("%s", s); // Nhap vao chuoi la he co so 2

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d", demical(s)); // In ra so o he co so 10

	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system("pause");
	return (0);
}
