public class Store extends Shops{

    public Store() {
        myOrder = new Computer();
        myPayment = new Cash();

        this.display();
    }

    public void display() {
        System.out.print("Welcome to our Store! \n");
    }
}
