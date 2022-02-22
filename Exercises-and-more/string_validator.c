/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: String validator
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

//syntax Cstringval(arr[],checkarr[]) checkarr always must not be a cap character
//As Cstringval compare arr to checkarr, arr can be capped and still return true.
int Cstringval(char arr[],char checkarr[])
{
    int cnt=0,arrcnt=0;
    while(checkarr[cnt]!='\0') cnt++;
    while(arr[arrcnt]!='\0') arrcnt++;
    if(arrcnt!=cnt) return 1;
    else 
    {
        for(int i=0;i<cnt;i++)
        {
            if((arr[i])>64&&(arr[i])<91)
            {
                if((arr[i]+32)!=checkarr[i]) return 1;
            }
            else if(checkarr[i]!=arr[i]) return 1;
        }
    }
    return 0;       //return 0 as true and 1 as false
}

int main()
{
    printf("result:%d\n",Cstringval("123AsF;","123asf;"));
    char a='a',A='A';
    if((a-32)==A) printf("YES\n");
    return 0;
}