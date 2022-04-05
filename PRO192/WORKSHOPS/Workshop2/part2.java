import java.util.Scanner;
public class part2 {
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        String input = new String();
        String partten = "PE123";
        boolean status = false;
        do
        {

            try
            {
                System.out.println("Input the string");
                input = in.nextLine();
                if(!input.equals(partten)) throw new Exception();
                System.out.println("The string is " + input);
                status = true;

            } catch(Exception e)
            {
                System.out.println("The string is invalid.");
            }

        }while(status == false);
    }
}
