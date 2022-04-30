package src;
import java.util.Scanner;
public class Inputter {
    public static Scanner sc = new Scanner(System.in);
    public int inputInt(String msg, int min, int max)
    {
        if(max < min) 
        {
            int temp = max;
            max = min;
            min = temp;
        }
        int input;
        System.out.println(msg);
        do
        {
            while(!sc.hasNextInt())
            {
                System.out.println("Input an int!");
                sc.nextLine();
            }
            input = sc.nextInt();
            if (input > max || input < min)
                System.out.println("Out of bound!");
        } while (input > max || input < min);
        sc.nextLine();
        return input;
    }
    public String inputNonBlankStr(String msg)
    {
        String input;
        System.out.println(msg);
        do
        {
            input = sc.nextLine();
            if(input == null)
            System.out.println("Cannot be blank");
        } while (input == null);
        return input;
    }
    public String inputPatten(String msg, String partten)
    {
        System.out.println(msg);
        String input;
        boolean match;
        do
        {
            input = sc.nextLine().trim();
            match = input.matches(partten);
            if(!match) System.out.println("Partten is not matched!");
        } while (!match);
        return input;
    }
}
