#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>

#include "crop.h"

class CategoryTree
{
private:
    struct Node
    {
        std::string key;
        std::string category;
        std::vector<Crop> crops;
        Node* left;
        Node* right;

        explicit Node(Crop crop);
    };

    Node* root;

    static std::string makeKey(const std::string& category);
    static Node* insert(Node* node, Crop crop);
    static Node* find(Node* node, const std::string& key);
    static void displayInOrder(Node* node);
    static void destroy(Node* node);

public:
    CategoryTree();
    ~CategoryTree();

    CategoryTree(const CategoryTree&) = delete;
    CategoryTree& operator=(const CategoryTree&) = delete;

    void insertCrop(Crop crop);
    void displayCategories();
    bool displayCategory(const std::string& category);
};

#endif
