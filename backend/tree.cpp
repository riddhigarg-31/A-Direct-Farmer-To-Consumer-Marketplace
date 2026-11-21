#include "tree.h"

#include <cctype>
#include <iostream>

using namespace std;

CategoryTree::Node::Node(Crop crop)
    : key(CategoryTree::makeKey(crop.getcategory())),
      category(crop.getcategory()),
      crops(1, crop),
      left(nullptr),
      right(nullptr)
{
}

CategoryTree::CategoryTree()
    : root(nullptr)
{
}

CategoryTree::~CategoryTree()
{
    destroy(root);
}

string CategoryTree::makeKey(const string& category)
{
    string key;

    for (unsigned char character : category)
    {
        if (!isspace(character))
            key += static_cast<char>(tolower(character));
    }

    return key;
}

CategoryTree::Node* CategoryTree::insert(Node* node, Crop crop)
{
    if (node == nullptr)
        return new Node(crop);

    const string key = makeKey(crop.getcategory());

    if (key < node->key)
        node->left = insert(node->left, crop);
    else if (key > node->key)
        node->right = insert(node->right, crop);
    else
        node->crops.push_back(crop);

    return node;
}

CategoryTree::Node* CategoryTree::find(Node* node, const string& key)
{
    while (node != nullptr)
    {
        if (key == node->key)
            return node;

        node = (key < node->key) ? node->left : node->right;
    }

    return nullptr;
}

void CategoryTree::displayInOrder(Node* node)
{
    if (node == nullptr)
        return;

    displayInOrder(node->left);

    cout << "\nCategory: " << node->category << endl;
    cout << "-------------------------" << endl;
    for (Crop& crop : node->crops)
    {
        crop.display();
        cout << endl;
    }

    displayInOrder(node->right);
}

void CategoryTree::destroy(Node* node)
{
    if (node == nullptr)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

void CategoryTree::insertCrop(Crop crop)
{
    root = insert(root, crop);
}

void CategoryTree::displayCategories()
{
    if (root == nullptr)
    {
        cout << "No crops available." << endl;
        return;
    }

    cout << "\nCrops categorized by category:\n";
    displayInOrder(root);
}

bool CategoryTree::displayCategory(const string& category)
{
    Node* node = find(root, makeKey(category));

    if (node == nullptr)
    {
        cout << "Category not found." << endl;
        return false;
    }

    cout << "\nCategory: " << node->category << endl;
    cout << "-------------------------" << endl;
    for (Crop& crop : node->crops)
    {
        crop.display();
        cout << endl;
    }

    return true;
}
