#include "buyer.h"

void Buyer::input()
{
    cout << "Enter id : ";
    cin >> BuyerID;
    cin.ignore();
    cout << "Enter name : ";
    getline(cin, Buyername);
    cout << "Enter location : ";
    getline(cin, Location);
    cout << "Enter phone : ";
    getline(cin, Phone);
}

void Buyer::display()
{
    cout << "Buyer ID : " << BuyerID << endl;
    cout << "Name : " << Buyername << endl;
    cout << "Location : " << Location << endl;
    cout << "Phone : " << Phone << endl;
}

void Buyer::save(ofstream &file)
{
    file << BuyerID << endl;
    file << Buyername << endl;
    file << Location << endl;
    file << Phone << endl;
}

void Buyer::read(ifstream &readfile)
{
    getline(readfile, BuyerID);
    getline(readfile, Buyername);
    getline(readfile, Location);
    getline(readfile, Phone);
}

string Buyer::getID()
{
    return BuyerID;
}