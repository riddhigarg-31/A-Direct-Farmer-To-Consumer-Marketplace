#include <iostream>
#include "OrderQueue.h"

using namespace std;

OrderQueue::OrderQueue()
{
    f = 0;
    r = -1;
}

bool OrderQueue::isEmpty()
{
    return f > r;
}

bool OrderQueue::isFull()
{
    return r >= 99;
}

void OrderQueue::enqueue(Order o)
{
    if (isFull())
    {
        cout << "Order queue is full!" << endl;
        return;
    }
    orders[++r] = o;
}

Order OrderQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Order queue is empty!" << endl;
        return Order(0, "", "", 0.0, 0.0); 
    }
    return orders[f++];
}