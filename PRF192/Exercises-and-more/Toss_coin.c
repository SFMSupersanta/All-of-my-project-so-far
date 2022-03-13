/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: Coin toss
version #
////////////////////////////////////////////////////////////////
simulate n times of tossing coins
****************************************************************/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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
        printf("%s", msg);
        printf("in the range [%lld,%lld] : ",min, max);
        rc = scanf("%lld",&value);
        if(rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if(getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

//\choice validation\    getchar(char str[])
char GetChar(char str[])
{
    char choice;                             
    while(true)
    {
        printf("%s", str);
        choice=getchar();
        if (choice == 'y'||choice == 'Y'||choice =='n'||choice == 'N') 
        {
            if(getchar() == '\n')break;
            else 
            {
                printf("Invalid input!\n");
                clear();
            }
        }
        else 
        {
            printf("Invalid input!\n");
            clear();
        }
    }
    return choice;
}

//\result array print function\*
void coindump(bool data[],int times)
{
    int count = 0;
    for(int i = 0; i < times; i++)
    {
        if(data[i] == true)      //0
        {
            printf("Head\t");
            count++;
        }
        else if(data[i] == false)//1
        {
            printf("Tail\t");
            count++;
        }
        if (count%10==0&&count!=0)//newline for every n output, change n for difference output
        {
            printf("\n");
        }
    }
    printf("\n");
}

//\coin toss simulation funtion\  gamestart(&value,&value,bool arr[])
void gamestart(int *head, int *tail, long long times, bool data[])
{
    for (int i = 0; i < times; i++)     //simulation loop
    {
        bool coin = rand() % 2;         //value is either 0 or 1
        if (coin == true)
        {
            data[i] = coin;            //result array assign
            *head=*head+1;             //pointer value accending
        }else
        {
            data[i] = coin;
            *tail=*tail+1;
        }
    }
    printf("Ingame head,tail,times: %d %d %lld", *head, *tail, times);
}

//main function
int main()
{
    srand(time(NULL));                               //time seed 
    int head=0, tail=0;
    while(true)
    {
        //get toss time
        long long times = GetInt("Input toss times\n",0,1000000);
        printf("times: %d\n",times);
    
        //toss data array
        bool data[times];  
    
        //game function                                 
        gamestart(&head, &tail, times, data);
    
        //result print
        printf("The percentage of head result is %.2lf%%\n",(double)head*100/times);
        printf("The percentage of tail result is %.2lf%%\n",(double)tail*100/times);
    
        //result sheet print
        char ans = GetChar("Do you want to see the results sheet? (y/Y for yes, n/N for no): ");
        
        //print data array
        if(ans == 'Y' || ans == 'y')
        {
            coindump(data, times);
            printf("Number of head toss: %d\nNumber of tail toss: %d\n",head,tail);
        }
        char choice = GetChar("\nDo you want to Replay? (y/Y for yes, n/N for no): ");
        if(choice == 'N' || choice == 'n') break;  
    }

    return 0;
}
