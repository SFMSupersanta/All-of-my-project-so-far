#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pc(int i)
{
    if(i<2) return 1;
    for (int j = 2; j <= sqrt(i); j++)
    {
        if(i % j == 0)
        {
          return 1;
        }
    } return 0;
}

int main() 
{
    
    printf("number = %d\n",pc(3));
    return(0);
}
