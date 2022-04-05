import java.util.Scanner;

public class exThree {

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String students[] = new String[10];
        for(int i = 0; i < 10; i++)
        {
            System.out.print("Enter studernt #" + i + "'s name: ");
            students[i] = in.nextLine();
        }

        for(int i = 0; i < 10; i++)
        {
            students[i].strip();
            String strbuffer[] = students[i].split(" ");     // yeash, oop is the BEST    
            for(int j = 0; j < strbuffer.length; j++)
            System.out.print(strbuffer[j].substring(0,1).toUpperCase() + strbuffer[j].substring(1,strbuffer[j].length()).toLowerCase() + " ");
            System.out.println();
        }
    }
}
 
// This is purely for testing purpose, just ignore it
/*
supersanta hibiki
something named
your name 
someoneelse's named
somethign somgthign
lmao lmaos
bruh bruh hib
lmao lmao lmaos
bruh bruh lmao lma
last one

*/