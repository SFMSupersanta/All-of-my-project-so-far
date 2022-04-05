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
