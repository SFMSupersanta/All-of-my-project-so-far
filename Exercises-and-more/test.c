#include <stdio.h>

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


int main()
{
    
    int a=10;
    int b=10;
    printf("%d\n",++a + ++b);
    printf("%d\n",a++ + b++);
    printf("%d\n",a + b);
    return 0;
}