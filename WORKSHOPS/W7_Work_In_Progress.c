/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXITEM  101                      //edit this statement to change the max item value

//Stuct defined for
struct item 
{
    long long barcode;
    double price;
    int quantity;
    double value;
};


 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

//Getint validator
long long getInt(char msg[], long long min, long long max) 
{
     char val[20];           //input value
     long long intval;
     int count,rc;      //int value and count value
     while(1)
     {
         printf("%s", msg);
         count = 0;
         rc = 0;
         fgets(val,20,stdin);

         if(val[0]!='\n')
         {
             if(0<=max&&0>=min) if(val[0]=='0' && val[1] == '\n') return 0;
             for(int i=0; i< 20; i++) 
             {
                 if(val[i]=='\n') 
                 {
                     rc = 1;
                     i=20;
                 }
             } 
             if(rc==0) 
             {

                 clear_buffer();
             }
             val[strcspn(val,"\n")] = '\0';
             
             if(val[count]=='0') 
             {

                 while(val[count]=='0')
                 {
                     count++;
                 }
             }             
             char *ovf;
             intval = strtoll(val,&ovf,10);
             
             if(intval<=0) count++;

             long long intvaldup = intval;
 
             while(intvaldup!=0)
             {
                 intvaldup/=10;
                 count++;
             }
             if (val[count] != '\0')  printf("**Trailing Character(s)**\n");
             else if(min<=intval&&intval<=max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }

//Getdouble validator
 double getDouble(char msg[], double min, double max) 
{
     double value, rc;
     int keeptrying = 1;
     char excess;

     do 
     {
         printf("%s ", msg);
         rc = scanf("%lf%c", &value, &excess);
         if (rc == 0) 
         {
             printf("**No input accepted!**\n\n");
             clear_buffer();
         } 
         else if (excess != '\n') 
         {
             printf("**Trailing characters!**\n\n"); 
             clear_buffer();
         } 
         else if (value < min || value > max) 
         {
             printf("**Out of range!**\n\n");
         } 
         else
             keeptrying = 0;
     } 
     while (keeptrying == 1);
     
     return value;
 }

//swap swap struct function
void swapstruct(struct item *a, struct item *b)
{
    struct item c= *a;
    *a=*b;
    *b=c;
}

//Struck sorting function
void structsort(struct item arr[], int size)
{
    int tracker;
    for(int i = 0; i < size; i++)
      {
          long long *jmin = &arr[i].barcode;
          for(int j = i+1; j < size; j++)
          {
              if(arr[j].barcode < *jmin) 
              {
                jmin = &arr[j].barcode;
                tracker = j;
              }
          }
          swapstruct(&arr[i], &arr[tracker]);
      }
}

int main()
{
    //program name
    printf(" Work in Progress Organizer\n");
    printf(" ==========================\n");  
    struct item packageArr[MAXITEM];
    long long tempISBN=1;
    int itemnum=0;
    double totalValue=0;   
    //Input section
    do
    {

        tempISBN=getInt(" Project     :  ",0,9999999999);
        if(tempISBN==0) continue;        //skip to the while part
        packageArr[itemnum].barcode = tempISBN;    
        //Get other data      
        packageArr[itemnum].price = getDouble(" Rate        : ",1,1000000000);
        packageArr[itemnum].quantity = getInt(" Hours Spent :  ",1,1000000000);
        packageArr[itemnum].value = packageArr[itemnum].price * packageArr[itemnum].quantity;
        totalValue += packageArr[itemnum].value;
        itemnum++;
    }
    while(tempISBN!=0);                 //the while part

    //sorting section 
    structsort(packageArr,itemnum);

    //printing section
    printf("            Work in Progess\n Project   Rate  Hours      Value\n --------------------------------\n");
    for(int i=0; i < itemnum; i++)
    {
        printf(" %lld%10.2lf%7d",packageArr[i].barcode,packageArr[i].price,packageArr[i].quantity);
        printf("%11.2lf\n",packageArr[i].value);
    }
    printf("                         --------\n Total Work in Progress");
    printf("%10.2lf",totalValue);
    return 0;
}



/*
##############################################
3289
120.00
35
1259
100.00
25
2231
93.50
75
0
##############################################
#    CTR+PASTE THE ABOVE LINES FOR INPUT     #
##############################################
#     EXAMPLE FOR SUCCESS CODE:              #
##############################################
 Work in Progress Organizer
 ==========================
 Project     :  3289
 Rate        :  120.00
 Hours Spent :  35
 Project     :  1259
 Rate        :  100.00
 Hours Spent :  25
 Project     :  2231
 Rate        :  93.50
 Hours Spent :  75
 Project     :  0

            Work in Progess
            ===============
 Project   Rate  Hours      Value 
 --------------------------------
 1259    100.00     25    2500.00
 2231     93.50     75    7012.50
 3289    120.00     35    4200.00
                         --------
 Total Work in Progress  13712.50
##############################################
*/