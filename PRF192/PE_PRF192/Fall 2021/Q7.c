#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Sap xep cac ki tu trong 1 chuoi

void swap(char *a, char *b)
{
  char c = *a;
  *a = *b;
  *b = c;
}
void sap_xep_chu_cai(char str[])
{
  int size = strlen(str);
  for (int i = 0; i < size; i++)
  {
    char *jmin = &str[i];
    for (int j = i + 1; j < size; j++)
    {
      if (str[j] < *jmin)
        jmin = &str[j];
    }
    swap(&str[i], &*jmin);
  }
}

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  char a[105];
  scanf("%s", a); // Nhap 1 chuoi
  sap_xep_chu_cai(a);

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  printf("%s", a); // In ra chuoi sau khi sap xep

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
