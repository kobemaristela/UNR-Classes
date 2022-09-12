public class ShaveIceDriver {
    public static void main(String[] args) {

        // Create Kiosk Ice Shop
        Shops iceKiosk = new Kiosk();

        iceKiosk.getOrder(); // Take ticket order number from user
        iceKiosk.getPayment();  // Take sale and cash amounts --> returns customer change (Cash Payment)

        // Create Store Ice Shop
        Shops iceStore = new Store();

        iceStore.getOrder(); // Generates order number
        iceStore.getPayment(); // Take sale and cash amounts --> returns customer change (Cash Payment)

        iceStore.setPayment(new CreditCard()); // Set payment to credit card

        iceStore.getOrder(); // Generates new order number
        iceStore.getPayment(); // Take credit card # and sale amount --> return sale and card # (Card Payment)
    }
}
