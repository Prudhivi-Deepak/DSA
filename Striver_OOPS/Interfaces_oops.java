package Striver_OOPS;

//Your code goes here

interface PaymentGateway{
    public void processPayment(double amount);
}

class CreditCardPayment implements PaymentGateway{

    @Override
    public void processPayment(double amount){
        System.out.printf("Processing credit card payment of %.2f\n",amount);
    }
}

class UPIPayment implements PaymentGateway{

    @Override
    public void processPayment(double amount){
        System.out.printf("Processing UPI payment of %.2f\n",amount);
    }
}


//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your abstract class `PaymentGateway` and the drived classes 'CreditCardPayment', 'UPIPayment'.

If the Payement Method is credit card then
    It creates the object of class CreditCardPayment.
    It then calls the processPayment method of the CreditCardPayment class and prints th corresponding text in the method.
    
If the Payement Method is upi then
    It creates the object of class UPIPayment.
    It then calls the processPayment method of the UPIPayment class and prints th corresponding text in the method.


public class Main {

    public static void main(String[] args) {
    
        Scanner scanner = new Scanner(System.in);
            
        List<String> paymentMethods;
        List<Double> amounts;

        for (int j = 0; j < paymentMethods.size(); j++) {
        
            PaymentGateway payment = null;

            String method = paymentMethods.get(j);
            if (method.equalsIgnoreCase("credit")) {
                payment = new CreditCardPayment();
            } 
            else if (method.equalsIgnoreCase("upi")) {
                payment = new UPIPayment();
            }

            payment.processPayment(amounts.get(j));
        }

        scanner.close();
    }
}

*/

/*
//Below are the output statements

System.out.printf("Processing credit card payment of %.2f%n", amount);
System.out.printf("Processing UPI payment of %.2f%n", amount);

*/