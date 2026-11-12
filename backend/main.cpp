#include <iostream>
#include <limits>
#include "market.h"

using namespace std;

int main()
{
    Market m;

    m.loadData();

    int choice = -1;

    do
    {
        cout << "\nFarmer to Consumer Marketplace\n";
        cout << "1. Add Farmer\n";
        cout << "2. Add Buyer\n";
        cout << "3. Add Crop\n";
        cout << "4. Show All Crops\n";
        cout << "5. Search Crop\n";
        cout << "6. Sort Crops by Price\n";
        cout << "7. Show Expiry Priority\n";
        cout << "8. Place Order\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
                m.addFarmer();
                break;

            case 2:
                m.addBuyer();
                break;

            case 3:
                m.addCrop();
                break;

            case 4:
                m.showCrops();
                break;

            case 5:
                m.searchCrop();
                break;

            case 6:
                m.sortByPrice();
                break;

            case 7:
                m.showExpiryPriority();
                break;

            case 8:
                m.placeOrder();
                break;

            case 0:
                m.saveData();
                cout << "Data saved. Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
