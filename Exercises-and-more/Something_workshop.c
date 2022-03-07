/****************************************************************
╰（‵□′）╯ THIS MIGHT BE THE MOST USELESS PROGRAM EVER.
Referring code made by SFMSupersanta.
Program: Dunno
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 long long word_cnt(char str[], int size);
 void conv_words(char str[], int size);
 void capitalize(char str[], int size);
 void cl_text(char str[], int size);

int main()
{
    int choice , wordnum;
    char str[255];
    

    do
    {
        printf("Choose one of the following options\n\n1. Input a string\n2. Split a string into words\n3. Convert a string into proper form\n4. Remove redundant spaces\n5. Check valid name\n0. Exit\n\nYour selection (0 -> 5):");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 1)
        {  
            printf("Input a string:");
            fgets(str, sizeof(str)/sizeof(str[0]), stdin);
            str[strcspn(str,"\n")] = '\0';
        }
        else if (choice == 2)
        { ;
            printf("The original string:%s\n",str);

            wordnum = word_cnt(str,strlen(str));
            
            printf("Number of words in the string: %d, they are\n",wordnum);     
            
            conv_words(str, strlen(str));
            
        }
        else if (choice == 3)
        {
            printf("The original string:%s\n",str);
            capitalize(str, strlen(str));
            printf("The proper form:"); 
            for(int i=0; i<strlen(str); i++) printf("%c",str[i]);
            printf("\n");
             
        }
        else if (choice == 4)
        { 
            printf("The original string:%s\n",str);
            cl_text(str, strlen(str));

            printf("The cleaned form:%s\n",str);
        }
        else if (choice == 5)
        { 
            //code
        }

    }while(choice!=0);
    return 0;
}

void cl_text(char str[], int size)
{
    char substr[255];
    int count=0;
    for(int i=0;i<size;i++)
    { 
        if(str[i]==' '&&i==0)
        {
            i++;
        }
        else if(str[i]==' '&&i!=0)
        {
            substr[count++]=' ';
            while(str[i+1]==' ') i++;
        }
        else
        {
            substr[count++]=str[i];
        }
    }
    strcpy(str,substr);
}

void capitalize(char str[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(str[i]==' ')
        {
            while(str[i] == ' ') 
            {
                i++;
                if(i==size) break;
            }
        }
        if(str[i]>=97 && str[i]<= 122) str[i] = str[i] - 32;
        i++;
        while(str[i] != ' '&& str[i] != '\0') 
        {
            if(str[i]>=65 && str[i]<= 90) str[i] = str[i] + 32;
            i++;
        }
    }
    
}

void conv_words(char str[], int size)
{ 
    for(int i=0; i<size; i++)
    { 
        if(str[i]==' ') 
        {
            while(str[i]==' ') i++;
            if(i==size) continue;
        }
        do
        {
            printf("%c",str[i++]);
        } while (str[i]!=' '&&str[i]!='\0');
        printf("\n");
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