#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 1 chuoi ki tu, dem xem co bao nhieu ki tu la chu so, bao nhieu ki tu la chu, bao nhieu ki tu dac biet

int main()
{
	system("cls");
	// INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

	int chu = 0, so = 0, ki_tu_db = 0, i;
	char str[1000];
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]))
			so++;
		if (isalpha(str[i]))
			chu++;
		else
			ki_tu_db++;
	}

	// Fixed Do not edit anything here.
	printf("\nOUTPUT:\n");
	//@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d %d %d", so, chu, ki_tu_db);
	//--FIXED PART - DO NOT EDIT ANY THINGS HERE
	printf("\n");
	system("pause");
	return (0);
}
