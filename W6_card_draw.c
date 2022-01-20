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
    else if (temp == 10) rank = '1';           //this function return a char and 10 is not a char so it returns 1
    else if(temp ==11) rank = 'J';
    else if(temp == 12) rank = 'Q';
    else if(temp == 13) rank = 'K';
    else rank = temp+'0';
    printf("rank: %d\n", temp);
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
    printf("suit: %d\n", temp);
    return suit;
}

void game(char suit,char *rank)
{
    char req[3] = {rank,suit,};
    int i=1;
    int count = 0;
    while(i=1)
    {
        count++;
        int decem=0;                                        //latin word for ten, this =1 means the rank is num(10)
        char draw[3] = {rank_gen(),suit_gen(),'0'};
        if(draw[1]=='1') decem =1;
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
    char suit, *rank;
    printf("Suit : ");
    scanf("%c",&suit);
    getchar();
    printf("Rank : ");
    scanf(" %[^\n]", rank);
    
    game(suit,*rank);
    
    //main code
}