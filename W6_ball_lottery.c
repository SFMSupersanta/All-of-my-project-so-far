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