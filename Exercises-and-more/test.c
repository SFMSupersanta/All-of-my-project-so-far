#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
    char *s = (char*)malloc(sizeof(char) * 17);
	s = "bruhbruhlmaolmao";
    //printf("%d\n", strlen(s));
    char *temps = (char*)malloc(sizeof(char) * strlen(s));
    memcpy(temps, s+8, 9);
    //printf("%s\n",temps);
    
    s = (char*)realloc(s, sizeof(char) * 18);  
    printf("%s\n",s);
    
    s[8] = '\n';

    memcpy(s+10, temps, strlen(temps));
    
    return(0);
}
