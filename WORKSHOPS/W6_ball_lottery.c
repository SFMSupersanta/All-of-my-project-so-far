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
#include <stdbool.h>

//\input stream clear function\*
void clear (void) 
{
    while ( getchar() != '\n' );
}

//GetInt(char str[], min, max)
int GetInt(char msg[], int min, int max)
{
    int value;
    int rc;
    char ovflow;
    while (true) 
    {
        printf("%s", msg);
        rc = scanf("%d%c",&value,&ovflow);
        if(rc == 0)
        {
            printf("**No input accepted!**\n\n");
            clear();
            printf("----Press Enter to continue----");
            clear();
        }
        else if(ovflow != '\n')
        {
            printf("**Trailing characters!**\n\n");
            clear();
            printf("----Press Enter to continue----");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n\n");
            printf("----Press Enter to continue----");
            clear();
        }
        else break;
    }
    return value;
}

//\random number generator\* 
int ran_gen()
{  
    return rand()%10; //randnum 0-9
}

//\game function\*
void game(int sought)
{
    int x=1,first,second,pickct=1;       //pick count

    while(x==1)
    {
        first = ran_gen() +1;                //so that first [1-6]
        second = ran_gen() +1;              //so that second [1-6]
        printf("Result of picks %d and %d  : %d + %d\n",pickct++,pickct,first,second);     
        pickct++;
        if (first +second== sought)
        {
            printf("you got your total in %d picks!",pickct-1);
            x=0;
            break;
        }
    }
}

//main function
int main()
{
    //print
    printf("Ball lottery\n");
    printf("------------\n");
    //main code
    long long sought,num;

    srand(time(NULL));

    sought = GetInt("Total sought : ",2,20);

    game(sought);

    return 0;
}
/*
###################
#   EXAMPLE:      #
###################
 Ball Lottery
 ============
 Total sought : 11
 Result of picks 1 and 2 : 1 + 3
 Result of picks 3 and 4 : 4 + 5
 Result of picks 5 and 6 : 6 + 3
 Result of picks 7 and 8 : 5 + 6
 You got your total in 8 picks!
 NOTICE: the result is differ every test
#########################*/