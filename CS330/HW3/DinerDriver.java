public class DinerDriver {
    public static void main(String[] args) {
        Waitress waitress = new Waitress();
        ShortOrderCook cook = new ShortOrderCook();
        Customer customer = new Customer(waitress);

        // Make burger
        BurgerCommand burger = new BurgerCommand(cook);
        customer.createOrder(burger);
        customer.makeOrder();

        // Make shake
        ShakeCommand shake = new ShakeCommand(cook);
        customer.createOrder(shake);
        customer.makeOrder();
    }
}