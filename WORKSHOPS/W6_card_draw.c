// toi da~ lam' qua' nhieu' game nhan pham^ roi'
/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
/*
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool compare_arr(char a[], char b[])
{
    for(int i = 0; i <2;i++)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}

char rank_gen()
{  
    int temp = (rand()%13) +1; //randnum 0-12
    char rank;
    if(temp == 1) rank = 'A';
    else if (temp == 10) rank = '1';           //this function return a char and 10 is not a char so it returns 1
    else if(temp ==11) rank = 'J';
    else if(temp == 12) rank = 'Q';
    else if(temp == 13) rank = 'K';
    else rank = temp+'0';
    return rank;
    return '1';
}

char suit_gen()
{
    int temp = (rand() % 4) + 1;
    char suit;
    if(temp==1) suit='H';
    else if(temp==2) suit='D';
    else if(temp==3) suit = 'S';
    else if(temp == 4) suit = 'C';
    printf("suit: %d\n", temp);
    return suit;
}

void game(char suit,char rank[])
{
    printf("rank: %s\n",rank);
    int count = 0;
    char rank_draw[2];
    char suit_draw;
    while(true)
    {
        count++;
        char ranktemp=rank_gen();
        if(ranktemp=='1')
        {
            rank_draw[0] = '1';
            rank_draw[1] = '0';
            rank_draw[2] = '\0';
        }
        else
        {
            rank_draw[0] = ranktemp;
            rank_draw[1] = '\0';
        }
        printf("rankdraw: %s\n", rank_draw);
        suit_draw = suit_gen();
        printf("Result of draw %d : %s", count,rank_draw);
        printf("%c\n",suit_draw);
        if(compare_arr(rank,rank_draw)==true&&suit==suit_draw)
        {
            printf("You got your result in %d draws!",count);
            break;
        }
        //if (count==30) break;
    }
}

int main()
{
    srand(time(NULL));
    //print
    printf("Dice Thrower\n");
    printf("------------\n");
    char suit, rank[2];
    printf("Suit : ");
    scanf("%c",&suit);
    getchar();
    printf("Rank : ");
    scanf(" %[^\n]", rank);
    game(suit,rank);
}*/
// FUCK THISI QUIT