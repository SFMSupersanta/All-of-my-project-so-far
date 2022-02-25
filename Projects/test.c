/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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
         //printf("%s\n", val);
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
             
 
             printf("intval: %lld\n", intval);
 
             if(intval<=0) count++;
 
             while(intval!=0)
             {
                 intval/=10;
                 count++;
             }
 
             printf("%d\n", count);
 
             intval = strtoll(val,&ovf,10);

             if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
             else if(min<intval&&intval<max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }

int main()
{
  //printf("%lld \n", getInt("number:",-9999999999999,9999999999999));
  bool a = true ;
  a = !a;
  bool b = (true)%2 ;
  int d = 1/2;
  int c = a+b;
  printf("%d\n",a);
  return 0;
}