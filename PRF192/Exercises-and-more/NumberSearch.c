/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: Number of digit occurrence
version #
////////////////////////////////////////////////////////////////
Design and code a program that reports the number of occurrences
of an integer value in each of ten random numbers between 0 and
30,000 inclusive.  Your program prompts for and accepts from the
user the search value.

Do not assume that the input is valid.  If the value entered
contains any non-numeric characters, your program asks for another
value.  Do not ignore any trailing characters to an otherwise
valid entry.

Your program generates the ten random numbers by calling a
standard library function and does not necessarily generate
the same set of random numbers for each run.

You may call the noOfDigits function to determine the number
of occurrences of the search value in each random number.
You may assume that the function works as specified, even
if you have not written the function.
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_buffer(void);

long long getInt(char msg[], long long min, long long max);

int noOfDigits(char arr[], char checkarr[]);

long long randnumgen();

int main()
{
    srand(time(NULL));
    char checkarr[100];
    char arr[100];
    long long checkarrnum = getInt("Enter the check number: ", -9999999999, 9999999999);
    sprintf(checkarr, "%lld", checkarrnum);
    for (int i = 0; i < 10; i++)
    {
        long long randnum = randnumgen();
        printf("The number #%d is %lld\n", i + 1, randnum);
        sprintf(arr, "%lld", randnum);
        printf("The number of occurrence id %d\n", noOfDigits(arr, checkarr));
    }
    return 0;
}

long long randnumgen()
{
    return rand() % 30000;
}

int noOfDigits(char arr[], char checkarr[])
{
    int width = 0;
    int arrwidth = 0;
    int count = 0;

    while (checkarr[width] != '\0')
        width++;
    while (arr[arrwidth] != '\0')
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

long long getInt(char msg[], long long min, long long max)
{
    char val[20]; // input value
    long long intval;
    int count, rc; // int value and count value
    while (1)
    {
        printf("%s", msg);
        count = 0;
        rc = 0;
        fgets(val, 20, stdin);

        if (val[0] != '\n')
        {
            if (0 < max && 0 > min)
                if (val[0] == '0' && val[1] == '\n')
                    return 0;
            for (int i = 0; i < 20; i++)
            {
                if (val[i] == '\n')
                    rc = 1;
            }
            if (rc == 0)
                clear_buffer();
            char *ovf;

            intval = strtoll(val, &ovf, 10);

            if (intval <= 0)
                count++;

            long long intvaldup = intval;

            while (intvaldup != 0)
            {
                intvaldup /= 10;
                count++;
            }

            if (val[count] != '\n')
                printf("**Trailing Character(s)**\n");
            else if (min < intval && intval < max)
            {
                return intval;
            }
            else
                printf("**OUT OF RANGE**\n");
        }
        else
            printf("**No input**\n");
    }
}