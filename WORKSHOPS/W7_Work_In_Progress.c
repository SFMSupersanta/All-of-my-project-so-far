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

bool barc_val(char barc_arr[])
{
    //check if the first 10 value is a Number
    for (int i=0;i<4;i++)
    {
      if (barc_arr[i]!='0'&&barc_arr[i]!='1'&&
          barc_arr[i]!='2'&&barc_arr[i]!='3'&&
          barc_arr[i]!='4'&&barc_arr[i]!='5'&&
          barc_arr[i]!='6'&&barc_arr[i]!='7'&&
          barc_arr[i]!='8'&&barc_arr[i]!='9')
          return false;
    }
    //check if the user tped a string more than 10
    return true;
}

long long demic_conv(char barc_arr[])
{
  long long returnnum=0 ;
  for (int i = 0; i <= 3; i++)
  {
    returnnum *=10;
    returnnum += barc_arr[i]-'0'; 
    //printf("returnnum:%lld\n",returnnum);
  }
  return returnnum;
}

double scan_price(void)
{
    
    double price;
    char ovflow;
    int rc;
    while(true)
    {
      printf("Rate        :  ");
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
      printf("Hours Spent :  ");
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
  printf("Work in Progress Organizer\n");
  printf("==========================\n");  
  char total_barc [max_items][5];
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
        char barc_arr[5];
        barc_arr[4]='\0';
        printf("Project     :  ");
        scanf(" %[^\n]",&barc_arr);
        if (barc_arr[0]=='0'&&barc_arr[1]=='\0')
        {
          status=false;
          break;
        }
        else if(barc_arr[4]!='\0')
        {
          printf("Character overflow!\n");
        }
        else if(barc_val(barc_arr)==true)
        {
          for (int i = 0; i <4;i++) 
          {
            total_barc[total_cnt][i]= barc_arr[i];
          }
          break;
        }  
        else 
        {
            printf("INVALID INPUT\n");
            continue;
        }
      }
      if(status == false) break;   //first break out of second loop

      //scan price
      total_price[total_cnt]=scan_price();

      //scan quantity
      quantity[total_cnt] = scan_quantity();

      //total value caculations
      value[total_cnt]=total_price[total_cnt]*quantity[total_cnt];
      total_cnt++;
    } 
    if (status==false) break;     //second break out of first loop
  }
//print results
  printf("\n            Work in Progess\n            ===============\nProject   Rate  Hours      Value");
  printf("\n-----------------------------------\n");
  
  for (int i=0; i< total_cnt; i++)
  {
    int max_index;
    long long max_value=9999;
    for (int l=0; l < total_cnt; l++)
    {
      char temp_barc[4];
      //get a temo string "temp_barc"
      for (int k = 0; k < 4; k++)
      {
        temp_barc[k]=total_barc[l][k];
      }
      //turn string into demical value
      long long barc_dem = demic_conv(temp_barc);
      //get the smallest value out of three
      if (max_value>barc_dem)
      {
        max_value=barc_dem;
        //printf("max_value: %d\n",max_value);
        max_index=l;
      }
    }
    //Print barcode
    for (int j = 0; j < 4; j++)
    { 
      printf("%c", total_barc[max_index][j]);
    }
    for (int h = 0; h < 4; h++)
    {
      total_barc[max_index][h]='9';
    }
    //print price
    printf("%10.2lf",total_price[max_index]);
    //print quantity
    printf("%7lld",quantity[max_index]);
    //print value
    printf("%11.2lf",value[max_index]);
    printf("\n");
  }
  
//toal value print
  printf("                        --------\nTotal Work in Progress");
  double total_value;
  for(int i = 0; i <total_cnt;i++)
  {
      total_value+=value[i];
  }
  printf("%10.2lf",total_value);
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