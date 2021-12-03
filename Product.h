#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
//Ines Alejandro
class Product{
    private:
        std::string name;
        float price;
    public:
    //Constructores
        Product();
        Product(std::string,float);
        ~Product();
        //Seccion de getters
        std::string getName() const;
        float getPrice() const;
        //Seccion de setters
        void setName(std::string);
        void setPrice(float);
        //Metodos
        void printProduct();
};

#endif