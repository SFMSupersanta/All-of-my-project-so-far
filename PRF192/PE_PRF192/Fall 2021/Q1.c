#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 2 so h,b lan luot la chieu cao va canh huyen cua tam giac.
// In ra man hinh dien tich cua tam giac vuong do

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int h, b;
  scanf("%d%d", &h, &b);
  int c = sqrt(b * b - h * h);
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  printf("%d", (h * c) / 2);
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
