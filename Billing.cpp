#include <iostream>
#include "Billing.h"
#include <string>
using namespace std;


Billing::Billing(){
    cardNumber = "0000000000000000";
    address = "avenida xxxx";
}

Billing::Billing(string _cardNumber, string _address){
    cardNumber = _cardNumber;
    address = _address;    
}

string Billing::getAddress()const{
    return address;
}


string Billing::getCardNumber()const{
    return cardNumber;
}

void Billing::setAddress(string _address){
    address = _address;
}

void Billing::setCardNumber(string _cardNumber){
    cardNumber = _cardNumber;
}


void Billing::billingPrint(){
    cout << "Impresion de Factturación\n";
    cout << "Direccion: " << address;
    cout << "Número de tarjeta: **** **** **** " << cardNumber[12] << cardNumber[13] << cardNumber[14] << cardNumber[15] << endl;
}