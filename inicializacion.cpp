#include <iostream>
#include "User.h"
#include "Billing.h"
#include <string>
using namespace std;
int main()
{
    User u1;
    //User(name,age,email,password,cardNumber,ccv,adress);
    User u2("Benjamin",19,"email@email.com","avenidacion","1234567891234567");
    u2.PrintUser();
    cout << "-------------------------\n";
    u1.PrintUser();
    /*Billing b1;
    Billing b2("1234567891234567","av.av");
    b1.billingPrint();
    b2.billingPrint();*/
    system("pause");
}

