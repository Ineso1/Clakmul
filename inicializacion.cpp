#include <iostream>
#include "User.h"
#include "Billing.h"
#include "Product.h"
#include "ShoppingCart.h"
#include <string>
#include <fstream>
using namespace std;

void menu(){
    cout << "---------------Calakmul eSHOP---------------\n" << endl;
}

const int MAXPROD = 15;
void llenarCatalogo(Product prod[], int &cant){
    float precio;
    string nombre;
    ifstream archivo;
    archivo.open("Products.txt");
    while(archivo >> nombre >> precio){
        prod[cant].setName(nombre);
        prod[cant].setPrice(precio);
        cant++;
    }
}

void imprimeCatalogo(Product prod[], int cant){
    for (int i = 0; i < cant; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}

ShoppingCart llenarCarrito(Product cat[], int cant){
    int respuesta = 1;
    int numeroProducto;
    int cantidad;
    ShoppingCart nuevo;
    while (respuesta == 1 && nuevo.getAmountProduct() < 3){
        cout << "Catalogo de productos" << endl;
        imprimeCatalogo(cat, cant);
        cout << "Numero de producto a comprar: ";
        cin >> numeroProducto;
        cout << "Cantidad: ";
        cin >> cantidad;
        nuevo.addProduct(cat[numeroProducto - 1], cantidad);
        cout << "Quieres agregar otro producto 1-sí";
        cin >> respuesta;
    }
    return nuevo;
}


int main()
{
    menu();
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

    Product catalogo[MAXPROD];
    int cuantos = 0;
    ShoppingCart miCarrito;
    llenarCatalogo(catalogo, cuantos);
    imprimeCatalogo(catalogo, cuantos);
    miCarrito = llenarCarrito(catalogo, cuantos);
    miCarrito.printTicket();

    system("pause");
}

