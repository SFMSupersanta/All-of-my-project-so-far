#include<iostream>
using namespace std;
int main()
{
    string greetings;
    cout<<"enter your greetings: ";
    cin>>greetings;
    cout<<"your greetings is: "<<greetings<<endl<<"therefore i would say: ";
    if(greetings=="hello")
    {
        cout<<"have a nice day";
    }
    else
    {
        cout<<"Your words are beyond this super highly intelligent AI's ability. I have nothing so say other than \"hava a nice day\"";
    }
    return 0;
}