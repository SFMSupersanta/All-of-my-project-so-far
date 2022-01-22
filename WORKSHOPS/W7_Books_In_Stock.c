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

bool  numcheck(long long num)
{
    long long  check_digit = num % 10;
    num /= 10;
    long long weighted_sum = 0;
    long long total_sum;
    for(long long i = 2; i <= 10; i++) 
    {
        long long product = i * (num % 10);
        num /= 10;
        weighted_sum += product;
        //printf("%d\n", product);   for debugging only
    }
    total_sum = weighted_sum + check_digit;
    if(total_sum % 11 == 0) 
        return true;
    else
        return false;
}

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

bool barc_val(char barc_arr[])
{
    //check if the first 10 value is a Number
    for (int i=0;i<10;i++)
    {
      if (barc_arr[i]!='0'&&barc_arr[i]!='1'&&
          barc_arr[i]!='2'&&barc_arr[i]!='3'&&
          barc_arr[i]!='4'&&barc_arr[i]!='5'&&
          barc_arr[i]!='6'&&barc_arr[i]!='7'&&
          barc_arr[i]!='8'&&barc_arr[i]!='9')
          return false;
    }
    //check if the user tped a string more than 10
    if (barc_arr[10]!='\0') return false;
    else return true;
}


int main()
{
  //program name
  printf("Books in Stock Organizer\n");
  printf("========================\n");  
  int max_items = 101;                      //edit this statement to change the max item value
  char total_barc [max_items][11];
  double total_price [max_items];
  long long quantity[max_items];
  double value[max_items];

  int total_cnt = 0;
  //input code
  bool status = true;
  while (true)
  {
    //barcode array input
    while (true)
    {
      //scan and check for ISBN loop
      while (true)
      {
        char barc_arr[11];
        printf("ISBN     :  ");
        barc_arr[10]='\0';
        barc_arr[2]='\0';
        scanf(" %[^\n]",&barc_arr);
        if (barc_arr[0]=='0'&&barc_arr[1]=='\0')
        {
          status=false;
          break;
        }
        if (barc_val(barc_arr)==true&&numcheck(demic_conv(barc_arr)==true)) 
        {
          for (int i = 0; i <10;i++) 
          {
            total_barc[total_cnt][i]= barc_arr[i];
          }
          break;
          //total_cnt++;
        }
        else 
        {
            printf("INVALID INPUT\n");
            continue;
        }
      }
      if(status == false) break;   //first break out of second loop
      //Price scan
      printf("Price    :  ");
      scanf("%lf",&total_price[total_cnt]);
      //quantity scan
      printf("Quantity :  ");
      scanf("%lld",&quantity[total_cnt]);
      //total value caculations
      value[total_cnt]=total_price[total_cnt]*quantity[total_cnt];
      total_cnt++;
    } 
    if (status==false) break;     //second break out of first loop
  }
//print results
  printf("\n            Books in Stock\n            ==============\nISBN        Price   Quantity   Value");
  printf("\n-----------------------------------\n");
  
  for (int i=0; i< total_cnt; i++)
  {
    int max_index;
    long long max_value=9999999999;
    for (int l=0; l < total_cnt; l++)
    {
      char temp_barc[10];
      //get a temo string "temp_barc"
      for (int k = 0; k < 10; k++)
      {
        temp_barc[k]=total_barc[l][k];
      }
      //turn string into demical value
      long long barc_dem = demic_conv(temp_barc);
      //get the smallest value out of three
      if (max_value>barc_dem)
      {
        max_value=barc_dem;
        max_index=l;
      }
    }
    //Print barcode
    for (int j = 0; j < 10; j++)
    { 
      printf("%c", total_barc[max_index][j]);
    }
    for (int h = 0; h < 10; h++)
    {
      total_barc[max_index][h]='9';
    }
    //print price
    printf("%6.2lf",total_price[max_index]);
    //print quantity
    printf("%11lld",quantity[max_index]);
    //print value
    printf("%8.2lf",value[max_index]);
    printf("\n");
  }
  
//toal value print
  printf("                             ------\nTotal value books in stock");
  double total_value;
  for(int i = 0; i <total_cnt;i++)
  {
      total_value+=value[i];
  }
  printf("%9.2lf",total_value);
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
#   EXAMPLE:      #
###################
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
###########################################################*/