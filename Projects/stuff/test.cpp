#include<iostream>
using namespace std;
bool testf(int n)
{
    cout<<"typed number:"<<n<<endl;
    int a=0;
    for (int i = 2; i < n/2; i++)
    {
        if(n%i==0) a++; 
        if(a!=0) break;
    }
    if (a==0) return true;
    else return false;
}
int main()
{
    int n;
    cout<<"type your number: ";
    cin>>n;
    cout<<testf(n);
    return 0;
}