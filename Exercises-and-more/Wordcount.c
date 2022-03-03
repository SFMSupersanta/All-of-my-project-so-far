/****************************************************************
╰（‵□′）╯ THIS MIGHT BE THE MOST USELESS PROGRAM EVER.
Referring code made by SFMSupersanta.
Program: Word count
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

 void getString(char msg[], char arr[],int size)
 {
     while (1)
     {
        printf("%s",msg);
        fgets(arr,size,stdin);
        int rc=1;
        for(int i=0;i<size;i++)
        {
            if(arr[i]=='\n') 
            {
                rc = 0;
                //printf("i: %d\n",i);
                arr[i]= '\0';
                i=size;
            }
        }
        if(rc!=0) 
        {
            printf("**Trailing Characters!**\n");
            clear_buffer();
        }
        else
        { 
            if(arr[0]=='\n')printf("**No input detected!!**\n");
            else break;
        }
     }
 }

long long word_cnt(char str[], int size)     
{

    int word = 0;
    for(int i=0; i<=size; i++)
    {

        if(str[i]==' '||str[i]=='\n'||str[i]=='\t') 
        {

            word++;
            while(str[i+1]==' '||str[i+1]=='\n'||str[i+1]=='\t')
            {
                i+=1;
            }
        }
        if (i==0  && str[i]!=' ' && str[i]!='\n' && str[i]!='\t')
        {

            word++;
        }
    }

    return word;
}

void print_words(char str[], int size)
{ 
    printf("\nResult printting...\n");

    for(int i=0; i<size; i++)
    {
        printf("\n%d",i);
        if(str[i]==' ')
        {
            do
            {
               ++i;
            } while (str[i]==' ' && str[i]!='\0');    
        }
        printf("\n");
        do
        {
            printf("%c", str[i]);
            i++;
        } while (str[i]!=' ' && str[i]!='\0');   
    }
}

int main()
{
    printf("Word Counter\n============\n");

    char str[101];
    getString("String to be counted :",str,sizeof(str)/sizeof(str[0]));

    printf("Number of words in the string : %d",word_cnt(str,strlen(str)));

    print_words(str, strlen(str));

    return 0;
}
