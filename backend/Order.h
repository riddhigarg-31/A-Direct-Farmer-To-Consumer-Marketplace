#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
using namespace std;

class Order
{
private:
    int orderID;
    string buyerID;
    string cropName;
    double quantity;
    double totalPrice;

public:
    Order();
    Order(int id, string bID, string cName, double q, double price);

    void display();

    int getOrderID();
    string getBuyerID();
    double getTotalPrice();
};

#endif
