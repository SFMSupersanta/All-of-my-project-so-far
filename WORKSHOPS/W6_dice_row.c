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
    return rand()%6; //randnum 0-5
}

void game(int sought)
{
    int x=1,count=0,first,second;

    while(x==1)
    {
        count ++;
        first = ran_gen() +1;
        second = ran_gen() +1;
        printf("Result of throw  %d : %d + %d\n", count,first,second);
        if (first +second== sought)
        {
            printf("you got your total in %d throw!",count);
            x=0;
            break;
        }
    }
}

int main()
{
    //print
    printf("Dice Thrower\n");
    printf("------------\n");
    //main code
    long long sought,num;

    srand(time(NULL));

    printf("Total sought : ");
    scanf("%lld",&sought);
    if(sought>12||sought<0) printf("Invalid input");
    else game(sought);

    return 0;
}