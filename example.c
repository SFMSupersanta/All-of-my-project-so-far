#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main( void )
{
    printf("2 players: type 2 \t\t3 players: type 3 \t\t4 players: type4 \t\t5 players: type5\n What is your choice? \n");
  int players ;
  scanf("%d", &players) ;
  char player_name[4][255];
  for(int i=0;i<players;i++)
  {
    printf("Type in the number %d player's name: ",i+1) ;
    scanf("%s",&player_name[i]) ;  
  }
  for(int i=0;i<=players;i++)
  {
    printf("%s \n",player_name[i]);
  }
  return 0;
}
