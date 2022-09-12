public class Computer implements Order {
    protected int myOrder = 0;

    public void makeOrder() {
        myOrder += 1;   // Assigns next integer 

        System.out.println("You are order number: " + myOrder + '\n');
    }
}
