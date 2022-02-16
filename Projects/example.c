#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int main()
{
  srand(time(NULL));
	int toss;
	printf("How many time do you wanna toss? :");
	scanf("%d", &toss);
	printf("toss: %d\n", toss);
	int hr=0, tr=0;

	for (int i = 0; i < toss; i++)
	{
		if (rand() % 2 == 1)
		{
			hr ++;
		}
		else tr ++;
	}
	printf("\nNumber of head result: %d\n", hr);
	printf("\nNumber of tail result: %d\n", tr);
	
	system("pause");
	return 0;
}