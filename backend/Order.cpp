#include "Order.h"

Order::Order()
{
    orderID = 0;
    buyerID = "";
    cropName = "";
    quantity = 0.0;
    totalPrice = 0.0;
}

Order::Order(int id, string bID, string cName, double q, double price)
{
    orderID = id;
    buyerID = bID;
    cropName = cName;
    quantity = q;
    totalPrice = q * price;
}

void Order::display()
{
    cout << "\nOrder ID : " << orderID << endl;
    cout << "Buyer ID : " << buyerID << endl;
    cout << "Crop Name : " << cropName << endl;
    cout << "Quantity : " << quantity << " kg" << endl;
    cout << "Total Price : Rs " << totalPrice << endl;
}

int Order::getOrderID()
{
    return orderID;
}

string Order::getBuyerID()
{
    return buyerID;
}

double Order::getTotalPrice()
{
    return totalPrice;
}
