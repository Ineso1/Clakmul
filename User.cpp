#include <iostream>
#include "User.h"
#include "Billing.h"
#include <string>
using namespace std;

User::User(){
    name = "Default";
    age = 1;
    email = "someone@email.com";
 
}

User::User(string _name, int _age,string _email, string _address, string _cardNumber){
    name = _name;
    age = _age;
    email = _email;
    billing.setAddress(_address);
    billing.setCardNumber(_cardNumber);
}


//Seccion de Getters

string User::getName()const{
    return name;
}

int User::getAge()const{
    return age;
}

string User::getEmail()const{
    return email;
}

//Seccion de Setters 

void User::setName(string _name){
    name = _name;
}

void User::setAge(int _age){
    age= _age;
}

void User::setEmail(string _email){
    email = _email;
}


//metodos

void User::PrintUser(){
    cout<< "Nombre: " << name << endl;
    cout << "Edad: " << age << endl;
    cout << "Correo electronico: " << email << endl;
    billing.billingPrint();
}
