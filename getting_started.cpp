#include<iostream>
using namespace std;
int main()
{
    string greetings;
    cout<<"enter your greetings: ";
    cin>>greetings;
    cout<<"your greetings is: "<<greetings<<endl<<"therefore i would say: ";
    if(greetings=="hello?")
    {
        cout<<"have a nice day";
    }
    return 0;
}