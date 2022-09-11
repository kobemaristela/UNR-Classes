import java.util.Scanner;

public class Ticket implements Order {
    protected int myOrder;

    public void orderNumber() {
        Scanner reader = new Scanner(System.in);
        System.out.println("Please enter the order number: ");
        myOrder = reader.nextInt(); 
        reader.close();

        System.out.println("Your order number: " + myOrder);
    }
    
}
