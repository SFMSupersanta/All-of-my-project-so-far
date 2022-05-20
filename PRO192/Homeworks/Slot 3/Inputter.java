

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
        
        do
        {
            System.out.print(msg);
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
}
