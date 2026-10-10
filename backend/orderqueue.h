#pragma once
#include "Order.h"

class OrderQueue
{
    Order orders[100];
    int f;
    int r;

public:
    OrderQueue();
    void enqueue(Order o);
    Order dequeue();
    bool isEmpty();
    bool isFull();
};