/*Part 2: [3 points]
Write a Java program that will accept two float numbers and an operator (+-* //) then the program will print out the result of the specified expression that bases on the inputted operator.
The user interface may be
Input the number 1 4
Input the number 2 5
Input the operator +
the result of 4+5=9
*/

import java.util.Scanner;
public class exTwo {

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Input 1st number: ");
        double numOne = in.nextDouble();
        System.out.print("Input 2nd number: ");
        double numTwo = in.nextDouble();
        System.out.print("Input the operator (+-*/) : ");
        String operator;
        in.nextLine();
        operator = in.nextLine();

        switch (operator)
        {
            case "+":
                System.out.println("The results of " + numOne + operator + numTwo + "=" + (numOne + numTwo));
            break;
            case "-":
                System.out.println("The results of " + numOne + operator + numTwo + "=" + (numOne - numTwo));
            break;
            case "*":
                System.out.println("The results of " + numOne + operator + numTwo + "=" + (numOne * numTwo));
            break;
            case "/":
                System.out.println("The results of " + numOne + operator + numTwo + "=" + (numOne / numTwo));
            break;
        }
        
    }
    
}
