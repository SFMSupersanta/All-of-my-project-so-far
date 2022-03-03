/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
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

/*
function to make the text "clean"
take a string, size of the string and a string pointer as input and assing value to the string pointer
*/
void cl_text(char str[], int size, char *out_str)
{
    for (int i = 0; i <= size-1; i++)
    {
        if(str[i] == ' '&& i==0)
        {
            while(str[i+1] == ' ')
            {
                i++;
            }
        }

        else if(str[i] == ' ')
        {
            while(str[i+1] == ' ')
            {
                i++;
            }
            *out_str++ = str[i];
        }

        else if (str[i] < 32 || str[i] == 127)
        {
           *out_str++ = '_';
        }

        else 
        {
            *out_str++ = str[i];
        }
    }
}

int main()
{
    printf("String Cleaner");
    printf("\n==============\nString to be cleaned : ");
    char str[101];
    getString("String to be cleaned :",str,sizeof(str)/sizeof(str[0]));
    char cl_str[101];
    cl_text(str,/*return length value*/strlen(str),cl_str);
    printf("Cleaned string       : %s", cl_str);
}
/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
   BTP100   is not    that  hard!
###################
#   EXAMPLE:      #
###################
 String Cleaner
 ==============
 String to be cleaned :   BTP100   is not    that  hard!
 Cleaned string       : BTP100 is not that hard!
###########################################################*/