/****************************************************************
d=====(￣▽￣*)b
Referring code made by SFMSupersanta.
Program: validator
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

//even val
int getAnEvenInteger(char arr[],int min, int max)
{
    char val[20];           //input value
    int intval,count,rc;      //int value and count value
    while(1)
    {
        printf("%s", arr);
        count = 0;
        rc =0;
        fgets(val,20,stdin);
        if(val[0]!='\n')
        {
            if(0<max&&0>min) if(val[0]=='0' && val[1] == '\n') return 0;
            for(int i=0; i< 20; i++) 
            {
                if(val[i]=='\n') rc = 1;
            } 
            if(rc==0) clear_buffer();
            intval = atoi(val);

            //printf("%d\n", intval);

            if(intval<=0) count++;

            while(intval!=0)
            {
                intval/=10;
                count++;
            }

            //printf("%d\n", count);

            intval = atoi(val);
            if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
            else if(min<intval&&intval<max)
            {
                if(intval%2==0) return intval;
                else printf("**Not an even number**\n");
            }else printf("**OUT OF RANGE**\n");
        } else printf("**No input**\n");
    }
}

int main()
{
    int even = getAnEvenInteger("Enter the enven number : ",-1000,1000);
    printf("Even number accepted: %d\n",even);
    return 0;
}