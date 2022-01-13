#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={2,1,3,5,2,6,4,7,3,4,9};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    for (int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}