#include "expirypriorityqueue.h"

ExpiryPriorityQueue::ExpiryPriorityQueue()
{
    size = 0;
}
void ExpiryPriorityQueue::indexup(int index)
{
    int parent = 0;

    while (index > 0)
    {
        parent = (index - 1) / 2;

        if (crop[parent].getexpiry() > crop[index].getexpiry())
        {
            Crop temp = crop[parent];
            crop[parent] = crop[index];
            crop[index] = temp;

            index = parent;
        }
        else
        {
            break;
        }
    }
}
void ExpiryPriorityQueue::indexdown(int index)
{
    int leftchild = 2 * index + 1;
    int rightchild = 2 * index + 2;
    int smallest = index;
    if (leftchild < size &&
        crop[leftchild].getexpiry() < crop[smallest].getexpiry())
    {
        smallest = leftchild;
    }
    if (rightchild < size &&
        crop[rightchild].getexpiry() < crop[smallest].getexpiry())
    {
        smallest = rightchild;
    }
    if (smallest != index)
    {
        Crop temp = crop[index];
        crop[index] = crop[smallest];
        crop[smallest] = temp;

        indexdown(smallest);
    }
}
void ExpiryPriorityQueue::insertcrop(Crop c)
{
    if (size >= max)
        return;

    crop[size] = c;
    indexup(size);
    size++;
}
Crop ExpiryPriorityQueue::removeHighestPriority()
{
    if (size == 0)
    {
        cout << "No crops available" << endl;
        return Crop();
    }
    Crop removed = crop[0];
    crop[0] = crop[size - 1];
    size--;
    if (size > 0)
    {
        indexdown(0);
    }
    return removed;
}
void ExpiryPriorityQueue::displayByPriority()
{
    if (size == 0)
    {
        cout << "No crops available" << endl;
        return;
    }
    ExpiryPriorityQueue temp = *this;
    int rank = 1;
    cout << "\nCrops in Expiry Priority Order:\n";
    while (temp.size > 0)
    {
        Crop c = temp.removeHighestPriority();
        cout << "\nPriority Rank: " << rank << endl;
        c.display();
        rank++;
    }
}