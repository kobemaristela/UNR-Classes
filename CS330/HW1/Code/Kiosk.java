public class Kiosk extends Shops{

    public Kiosk() {
        myOrder = new Ticket();
        myPayment = new Cash();

        this.display();
    }

    public void display() {
        System.out.println("Welcome to our Kiosk! \n");
    }
}
