
#include <stdio.h>
 
int MAXSIZE = 20;                         // bien khong thay doi
int stack[20];                            // mang stack 
int top = -1;                             // so dem phan tu trong mang

//ham kiem tra stack rong
int isempty()  
{
   if(top == -1)                          
      return 1;
   else
      return 0;
}


//ham kiem tra stack day
int isfull() 
{

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

//ham pop
int pop() 
{
	
   if(!isempty())                                 //kiem tra stack
   {
      top = top - 1;
      return stack[top+1];
   }
   return 0;
}

//ham push
int push(int data) 
{
   if(!isfull()) 
   {
      top = top + 1;   
      stack[top] = data;
   } else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}

//main function
int main()
{
   int num;                             //so dung de xu ly
   printf("Enter the number: ");        //in ra ngoai console
   scanf("%d", &num);                   //lay du lieu tu ban phim

   while(num!=0)                        //vong while de lay phan tu vao stack
   {
       push(num%10);                    //push phan tu vao stack
       num/=10;                         //giam num di 1 hang don vi
   }

   while(!isempty())                    //thuc hien cho den khi stack empty
   {
       num += pop();                    //cong ket qua
   }   
   
   printf("Sum of all digits: %d",num); //in ket qua

   return 0;
}

