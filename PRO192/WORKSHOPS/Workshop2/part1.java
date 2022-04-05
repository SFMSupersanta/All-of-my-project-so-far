/*Write a Java program to accept a number and print out it. If the number is below 1 then a message “the number is invalid” is printed out. Using do..while to input again, try-catch block to handle errors. 

The user interface may be:
Enter the number: - 2
The number is invalid”
Enter the number: world
The number is invalid”
Enter the number: 2
The number is 2
*/
import java.util.Scanner;
public class part1 {

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int input;
        boolean status = false;
        do
        {

            try
            {
                System.out.println("Input the number");
                input = in.nextInt();
                if(input < 1) throw new Exception();
                System.out.println("The number is " + input);
                status = true;

            } catch(Exception e)
            {
                System.out.println("The number is invalid.");
            }

        }while(status == false);
    }
    
}
