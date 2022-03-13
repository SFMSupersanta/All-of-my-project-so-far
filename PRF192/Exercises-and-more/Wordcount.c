/****************************************************************
╰（‵□′）╯ THIS MIGHT BE THE MOST USELESS PROGRAM EVER.
Referring code made by SFMSupersanta.
Program: Word count
version #
////////////////////////////////////////////////////////////////
count words in an array
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void clear_buffer (void);

 void getString (char msg[], char arr[],int size);

 long long word_cnt (char str[], int size);

 void clear_buffer (void);

 void conv_words (char str[], int size, char word[][255]);



int main()
{
    printf("Word Counter\n============\n");

    char str[101];
    getString ("String to be counted :",str,sizeof (str) / sizeof (str[0]));

    int wnum = word_cnt (str,strlen (str));
    printf ("Number of words in the string : %d\n",wnum);

    char word[wnum][255];

    conv_words (str, strlen (str), word);

    for(int i = 0; i < wnum; i++)
    { 
        printf ("%s\n",word[i]);
    }

    return 0;
}

 void clear_buffer (void)
 {
     char c;
     while ( (c=getchar ()) != '\n'&&c!=EOF);
 }

 void getString (char msg[], char arr[],int size)
 {
     while (1)
     {
        printf ("%s", msg);
        fgets (arr, size, stdin);
        int rc = 1;
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == '\n') 
            {
                rc = 0;
                //printf("i: %d\n",i);
                arr[i] =  '\0';
                i = size;
            }
        }
        if(rc != 0) 
        {
            printf ("**Trailing Characters!**\n");
            clear_buffer ();
        }
        else
        { 
            if (arr[0] == '\n') printf ("**No input detected!!**\n");
            else break;
        }
     }
 }

long long word_cnt(char str[], int size)     
{

    int word = 0;
    for(int i =0 ; i <= size; i++)
    {

        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') 
        {

            word++;
            while (str[i+1] ==  ' ' || str[i+1] == '\n' || str[i+1] == '\t')
            {
                i+=1;
            }
        }
        if (i == 0  && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {

            word++;
        }
    }

    return word;
}

//convert every word in arr string to (size) substring in word 2d array
void conv_words(char str[], int size, char word[][255])
{ 
    //printf("\nResult printting...\n");
    char temp[255];
    int tempi;
    int temps = 0;
    for(int i = 0; i < size; i++)
    {
        tempi=0;
        //printf("\n%d",i);
        if (str[i]==' ')
        {
            do
            {
               ++i;
            } while (str[i]==' ' && str[i]!='\0');    
        }
        do
        {
            temp[tempi]=str[i];
            tempi++;
            i++;
        } while (str[i]!=' ' && str[i]!='\0');
        temp [++tempi]='\0';  
        strcpy (word[temps++], temp);
    }
}
