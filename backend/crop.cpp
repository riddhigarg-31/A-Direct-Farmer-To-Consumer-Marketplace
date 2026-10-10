#include "crop.h"
Crop::Crop()
{
}
Crop::Crop(string id, string name, string cat, double p, double quant, int ex, string fid)
{
    cropID = id;
    cropName = name;
    category = cat;
    price = p;
    quantity = quant;
    expiry = ex;
    farmerID = fid;
}
void Crop::input()
{
    cout << "Enter Crop ID: ";
    cin >> cropID;
    cin.ignore();

    cout << "Enter Crop Name: ";
    getline(cin, cropName);

    cout << "Enter Category: ";
    getline(cin, category);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Expiry: ";
    cin >> expiry;

    cout << "Enter Farmer ID: ";
    cin >> farmerID;
}
void Crop::display()
{
    cout << "Crop ID: " << cropID << endl;
    cout << "Crop Name: " << cropName << endl;
    cout << "Category: " << category << endl;
    cout << "Price: Rs " << price << endl;
    cout << "Quantity: " << quantity << " kg" << endl;
    cout << "Expiry: " << expiry << " days" << endl;
    cout << "Farmer ID: " << farmerID << endl;
}
string Crop::getcropID()
{
    return cropID;
}
string Crop::getcropName()
{
    return cropName;
}
string Crop::getcategory()
{
    return category;
}
double Crop::getprice()
{
    return price;
}
double Crop::getquantity()
{
    return quantity;
}
int Crop::getexpiry()
{
    return expiry;
}
string Crop::getfarmerID()
{
    return farmerID;
}
void Crop::quantityUpdate(double quantpurchased)
{
    cout << "Available quantity: " << quantity << endl;
    cout << "Quantity purchased: " << quantpurchased << endl;
    if (quantpurchased > quantity || quantpurchased < 0)
    {
        cout << "Invalid quantity" << endl;
    }
    else
    {
        quantity -= quantpurchased;
        cout << "Remaining quantity: " << quantity << endl;
    }
}
void Crop::setprice(double p)
{
    price = p;
}
void Crop::setexpiry(int e)
{
    expiry = e;
}
void Crop::saveToFile()
{
    ifstream check("crops.txt");
    string id, name, cat, fid;
    double p, q;
    int ex;
    while (check >> id >> name >> cat >> p >> q >> ex >> fid)
    {
        if (id == cropID)
        {
            cout << "Crop already exists in file." << endl;
            check.close();
            return;
        }
    }
    check.close();
    ofstream file("crops.txt", ios::app);
    file << cropID << " "
         << cropName << " "
         << category << " "
         << price << " "
         << quantity << " "
         << expiry << " "
         << farmerID << endl;

    file.close();
    cout << "Crop saved successfully." << endl;
}
void Crop::readFromFile()
{
    ifstream file("crops.txt");
    while (file >> cropID)
    {
        file >> cropName;
        file >> category;
        file >> price;
        file >> quantity;
        file >> expiry;
        file >> farmerID;

        cout << endl;
        display();
    }
    file.close();
}