//(▀̿Ĺ̯▀̿ ̿)
//Referring code made by supersanta
//Program:String optimization
//version NULL
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char temp_string[255];
  char *string[2];
  for(int i = 0; i <2;i++) 
  {
    printf("Enter string: ");
    scanf(" %[^\n]",&temp_string);
    string[i] = strdup(temp_string);
  }
  for(int i = 0; i <2;i++) 
  {
    printf("The %d string is: %s\n",i+1,string[i]);
  }
  return 0;
}