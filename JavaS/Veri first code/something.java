// My veri first java program
import java.util.Scanner;

public class something{
    public static void main(String[] args)
    {
        System.out.println("Type in your first name:");
        Scanner scan = new Scanner(System.in);
        User userA = new User();
        userA.firstName = scan.nextLine();
        System.out.println("Type in your last name:");
        userA.lastName = scan.nextLine();
        System.out.println("Hello " + userA.fullName());
        System.out.println("Type user " + userA.fullName() + "'s password");
        userA.password = scan.nextLine();
        System.out.println("UserA: " + userA.fullName() + "\nPassword: " + userA.password);
        System.out.println("Guess the password: ");
        String typedInPassword = scan.nextLine();
        if(userA.password.equals(typedInPassword) == true) System.out.println("You guessed it!!");
        else System.out.println("BOO, worng password!"); 
    }
}