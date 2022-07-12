// code made by SFMSupersanta
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long word_cnt(char str[], int size)
{
    // printf("string: %s",str);
    int word = 0;
    for (int i = 0; i <= size; i++)
    {
        printf("%c", str[i]);
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            // printf("%c",str[i]);
            word++;
            while (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\t')
            {
                i += 1;
            }
        }
        if (i == 0 && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            // printf("\ntrue\n");
            word++;
        }
    }
    printf("\n");
    return word;
}

int main()
{
    char str[100];
    int words = 1, characters = 0, space = 0; // display and initiolize variables
    printf("Please enter the string :");
    gets(str);
    // printf("string: %s",str);
    words = word_cnt(str, strlen(str));
    printf("Total words: %d ", words);
    return 0;
}