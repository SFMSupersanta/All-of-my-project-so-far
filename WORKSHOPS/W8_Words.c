/****************************************************************
╰（‵□′）╯ THIS MIGHT BE THE MOST USELESS PROGRAM EVER.
Referring code made by SFMSupersanta.
Program: PRF101
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

int main()
{
    printf("Word Counter");
    printf("\n============\n");
    char str[101];
    getString("String to be counted :",str,sizeof(str)/sizeof(str[0]));
    printf("Number of words in the string : %d",word_cnt(str,strlen(str)));
    return 0;
}
/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
   BTP100   is not    that  hard!
###################
#   EXAMPLE:      #
###################
 Word Counter
 ============
 String to be counted :   BTP100   is not    that  hard!
 Number of words in the string : 5
###########################################################*/