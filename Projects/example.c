#include <stdio.h>
#include <math.h>
void simplyfy(int tu, int mau)
{
	int i,count,a,b;
	a=tu;b=mau;  
	int tg=mau;
	if (mau<0 && tu <0)
	{
		mau=abs(mau);
		tu=abs(tu);
	}
	if (mau>tu)
	{
		mau=a;
		tu=b;
	}
	for (i=1;i<=abs(mau);i++)
	{
		if (tu%i==0){
			count=i;
		}
	}
	mau=b/count;
	tu=a/count;
	if (a==0)
	{
		printf ("%d / %d = %d",tu,tg,tu);
	}
	else if (b==0)
	{
		printf("\nInvalid fraction");
	}
	else if (mau==1 || mau==-1)
	{
		printf("%d / %d = %d",a,b,a/b);
	}	
	else if (mau<0 && tu <0)
	{
		printf("%d / %d = %d / %d",a,b,abs(tu),abs(mau));
	}
	else
	printf("%d / %d = %d / %d",a,b,tu,mau);
}
int main ()
{
	int a,b;
	printf("Enter numerator: ");
	scanf("%d",&a);
	printf("Enter denominator: ");
	scanf("%d",&b);
	simplyfy( a, b);
	return 0;
}