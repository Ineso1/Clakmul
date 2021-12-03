#include <iostream>
#include "Billing.h"
#include <string>
using namespace std;

//Ines Alejnadro
Billing::Billing(){
    cardNumber = "0000000000000000";
    address = "avenida xxxx";
    ccv = "000";
}

Billing::Billing(string _cardNumber, string _address, string _ccv){
    cardNumber = _cardNumber;
    address = _address;    
    ccv = _ccv;
}

string Billing::getAddress()const{
    return address;
}


string Billing::getCardNumber()const{
    return cardNumber;
}

string Billing::getCcv()const{
    return ccv;
}

void Billing::setAddress(string _address){
    address = _address;
}

void Billing::setCardNumber(string _cardNumber){
    cardNumber = _cardNumber;
}

void Billing::setCcv(string _ccv){
    ccv = _ccv;
}

void Billing::billingPrint(){
    cout << "Impresion de Factturacion\n";
    cout << "\nDireccion: " << address;
    cout << "\nNúmero de tarjeta: **** **** **** " << cardNumber[12] << cardNumber[13] << cardNumber[14] << cardNumber[15] << endl;
}