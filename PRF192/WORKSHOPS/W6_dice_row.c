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
void clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

//GetInt(char str[], long long min, long long max) returns long long from min to max
long long  GetInt(char msg[], long long  min, long long max)
{
    long long value;
    int rc;

    while (true) 
    {
        printf ("%s", msg);
        //printf("in the range [%lld,%lld] : ",min, max);
        rc = scanf ("%lld",&value);
        if (rc == 0)
        {
            printf ("**No input accepted!**\n");
            clear ();
        }
        else if (getchar() != '\n')
        {
            printf( "**Trailing characters!**\n");
            clear ();
        }
        else if (value < min || value > max)
        {
            printf ("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

//\random number generator\* 
int ran_gen()
{  
    return rand()%6; //randnum 0-5
}

//\game function\*
void game (int sought)
{
    int x = 1,count = 0,first,second;

    while(x == 1)
    {
        count ++;
        first = ran_gen() +1;
        second = ran_gen() +1;
        printf ("Result of throw  %d : %d + %d\n", count,first,second);
        if (first + second == sought)
        {
            printf ("you got your total in %d throw!",count);
            x = 0;
            break;
        }
    }
}

int main()
{
    //print
    printf ("Dice Thrower\n");
    printf ("------------\n");
    //main code
    long long sought,num;

    srand (time(NULL));

    sought = GetInt ("Total sought : ",2,12);
    
    game (sought);

    return 0;
}
/*###################
////////////////////////////////////////////////////////////////
Design and code a program that throws two dice until the top 
faces of the two dice total to a specified number.  The values 
on each die range from one to six inclusive.  Your program 
prompts for and accepts the total number sought, includes input 
validation and uses both your own and standard library functions. 

Design your program according to structured design principles 
and write your own functions so that you can readily use them in 
other applications. 

Preface your function headers with comprehensive descriptions of 
function purpose, function parameters and function return value.

The output from your program looks something like: 

 Dice Thrower
 ============
 Total sought : 11
 Result of throw  1 : 1 + 3
 Result of throw  2 : 4 + 4
 Result of throw  3 : 6 + 2
 Result of throw  4 : 5 + 6
 You got your total in 4 throws!
****************************************************************/