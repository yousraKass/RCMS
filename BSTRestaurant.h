#ifndef BSTRESTAURANT_H
#define BSTRESTAURANT_H

#include "Restaurant.h"

#include <iostream>
using namespace std;

class PrizeWinners;

class BSTRestaurantTree
{
    friend class PrizeWinners;

private:
    Restaurant *root;
    int totalRestaurants;

    //************Utility functions************
    // Insert x with two version
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);

    // search for x return true if found, else false
    bool contains(const int &key, Restaurant *ROOT) const;

    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const;

    // utility function to find a restaurant with an ID, returns a pointer to the restaurant if found , else return nullptr
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const;

    // destroy the the BST
    void makeEmpty(Restaurant *&ROOT);

public:
    // default constructor
    BSTRestaurantTree();

    // return true if empty,false otherwise
    bool IsEmpty() const;

    // return true if restaurant with Id =key is found
    bool contains(const int &key);

    // insert restaurant
    void insert(const Restaurant &R);

    // return the total number of restaurants
    int getTotalRestaurants() const;

    // show data of all restaurant in the BST
    void printRestaurantsData() const;

    // return a pointer to the restaurant with Id=key
    Restaurant *getRestaurant(const int &key) const;

    // Remove all restaurants start with left tree, right tree then the root
    void makeEmpty();
    
    // destructor that will call makeEmpty
    ~BSTRestaurantTree();
};

// default constructor
BSTRestaurantTree::BSTRestaurantTree() : root(nullptr)
{
    totalRestaurants = 0;
}
void BSTRestaurantTree::insert(const Restaurant R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }
    else if (R.getId() < ROOT->getId())
        insert(R, ROOT->leftChild);
    else if (R.getId() > ROOT->getId())
        insert(R, ROOT->rightChild);
}
void BSTRestaurantTree::insert(Restaurant &&R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }
    else if (!contains(R.getId(), ROOT))
    {
        if (R.getId() < ROOT->getId())
            insert(R, ROOT->leftChild);
        else if (R.getId() > ROOT->getId())
            insert(R, ROOT->rightChild);
    }
    // duplicates
}

bool BSTRestaurantTree::contains(const int &key, Restaurant *ROOT) const
{

    if (ROOT == nullptr)
        return false;
    else if (ROOT->getId() == key)
        return true;
    else if (key < ROOT->getId())
        return contains(key, ROOT->leftChild);
    else if (key > ROOT->getId())
        return contains(key, ROOT->rightChild);
    else
        return ROOT;
}

// show data of all restaurants
void BSTRestaurantTree::printHelper(Restaurant *ROOT) const
{
    if (ROOT != nullptr)
    {
        printHelper(ROOT->leftChild);
        ROOT->showRestaurantData();
        cout << "--------------------------------------------" << endl;
        cout << "--------------------------------------------" << endl;
        printHelper(ROOT->rightChild);
    }
}
// utility function to find a restaurant with an ID
Restaurant *BSTRestaurantTree::getRestauranthelper(const int &key, Restaurant *ROOT) const
{
    if (ROOT == nullptr)
        return nullptr;
    else if (ROOT->getId() == key)
        return ROOT;
    else if (key < ROOT->getId())
        return getRestauranthelper(key, ROOT->leftChild);
    else
        return getRestauranthelper(key, ROOT->rightChild);
}
void BSTRestaurantTree::makeEmpty(Restaurant *&ROOT)
{
    if (ROOT != nullptr)
    {

        makeEmpty(ROOT->leftChild);
        makeEmpty(ROOT->rightChild);
        delete ROOT;
        ROOT = nullptr;
    }
}

bool BSTRestaurantTree::IsEmpty() const
{
    return (root == nullptr);
}

bool BSTRestaurantTree::contains(const int &key)
{
    return contains(key, root);
}

void BSTRestaurantTree::insert(const Restaurant &R)
{

    insert(R, root);
}
int BSTRestaurantTree::getTotalRestaurants() const
{
    return totalRestaurants;
}
void BSTRestaurantTree::printRestaurantsData() const
{
    cout << "Total number of restaurants is: " << getTotalRestaurants() << endl;
    printHelper(root);
}
Restaurant *BSTRestaurantTree::getRestaurant(const int &key) const
{
    return getRestauranthelper(key, root);
}

//--> Remove all restaurants
void BSTRestaurantTree::makeEmpty()
{
    makeEmpty(root);
}
BSTRestaurantTree::~BSTRestaurantTree()
{
    makeEmpty();
}

#endif
