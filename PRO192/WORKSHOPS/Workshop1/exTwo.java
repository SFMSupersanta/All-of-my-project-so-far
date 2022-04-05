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
