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


double slope(int arrx[], double arry[], int n, int Mx, double My)     //function to caculate slope
{
    double nominator = 0,denominator = 0;
    for (int i = 0; i < n; i++)
    {
        nominator += (arrx[i]-Mx)*(arry[i]-My);
        denominator += (arrx[i]-Mx)*(arrx[i]-Mx);
    }
    return nominator/(denominator);
}

double pmcc(int arrx[], double arry[], double n, int Mx, double My, int Dx, double Dy)//pearson or product-moment correlation coefficient
{
    double tpros;//total product sum
    for (int i = 0; i <n;i++)
    {
        tpros = arrx[i]*arry[i];
    }
    return ((tpros/(n-(Mx*Mx)))/(Dx*Dy));
}

double deviation(double Sx, int n, double MxS)    
{
    return sqrt((Sx/n)-MxS);
}

int deviationi(int Sx, int n, int MxS)    
{
    return sqrt((Sx/n)-MxS);
}

int meani(int data[], int size)
{
    int sum;
    for (int i = 0; i < size;i++)
    {
        sum += data[i];
    }
    sum /= size;
    return sum;
}

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

int Ssumi(int data[], int size)     //sum of squares
{
    int Ssum=0;                        //squared sum variable
    for (int i = 0; i < size;i++)
    {
        Ssum += data[i]*data[i];
    }
    
    return Ssum;
}

double Ssum(double data[], int size)     //sum of squares
{
    double Ssum=0;                        //squared sum variable
    for (int i = 0; i < size;i++)
    {
        Ssum += data[i]*data[i];
    }
    
    return Ssum;
}

int main()
{
    char filename[100];
    printf("Regression Analysis\n===================\nEnter the name of the data file : ");
    gets (filename);
    FILE *fileP = NULL;                                                          //initialize file pointer variable
    fileP = fopen (filename,"r");
    if (fileP != NULL)
    {
        int x_val[100];
        double y_val[100];
        char c;
        int rec_count = 0;                                                           //seprate variable to count in while function
        do
        {
            c = fgetc (fileP);
            if (c == '\n') rec_count++;
        }while(!feof (fileP));
        //printf ("rec_count: %d\n", rec_count);

        rewind (fileP);

        for (int i = 0; i <= rec_count; i++)
        {
            fscanf(fileP, "%d", &x_val[i]);
            fscanf(fileP, "%lf", &y_val[i]);
        }
        
        printf("The number of data values read from this file was %d",rec_count);

        //test code:
        /*for(int i = 0; i <= rec_count; i++)
        {
            printf("x: %lf, y: %lf", x_val[i], y_val[i]);
            printf("\n");
        }*/
        //test code end.
        
        int Mx = meani(x_val,rec_count);
        double My = mean(y_val,rec_count);
        int Sx = Ssumi(x_val,rec_count);
        double Sy = Ssum(y_val,rec_count);
        int Dx = deviationi(Sx, rec_count, Mx*Mx);
        double Dy = deviation(Sy, rec_count, My*My);
        /*
        printf("Their statistical mean of the abscissa values is %.2lf\n",);
        printf("Their standard deviation of the abscissa values is %.2lf\n",);
        printf("Their statistical mean of the ordinate values is %.2lf\n",);
        printf("Their standard deviation of the ordinate values is %.2lf\n",);
        */
        double t=slope(x_val,y_val,rec_count,Mx,My);
        printf("\nThe slope of the least squares fit is %lf\n",t);
        printf("The y-intercept of the least squares fit is  %.2lf\n", My-t*Mx);
        printf("The correlation coefficient is %.2lf\n", pmcc(x_val,y_val,rec_count,Mx,My,Dx,Dy));

        printf("\nWhat is the age of your car in months ? ");
        int age;
        scanf("%d",&age);
        //printf("You can expect a stopping distance of ")

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