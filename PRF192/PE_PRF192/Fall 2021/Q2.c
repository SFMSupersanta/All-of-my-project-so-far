#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 4 nam, kiem tra xem nhung nam nhap vao, nam nao la nam nhuan, in ra chung

int check(int n) // Xay dung ham kiem tra nam nhuan
{
  if (n % 400 == 0)
    return 1;
  if (n % 4 == 0 && n % 100 != 0)
    return 1;
  return 0;
}

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int a[4], i;
  for (i = 0; i < 4; i++)
    scanf("%d", &a[i]); // Nhap vao 4 nam

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  for (i = 0; i < 4; i++)
  {
    if (check(a[i]) == 1) // Kiem tra xem day co phai nam nhuan khong
    {
      printf("%d ", a[i]);
    }
  }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
