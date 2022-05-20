import java.util.Arrays;
public class Operations {
    public Operations() {

    }
    public int[][] plusArrays() {
        Inputter input = new Inputter();
        int rows = input.inputInt("How many rows?(in range 1-100): ", 1,100);
        int cols = input.inputInt("How many columns?(in range 1-100): ",1,100);
        int arr1[][] = new int[rows][cols];
        int arr2[][] = new int[rows][cols];
        int result[][] = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr1[i][j] = input.inputInt("First matrix, row: " + (i+1) + " cols: " + (j+1) + "'s value: ", -10000000,10000000);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr2[i][j] = input.inputInt("Second matrix, row: " + (i+1) + " cols: " + (j+1) + "'s value: ", -10000000,10000000);
            }
        }
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        showArray(arr1, rows, "The first array:");
        showArray(arr2, rows, "The second array:");
        showArray(result, rows);
        return result;
    }
    public void multiplyArrays()
    {
        Inputter input = new Inputter();
        System.out.println("For the first matrix:");
        int rows = input.inputInt("How many rows?(in range 1-100): ", 1,100);
        int cols = input.inputInt("How many columns?(in range 1-100): ",1,100);
        int arr1[][] = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr1[i][j] = input.inputInt("First matrix, row: " + (i+1) + " cols: " + (j+1) + "'s value: ", -10000000,10000000);
            }
        }
        System.out.println("For the second matrix:");
        int rows2 = input.inputInt("How many rows for the second matrix (must be first matrix's cols) ", cols, cols);
        int cols2 = input.inputInt("How many columns?(in range 1-100): ",1,100);
        int arr2[][] = new int[rows2][cols2];
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                arr2[i][j] = input.inputInt("Second matrix, row: " + (i+1) + " cols: " + (j+1) + "'s value: ", -10000000,10000000);
            }
        }
        showArray(arr1, rows, "The first array:");
        showArray(arr2, rows2, "The second array:");
        int result[][] = new int[rows][cols2];
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols2; j++)
            {
                for(int k = 0; k < rows2; k++)
                {
                    result[i][j] += arr1[i][k] * arr2[k][j];
                    //System.out.println(arr1[i][k] + "*" + arr2[k][j]);
                }
            }
        }
        showArray(result, rows);
    }
    public void showArray(int arr[][], int rows, String msg)
    {
        System.out.println(msg);
        for(int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public void showArray(int arr[][], int rows)
    {
        System.out.println("The result array :");
        for(int i = 0; i < rows; i++) {
            System.out.println(Arrays.toString(arr[i]));
        }
    }
}