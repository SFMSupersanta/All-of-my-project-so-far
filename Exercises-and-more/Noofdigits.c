/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: No of digit
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer (void);

long long getInt(char msg[], long long min, long long max) ;

int noOfDigits(char arr[], char checkarr[]);

int main()
{
    char arr[100];
    char checkarr[100];
    long long arrnum = getInt("Enter the number: ",-9999999999,9999999999);
    long long checkarrnum = getInt("Enter the check number: ",-9999999999,9999999999);
    sprintf(arr, "%lld", arrnum);
    sprintf(checkarr, "%lld", checkarrnum);
    printf("arr: %s\ncheckarr: %s\n", arr, checkarr);
    printf("Number of appearance: %d", noOfDigits(arr, checkarr));
    return 0;
}

int noOfDigits(char arr[], char checkarr[])
{
    int width=0;
    int arrwidth = 0;
    int count=0;

    while(checkarr[width]!='\0') width++;
    while(arr[arrwidth]!='\0') arrwidth++;

    for(int i=0; i< arrwidth-width; i++)
    {
        if(arr[i]==checkarr[0])
        {
            if(width==1) count++;
            else
            {
                int rc = 0;
                for(int j=1; j < width; j++)
                { 
                    if (arr[i+j] != checkarr[j]) rc = 1;
                }
                if(rc==0) count++;
            }
        }
    }
    return count;
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

