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
#include <stdbool.h>
#include <string.h>

//\input stream clear function\*
void bufc()
{
    int c;
    while ( (c = getchar()) != '\n' && c != EOF) {}
}

//Rank input validator
char RankChar( char str[])
{
    char suit;
    while (true)
    {
        printf ("%s", str);
        suit=getchar ();
        if (suit == 'A'||suit == '2'||suit ==' 4'||suit == '3'||suit == '5'||
            suit == '6'||suit == '7'||suit == '8'||suit == '9'||suit == '1'||
            suit ==' J'||suit ==' Q'||suit == 'K') 
        {
            if(suit == '1')
            {
                if(getchar() == '0'&&getchar() == '\n') break;
                else
                {
                    printf (" statement not regconized\n");
                    bufc ();
                }
            }
            else if (getchar() == '\n') 
            {
                break;
            }
            else 
            {
                printf (" statement not regconized\n");
                bufc ();
            }
        }
        else 
        {
            printf (" statement not regconized\n");
            bufc ();
        }
    }
    return suit;
}

//Suit input validator
char SuitChar (char str[])
{
    char suit;
    while(true)
    {
        printf ("%s", str);
        suit = getchar();
        if (suit == 'H'||suit == 'S'||suit == 'C'||suit == 'D') 
        {
            if (getchar() == '\n') break;
            else bufc();
        }
        else 
        {
            printf (" statement not regconized\n");
            bufc ();
        }
    }
    return suit;
}

//random Rank (char) generator
char rankgen() { return "A234567891JQK"[rand() % 13]; }

//random Suit (char) generator
char suitgen() { return "CHDS"[rand()%4]; }

//game function
void gamestart (char Suit, char Rank)
{
    char suit,rank;
    int count=1;
    while (Suit!=suit || Rank!=rank)
    {
        printf (" Result of draw  %d : ",count++);
        suit=suitgen();
        rank=rankgen();
        printf ("%c%c", suit, rank);
        if (rank=='1') printf ("%c",'0');
        printf ("\n");
    }
        
    printf (" You got your result in %d draws!",--count);
}

//main function
int main()
{
    srand (time(NULL));
    printf (" Card Draw\n =========\n");

    char suit =SuitChar(" Suit : ");

    char rank =RankChar(" Rank : ");

    gamestart (suit,rank);
    printf ("\n");
    system ("pause");
    return 0;
}

/***************************************************************
////////////////////////////////////////////////////////////////
Design and code a program that keeps drawing a card from an 
original deck of 52 cards until the card drawn is the card 
requested.  Your program prompts for and accepts the suit and 
rank of the card sought, includes input validation and uses your 
own and standard library functions.  You may assume that the user 
returns the card drawn to the deck before drawing another card.

Design your program according to structured design principles 
and write the functions so that you can readily use them in other 
applications. 

Preface your function headers with comprehensive descriptions 
of function purpose, function parameters and function return value.

The output from your program looks something like: 

 Card Draw
 =========
 Suit : H
 Rank : 4
 Result of draw  1 : 2C
 Result of draw  2 : 3S
 Result of draw  3 : KD
 Result of draw  4 : 4H
 You got your result in 4 draws!


****************************************************************/
