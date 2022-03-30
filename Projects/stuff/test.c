#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[256];
	int point;
} player;



int main()
{
	FILE *fP = fopen("test.txt","a+");
	char string[] = "supersanta;44\n";
	char buffer[256];
	fwrite(string, strlen(string), 1, fP);
	player player1;

	return 0;
}