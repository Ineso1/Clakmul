#include <iostream>
#include <time.h>
#include "User.h"
#include "Billing.h"
#include "Product.h"
#include "ShoppingCart.h"
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

//Declaracion de variables globales y arreglos para precargar datos
const int MAXPROD = 20;
const int MAXUSER = 15;
Product catalogo[MAXPROD];
User users[MAXUSER];
int cuantos = 0;
int id = 0;

//Cargar datos a catalogo de productos 
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
    archivo.close();
}
//Cargar lista de usuarios y construir el objeto con datos de usuario 
void llenarListaUsuarios(User users[], int &cant){
    char delimitador = ',';
    string linea;
    string name,email,cardNumber,address,ccv;
    int age;
    ifstream archivo("Users.txt");
    //archivo.open("Users.txt");
    while(getline(archivo, linea)){
        stringstream stream (linea);
        getline(stream, name, delimitador);
        //getline(stream, age, delimitador);
        getline(stream, email, delimitador);
        getline(stream, cardNumber, delimitador);
        getline(stream, address, delimitador);
        getline(stream, ccv, delimitador);
        
        //Formato de llenado
        //name >> age >> email >> cardNumber >> address >> ccv
        users[cant].setName(name);
        //users[cant].setAge(age);
        users[cant].setEmail(email);
        users[cant].getBilling().setCardNumber(cardNumber);
        users[cant].getBilling().setAddress(address);
        users[cant].getBilling().setCcv(ccv);
        cant++;
    }
    archivo.close();
}

//Impresion de todos los productos 
void imprimeCatalogo(Product prod[], int cant){
    for (int i = 0; i < cant; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}

//Cargar lista de pedidos 
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

//Funcion de validacion de usuario ingresado
void Login(int &id){
    llenarListaUsuarios(users,cuantos);
    string userLogin = "";
    while(id == 0){ 
    system("cls");
    cout << "---------------Inicio de sesion---------------\n" << endl;
    cout << "USUARIO: "; 
    cin >> userLogin;
    
    for (int i=0 ; i <= MAXUSER; i++){
        if (users[i].getName() == userLogin){
            id = i+1; 
        }
    }
    if (id != 0){    
        cout << "\nBienvenido "<< users[id-1].getName();
        system("pause");
        break;
        }
    else{
        cout << "No hay cuenta creada como " << userLogin << " vuelve a ingresar otro nombre de usuario\n";
        }
    system("pause");
    }
}

//Lista de productos tecnologia
void tech(Product prod[]){
    for (int i = 0; i < 4; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}


void sports(){

}

void beauty(){

}

void pets(){
    
}

//Menu principal
void menu(){
    system("cls");
    system("clc");
    cout << "---------------Calakmul eSHOP---------------\n" << endl;
    cout << "\t1-Tecnologia\n\t2.Mascotas\n\t3.Belleza\n\t4.Deportes\n\t5.Mi cuenta\n\t6.Salir" <<endl;
    /*
    llenarCatalogo(catalogo, cuantos);
    llenarListaUsuarios(users,cuantos);
    imprimeCatalogo(catalogo, cuantos);
    */

}


//Programa principal
int main()
{   
    Login(id);
    menu();
    llenarCatalogo(catalogo,cuantos);
    int option = 0;
    while (option != 6){
        cout << "Ingrese la opcion que desea: ";
        cin >> option;
        switch (option){
            case 1:
                cout << "----------------------CATALOGO DE TECNOLOGIA----------------------";
                tech(catalogo);
                break;
            case 2:
                cout << "----------------------CATALOGO DE MASCOTAS----------------------";
                break;
            case 3:
                cout << "----------------------CATALOGO DE BELLEZA----------------------";
                break;
            case 4:
                cout << "----------------------CATALOGO DE DEPORTES----------------------";
                break;
            case 5:
                cout << "----------------------MI CUENTA----------------------";
                break;
            case 6:
                cout << "Nos vemos " << users[id-1].getName() << endl;
                cout << "Hora de cierre se seción: ";
                time_t current_time;
                struct tm * time_info;
                char timeString[9];
                time(&current_time);
                time_info = localtime(&current_time);
                strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
                puts(timeString);
                break;
            default:
                cout << "Ups! Hubo un erro en su ingreso de opcion, por favor, ¡intentelo de nuevo!";
                break;
        }
    } 
    

    /*Product catalogo[MAXPROD];
    int cuantos = 0;
    ShoppingCart miCarrito;
    llenarCatalogo(catalogo, cuantos);
    imprimeCatalogo(catalogo, cuantos);
    miCarrito = llenarCarrito(catalogo, cuantos);
    miCarrito.printTicket();*/
    system("pause");
    return 0;

}

