#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// DE BAI: Nhap vao 1 day n so, nhap 1 so va vi tri muon chen so day. In ra day sau khi chen

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int n;
  scanf("%d", &n);
  int a[n], i;
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]); // Nhap 1 day n so
  int v, p;
  scanf("%d%d", &v, &p); // Nhap so muon chen va vi tri muon chen
                         // 1, 2, 3, 4, 5, 6 : v = 7, n = 2, size = 6
                         // 1, 2, 7, 3, 4, 5, 6 : 7

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  int b[n];
  for (i = 0; i < n; i++)
    b[i] = a[i];
  n++;
  for (i = p + 1; i < n; i++)
    a[i] = b[i - 1];
  a[p] = v;

  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  /*
  for (i = 0; i < p; i++)
    printf("%d ", a[i]);

  printf("%d ", v);

  for (i = p; i < n; i++)
    printf("%d ", a[i]); // In ra day sau khi chen
  */
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
