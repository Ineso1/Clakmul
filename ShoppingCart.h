#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "Product.h"
static const int MAX = 10;
class ShoppingCart{
    private:
        Product products[MAX];
        int amount[MAX];
        int amountProduct;
    public:
        ShoppingCart();
        ~ShoppingCart();
        Product getProduct(int);
        int getAmount(int);
        int getAmountProduct() const;
        void addProduct(Product, int);
        float total();
        void printTicket();
};

#endif