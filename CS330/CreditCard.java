
public class CreditCard implements Payment{
    private String creditCard;
    private double money;

    public void payment(double sale){
        System.out.println("Paying with credit card...");
        this.money = sale;
    }

    public void setCreditCard(String card) {
        this.creditCard = card;
    }
}
