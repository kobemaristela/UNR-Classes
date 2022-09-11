public abstract class Shops{
    Order myOrder;
    Payment myPayment;

    protected Shops(){
    }

    public void getOrder() {
        myOrder.orderNumber();
    }

    public void mySale(){
        myPayment.getSale();
    }

}