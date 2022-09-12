public abstract class Shops{
    Order myOrder;
    Payment myPayment;

    protected Shops(){
    }

    public void getOrder() {
        myOrder.makeOrder();
    }

    public void getPayment(){
        myPayment.makePayment();
    }
    
    // Set payment and order dynamically
    public void setPayment(Payment sale) {
        myPayment = sale;
    }

    public void setOrder(Order order) {
        myOrder = order;
    }

}