import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.NumberFormat;
import java.util.Locale;

public class Cash implements Payment{
    private static Scanner reader = new Scanner(System.in);

    public void makeSale(){
        // Get credit card number
        System.out.print("Please enter sale amount: ");
        Double sale = reader.nextDouble();

        // Get sale amount
        System.out.print("Please enter cash payment amount: ");
        Double cash = reader.nextDouble();

        // Logic Statement
        if (sale > cash){
            System.out.println("Cash payment not enough...");
            return;
        }

        // Convert data types (double --> BigDecimal)
        BigDecimal cashSale = BigDecimal.valueOf(sale);
        BigDecimal myCash = BigDecimal.valueOf(cash);

        BigDecimal myChange = myCash.subtract(cashSale);    // Get change
        myChange.setScale(2, RoundingMode.HALF_EVEN); // Round value

        // Set currency to USD
        NumberFormat usd = NumberFormat.getCurrencyInstance(Locale.US);

        // Print out to user sale and card #
        System.out.println("You have a change of " + usd.format(myChange.doubleValue()) + "\n");
    }
}
