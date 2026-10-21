#include "buyer.h"
#include <limits>
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
Buyer::Buyer(string id, string name, string loc, string ph)
{
    BuyerID = id;
    Buyername = name;
    Location = loc;
    Phone = ph;
}

string Buyer::getID()
{
    return BuyerID;
}
string Buyer::getName() {
     return Buyername; }
string Buyer::getLocation() { 
    return Location; }
string Buyer::getPhone() {
     return Phone; }
