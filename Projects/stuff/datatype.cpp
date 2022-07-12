#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// note: int &n means that the variable n is passed to the function, not it's copy.
void input(int a[], int &n)
{
	printf("Enter number of elements n = ");
	scanf("%d", &n);
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

double factorial(double n)
{
	double s = 1;

	for (double i = 2; i <= n; ++i)
	{
		s *= i;
	}

	return s;
}

//----------------------------------------------------------------------
double fen(double x, int n)
{	// You should complete this function
	// Write your statements here
	// return bt(x, 0, c);
	// return(-1); //This statement must be changed
	double powNum = 0;
	double s = 0;

	while (fabs(pow(x, (2 * powNum + 1)) / factorial(2 * powNum + 1)) > n / 10000000)
	{
		if ((int)powNum % 2 == 0)
		{
			s += (pow(x, (2 * powNum + 1)) / factorial(2 * powNum + 1));
		}
		else
		{
			s -= (pow(x, (2 * powNum + 1)) / factorial(2 * powNum + 1));
		}

		++powNum;
	}

	return s;
}

int inc(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
	{
		return 1;
	}

	return -1;
}

int dec(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
	{
		return 1;
	}

	return -1;
}

int fun(int a[], int n)
{	// You should complete this function
	// Write your statements here

	if (n % 2 != 0)
	{
		qsort(a, n, sizeof(a[0]), dec);
	}
	else
	{
		qsort(a, n, sizeof(a[0]), inc);
	}

	return a[0];
}

int main()
{ // Do not edit this function
	system("cls");
	printf("\nTEST QUESTION (4 marks):\n");
	printf("1. Run TC 1 (fen) \n");
	printf("2. Run TC 2 (fun) \n");
	// tc holds the test case number of test
	int tc;
	printf("Enter TC (0 to exit): ");
	scanf("%d", &tc);
	if (tc == 0)
		return (0);
	//============================================================
	switch (tc)
	{
	case 1:
	{ // Start of TC 1
		double x, s;
		int n;
		printf("Enter x = ");
		scanf("%lf", &x);
		printf("Enter n = ");
		scanf("%d", &n);
		s = fen(x, n);
		printf("\n\nsin(%lf) = %.4lf\n\n", x, s);
		printf("\nOUTPUT:\n");
		printf("%.4f\n", s);
	}
	break; // end of TC 1

	case 2:
	{ // Start of TC 2
		int a[100];
		int n;
		input(a, n);
		n = fun(a, n);
		printf("\nOUTPUT:\n");
		printf("%d", n);
		printf("\n");
	};
	break; // The end of TC2
	}
	printf("\n\n");
	system("pause");
	return (0);
}
