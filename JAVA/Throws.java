 import java.util.*;

 class saran extends Exception {
    saran(String s)
    {
        super(s);
    }
 }
 class Throws {
    static void display(int a) throws saran {
        if(a>18)
        {
            System.out.println("Eligible to vote");
        }
        else{
            throw new saran("Junior");
        }
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            try {
                display(a);
            }
            catch (Exception e) {
                System.out.println(e);
            }
        }
    }
 }

 