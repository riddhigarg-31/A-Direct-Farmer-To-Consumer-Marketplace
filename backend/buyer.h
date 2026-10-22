#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Buyer
{
private:
    string BuyerID;
    string Buyername;
    string Location;
    string Phone;
public:
Buyer() {}
Buyer(string id, string name, string loc, string ph);
    void input();
    void display();
    void save(ofstream &file);
    void read(ifstream &readfile);
    string getID();
    string getName();
string getLocation();
string getPhone();
}; 