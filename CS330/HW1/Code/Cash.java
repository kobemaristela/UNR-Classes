import java.util.Currency;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.NumberFormat;
import java.util.Locale;

public class Cash implements Payment{
    protected BigDecimal cashSale = new BigDecimal("0.00");

    public void change(BigDecimal sale, BigDecimal payment){
        BigDecimal myChange = payment.subtract(sale);
        cashSale.add(sale);
        myChange.setScale(2, RoundingMode.HALF_EVEN);

        NumberFormat usd = NumberFormat.getCurrencyInstance(Locale.US);
        usd.setMinimumFractionDigits(1);
        usd.setMaximumFractionDigits(2);
        System.out.println("Returning change of " + usd.format(myChange.doubleValue()));
    }

    public void getSale(){
        NumberFormat usd = NumberFormat.getCurrencyInstance(Locale.US);
        usd.setMinimumFractionDigits(1);
        usd.setMaximumFractionDigits(2);
        
        System.out.println("Current Sale: " + usd.format(cashSale.doubleValue()));
    }

}
