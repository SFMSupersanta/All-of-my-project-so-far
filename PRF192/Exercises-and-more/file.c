//this is nothing but a test file
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main()
{
        char filename[100];
        printf("Type in the file name: ");
        scanf("%[^\n]%*c", filename);
        FILE* fi=fopen(filename,"r");
        printf("filename: %s\n",filename);
        if(fi==NULL)
        {
                printf("unable to open file");
        }
        else
        {
                char c;
                printf("File content:\n");
                while((c=fgetc(fi))!=EOF)
                {
                        printf("%c",c);
                }
        }
        fclose(fi);
        return 0;
}