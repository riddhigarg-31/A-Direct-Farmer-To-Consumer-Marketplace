
#include "market.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <utility>

using namespace std;

static vector<string> splitLine(const string& line)
{
    vector<string> parts;
    stringstream ss(line);
    string item;
    while (getline(ss, item, '|'))
        parts.push_back(item);
    return parts;
}

Market::Market()
{
    nextOrderID = 1;
}

bool Market::farmerExists(string id)
{
    for (int i = 0; i < (int)farmers.size(); i++)
        if (farmers[i].getID() == id)
            return true;
    return false;
}

bool Market::buyerExists(string id)
{
    for (int i = 0; i < (int)buyers.size(); i++)
        if (buyers[i].getID() == id)
            return true;
    return false;
}

int Market::findCrop(string id)
{
    for (int i = 0; i < (int)crops.size(); i++)
        if (crops[i].getcropID() == id)
            return i;
    return -1;
}

void Market::loadData()
{
    string line;

    ifstream ff("farmers.txt");
    while (getline(ff, line))
    {
        vector<string> p = splitLine(line);
        if (p.size() == 4)
            farmers.push_back(Farmer(p[0], p[1], p[2], p[3]));
    }
    ff.close();

    ifstream bf("buyers.txt");
    while (getline(bf, line))
    {
        vector<string> p = splitLine(line);
        if (p.size() == 4)
            buyers.push_back(Buyer(p[0], p[1], p[2], p[3]));
    }
    bf.close();

    ifstream cf("crops.txt");
    while (getline(cf, line))
    {
        vector<string> p = splitLine(line);
        if (p.size() == 7)
        {
            Crop c(p[0], p[1], p[2], stod(p[3]), stod(p[4]), stoi(p[5]), p[6]);
            crops.push_back(c);
            cropSearch.insertCrop(c);
            expiryQueue.insertcrop(c);
        }
    }
    cf.close();

    ifstream ordf("orders.txt");
    while (getline(ordf, line))
    {
        vector<string> p = splitLine(line);
        if (p.size() == 5)
        {
            int id = stoi(p[0]);
            double qty = stod(p[3]);
            double total = stod(p[4]);
            double perKg = (qty > 0) ? total / qty : 0;
            orders.push_back(Order(id, p[1], p[2], qty, perKg));
            if (id >= nextOrderID)
                nextOrderID = id + 1;
        }
    }
    ordf.close();
}

void Market::saveData()
{
    ofstream ff("farmers.txt");
    for (Farmer& f : farmers)
        ff << f.getID() << "|" << f.getName() << "|"
           << f.getLocation() << "|" << f.getPhone() << endl;
    ff.close();

    ofstream bf("buyers.txt");
    for (Buyer& b : buyers)
        bf << b.getID() << "|" << b.getName() << "|"
           << b.getLocation() << "|" << b.getPhone() << endl;
    bf.close();

    ofstream cf("crops.txt");
    for (Crop& c : crops)
        cf << c.getcropID() << "|" << c.getcropName() << "|"
           << c.getcategory() << "|" << c.getprice() << "|"
           << c.getquantity() << "|" << c.getexpiry() << "|"
           << c.getfarmerID() << endl;
    cf.close();

    ofstream ordf("orders.txt");
    for (Order& o : orders)
        ordf << o.getOrderID() << "|" << o.getBuyerID() << "|"
             << o.getCropName() << "|" << o.getQuantity() << "|"
             << o.getTotalPrice() << endl;
    ordf.close();
}

void Market::addFarmer()
{
    Farmer f;
    f.input();

    if (farmerExists(f.getID()))
    {
        cout << "Farmer with this ID already exists" << endl;
        return;
    }

    farmers.push_back(f);
    saveData();
    cout << "Farmer saved successfully." << endl;
}

void Market::addBuyer()
{
    Buyer b;
    b.input();

    if (buyerExists(b.getID()))
    {
        cout << "Buyer of this id already exists" << endl;
        return;
    }

    buyers.push_back(b);
    saveData();
    cout << "Buyer saved successfully." << endl;
}

void Market::addCrop()
{
    Crop c;
    c.input();

    if (findCrop(c.getcropID()) != -1)
    {
        cout << "Crop of this id already exists" << endl;
        return;
    }

    if (!farmerExists(c.getfarmerID()))
    {
        cout << "Farmer ID not found , first add farmer" << endl;
        return;
    }

    crops.push_back(c);
    cropSearch.insertCrop(c);
    expiryQueue.insertcrop(c);
    saveData();
    cout << "Crop saved successfully." << endl;
}

void Market::showCrops()
{
    if (crops.empty())
    {
        cout << "NO crop available" << endl;
        return;
    }
    for (Crop& c : crops)
    {
        c.display();
        cout << endl;
    }
}

void Market::searchCrop()
{
    string name;
    cout << "Enter name of the crop : ";
    getline(cin, name);
    cropSearch.searchCrop(name);
}

void Market::sortByPrice()
{
    vector<Crop> sorted = crops;
    int n = (int)sorted.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (sorted[j].getprice() > sorted[j + 1].getprice())
                swap(sorted[j], sorted[j + 1]);

    for (Crop& c : sorted)
    {
        c.display();
        cout << endl;
    }
}

void Market::showExpiryPriority()
{
    expiryQueue.displayByPriority();
}

void Market::placeOrder()
{
    string buyerID, cropID;
    double qty;

    cout << "Buyer ID: ";
    getline(cin, buyerID);
    if (!buyerExists(buyerID))
    {
        cout << "Buyer not found." << endl;
        return;
    }

    cout << "Crop ID: ";
    getline(cin, cropID);
    int ci = findCrop(cropID);
    if (ci == -1)
    {
        cout << "Crop not found." << endl;
        return;
    }

    cout << "Quantity (kg): ";
    cin >> qty;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (qty <= 0)
    {
        cout << "Quantity can't be more than 0." << endl;
        return;
    }
    if (qty > crops[ci].getquantity())
    {
        cout << "This much quantity is not available." << endl;
        return;
    }

    crops[ci].quantityUpdate(qty);

    Order o(nextOrderID++, buyerID, crops[ci].getcropName(), qty, crops[ci].getprice());
    orders.push_back(o);
    orderQueue.enqueue(o);

    saveData();
    cout << "Order placed. Total: Rs " << o.getTotalPrice() << endl;
}