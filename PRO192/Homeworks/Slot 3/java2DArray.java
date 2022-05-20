
public class java2DArray {
    public static void main(String[] args) {
        String cliff = "---------------------------------------------";
        Inputter input  = new Inputter();
        Operations operate = new Operations();
        int choice;
        do
        { 
            choice = input.inputInt("Type (1) to plus 2 arrays.\nType (2) to multiply 2 arrays.\nType (3) to quit.\n", 1,3);   
            switch (choice) {
                case 1:
                System.out.println(cliff);
                operate.plusArrays();
                System.out.println(cliff);
                break;
                case 2:
                System.out.println(cliff);
                operate.multiplyArrays();
                System.out.println(cliff);
                break;
                case 3:
                System.out.println("Have a great day!!");
                break;
            }
        } while(choice != 3);
    }
}
