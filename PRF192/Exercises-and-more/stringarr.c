#include <stdio.h>
#include <string.h>
// Hàm nhập danh sách n tên sinh viên (dùng array of string)
void nhap(int n, char ten[][30])
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        gets(ten[i]);
    }
}

// sort the string array
void sort(int n, char ten[][30])
{
    int i, j;
    char temp[30];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(ten[i], ten[j]) > 0)
            {
                strcpy(temp, ten[i]);
                strcpy(ten[i], ten[j]);
                strcpy(ten[j], temp);
            }
        }
    }
}

int main()
{
    /* switch case with 2 choices of:
    1.	Hàm nhập danh sách n tên sinh viên (dùng array of string)
    2.	Hàm sắp xếp tên sinh viên theo alphabel (dùng Bubble sort)
    */
    int n;
    char ten[50][30];
    int choice;

    do
    {
        printf("0. exit\n");
        printf("1. Nhap danh sach n ten sinh vien (dung array of string)\n");
        printf("2. Sap xep ten sinh vien theo alphabel (dung Bubble sort)\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            fflush(stdin);
            nhap(n, ten);
            break;
        case 2:
            sort(n, ten);
            printf("Danh sach sinh vien sau khi sap xep:\n");
            for (int i = 0; i < n; i++)
                printf("%s\n", ten[i]);
        }
    } while (choice != 0);
    return 0;
}