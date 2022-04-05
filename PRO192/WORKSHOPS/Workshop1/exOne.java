/*Part1: [3 points]

Write a Java program that will accept a matrix of integers then this matrix will be printed out and sum of values and average of values are printed also.

The user interface may be:
Enter number of rows: 2
Enter number of columns: 3
Enter the matrix
m[0][0]=1
m[0][1]=2
m[0][2]=3
m[1][0]=4
m[1][1]=5
m[1][2]=6
Matrix inputted:
1 2 3
4 5 6
Sum: 21
Average: 3.5

Hint: Use System.out.format("%3d", n);*/

import java.util.Scanner;

public class exOne {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Type in the rows: ");
        int rows = scanner.nextInt();
        System.out.print("Type in the columns: ");
        int cols = scanner.nextInt();

        int matrix[][] = new int[rows][cols];
        int sum = 0;
        
        for(int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++)
            {
                System.out.print("Matrix[" + i + "][" + j + "] = ");
                matrix[i][j] = scanner.nextInt();
                sum += matrix[i][j];
            }
        }

        for(int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++)
            {
                System.out.format("%3d", matrix[i][j]);
            }
            System.out.println();
        }
        System.out.println("Sum : " + sum);
        System.out.println("Averge : " + (double)sum / ((double)rows * (double)cols));
    }
    
}
