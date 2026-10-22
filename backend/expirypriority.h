#pragma once
#include <iostream>
#include "crop.h"
using namespace std;
const int MAX_CROPS = 100;
class ExpiryPriorityQueue
{
private:
   Crop crop[MAX_CROPS];
    int size;

    void indexup(int index);
    void indexdown(int index);

public:
    ExpiryPriorityQueue();

    void insertcrop(Crop c);

    Crop removeHighestPriority();

    void displayByPriority();
};