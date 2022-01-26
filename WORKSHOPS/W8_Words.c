/****************************************************************
╰（‵□′）╯ THIS MIGHT BE THE MOST USELESS PROGRAM EVER.
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long word_cnt(char str[], int size)     
{
    //printf("string: %s",str);
    int word = 0;
    for(int i=0; i<=size; i++)
    {
        //printf("%c",str[i]);
        if(str[i]==' '||str[i]=='\n'||str[i]=='\t') 
        {
            //printf("%c",str[i]);
            word++;
            while(str[i+1]==' '||str[i+1]=='\n'||str[i+1]=='\t')
            {
                i+=1;
            }
        }
        if (i==0  && str[i]!=' ' && str[i]!='\n' && str[i]!='\t')
        {
           // printf("\ntrue\n");
            word++;
        }
    }
    //printf("\n");
    return word;
}

int main()
{
    printf("Word Counter");
    printf("\n============\nString to be counted :");
    char str[101];
    gets(str);
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