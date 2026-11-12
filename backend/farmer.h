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
    Farmer();

    Farmer(string id, string name, string loc, string ph);

    void input();
    void display();

    void save(ofstream &file);
    void read(ifstream &readfile);

    string getID();
    string getName();
    string getLocation();
    string getPhone();

    void setLocation(string loc);
    void setPhone(string ph);

    void saveToFile();
    void readFromFile();
};
