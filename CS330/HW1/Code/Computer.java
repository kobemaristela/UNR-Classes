public class Computer implements Order {
    protected int myOrder = 0;

    public void orderNumber() {
        myOrder += 1;   // Assigns next integer 

        System.out.println("Your order number: " + myOrder);
    }
}
