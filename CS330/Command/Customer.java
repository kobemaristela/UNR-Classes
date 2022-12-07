public class Customer {
    Waitress myWaitress;
    Command myOrder;

    public Customer(Waitress waitress) {
        this.myWaitress = waitress;
    }

    public void createOrder(Command order) {
        this.myOrder = order;
    }

    public void makeOrder() {
        myWaitress.takeOrder(myOrder);
    }

}
