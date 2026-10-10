#include "farmer.h"

Farmer::Farmer()
{}

Farmer::Farmer(string id, string name, string loc, string ph)
{
    FarmerID = id;
    Farmername = name;
    Location = loc;
    Phone = ph;
}

void Farmer::input()
{
    cout << "Enter id : ";
    cin >> FarmerID;
    cin.ignore();
    cout << "Enter name : ";
    getline(cin, Farmername);
    cout << "Enter location : ";
    getline(cin, Location);
    cout << "Enter phone : ";
    getline(cin, Phone);
}

void Farmer::display()
{
    cout << "Farmer ID : " << FarmerID << endl;
    cout << "Name : " << Farmername << endl;
    cout << "Location : " << Location << endl;
    cout << "Phone : " << Phone << endl;
}

void Farmer::save(ofstream &file)
{
    file << FarmerID << endl;
    file << Farmername << endl;
    file << Location << endl;
    file << Phone << endl;
}

void Farmer::read(ifstream &readfile)
{
    getline(readfile, FarmerID);
    getline(readfile, Farmername);
    getline(readfile, Location);
    getline(readfile, Phone);
}

string Farmer::getID()
{
    return FarmerID;
}

string Farmer::getName()
{
    return Farmername;
}

string Farmer::getLocation()
{
    return Location;
}

string Farmer::getPhone()
{
    return Phone;
}

void Farmer::setLocation(string loc)
{
    Location = loc;
}

void Farmer::setPhone(string ph)
{
    Phone = ph;
}

void Farmer::saveToFile()
{
    ifstream check("farmers.txt");

    string id, name, loc, ph;
    while (getline(check, id))
    {
        getline(check, name);
        getline(check, loc);
        getline(check, ph);
        if (id == FarmerID)
        {
            cout << "Farmer already exists in file." << endl;
            check.close();
            return;
        }
    }
    check.close();

    ofstream file("farmers.txt", ios::app);
    save(file);
    file.close();

    cout << "Farmer saved successfully." << endl;
}

void Farmer::readFromFile()
{
    ifstream file("farmers.txt");
    while (getline(file, FarmerID))
    {
        getline(file, Farmername);
        getline(file, Location);
        getline(file, Phone);
        cout << endl;
        display();
    }
    file.close();
}