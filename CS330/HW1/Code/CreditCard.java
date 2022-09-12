import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;
import java.math.RoundingMode;

public class CreditCard implements Payment{
    private static Scanner reader = new Scanner(System.in);

    public void makePayment(){
        // Get credit card number
        System.out.print("Please enter credit card number: ");
        Integer myCreditCard = reader.nextInt();

        // Get sale amount
        System.out.print("Please enter sale amount: ");
        Double sale = reader.nextDouble();

        // Convert data types (double --> BigDecimal)
        BigDecimal creditSale = BigDecimal.valueOf(sale);
        creditSale.setScale(2, RoundingMode.HALF_EVEN);

        // Set currency to USD
        NumberFormat usd = NumberFormat.getCurrencyInstance(Locale.US);

        // Print out to user sale and card #
        System.out.println("Current Sale: " + usd.format(creditSale.doubleValue()));
        System.out.println("Charged to card credit #: " + myCreditCard + "\n");
    }
}
