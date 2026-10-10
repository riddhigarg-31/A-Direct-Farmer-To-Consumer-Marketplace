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
Order()
{
    orderID = 0;
    buyerID = "";
    cropName = "";
    quantity = 0.0;
    totalPrice = 0.0;
}
    Order(int id, string bID, string cName, double q, double price)
    {
        orderID = id;
        buyerID = bID;
        cropName = cName;
        quantity = q;
        totalPrice = q * price;
    }

    void display()
    {
        cout << "\nOrder ID : " << orderID << endl;
        cout << "Buyer ID : " << buyerID << endl;
        cout << "Crop Name : " << cropName << endl;
        cout << "Quantity : " << quantity << " kg" << endl;
        cout << "Total Price : Rs " << totalPrice << endl;
    }

    int getOrderID()
    {
        return orderID;
    }

    string getBuyerID()
    {
        return buyerID;
    }

    double getTotalPrice()
    {
        return totalPrice;
    }
};
