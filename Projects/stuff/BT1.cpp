#include<bits/stdc++.h>
using namespace std;
int sum(int a)
{ 
    int d=0;
    for(int i=0;i<2;i++)
    {
        d+=a%10;
        a/=10; 
    }
    return d;
}
int t(int a)
{
    int c=0;
    while (a>100)
    {
        a/=10;
    }
    while(a!=0)
    {
        c+=a%10;
        a/=10;
    }
    return c;
}

int main()
{
    int n;
    cout<<"Nhap so:";
    cin>>n;
    cout<<"Tong 2 so cuoi: "<<sum(n)<<endl<<"Tong 2 so dau: " << t(n)<<endl;
return 0;
}
