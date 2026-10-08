#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Buyer
{
private:
    string BuyerID;
    string Buyername;
    string Location;
    string Phone;
public:
    void input()
    {
        cout<<"Enter id : ";
        cin>>BuyerID;
        cin.ignore();
        cout<<"Enter name : ";
        getline(cin,Buyername);
        cout<<"Enter location : ";
        getline(cin,Location);
        cout<<"Enter phone : ";
        getline(cin,Phone);
    }
    void display()
    {
        cout<<"Buyer ID : "<<BuyerID<<endl;
        cout<<"Name : "<<Buyername<<endl;
        cout<<"Location : "<<Location<<endl;
        cout<<"Phone : "<<Phone<<endl;
    }
    void save(ofstream &file)
    {
        file<<BuyerID<<endl;
        file<<Buyername<<endl;
        file<<Location<<endl;
        file<<Phone<<endl;
    }
    void read(ifstream &readfile)
    {
        getline(readfile,BuyerID);
        getline(readfile,Buyername);
        getline(readfile,Location);
        getline(readfile,Phone);
    }
    string getID()
    {
        return BuyerID;
    }
};