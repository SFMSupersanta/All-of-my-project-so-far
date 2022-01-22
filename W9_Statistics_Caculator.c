/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double mean(double data[], int size)
{
    double sum;
    for (int i = 0; i < size;i++)
    {
        sum += data[i];
    }
    sum /= size;
    return sum;
}

double dev(double data[], int size, double m)
{
    double Ssum=0;                        //squared sum variable
    for (int i = 0; i < size;i++)
    {
        Ssum += data[i]*data[i];
    }
    double deviation = (Ssum / size) - (m*m);
    return sqrt(deviation);
}

int main()
{
    char filename[100];
    printf("Statistics Calculator\n=====================\nEnter the name of the data file : ");
    gets (filename);
    FILE *fileP = NULL;                                                      //initialize file pointer variable
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
text file: sample_1.dat
5.4
6.5
6.8
7.1
6.4
5.6
5.7
6.6
5.0
7.3
8.2
8.4
9.2
8.8
7.6
9.4
10.9
12.4
12.1
10.9
9.0
10.3
9.8
8.2
6.4
4.9
6.6
8.0
10.0
11.4
10.8
9.3
10.0
9.1
9.5
6.0
5.1
4.2
6.2
###################
#TEST CASE(ctrc+v)#
###################
   BTP100   is not    that  hard!
###################
#   EXAMPLE:      #
###################
 Statistics Calculator
 =====================
 Enter the name of the data file : sample_1.dat 

 The number of data values read from this file was 39 
 Their statistical mean is 8.08
 Their standard deviation is 2.15
###########################################################*/