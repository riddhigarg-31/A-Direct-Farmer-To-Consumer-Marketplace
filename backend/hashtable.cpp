
#include "hashtable.h"

HashTable::Node::Node(Crop c)
{
    crop = c;
    next = nullptr;
}

int HashTable::hashFunction(string name)
{
    int sum = 0;

    for (int i = 0; i < name.length(); i++)
    {
        sum += name[i];
    }

    return sum % SIZE;
}

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = nullptr;
    }
}

void HashTable::insertCrop(Crop c)
{
    int index = hashFunction(c.getcropName());

    Node* newNode = new Node(c);
    newNode->next = table[index];
    table[index] = newNode;

    cout << "Crop inserted successfully!" << endl;
}

void HashTable::searchCrop(string name)
{
    int index = hashFunction(name);
    Node* temp = table[index];

    while (temp != nullptr)
    {
        if (temp->crop.getcropName() == name)
        {
            cout << "Crop found:" << endl;
            temp->crop.display();
            return;
        }

        temp = temp->next;
    }

    cout << "Crop not found!" << endl;
}

void HashTable::displayTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << ": ";

        Node* temp = table[i];

        while (temp != nullptr)
        {
            cout << temp->crop.getcropName() << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        Node* temp = table[i];

        while (temp != nullptr)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
}
