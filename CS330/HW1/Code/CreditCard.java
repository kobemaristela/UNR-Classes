import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Locale;

public class CreditCard implements Payment{
    protected BigDecimal creditSale = new BigDecimal("0.00");
    protected double myCreditCard;

    public void cardPayment(BigDecimal sale, double card){
        myCreditCard = card;
        creditSale.add(sale);
    }

    public void getSale(){
        NumberFormat usd = NumberFormat.getCurrencyInstance(Locale.US);
        usd.setMinimumFractionDigits(1);
        usd.setMaximumFractionDigits(2);
        
        System.out.println("Current Sale: " + usd.format(creditSale.doubleValue()));
    }
}
