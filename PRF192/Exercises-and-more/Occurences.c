/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: Number array occurrence
version #
////////////////////////////////////////////////////////////////
Design and code a function named occurences that returns the
number of times that a search string appears within a reference
string.  The search string is the first parameter of your
function.  The reference string is the second parameter.

For example, the statements

 int i;

 i = occurences( "BT", "BTP100 BTO120" );
 printf("%d\n", i );

display

 2

The statements

 int i;

 i = occurences( "BB", "BBBXCBBb" );
 printf("%d\n", i );

display

 3

****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int occurrences(char arr[], char checkarr[]);

void clear_buffer(void);

void getString(char mgs[], char arr[], int size);

int main()
{
    char arr1[30];
    char arr2[30];
    getString("Type the large array: ", arr1, 30);
    getString("Type the small array: ", arr2, 30);
    printf("The occurrences of small arrays in the large array: %d\n", occurrences(arr2, arr1));
    return 0;
}

int occurrences(char checkarr[], char arr[])
{
    int width = 0;
    int arrwidth = 0;
    int count = 0;

    while (checkarr[width] != '\n')
        width++;
    while (arr[arrwidth] != '\n')
        arrwidth++;

    for (int i = 0; i < arrwidth - width; i++)
    {
        if (arr[i] == checkarr[0])
        {
            if (width == 1)
                count++;
            else
            {
                int rc = 0;
                for (int j = 1; j < width; j++)
                {
                    if (arr[i + j] != checkarr[j])
                        rc = 1;
                }
                if (rc == 0)
                    count++;
            }
        }
    }
    return count;
}

/* clear empties input buffer */
void clear_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void getString(char msg[], char arr[], int size)
{
    while (1)
    {
        printf("%s", msg);
        fgets(arr, size, stdin);
        int rc = 1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == '\n')
                rc = 0;
        }
        if (rc != 0)
        {
            printf("**Trailing Characters!**\n");
            clear_buffer();
        }
        else
        {
            if (arr[0] == '\n')
                printf("**No input detected!!**\n");
            else
                break;
        }
    }
}
