import java.util.Scanner;

public class Ticket implements Order {
    private static Scanner reader = new Scanner(System.in);

    public void makeOrder() {
        System.out.print("Please enter the order number: ");
        Integer myOrder = reader.nextInt();
        
        System.out.println("You are order number: " + myOrder);
    }
    
}
