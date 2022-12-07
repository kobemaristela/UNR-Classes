public class Waitress {
    Command orderSlip;

    public Waitress () {}

    public void takeOrder (Command order) {
        this.orderSlip = order;
        orderSlip.orderUp();
    }
}