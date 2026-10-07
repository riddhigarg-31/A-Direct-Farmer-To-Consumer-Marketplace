# A-Direct-Farmer-To-Consumer-Marketplace

A simple C++ project that connects farmers directly with buyers, without a middleman. Farmers list their crops, buyers search and order them, and crops that are close to expiry are given priority so perishable produce is used before it loses value.

##Features
Farmer registration and crop listing (name, category, price, quantity, expiry)
Buyer registration
Search crops by name
Sort crops by price
Order placing with quantity update
Expiry based priority (near expiry crops first)
File handling to save and load data

##Classes
Farmer: ID, name, location, phone
Buyer: ID, name, location, phone
Crop: crop ID, name, category, price, quantity, expiry, farmer ID
Order: buyer ID, crop ID, quantity
Market: holds farmers, crops and orders, and handles add, search, sort and orders

##Sample Menu
1. Add farmer
2. Add crop
3. Show crops
4. Search crop
5. Sort by price
6. Exit

##Data Structures Used
Arrays to store farmers, buyers and crops
Linear search / hashing to search crops
Bubble sort to sort crops by price
Queue to process orders
Priority queue for expiry based priority
File handling (fstream) to save and load data

##Technology Stack
C++
HTML, CSS, JavaScript (frontend)
Git and GitHub for version control
Visual Studio Code

##Team Members
Riddhi Garg
Siddhi Atray
Darishti Rane
Kunal
