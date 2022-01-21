#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long long demic_conv(char barc_arr[])
{
  long long returnnum=0 ;
  for (int i = 0; i <= 9; i++)
  {
    returnnum *=10;
    returnnum += barc_arr[i]-'0'; 
    //printf("returnnum:%lld\n",returnnum);
  }
  return returnnum;
}

int main()
{

    char arr[12]="6300090801";
    long long i=demic_conv(arr);
    printf("i:%lld\n", i);
    return 0;
}