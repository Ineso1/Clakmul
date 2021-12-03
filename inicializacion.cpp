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

//Link para acceso a Github:
//https://github.com/Ineso1/Clakmul.git

                                                                        //Ines Alejandro

//Declaracion de variables globales y arreglos para cargar datos a las matrices declaradas
const int MAXPROD = 20;
const int MAXUSER = 15;
Product catalogo[MAXPROD];
User users[MAXUSER];
//ShoppingCart miCarrito;
int cuantos = 0;
int id = 0;
                                                                        //Ines Alejandro
//Cargar datos a catalogo de productos                                  
void llenarCatalogo(Product prod[], int &cantProductos){
    float precio;
    string nombre;
    ifstream archivo;
    archivo.open("Products.txt");
    while(archivo >> nombre >> precio){
        prod[cantProductos].setName(nombre);
        prod[cantProductos].setPrice(precio);
        cantProductos++;
    }
    archivo.close();
}                                                                       //Ines Alejandro
//Cargar lista de usuarios y construir el objeto con datos de los usuarios    
void llenarListaUsuarios(User users[], int &cantUsuarios){
    char delimitador = ',';
    string linea;
    string name,email,cardNumber,address,ccv,age;
    ifstream archivo("Users.txt");
    //archivo.open("Users.txt");
    while(getline(archivo, linea)){
        stringstream stream (linea);
        getline(stream, name, delimitador);
        getline(stream, age, delimitador);
        getline(stream, email, delimitador);
        getline(stream, cardNumber, delimitador);
        getline(stream, address, delimitador);
        getline(stream, ccv, delimitador);
        
        //Formato de llenado
        //name >> age >> email >> cardNumber >> address >> ccv
        users[cantUsuarios].setName(name);
        users[cantUsuarios].setAge(age);
        users[cantUsuarios].setEmail(email);
        users[cantUsuarios].setBilling(cardNumber,address,ccv);
        cantUsuarios++;
    }
    archivo.close();
}
                                                                        //Benjamin Gutierrez
//Impresion de todos los productos 
void imprimeCatalogo(Product prod[], int cantProductos){
    for (int i = 0; i < cantProductos; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}
                                                                        //Ines Alejandro
//Cargar lista de pedidos  (generar nuevo objeto shoppin cart para remplazar)
ShoppingCart llenarCarrito(Product cat[], int cantProductos){
    int respuesta = 1;
    int numeroProducto;
    int cantidad;
    ShoppingCart nuevo;
    while (respuesta == 1 && nuevo.getAmountProduct() < 3){
        cout << "Catalogo de productos" << endl;
        imprimeCatalogo(cat, cantProductos);
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
                                                                        //Ines Alejandro
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
        cout << "\nBienvenido "<< users[id-1].getName() << endl << endl;
        system("pause");
        break;
        }
    else{
        cout << "No hay cuenta creada como " << userLogin << " vuelve a ingresar otro nombre de usuario\n"<<endl;
 
        }
    system("pause");
    }
}
                                                                        //Benjamin Gutierrez
//Lista de productos tecnologia en rango correspondiente
void tech(Product prod[]){
    cout << "\n"; 
    for (int i = 0; i < 5; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}
                                                                        //Benjamin Gutierrez
//Lista de productos deportes en rango correspondiente
void sports(Product prod[]){
    cout << "\n"; 
    for (int i = 5; i < 10; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}
                                                                        //Benjamin Gutierrez
//Lista de productos bellezaen rango correspondiente
void beauty(Product prod[]){
    cout << "\n"; 
    for (int i = 10; i < 15; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}
                                                                        //Benjamin Gutierrez
//Lista de productos mascotas en rango correspondiente
void pets(Product prod[]){
    cout << "\n"; 
    for (int i = 15; i < 20; i ++){
        cout << i + 1 << ". ";
        prod[i].printProduct();
        cout << endl;
    }
}
                                                                        //Benjamin Gutierrez//InesAlejandro
//Menu principal
void menu(){
    system("cls");
    system("clc");
    cout << "---------------Calakmul eSHOP---------------\n" << endl;
    cout << "\t1-Tecnologia\n\t2.Mascotas\n\t3.Belleza\n\t4.Deportes\n\t5.Catalogo Comopleto\n\t6.Mi cuenta\n\t7.Salir" <<endl;
}
                                                                        //Ines Alejandro
//Funcion para hacer la compra mediante el  catalogo
void ProcesoCompra(Product prod[]){
    ShoppingCart miCarrito;
    int numProducto = 0, cantidadProductos = 0;
    char respuesta = 's';
    while (respuesta == 's' && miCarrito.getAmountProduct() <= 25){
        cout << "Numero de producto a comprar: ";
        cin >> numProducto;
        cout << "Cantidad: ";
        cin >> cantidadProductos;
        miCarrito.addProduct(prod[numProducto - 1 ], cantidadProductos);
        cout << "¿Quieres agregar otro producto? s/n: ";
        cin >> respuesta;
    }
    miCarrito.printTicket();
    
}

                                                                        //Ines ALejandro//Benjamin Gutierrez
//Programa principal
int main()
{   
    Login(id);
    cuantos = 0;
    menu();
    llenarCatalogo(catalogo,cuantos);
    //imprimeCatalogo(catalogo,cuantos);
    int option = 0;
    while (option != 7){
        cout << "Ingrese la opcion que desea: ";
        cin >> option;
        switch (option){
            case 1:
                cout << "----------------------CATALOGO DE TECNOLOGIA----------------------";
                tech(catalogo);
                ProcesoCompra(catalogo);
                break;
            case 2:
                cout << "----------------------CATALOGO DE MASCOTAS----------------------";
                pets(catalogo);
                ProcesoCompra(catalogo);
                break;
            case 3:
                cout << "----------------------CATALOGO DE BELLEZA----------------------";
                beauty(catalogo);
                ProcesoCompra(catalogo);
                break;
            case 4:
                cout << "----------------------CATALOGO DE DEPORTES----------------------";
                sports(catalogo);
                ProcesoCompra(catalogo);
                break;
            case 5:
                cout << "----------------------CATALOGO DE COMPLETO----------------------\n";
                imprimeCatalogo(catalogo,cuantos);
                ProcesoCompra(catalogo);
                break;
            case 6:
                cout << "----------------------MI CUENTA----------------------\n";
                users[id-1].PrintUser();
                break;
            case 7:
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
        system("pause");
        menu();
    } 
    
    system("pause");
    return 0;

}