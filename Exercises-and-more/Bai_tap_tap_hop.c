#include<stdio.h>
#include<string.h>
#include<stdbool.h>


//\input stream clear function\*
void clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
//GetInt(char str[], long long min, long long max) returns long long from min to max
long long  GetInti(char msg[], long long  min, long long max, int i)
{
    long long value;
    int rc;

    while (true) 
    {
        printf("%s[%d] :", msg, i);
        //printf("in the range [%lld,%lld] : ",min, max);
        rc = scanf("%lld",&value);
        if(rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if(getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

//GetInt(char str[], long long min, long long max) returns long long from min to max
long long  GetInt(char msg[], long long  min, long long max)
{
    long long value;
    int rc;

    while (true) 
    {
        printf("%s", msg);
        printf("in the range [%lld,%lld] : ",min, max);
        rc = scanf("%lld",&value);
        if(rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if(getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

bool checkval(int a, int arr[])
{
    int i=0;
    while(arr[i] != '\0')
    {
        if(arr[i] == a)
        {
            return false;
            break;
        }
    }
    arr[i]=a;
    return true;
}

int hop(int Ar[], int Br[], int checkarr[],int A,int B)
{
    int count=0;
    for (int i = 0; i < Ar[0]; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if(Ar[i]==Br[j])
            {

            }
        }
    }
}

int main()
{
    int A,B;
    A=GetInt("Nhap so phan tu mang A(n): ",1,20);
    B=GetInt("Nhap so phan tu mang B(m): ",1,1000000);
    int Ar[A], Br[B];
    int checkar[A];
    for (int i; i<A; i++)
    {
        Ar[i]=GetInti("Nhap so A",0,1000000,i);
    }
    for (int i; i<B; i++)
    {
        Br[i]=GetInti("Nhap so B",0,1000000,i);
    }

}