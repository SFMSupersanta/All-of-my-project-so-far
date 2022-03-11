/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: Print all the comments in a .c file
version #
////////////////////////////////////////////////////////////////
Design and code a function named justComments with the header

 int justComments ( char filename[ ] )

Your function displays all of the C-style comments in a text file.
filename[ ] is a null-terminated string that contains the name 
of the file.  Your function displays multi-line comments as they 
appear in the source file, but with the first line starting in 
the first column.  Your function returns 0 if successful, 1 
if the file is not found. 

You may assume that each comment appears on a separate line 
and starts in the first column of that line. You may also assume 
that there are no input errors while reading the file. 

Consider a file named source.c consisting of the following 
statements

 /* Sample File
 *  source.c
 

 int main(void){
     int i;
     char s[100];

     /* prompt for input 
     printf("Enter a string : ");
     /* accept a string 
     scanf("%s", s);
     /* display the string entered *
     printf("%s\n", s);

     return 0;
 }

The statements

 int i;
 i = justComments("source.c");

display

 /* Sample File
 *  source.c
 */
 /* prompt for input 
 /* accept a string 
 /* display the string entered 

and assign a value of 0 to i.  The statements

 int i;
 i = justComments("");

display nothing and assign a value of 1 to i.

As an additional challenge, upgrade your function so that each comment displays in the same position as the comment appears in the source file.  That is, if a comment starts in column 8 and ends in column 16 in the source file, your upgraded function displays the comment in columns 8 through 16 inclusive.  You may assume that each tab character in the source file expands to 8 spaces on display. 


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
    //printf("filename: %s\n",filename);
    int i=justComments(filename);
    printf("\ni: %d\n",i);
    return 0;
}

int justComments ( char filename[ ] )
{
    //printf("filename: %s\n",filename);
    FILE *fi = NULL;
    
    fi = fopen(filename,"r");
    //printf("fi: %s\n",fi);
    if(fi != NULL)
    {
        do
        {
            char buffer[512];
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
                                printf("%c",d);
                                c = fgetc(fi);
                                if(c=='\n'||c==EOF) printf("%c",'\n');
                                else printf("%c",c);
                                break;
                            }
                            else printf("%c",d);
                        }else if (c == '/' && d == '*') 
                        {
                            if(fgetc(fi)=='\n'||fgetc(fi)==EOF) printf("\n");
                            break;
                        }

                    }
                }else if (d=='/')
                {
                    printf("//");
                    fgets(buffer,512,fi);
                    printf("%s",buffer);
                }
            }
        } while (!feof(fi));
        fclose(fi);
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