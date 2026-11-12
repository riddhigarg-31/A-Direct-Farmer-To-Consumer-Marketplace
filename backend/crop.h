#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Crop
{
private:
    string cropID;
    string cropName;
    string category;
    double price;
    double quantity;
    int expiry;
    string farmerID;

public:
    Crop();
    Crop(string id, string name, string cat, double p, double quant, int ex, string fid);

    void input();
    void display();

    string getcropID();
    string getcropName();
    string getcategory();
    double getprice();
    double getquantity();
    int getexpiry();
    string getfarmerID();

    void quantityUpdate(double quantpurchased);
    void setprice(double p);
    void setexpiry(int e);

    void saveToFile();
    void readFromFile();
};

#endif