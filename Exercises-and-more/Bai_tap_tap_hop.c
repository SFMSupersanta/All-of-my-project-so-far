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

bool checkdif(int arr[], int a, int b)
{
    for(int i = 0; i <b; i++) 
    {
        if(a==arr[i])
        {
            return false;
            break;
        }
    }
    return true;
}

int hamhop(int Ar[], int Br[],int hop[], int A,int B)
{
    int checkar[A];
    int count=0;

    for (int i = 0; i < A; i++)
    {
        //printf("i: %d\n", i);
        if(checkdif(Br,Ar[i],B)==true)
        {
            hop[count]=Ar[i];
            //printf("Ar[i]:%d\n",Ar[i]);
            count++;
        }
    }
    return count;
}

int main()
{
    
    
    int A,B;
    A=GetInt("Nhap so phan tu mang A(n): ",1,20);
    int Ar[A];
    int hop[A];
    for (int i; i<A; i++)
    {
        Ar[i]=GetInti("Nhap so A",0,1000000,i+1);
    }
    B=GetInt("Nhap so phan tu mang B(m): ",1,1000000);
    int Br[B];
    for (int i; i<B; i++)
    {
        Br[i]=GetInti("Nhap so B",0,1000000,i+1);
    }

    int so_hop = hamhop(Ar,Br,hop,A,B);
    printf("so_hop = %d\n",so_hop);

    printf("Ham tru cua A va B la:\n{");
    {
        for (int i = 0; i < so_hop; i++)
        {
            printf("%d", hop[i]);
            if((i-1)!=so_hop)printf(",");
        }
    }
    printf("}\n");
}

