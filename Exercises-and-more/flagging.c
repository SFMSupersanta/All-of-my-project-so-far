#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10


int main()
{
    int sku[SIZE] = {1,2,1,4,9,6,10,8,9,10};
    int unit[SIZE]= {10,3,6,3,7,12,54,12,7,5};
    bool flag[SIZE] = {0};
    int i,j,total,code;
    for (i=0;i<SIZE;i++)
    {

        if(flag[i]==false)
        {
            code = sku[i];
            total = 0;
            for(j=i;j<SIZE;j++)
            {
                if(sku[j]==code)
                {
                    total+=unit[j];
                    flag[j]=true;
                }
            }
            printf("Code: %d, Total: %d\n", code, total);
        }
    }

    return 0;
}