#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[30];
    printf("Nhap xau: ");
    scanf("%[^\n]s", a);
    int mask[strlen(a)];
    for (int i = 0; i < strlen(a); i++)
        mask[i] = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (mask[i] == 0)
        {
            mask[i]++;
            for (int j = i + 1; j < strlen(a); j++)
            {
                if (mask[j] == 0 && a[i] == a[j])
                {
                    mask[j] = -1;
                    mask[i]++;
                }
            }
        }
    }

    int largest = -1, second = -1;
    int largestPos = 0, secondPos = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (mask[i] != -1 && mask[i] > largest)
        {
            second = largest;
            secondPos = largestPos;
            largest = mask[i];
            largestPos = i;
        }
    }
    if (largest != -1)
    {
        printf("The most appears: %c\n", a[largestPos]);
        if (second == -1)
            printf("Only one appears");
        printf("The second most appears: %c\n", a[secondPos]);
    }
    else
        printf("No digits");
}