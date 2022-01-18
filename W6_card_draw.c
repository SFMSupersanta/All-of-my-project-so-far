// toi da~ lam' qua' nhieu' game nhan pham^ roi'
/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int compare_arr(char a[], char b[])
{
    for(int i = 0; i <2;i++)
    {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

char rank_gen()
{  
    int temp = (rand()%13) +1; //randnum 0-12
    char rank;
    if(temp == 1) rank = 'A';
    else if(temp ==11) rank = 'J';
    else if(temp == 12) rank = 'Q';
    else if(temp == 13) rank = 'K';
    else rank = temp+'0';
    return rank;
}

char suit_gen()
{
    int temp = (rand() % 4) + 1;
    char suit;
    if(temp==1) suit='H';
    else if(temp==2) suit='D';
    else if(temp==3) suit = 'S';
    else if(temp == 4) suit = 'C';
    return suit;
}

void game(char suit,char rank)
{
    char req[2] = {rank,suit};
    int i=1;
    int count = 0;
    while(i=1)
    {
        count++;
        char draw[2] = {rank_gen(),suit_gen(),};
        printf("Result of draw %d : ", count);
        for (int i = 0; i < 2; i++) printf("%c",draw[i]);
        printf("\n");
        if(compare_arr(req,draw)==1)
        {
            printf("You got your result in %d draws!", count);
            break;
        }
    }
}

int main()
{
    //print
    printf("Dice Thrower\n");
    printf("------------\n");
    char suit, rank;
    printf("Suit : ");
    scanf("%c",&suit);
    getchar();
    printf("Rank : ");
    scanf("%c",&rank);
    
    game(suit,rank);
    
    //main code
}