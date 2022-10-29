#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 1 day, in ra phan tu la so chan va xuat hien nhieu lan (tu 2 do len)

int so_chan_xuat_hien_nhieu_nhat(int arr[], int size, int result[])
{
  int mask[size];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] % 2 == 0)
      mask[i] = 0;
    else
      mask[i] = -1;
  }
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (mask[i] == 0)
    {
      mask[i]++;
      for (int j = i + 1; j < size; j++)
      {
        if (mask[j] == 0)
        {
          if (arr[j] == arr[i])
          {
            mask[j] = -1;
            mask[i]++;
          }
        }
      }
    }
    if (mask[i] > 1)
      count++;
  }

  int dem = 0;
  for (int i = 0; i < size; i++)
  {
    if (mask[i] > 1)
      result[dem++] = arr[i];
  }
  return dem;
}

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  // scan the amounnt of numbers
  int n;
  scanf("%d", &n);
  // number array initialize
  int numbers[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &numbers[i]);
  }

  int result[n];
  int resultnum = so_chan_xuat_hien_nhieu_nhat(numbers, n, result);

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

  for (int i = 0; i < resultnum; i++)
  {
    printf("%d ", result[i]);
  }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
