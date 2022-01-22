/****************************************************************
`(*>﹏<*)′
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    {
    char filename[100];
    printf("Regression Analysis\n===================\nEnter the name of the data file : ");
    gets (filename);
    FILE *fileP = NULL;                                                          //initialize file pointer variable
    double data[100];
    fileP = fopen (filename,"r");
    if (fileP != NULL)
    {
        int count = 0;                                                           //seprate variable to count in while function
        while(fscanf (fileP, "%lf", &data[count]) !=EOF)                         //fscanf funtion return value "EOF" than terminate the loop
        {
            count++;
        }
        //test code:
        /*for (int i = 0; i < count; i++)
        {
            printf("%.2lf ", data[i]);
        }
        printf("\n");*/
        //test code end.
        printf("The number of data values read from this file was %d\n",count);
        printf("Their statistical mean is %.2lf\n",mean(data,count));
        printf("Their standard deviation is %.2lf", dev(data,count,mean(data,count)));
        fclose(fileP);
    }
    else printf("Failed to open the file for reading");
    return 0;
}

/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
text file: sample_2.dat
 9 28.4
15 29.3
24 37.6
30 36.2 
38 36.5
46 35.3
53 36.2 
60 44.1
64 44.8
76 47.2 
###################
#   EXAMPLE:      #
###################
 Regression Analysis
 ===================
 Enter the name of the data file : sample_2.dat

 The number of data values read from this file was 10
 Their statistical mean of the abscissa values is 41.50
 Their standard deviation of the abscissa values is 20.98 
 Their statistical mean of the ordinate values is 37.56
 Their standard deviation of the ordinate values is 5.92

 The slope of the least squares fit is 0.26
 The y-intercept of the least squares fit is 26.94
 The correlation coefficient is 0.91

 What is the age of your car in months ? 32
 You can expect a stopping distance of 35.13 metres
###########################################################*/