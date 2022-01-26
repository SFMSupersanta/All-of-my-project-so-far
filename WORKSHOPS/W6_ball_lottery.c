// toi da~ lam' qua' nhieu' game nhan pham^ roi'
/****************************************************************
≡(▔﹏▔)≡
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int ran_gen()
{  
    return rand()%10; //randnum 0-5
}

void game(int sought)
{
    int x=1,first,second,pickct=1;

    while(x==1)
    {
        first = ran_gen() +1;
        second = ran_gen() +1;
        printf("Result of picks %d and %d  : %d + %d\n",pickct,pickct + 1,first,second);
        pickct+=2;
        if (first +second== sought)
        {
            printf("you got your total in %d picks!",pickct-1);
            x=0;
            break;
        }
    }
}

int main()
{
    //print
    printf("Ball lottery\n");
    printf("------------\n");
    //main code
    long long sought,num;

    srand(time(NULL));

    printf("Total sought : ");
    scanf("%lld",&sought);
    if(sought>20||sought<0) printf("Invalid input");
    else game(sought);

    return 0;
}
/*
###################
#   EXAMPLE:      #
###################
 Fraction Simplifier
 ===================
 Ball Lottery
 ============
 Total sought : 11
 Result of picks 1 and 2 : 1 + 3
 Result of picks 3 and 4 : 4 + 5
 Result of picks 5 and 6 : 6 + 3
 Result of picks 7 and 8 : 5 + 6
 You got your total in 8 picks!
 NOTICE: the result differ every test
#########################*/