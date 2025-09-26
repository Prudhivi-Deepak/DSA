// Your code goes here

#include <bits/stdc++.h>
using namespace std;

class PaymentGateway{
public:
    virtual void processPayment(double amount)=0;
};

class CreditCardPayment : public PaymentGateway{

    // @Override
    public :
    void processPayment(double amount) override{
        cout << std::fixed << std::setprecision(2);
        cout << "Processing credit card payment of " << amount << endl;
    }
};

class UPIPayment : public PaymentGateway{

    // @Override
    public:
    void processPayment(double amount) override{
        cout << std::fixed << std::setprecision(2);
        cout << "Processing UPI payment of " << amount << endl;
    }
};



// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your abstract class `PaymentGateway` 
and the derived classes `CreditCardPayment` and `UPIPayment`.

If the payment method is credit card:
    It creates the object of class `CreditCardPayment`.
    It then calls the `processPayment` method of the `CreditCardPayment` class 
    and prints the corresponding text inside the method.

If the payment method is UPI:
    It creates the object of class `UPIPayment`.
    It then calls the `processPayment` method of the `UPIPayment` class 
    and prints the corresponding text inside the method.


int main() {
    vector<string> paymentMethods;
    vector<double> amounts;

    for (int j = 0; j < paymentMethods.size(); j++) {
        PaymentGateway* payment = nullptr;

        string method = paymentMethods[j];
        transform(method.begin(), method.end(), method.begin(), ::tolower);

        if (method == "credit") {
            payment = new CreditCardPayment();
        } else if (method == "upi") {
            payment = new UPIPayment();
        }

        payment->processPayment(amounts[j]);
        delete payment;
    }

    return 0;
}

*/


/*
// Below are the output statements:

cout << fixed << setprecision(2);
cout << "Processing credit card payment of " << amount << endl;

cout << fixed << setprecision(2);
cout << "Processing UPI payment of " << amount << endl;
*/
