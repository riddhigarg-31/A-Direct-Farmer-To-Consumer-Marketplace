#pragma once
#include <iostream>
#include "crop.h"
using namespace std;
#define max 100
class ExpiryPriorityQueue
{
private:
    Crop crop[max];
    int size;

    void indexup(int index);
    void indexdown(int index);

public:
    ExpiryPriorityQueue();

    void insertcrop(Crop c);

    Crop removeHighestPriority();

    void displayByPriority();
};