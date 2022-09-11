public abstract class Shops{
    Order myOrder;
    Payment myPayment;

    public Shops(){
    }

    public void getOrder() {
        myOrder.order();
    }

    public void mySale(){
        myPayment.getSale();
    }

}