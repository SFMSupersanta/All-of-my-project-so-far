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

#define max_items  101                      //edit this statement to change the max item value

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
    return true;
}

double scan_price(void)
{
    
    double price;
    char ovflow;
    int rc;
    while(true)
    {
      printf("Price    :  ");
      rc = scanf("%lf%c",&price,&ovflow);
      if(rc==0||rc==1)
      {
        printf("No input accepted!\n");
        while(getchar()!='\n') ;
      }else if(ovflow!='\n')
      {
        printf("Character overflow!\n");
        while(getchar()!='\n') ;
      }
      else if(price<0)
      {
        printf("Out ranged!\n");
      }else break;
    }
    return price;
}

int scan_quantity(void)
{
  
    int price;
    char ovflow;
    int rc;
    while(true)
    {
      printf("Quantity :  ");
      rc = scanf("%d%c",&price,&ovflow);
      if(rc==0||rc==1)
      {
        printf("No input accepted!\n");
        while(getchar()!='\n') ;
      }else if(ovflow!='\n')
      {
        printf("Character overflow!\n");
        while(getchar()!='\n') ;
      }
      else if(price<0)
      {
        printf("Out ranged!\n");
      }else break;
    }
    return price;
}


int main()
{
  //program name
  printf("Packaged Goods Orgranizer\n");
  printf("-------------------------\n");
  
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
      while (true)
      {
        char barc_arr[11];
        barc_arr[10]='\0';
        printf("Barcode  :  ");
        scanf(" %[^\n]",&barc_arr);
        
        if (barc_arr[0]=='0'&&barc_arr[1]=='\0')
        {
          status=false;
          break;
        }
        else if(barc_arr[10]!='\0')
        {
          printf("Character overflow!\n");
        }
        else if (barc_val(barc_arr)==true) 
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
      if(status == false) break;
      //scan price
      total_price[total_cnt]=scan_price();

      //scan quantity
      quantity[total_cnt] = scan_quantity();

      //total value caculations
      value[total_cnt]=total_price[total_cnt]*quantity[total_cnt];
      total_cnt++;
    } 
    if (status==false) break;
  }
//print results
  printf("\n            Goods in Stock\n            ==============\nBarcode    Price   Quantity   Value");
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
  printf("                             ------\nTotal value goods in stock");
  double total_value;
  for(int i = 0; i <total_cnt;i++)
  {
      total_value+=value[i];
  }
  printf("%9.2lf",total_value);
  return 0;
}
/*
##############################################
6300090801
3.25
5
6380613916
4.45
15
6038367157
3.95
10
0
##############################################
#    CTR+PASTE THE ABOVE LINES FOR INPUT     #
##############################################
#     EXAMPLE FOR SUCCESS CODE:              #
##############################################
 Packaged Goods Organizer
 ========================
 Barcode  :  6300090801
 Price    :  3.25
 Quantity :  5
 Barcode  :  6380613916
 Price    :  4.45
 Quantity :  15
 Barcode  :  6038367157
 Price    :  3.95
 Quantity :  10
 Barcode  :  0

-OUTPUT: 

             Goods in Stock
             ==============
 Barcode    Price   Quantity   Value 
 -----------------------------------
 6038367157  3.95         10   39.50
 6300090801  3.25          5   16.25
 6380613916  4.45         15   66.75
                              ------
 Total value goods in stock   122.50
##############################################
*/