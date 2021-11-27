#include <iostream>
#include "User.h"
using namespace std;

User::User(){
    name = "Default";
    age = 1;
    email = "someone@email.com";
    password = "*********";
    address = "Street";
    cardNumber = "0000000000000000";
    ccv = 111;
}

User::User(string _name, int _age,string _email,string _password, string _cardNumber, int _ccv, string _address){
    name = _name;
    age = _age;
    email = _email;
    password = _password;
    cardNumber = _cardNumber;
    ccv = _ccv;
    address = _address;
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

string User::getPassword()const{
    return password;
}

string User::getCardNumber()const{
    return cardNumber;
}

int User::getCcv()const{
    return ccv;
}

string User::getAddress()const{
    return address;
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

void User::setPassword(string _password){
    password= _password;
}

void User::setAddress(string _address){
    address = _address;

}

void User::setCardNumber(string _cardNumber){
    cardNumber = _cardNumber;
}

void User::setCcv(int _ccv){
    ccv = _ccv;
}

//metodos

void User::PrintUser(){
    cout<< "Nombre: " << name << endl;
    cout << "Edad: " << age << endl;
    cout << "Correo electronico: " << email << endl;
    cout << "Contrasena: " << password <<endl;
    cout << "Numero de Tarjeta: " << cardNumber << endl;
    cout << "Direccion: " << address << endl;
}
