#include<bits/stdc++.h>
using namespace std;
int sum(int i)
{
    int d=0;
    while (i!=0)
    {
        d+=i%10;
        i/=10;
    }
    return d;
}

int main()
{
    int n;
    cout<<"Nhap so: ";
    cin>>n;
    cout<<"tong cac chu so la:" <<sum(n);
    return 0;
}