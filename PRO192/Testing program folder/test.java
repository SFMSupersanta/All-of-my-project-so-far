import java.util.Scanner;

public class test {

    public static void main(String[] args) {
        int i = validatorInt("Type in an int", -100, 100);
        System.out.println(i);
    }

    public static int validatorInt(String ms, int min, int max) // hasNextInt() , hasNextDouble(), regex
    {
        Scanner sc = new Scanner(System.in);

        int Return = 0;
        do {
            System.out.print(ms);
            while (!sc.hasNextInt()) {
                System.out.println("Please type in an int!");
                sc.nextLine();
            }
            Return = sc.nextInt();
            if (Return < min || Return > max)
                System.out.println("Out of bound!");
        } while (Return < min || Return > max);
        sc.close();
        return Return;
    }
}
