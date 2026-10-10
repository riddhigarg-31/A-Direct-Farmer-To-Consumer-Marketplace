#pragma once
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class Crop
{
	string cropID;
	string cropName;
	string category;
	double price;
	double quantity;
	int expiry;
	string farmerID;
public:
    Crop()
    {}
	Crop(string id, string name, string cat, double p, double quant, int ex, string fid)
	{
		cropID = id;
		cropName = name;
		category = cat;
		price = p;
		quantity = quant;
		expiry = ex;
		farmerID = fid;
	}
    void input()
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
	void display()
	{
		cout<<"Crop ID :"<<cropID<<endl;
		cout<<"Crop Name :"<<cropName<<endl;
		cout<<"Category :"<<category<<endl;
		cout<<"Price : Rs "<<price<<endl;
		cout<<"Quantity :"<<quantity<<" kg"<<endl;
		cout<<"Expiry :"<<expiry<<" days"<<endl;
		cout<<"Farmer ID :"<<farmerID<<endl;
	}
	string getcropID()
	{
		return cropID;
	}
	string getcropName()
	{
		return cropName;
	}
	string getcategory()
	{
		return category;
	}
	double getprice()
	{
		return price;
	}
	double getquantity()
	{
		return quantity;
	}
	int getexpiry()
	{
		return expiry;
	}
	string getfarmerID()
	{
		return farmerID;
	}
	void quantityUpdate(double quantpurchased)
	{
		cout<<"Available quantity :"<<quantity<<endl;
		cout<<"Quantity purchased :"<<quantpurchased<<endl;
		if(quantpurchased>quantity)
		{
			cout<<"invalid quantity"<<endl;
		}
		else
		{
			quantity -= quantpurchased;
			cout<<"Remaining quantity :"<<quantity<<endl;
		}
	}
	void setprice(double p)
	{
		price = p;
	}
	void setexpiry(int e)
	{
		expiry = e;
	}
    void saveToFile()
    {
        ifstream check("crops.txt");

        string id, name, cat, fid;
        double p, q; 
        int ex;
        while(check >> id >> name >> cat >> p >> q >> ex >> fid)
        {
            if(id == cropID)
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
    void readFromFile()
    {
        ifstream file("crops.txt");
        while(file>>cropID)
        {
        file>>cropName;
        file>>category;
        file>>price;
        file>>quantity;
        file>>expiry;
        file>>farmerID;
        cout<<endl;
        display();
        }
        file.close();
    }
};