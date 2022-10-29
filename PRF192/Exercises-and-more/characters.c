#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to capitalize the first letter of each word in a string
void capitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
        else if (str[i] == ' ')
        {
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                str[i + 1] = str[i + 1] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != ' ')
            str[i] = str[i] + 32;
        i++;
    }
}

// sort the string
void sort(char *str)
{
    int i, j;
    char temp;
    for (i = 0; i < strlen(str) - 1; i++)
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// replace white space by any other character
void replace(char *str, char c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            str[i] = c;
        i++;
    }
}

// count the apparence of each character in a string
void count(char *str)
{
    int i, j, count;
    for (i = 0; i < strlen(str); i++)
    {
        count = 1;
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '0';
            }
        }
        if (str[i] != '0')
            printf("%c\t\t%d\n", str[i], count);
    }
}

int main()
{
    // menu of 4 choices
    int choice;
    char c;
    do
    {
        printf("0. exit\n");
        printf("1. in hoa in thuong, hoa chu cai dau\n");
        printf("2. sap xep chuoi\n");
        printf("3. thay ky tu trong bang bat ky ky tu khac\n");
        printf("4. thong ke\n");
        printf("Input your choice: ");
        scanf("%d", &choice);
        if (choice == 0)
            continue;
        char str[100];
        getchar();
        printf("Nhap chuoi : ");
        scanf("%[^\n]s", str);
        getchar();
        // ConG Hoa XA HOI CHu ngh1A v1Et NAM 1986
        switch (choice)
        {
        case 0:
            printf("Goodbye!");
            break;
        case 1:
            printf("%-20s= %s\n", "chuoi in thuong", strlwr(str));
            printf("%-20s= %s\n", "chuoi in hoa", strupr(str));
            capitalize(str);
            printf("%-20s= %s\n", "Chuoi In Hoa Kt", str);
            break;
        case 2:
            sort(str);
            printf("Sau khi sap xep : \n\n\t%s\n", str);
            break;
        case 3:
            printf(" Nhap ky tu thay the : ");
            c = getchar();
            replace(str, c);
            printf(" Chuoi sau khi thay the: %s\n", str);
            break;
        case 4:
            printf("Thong ke ky tu xuat hien trong chuoi %s la\n", str);
            count(str);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    } while (choice != 0);
}