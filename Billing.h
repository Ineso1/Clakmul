#ifndef BILLING_H
#define BILLING_H
#include <string>
//Ines Alejandro
class Billing{
    private:
        std::string ccv; 
        std::string cardNumber;
        std::string address;

    public: 
        //Constructores
        Billing();
        Billing(std::string,std::string,std::string);
        //Getters
        std::string getCardNumber() const;
        std::string getAddress() const;
        std::string getCcv() const;
        //Setters
        void setCardNumber(std::string);
        void setAddress(std::string);
        void setCcv(std::string);
        //Funciones
        void billingPrint();
};

#endif //BILLING_H