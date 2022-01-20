/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
  printf("Packaged Goods Orgranizer\n");
  printf("-------------------------\n");
  int max_items = 101;
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
        printf("Barcode  :  ");
        barc_arr[10]='\0';
        barc_arr[2]='\0';
        scanf(" %[^\n]",&barc_arr);
        if (barc_arr[0]=='0'&&barc_arr[1]=='\0')
        {
          status=false;
          break;
        }
        if (barc_val(barc_arr)==true) 
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
      //test code
      /*int resume=1;
      printf("resume/quit(1,0): ");
      scanf("%d",&resume);
      if (resume==0) break;
      else continue;*/
      //end of test code
      //scan price
      printf("Price    :  ");
      scanf("%lf",&total_price[total_cnt]);
      //printf("%6.2lf\n",total_price[total_cnt]);
      //scan quantity
      printf("Quantity :  ");
      scanf("%lld",&quantity[total_cnt]);
      //printf("%11lld\n",quantity[total_cnt]);
      //caculate value
      value[total_cnt]=total_price[total_cnt]*quantity[total_cnt];
      //printf("value: %8.2lf\n",value[total_cnt]);
      total_cnt++;
    } 
    if (status==false) break;
  }
  //print results
  printf("\n            Goods in Stock\n            ==============\nBarcode    Price   Quantity   Value");
  printf("\n-----------------------------------\n");
  for(int i = 0; i < total_cnt;i++)
  {
    //print barcode
    for (int j = 0; j < 10; j++)
    { 
      printf("%c", total_barc[i][j]);
    }
    //print price
    printf("%6.2lf",total_price[i]);
    //print quantity
    printf("%11lld",quantity[i]);
    //print value
    printf("%8.2lf",value[i]);
    printf("\n");
  }
  printf("                             ------\nTotal value goods in stock");
  double total_value;
  for(int i = 0; i <total_cnt;i++)
  {
      total_value+=value[i];
  }
  printf("%9.2lf",total_value);
  return 0;
}