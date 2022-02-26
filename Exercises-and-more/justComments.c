/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: Number array occurrence
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int justComments ( char filename[ ] );

void clear_buffer (void);

void getString(char mgs[],char arr[],int size);

int main()
{ 
    char filename[1024];
    getString("Enter the file name: ",filename,1024);
    printf("filename: %s\n",filename);
    int i=justComments(filename);
    printf("i: %d\n",i);
    return 0;
}

int justComments ( char filename[ ] )
{
    printf("filename: %s\n",filename);
    FILE *fi = NULL;
    
    fi = fopen(filename,"r");
    printf("fi: %s\n",fi);
    if(fi != NULL)
    {
        do
        {
            char c = fgetc(fi),d;
            if(c=='/')
            { 
                d=fgetc(fi);
                if(d=='*')
                {
                    printf("%c%c",c,d);
                    while(1)
                    {
                        c= fgetc(fi);
                        printf("%c",c); 
                        if(c=='*')
                        {
                            d = fgetc(fi);
                            if(d=='/')
                            {
                                printf("%c%c",c,d);
                                break;
                            }
                        }
                    }
                }
            }
        } while (!feof(fi));
        
    }else 
    {
        printf("Failed to open file: %s\n",filename);
        return 1;
    }
    return 0;
}

 /* clear empties input buffer */ 
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
                printf("i: %d\n",i);
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