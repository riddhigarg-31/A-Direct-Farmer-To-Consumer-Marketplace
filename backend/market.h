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
    vector<Crop> getExpiryPriorityCrops()
    {
    ExpiryPriorityQueue tempQueue;

    // Insert all crops into the temporary priority queue
    for (int i = 0; i < crops.size(); i++)
    {
        tempQueue.insertcrop(crops[i]);
    }

    vector<Crop> priorityCrops;

    // Remove crops according to expiry priority
    for (int i = 0; i < crops.size(); i++)
    {
        priorityCrops.push_back(tempQueue.removeHighestPriority());
    }

    return priorityCrops;
}
    void loadData();
    void saveData();
    vector<Crop> getAllCrops();
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
