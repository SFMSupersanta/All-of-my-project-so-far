#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordWrap(char arr[], int wrapline)
{
   int i = 0;
   int count = 0;

   while (i < (strlen(arr)))
   { 
      if (count == wrapline)
      {
         count = 0;
         if (arr[i] == ' ')
         { 
            while (arr[i+1] == ' ') i++;
            if (arr[i] != '\0') arr[i] = '\n';
            i++;

         }
         else if (arr[i] != ' ')
         {

            while (arr[i] != ' ') 
            {
               i--;
            }
            if (arr[i] != '\0') arr[i] = '\n';
            i++;

         }
      }

      count++;
      i++;
   }
}

int main()
{
    char s[100][1024];
    int count = 0;
    while (s[count-1][0]!='@')
    {
        fgets(s[count], 1024, stdin);
        s[count][strcspn(s[count],"\n")] = '\0';
        count++;
    }

    for(int i=0; i<count; i++)
    { 
        //wordWrap(s[i],70);
        printf("%s\n",s[i]);
    }
    system("pause");
    return 0;
}
