#include <iostream>
#include "User.h"
using namespace std;
int main()
{
    User u1;
    //User(name,age,email,password,cardNumber,ccv,adress);
    User u2("Benjamin", 19,"benjagod@gmail.com","contrasena123","1234567891234567",023,"av.avenidacion");
    u2.PrintUser();
    cout << "-------------------------\n";
    u1.PrintUser();
    system("pause");
}