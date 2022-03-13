/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: Binary array
version #
////////////////////////////////////////////////////////////////
Design and code a function named binary with the header

 int binary(int number, int b[ ], int size)

that stores in b[ ] the binary representation of number.  Your function handles positive and negative numbers and uses two's complement notation to represent a negative number.  size is the maximum number of elements in b[ ].  Your function returns 0 if successful, 1 if unsuccessful. 

For example, the statements

 int b[32] = {0};
 int i;

 i = binary( 1025, b, 32 );
 printf("%d ", i);
 for ( k = 0; k < 32; k++ )
     printf("%1d", b[k]);
 printf("\n");

display

 0 00000000000000000000010000000001

while the statements

 int b[32] = {0};
 int i;

 i = binary( -1025, b, 32 );
 printf("%d ", i);
 for ( k = 0; k < 32; k++ )
     printf("%1d", b[k]);
 printf("\n");

display

 0 11111111111111111111101111111111

The statements

 int b[32] = {0};
 int i;

 i = binary( 0, b, -10 );
 printf("%d ", i);
 printf("\n");

display

 1 
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clear_buffer (void);

long long getInt(char msg[], long long min, long long max) ;

int binary(int number, bool b[ ], int size);

void two_complement(bool arr[],int size);

int main()
{ 
    long long num = getInt("Type the converting number: ",-9999999999,9999999999);
    long long size = getInt("Size of array: ",-9999999999,9999999999);
    bool arr[size];
    for (int i = 0; i < size; i++) arr[i] = 0;
    int d;
    printf("%d ",d=binary(num,arr,size));
    if(d!=1)
    {
        for (int i = size-1; i >=0 ; i--)
        {
            printf("%d",arr[i]);
        }
    }
    printf("\n");
    return 0;
}

int binary(int number, bool b[ ], int size)
{
    if(number ==0 || size<=0) return 1;
    bool sign = false;
    if(number < 0) sign = true;
    int count = 0;
    while(number!=0)
    {
        b[count++] = number%2;
        number/=2;
    }
    if(sign == true) two_complement(b,size);
    return 0;
}

void two_complement(bool arr[],int size)
{
    for(int i=size-1; i>=0; i--)
    {
        arr[i] = ! arr[i];
        //printf("%d",arr[i]);
    }
    //printf("\n");
    bool carry=true;
    int count = 0;
    while (carry != false)
    {
        arr[count] = (arr[count]+1)%2;
        if(arr[count]==true) carry = false;
        count++; 
    }
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

 long long getInt(char msg[], long long min, long long max) 
{
     char val[20];           //input value
     long long intval;
     int count,rc;      //int value and count value
     while(1)
     {
         printf("%s", msg);
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
             char *ovf;

             intval = strtoll(val,&ovf,10);
             
 
             if(intval<=0) count++;

             long long intvaldup = intval;
 
             while(intvaldup!=0)
             {
                 intvaldup/=10;
                 count++;
             }

             if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
             else if(min<intval&&intval<max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }