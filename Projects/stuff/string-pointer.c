//(▀̿Ĺ̯▀̿ ̿)
// Referring code made by supersanta
// Program:String pointer test
// version NULL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char *string[10];
  string[0] = "bruh bruh lmao";
  string[1] = "dảk dảk bruh bruh lmao";
  string[2] = "duong ngu";
  string[3] = "del muon nghi nua";
  string[4] = "random 1";
  for (int i = 5; i <= 10; i++)
  {
    string[i] = "random";
  }
  srand(time(NULL));
  int rannum = rand() % 10;
  printf("%s", string[rannum]);
  return 0;
}
