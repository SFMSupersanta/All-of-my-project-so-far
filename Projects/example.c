
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    return '1';
}

int main()
{
    srand(time(NULL));
	char rank_draw[2];
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

	if(compare_arr(rank_draw,"10")==true)
	printf("true");
	else printf("false");

    //game(suit,rank);
    
    //main code
}