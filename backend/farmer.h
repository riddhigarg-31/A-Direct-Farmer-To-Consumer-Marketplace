#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class Farmer
{
private:
    string FarmerID;
    string Farmername;
    string Location;
    string Phone;

public:
    void input()
    {
        cout << "Enter id : ";
        getline(cin, FarmerID);
        cout << "Enter name : ";
        getline(cin, Farmername);
        cout << "Enter location : ";
        getline(cin, Location);
        cout << "Enter phone : ";
        getline(cin, Phone);
    }

    void display()
    {
        cout << "Farmer ID : " << FarmerID << endl;
        cout << "Name : " << Farmername << endl;
        cout << "Location : " << Location << endl;
        cout << "Phone : " << Phone << endl;
    }

    void save(ofstream &file)
    {
        file << FarmerID << endl;
        file << Farmername << endl;
        file << Location << endl;
        file << Phone << endl;
    }

    void read(ifstream &readfile)
    {
        getline(readfile, FarmerID);
        getline(readfile, Farmername);
        getline(readfile, Location);
        getline(readfile, Phone);
    }

    string getID() { return FarmerID; }
    string getName() { return Farmername; }
};
