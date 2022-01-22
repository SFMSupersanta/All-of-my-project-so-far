#include<iostream>
using std::cin;
using std::cout;
using std::endl;
void printar(int ar[],int size)
{
    for (int i=0;i<size;i++)
    {
        cout<<ar[i]<<'\t';
    }
    cout<<endl;
}
int main()
{
    cout<<"This is the experiment program that will take evey elements of entered array and print it into the console.\nNow, enter every elements of your array\n";
    cout<<"continue enter integer if you want to expand the array and enter anything that is not an interger to exit\n";
    int ar[100];
    int ar_size=0;
    for(int i=0;i<sizeof(ar)/sizeof(ar[1]);i++)
    {
        if(cin>>ar[i])
        {
            cout<<"entered.\n";
            ar_size++;
        }
        else
        {
            break;
        }
    }
    printar(ar,ar_size);
    
    return 0;
}