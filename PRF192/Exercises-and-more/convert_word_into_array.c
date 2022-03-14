/****************************************************************
╰（‵□′）╯
Referring code made by SFMSupersanta.
Program: Word count
version #
////////////////////////////////////////////////////////////////
convert words into an 2d char arr
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conv_words(char str[], int size, char word[][255])
{ 
    //printf("\nResult printting...\n");
    
    int tempi;
    int temps = 0;
    for(int i = 0; i < size; i++)
    {
        char *temp = (char*)malloc(sizeof(char)*255);
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
        } while (str[i] != ' ' && str[i]!='\0');
        temp [++tempi]='\0';  
        strcpy (word[temps++], temp);
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

int main()
{ 
    char arr[2000];
    fgets(arr,sizeof(arr)/sizeof(arr[0]), stdin);
    arr[strcspn(arr,"\n")] = '\0';
    int wordnum = word_cnt(arr, strlen(arr));
    char word[wordnum][255];
    conv_words(arr, strlen(arr), word);
    for(int i = 0; i < wordnum; i++)
    {
        printf ("%s ", word[i]);
    }
}