public class Checkout 
{
    private PaymentStrategy paymentStrategy;

    public void setPaymentStrategy(PaymentStrategy ps) 
    {
        this.paymentStrategy = ps;
    }
    public void processPayment(int amount) 
    {
        if (paymentStrategy != null) 
        {
            paymentStrategy.pay(amount);
        }
        else 
        {
            System.out.println("No payment method selected");
        }
    }
}