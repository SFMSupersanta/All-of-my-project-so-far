#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

	remove("ENG.txt");
	remove("FRA.txt");
	remove("GER.txt");
	remove("ITL.txt");
	remove("SPN.txt");
	
	FILE *Score = fopen("score.txt", "r");
	if( Score == NULL ) { printf("Failed to open score.txt");}
	FILE *Eng = fopen( "ENG.txt", "a+");
	if(Eng == NULL){printf("Failed to open ENG.txt");}
	FILE *Ger = fopen( "GER.txt", "a+");
	if(Ger == NULL){printf("Failed to open GER.txt");}
	FILE *Fra = fopen( "FRA.txt", "a+");
	if(Fra == NULL){printf("Failed to open FRA.txt");}
	FILE *Spn = fopen( "SPN.txt", "a+");
	if(Spn == NULL){printf("Failed to open SPN.txt");}
	FILE *Itl = fopen( "ITL.txt", "a+");
	if(Itl == NULL){printf("Failed to open ITL.txt");}

	char cntry[100][5], name[100][255];     // strings
	int matches[100], wins[100], losses[100]; // arrays
	int count = 0;   // count var


	do
	{
		fscanf(Score, "%[^;];", &cntry[count]);
		fscanf(Score, "%[^;];", &name[count]);
		fscanf(Score, "%d;", &matches[count]);
		fscanf(Score, "%d;", &wins[count]);
		fscanf(Score, "%d;", &losses[count]);
		fgetc(Score);
		count++;
	} while (!feof(Score));
	


	for(int i = 0; i < count; i++)
	{ 
		if(strcmp("ENG", cntry[i]) == 0)
		{ 
			fprintf(Eng, "%s;", cntry[i]);
			fprintf(Eng, "%s;", name[i]);
			fprintf(Eng, "%d;", matches[i]);
			fprintf(Eng, "%d;", wins[i]);
			fprintf(Eng, "%d\n", losses[i]);
		}
		else if(strcmp("GER", cntry[i]) == 0)
		{ 
			fprintf(Ger, "%s;", cntry[i]);
			fprintf(Ger, "%s;", name[i]);
			fprintf(Ger, "%d;", matches[i]);
			fprintf(Ger, "%d;", wins[i]);
			fprintf(Ger, "%d\n", losses[i]);
		}
		else if(strcmp("FRA", cntry[i]) == 0)
		{
			fprintf(Fra, "%s;", cntry[i]);
			fprintf(Fra, "%s;", name[i]);
			fprintf(Fra, "%d;", matches[i]);
			fprintf(Fra, "%d;", wins[i]);
			fprintf(Fra, "%d\n", losses[i]);
		}
		else if(strcmp("SPN", cntry[i]) == 0)
		{ 
			fprintf(Spn, "%s;", cntry[i]);
			fprintf(Spn, "%s;", name[i]);
			fprintf(Spn, "%d;", matches[i]);
			fprintf(Spn, "%d;", wins[i]);
			fprintf(Spn, "%d\n", losses[i]);
		}
		else if(strcmp("ITL", cntry[i]) == 0)
		{ 
			fprintf(Itl, "%s;", cntry[i]);
			fprintf(Itl, "%s;", name[i]);
			fprintf(Itl, "%d;", matches[i]);
			fprintf(Itl, "%d;", wins[i]);
			fprintf(Itl, "%d\n", losses[i]);
		}
	}
	

	fclose(Score);
	fclose(Eng);
	fclose(Ger);
	fclose(Fra);
	fclose(Spn);
	fclose(Itl);
	return 0;

}