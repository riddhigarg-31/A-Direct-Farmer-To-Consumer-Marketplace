#ifndef EXPIRYPRIORITY_H
#define EXPIRYPRIORITY_H

#include <iostream>
#include "crop.h"

using namespace std;

class ExpiryPriorityQueue
{
private:
    static const int MAX = 100;
    Crop crop[MAX];
    int size;

    void indexup(int index);
    void indexdown(int index);

public:
    ExpiryPriorityQueue();

    void insertcrop(Crop c);
    Crop removeHighestPriority();
    void displayByPriority();
};
end
