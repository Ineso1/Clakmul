#ifndef BILLING_H
#define BILLING_H
#include <string>

class Billing{
    private:
        std::string cardNumber;
        std::string address;

    public: 
        //Constructores
        Billing();
        Billing(std::string,std::string);
        //Getters
        std::string getCardNumber() const;
        std::string getAddress() const;
        //Setters
        void setCardNumber(std::string);
        void setAddress(std::string);
        //Funciones
        void billingPrint();
};

#endif //BILLING_H