/****************************************************************
o(*￣▽￣*)ブ
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
    long long isbn;
    double price;
    int quantity;
    double value;
};

//isbn validator
bool isbnValidator(long long num)
{
    long long  check_digit = num % 10;
    num /= 10;
    long long weighted_sum = 0;
    long long total_sum;
    for (long long i = 2; i <= 10; i++) 
    {
        long long product = i * (num % 10);
        num /= 10;
        weighted_sum += product;
        //printf("%d\n", product);   for debugging only
    }
    total_sum = weighted_sum + check_digit;
    if (total_sum % 11 == 0) 
        return true;
    else
        return false;
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ( (c=getchar ()) != '\n'&&c!=EOF);
 }

//Getint validator
long long getInt (char msg[], long long min, long long max) 
{
     char val[20];           //input value
     long long intval;
     int count,rc;      //int value and count value
     while (1)
     {
         printf("%s", msg);
         count = 0;
         rc = 0;
         fgets(val,20,stdin);
         if(val[0]!='\n')
         {
             if(0 <= max && 0 >= min) if (val[0] == '0' && val[1] == '\n') return 0;
             for(int i=0; i< 20; i++) 
             {
                 if(val[i] == '\n') 
                 {
                     rc = 1;
                     i = 20;
                 }
             } 
             if(rc == 0) 
             {
                 clear_buffer();
             }
             val[strcspn (val,"\n")] = '\0';            
             if (val[count] == '0') 
             {

                 while(val[count] == '0')
                 {
                     count++;
                 }
             }             
             char *ovf;
             intval = strtoll (val,&ovf,10);         
             if (intval <= 0) count++;
             long long intvaldup = intval;
             while (intvaldup != 0)
             {
                 intvaldup /= 10;
                 count++;
             }
             if (val[count] != '\0')  printf ("**Trailing Character(s)**\n");
             else if (min <= intval && intval <= max)
             {
                 return intval;
             }else printf ("**OUT OF RANGE**\n");
         } else printf ("**No input**\n");
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
         printf ("%s ", msg);
         rc = scanf ("%lf%c", &value, &excess);
         if (rc == 0) 
         {
             printf ("**No input accepted!**\n\n");
             clear_buffer ();
         } 
         else if (excess != '\n') 
         {
             printf ("**Trailing characters!**\n\n"); 
             clear_buffer ();
         } 
         else if (value < min || value > max) 
         {
             printf ("**Out of range!**\n\n");
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
    struct item c = *a;
    *a = *b;
    *b = c;
}

//Struck sorting function
void structsort (struct item arr[], int size)
{
    int tracker;
    for( int i = 0; i < size; i++)
      {
          long long *jmin = &arr[i].isbn;
          for(int j = i+1; j < size; j++)
          {
              if(arr[j].isbn < *jmin) 
              {
                jmin = &arr[j].isbn;
                tracker = j;
              }
          }
          swapstruct (&arr[i], &arr[tracker]);
      }
}

int main()
{
    //program name
    printf (" Books in Stock Organizer\n");
    printf (" ========================\n");  
    struct item bookArr[MAXITEM];
    long long tempISBN = 1;
    int itemnum = 0;
    double totalValue = 0;   
    //Input section
    do
    {
        //check if isbn = 0
        do
        {
          tempISBN = getInt (" ISBN     :  ",0,9999999999);
          if (tempISBN == 0) break;
        } while(isbnValidator (tempISBN) != true);
        if (tempISBN == 0) continue;        //skip to the while part
        bookArr[itemnum].isbn = tempISBN;    
        //Get other data      
        bookArr[itemnum].price = getDouble(" Price    : ",1,1000000000);
        bookArr[itemnum].quantity = getInt(" Quantity :  ",1,1000000000);
        bookArr[itemnum].value = bookArr[itemnum].price * bookArr[itemnum].quantity;
        totalValue += bookArr[itemnum].value;
        itemnum++;
    }
    while (tempISBN != 0);                 //the while part

    //sorting section 
    structsort (bookArr,itemnum);

    //printing section
    printf ("            Books in Stock\n            ==============\n ISBN        Price   Quantity   Value \n --------------------------------------\n");
    for(int i = 0; i < itemnum; i++)
    {
        printf (" %010lld%7.2lf%11d",bookArr[i].isbn,bookArr[i].price,bookArr[i].quantity);
        printf ("%10.2lf\n",bookArr[i].value);
    }
    printf ("                                -------\n Total value books in stock");
    printf ("%12.2lf",totalValue);
    return 0;
}

/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
0619215216
49.95
5
0201533936
89.95
10
0534379648
69.95
15
0
###################
////////////////////////////////////////////////////////////////
Design and code a program that lists the books in stock for a 
local bookstore in ISBN order.  Your program prompts for and 
accepts

an ISBN,
a price and
a quantity in stock
for each title. 
Design your program according to structured design principles.  
Your program uses parallel arrays and includes functions to 
validate the input and to sort the items by ISBN.  You may 
assume that there are no more than 100 titles to process, but 
write your code so that you can change this limit by editing a 
single statement.

Preface each function header with a comprehensive description 
of the function purpose, the function parameters and the function 
return value.

The output from your program looks something like:

 Books in Stock Organizer
 ========================
 ISBN     :  0619215216
 Price    :  49.95
 Quantity :  5
 ISBN     :  0201533936
 Price    :  89.95
 Quantity :  10
 ISBN     :  0534379648
 Price    :  69.95
 Quantity :  15
 ISBN     :  0

            Books in Stock
            ==============
 ISBN        Price   Quantity   Value 
 --------------------------------------
 0201533936  89.95         10    899.50
 0534379648  69.95         15   1049.25
 0619215216  49.95          5    249.75
                                -------
 Total value books in stock     2198.50


****************************************************************/

