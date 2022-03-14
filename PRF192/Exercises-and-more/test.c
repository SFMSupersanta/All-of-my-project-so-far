#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
int count = 0, c = 0, i, j = 0, k, l, space = 0;
    char str[100], p[50][100], str1[20], ptr1[50][100], cmp[50];
 
    printf("Enter a string:"); scanf(" %[^\n]s", str);
    for (i = 0;i < strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
        {
            space++;
        }
    }
    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
    {
        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }        
        else
             p[i][k++] = str[j];
    }
   
                strcpy(cmp, p[0]);
                strcpy(p[0], p[space]);
                strcpy(p[space], cmp);
              
  
  
  
  
  // OUTPUT for marking:
   printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

for (i = 0;i <= space;i++)
    {
        printf("%s ", p[i]);
    }







  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
