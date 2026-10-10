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
    void input();
    void display();
    void save(ofstream &file);
    void read(ifstream &readfile);
    string getID();
}; 