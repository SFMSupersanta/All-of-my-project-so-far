#include<iostream>
#include<climits>
using namespace std;
void printmax(long long a)
{
    cout<<"maximum range of your datatype is: "<<a<<endl;
}
void printmin(long long a)
{
    cout<<"minimum range of your datatype is: "<<a<<endl;
}
int main()
{
    cout<<"note: this is an experiment program made by supersanta and it was still in a very early stage of development; further research and impliments will be added over a period of time.\n Thank you for using this program.";
    cout<<"In this program, each datatype will be called inline as: \n"<<"a for int;\nb for short;\nc for long;\nd for long long\ne for exit\n"
    <<"what datatype you want to check?\n";
    string t;
        cin>>t;
        int A;
        short B;
        long C;
        long long D;
        cout<<"choosen: "<<t<<endl;
        if(t=="a")
        {
            cout<<"size of bits of choosen datatype is: "<<sizeof(A)*8<<endl;
            printmax(INT_MAX);
            printmin(INT_MIN);
        }
        if(t=="b")
        {
            cout<<"size of bits of choosen datatype is: "<<sizeof(B)*8<<endl;
            printmax(SHRT_MAX);
            printmin(SHRT_MIN);
        }   
        if(t=="c")
        {
            cout<<"size of bits of choosen datatype is: "<<sizeof(C)*8<<endl;
            printmax(LONG_MAX);
            printmin(LONG_MIN);
        }
        if(t=="d")
        {
            cout<<"size of bits of choosen datatype is: "<<sizeof(D)*8<<endl;
            printmax(LLONG_MAX);
            printmin(LLONG_MIN);
        }
        else
        {
            cout<<"type the datatype you want";
        }      
    return 0;
}