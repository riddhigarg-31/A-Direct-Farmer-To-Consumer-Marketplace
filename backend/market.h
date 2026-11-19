#ifndef MARKET_H
#define MARKET_H

#include <vector>
#include <string>
#include "farmer.h"
#include "buyer.h"
#include "crop.h"
#include "Order.h"
#include "hashtable.h"
#include "expirypriority.h"
#include "OrderQueue.h"
#include "tree.h"

using namespace std;

class Market
{
private:
    vector<Farmer> farmers;
    vector<Buyer> buyers;
    vector<Crop> crops;
    vector<Order> orders;

    HashTable cropSearch;
    ExpiryPriorityQueue expiryQueue;
    OrderQueue orderQueue;
    CategoryTree categoryTree;

    int nextOrderID;

    bool farmerExists(string id);
    bool buyerExists(string id);
    int findCrop(string id);

public:
    Market();

    void loadData();
    void saveData();

    void addFarmer();
    void addBuyer();
    void addCrop();
    void showCrops();
    void searchCrop();
    void sortByPrice();
    void showExpiryPriority();
    void showCropsByCategory();
    void placeOrder();
};

#endif
