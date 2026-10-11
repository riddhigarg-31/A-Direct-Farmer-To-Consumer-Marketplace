
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "crop.h"
#include <iostream>
#include <string>
using namespace std;

class HashTable
{
private:
    static const int SIZE = 10;

    struct Node
    {
        Crop crop;
        Node* next;

        Node(Crop c);
    };

    Node* table[SIZE];

    int hashFunction(string name);

public:
    HashTable();
    void insertCrop(Crop c);
    void searchCrop(string name);
    void displayTable();
    ~HashTable();
};

#endif
